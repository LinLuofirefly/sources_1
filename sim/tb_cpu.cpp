// ===========================================================================
// tb_cpu.cpp — Verilator C++ testbench for the RV32I/M CPU
//
// 功能:
//   1. 驱动双时钟 (cpu_clk ~200MHz, clk_50Mhz 50MHz)
//   2. 监控外设写总线，仅在 LED / SEG 被写入时打印日志
//   3. LED 写入 1 次且 SEG 写入 2 次后结束
//   4. +max_cycles=N 可选调试保护
//   5. 仿真结束时打印总周期数和结束原因
//   6. 日志同时输出到终端和文件
//   6. 性能统计 (可选): CPI, 分支预测, DCache, 停顿分析
//
// 用法:
//   ./obj_dir/Vsim_wrapper [+max_cycles=N] [+log=<path>] [+no-file-log]
//                          [--enable-perf] [--disable-perf] [--perf-output=<path>]
// ===========================================================================

#include "Vsim_wrapper.h"
#include "verilated.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdint>
#include <cstdarg>
#include <string>

// ---------------------------------------------------------------------------
// 全局配置
// ---------------------------------------------------------------------------
static bool g_max_cycles_en   = false;
static uint64_t g_max_cycles  = 0;
static const char *g_log_path = "sim/logs/sim.log";
static bool g_file_log        = true;
static bool g_expect_led_en   = false;
static uint32_t g_expect_led  = 0;
static int g_expect_shift_stalls = -1;
static int g_expect_shift_commits = -1;
static bool g_expect_no_shift_late = false;
static uint64_t g_trace_interval = 0;
static uint64_t g_trace_start = 0;
static uint64_t g_trace_end = UINT64_MAX;

static const uint32_t LED_ADDR = 0x80200040u;
static const uint32_t SEG_ADDR = 0x80200020u;
static const int REQUIRED_LED_WRITES = 1;
static const int REQUIRED_SEG_WRITES = 2;

// Performance statistics configuration
static bool g_perf_enabled = true;
static std::string g_perf_output_path = "sim/logs/performance_summary.txt";

// ---------------------------------------------------------------------------
// 日志
// ---------------------------------------------------------------------------
static FILE *g_logfp = nullptr;

static void log_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    if (g_logfp) {
        va_start(ap, fmt);
        vfprintf(g_logfp, fmt, ap);
        va_end(ap);
        fflush(g_logfp);
    }
}

// ---------------------------------------------------------------------------
// Performance Statistics Structure
// ---------------------------------------------------------------------------
struct CpuPerfStats {
    // Core performance
    uint64_t total_cycles = 0;
    uint64_t retired_instructions = 0;

    // Branch prediction
    uint64_t conditional_branch_count = 0;
    uint64_t branch_prediction_correct = 0;
    uint64_t branch_prediction_wrong = 0;
    uint64_t branch_mispredict_flush_count = 0;
    uint64_t branch_taken_count = 0;
    uint64_t branch_not_taken_count = 0;

    // BTB
    uint64_t btb_lookup_count = 0;
    uint64_t btb_hit_count = 0;
    uint64_t btb_target_wrong_count = 0;

    // DCache
    uint64_t dcache_access_count = 0;
    uint64_t dcache_hit_count = 0;
    uint64_t dcache_miss_count = 0;
    uint64_t dcache_miss_stall_cycles = 0;

    // Stall breakdown
    uint64_t total_stall_cycles = 0;
    uint64_t frontend_wait_cycles = 0;
    uint64_t load_use_stall_cycles = 0;
    uint64_t data_hazard_stall_cycles = 0;
    uint64_t dcache_or_memory_stall_cycles = 0;
    uint64_t branch_recovery_cycles = 0;
    uint64_t mul_div_stall_cycles = 0;
    uint64_t replay_stall_cycles = 0;
    uint64_t other_stall_cycles = 0;

    // Flush and replay
    uint64_t total_flush_count = 0;
    uint64_t branch_flush_count = 0;
    uint64_t replay_count = 0;

    // Internal state for edge detection
    bool prev_bp_update = false;
    bool prev_branch_redirect = false;
    bool prev_flush_ifid = false;
    bool prev_dcache_refill = false;
    bool prev_mem2_is_load = false;
    bool prev_bp_replay_flush = false;
    bool prev_hdu_hold = false;
    bool prev_ex_load_dep = false;
    bool prev_mem1_load_dep = false;
    bool prev_mem1_load_shift_dep = false;
    bool prev_mem2_slow_load_dep = false;
    bool prev_ex_busy = false;
    bool prev_btb_hit = false;
    bool prev_bp_pred_flush = false;

    void sample(const Vsim_wrapper* dut) {
        total_cycles++;

        // 1. Instruction retirement (WB stage)
        //    Count instructions that actually write back to a register
        //    Exclude NOP (x0 writes) and instructions with rd_addr == 0
        bool rd_wen = dut->mon_wb_rd_wen;
        uint32_t wb_inst = dut->mon_wb_inst;
        uint32_t rd_addr = (wb_inst >> 7) & 0x1Fu;
        bool is_nop = (wb_inst == 0x00000013u);

        if (rd_wen && rd_addr != 0 && !is_nop) {
            retired_instructions++;
        }

        // 2. Branch prediction (EX stage)
        //    Count conditional branches at resolution time
        //    Use edge detection to avoid counting same branch multiple times
        bool bp_update = dut->mon_bp_update_en;
        bool branch_redirect = dut->mon_branch_redirect;
        bool is_conditional = dut->mon_ex_is_branch;

        if (bp_update && !prev_bp_update) {
            // This is a conditional branch being resolved
            if (is_conditional) {
                conditional_branch_count++;

                if (dut->mon_bp_actual_taken) {
                    branch_taken_count++;
                } else {
                    branch_not_taken_count++;
                }

                if (branch_redirect) {
                    branch_prediction_wrong++;
                } else {
                    branch_prediction_correct++;
                }
            }
        }
        prev_bp_update = bp_update;

        // 3. BTB lookup (request stage)
        //    Count BTB lookups when a BTB hit occurs (rising edge)
        //    This indicates a branch prediction was made
        bool btb_hit = dut->mon_btb_hit;
        if (btb_hit && !prev_btb_hit) {
            btb_hit_count++;
            btb_lookup_count++;
        }
        prev_btb_hit = btb_hit;

        // 4. DCache
        //    Access = load that hits DRAM region
        //    Count on rising edge of mem2_is_load
        bool mem2_is_load = dut->mon_mem2_is_load;
        bool dcache_refill = dut->mon_dcache_refill;

        if (mem2_is_load && !prev_mem2_is_load) {
            dcache_access_count++;
            if (dut->mon_dcache_hit) {
                dcache_hit_count++;
            } else {
                dcache_miss_count++;
            }
        }
        prev_mem2_is_load = mem2_is_load;

        // Miss stall cycles
        if (dcache_refill) {
            dcache_miss_stall_cycles++;
        }
        prev_dcache_refill = dcache_refill;

        // 5. Stall breakdown
        //    Priority-based classification
        bool hdu_hold = dut->mon_hdu_hold;
        bool hdu_flush = dut->mon_hdu_flush;

        if (hdu_hold) {
            total_stall_cycles++;

            // Priority 1: Branch misprediction recovery
            if (dut->mon_bp_pred_flush) {
                branch_recovery_cycles++;
            }
            // Priority 2: DCache or memory wait
            else if (dcache_refill || dut->mon_mem2_slow_load_dep) {
                dcache_or_memory_stall_cycles++;
            }
            // Priority 3: Replay (pipeline replay, not branch mispredict)
            else if (dut->mon_bp_replay_flush) {
                replay_stall_cycles++;
            }
            // Priority 4: Multiply/divide wait
            else if (dut->mon_ex_busy || dut->mon_ex_done) {
                mul_div_stall_cycles++;
            }
            // Priority 5: Load-use hazard
            else if (dut->mon_ex_load_dep || dut->mon_mem1_load_shift_dep) {
                load_use_stall_cycles++;
            }
            // Priority 6: Other data hazard
            else if (dut->mon_mem1_load_dep) {
                data_hazard_stall_cycles++;
            }
            // Priority 7: Frontend wait
            else if (!hdu_flush) {
                frontend_wait_cycles++;
            }
            // Priority 8: Other
            else {
                other_stall_cycles++;
            }
        }

        // 6. Flush counting
        bool flush_ifid = dut->mon_ctrl_flush_ifid;
        if (flush_ifid && !prev_flush_ifid) {
            total_flush_count++;
        }
        prev_flush_ifid = flush_ifid;

        // Branch misprediction flush (from branch predictor)
        bool bp_pred_flush = dut->mon_bp_pred_flush;
        if (bp_pred_flush && !prev_bp_pred_flush) {
            branch_flush_count++;
            branch_mispredict_flush_count++;
        }
        prev_bp_pred_flush = bp_pred_flush;

        // Replay detection
        bool bp_replay_flush = dut->mon_bp_replay_flush;
        if (bp_replay_flush && !prev_bp_replay_flush) {
            replay_count++;
        }
        prev_bp_replay_flush = bp_replay_flush;
    }

    void print_summary() const {
        log_printf("\n================ CPU Performance Summary ================\n\n");

        // Core Performance
        log_printf("Core Performance\n");
        log_printf("---------------------------------------------------------\n");
        log_printf("Total cycles:                       %llu\n", (unsigned long long)total_cycles);
        log_printf("Retired instructions:               %llu\n", (unsigned long long)retired_instructions);
        if (retired_instructions > 0) {
            double cpi = (double)total_cycles / (double)retired_instructions;
            double ipc = (double)retired_instructions / (double)total_cycles;
            log_printf("CPI:                                   %.4f\n", cpi);
            log_printf("IPC:                                   %.4f\n", ipc);
        } else {
            log_printf("CPI:                                   N/A\n");
            log_printf("IPC:                                   N/A\n");
        }
        log_printf("\n");

        // Branch Prediction
        log_printf("Branch Prediction\n");
        log_printf("---------------------------------------------------------\n");
        log_printf("Conditional branches:                 %llu\n", (unsigned long long)conditional_branch_count);
        log_printf("Correct predictions:                  %llu\n", (unsigned long long)branch_prediction_correct);
        log_printf("Wrong predictions:                     %llu\n", (unsigned long long)branch_prediction_wrong);
        if (conditional_branch_count > 0) {
            double accuracy = (double)branch_prediction_correct / (double)conditional_branch_count * 100.0;
            log_printf("Prediction accuracy:                    %.2f%%\n", accuracy);
        } else {
            log_printf("Prediction accuracy:                    N/A\n");
        }
        log_printf("Branch recovery cycles:               %llu\n", (unsigned long long)branch_recovery_cycles);
        if (retired_instructions > 0) {
            double branch_cpi = (double)branch_recovery_cycles / (double)retired_instructions;
            log_printf("Branch CPI contribution:               %.4f\n", branch_cpi);
        }
        log_printf("\n");

        // BTB
        log_printf("BTB\n");
        log_printf("---------------------------------------------------------\n");
        log_printf("BTB lookups:                           %llu\n", (unsigned long long)btb_lookup_count);
        log_printf("BTB hits:                              %llu\n", (unsigned long long)btb_hit_count);
        if (btb_lookup_count > 0) {
            double hit_rate = (double)btb_hit_count / (double)btb_lookup_count * 100.0;
            log_printf("BTB hit rate:                            %.2f%%\n", hit_rate);
        } else {
            log_printf("BTB hit rate:                            N/A\n");
        }
        log_printf("Wrong target predictions:              %llu\n", (unsigned long long)btb_target_wrong_count);
        log_printf("\n");

        // DCache
        log_printf("DCache\n");
        log_printf("---------------------------------------------------------\n");
        log_printf("DCache accesses:                    %llu\n", (unsigned long long)dcache_access_count);
        log_printf("DCache hits:                        %llu\n", (unsigned long long)dcache_hit_count);
        log_printf("DCache misses:                         %llu\n", (unsigned long long)dcache_miss_count);
        if (dcache_access_count > 0) {
            double hit_rate = (double)dcache_hit_count / (double)dcache_access_count * 100.0;
            log_printf("DCache hit rate:                        %.2f%%\n", hit_rate);
        } else {
            log_printf("DCache hit rate:                        N/A\n");
        }
        log_printf("Miss stall cycles:                    %llu\n", (unsigned long long)dcache_miss_stall_cycles);
        if (dcache_miss_count > 0) {
            double avg_penalty = (double)dcache_miss_stall_cycles / (double)dcache_miss_count;
            log_printf("Average miss penalty:                    %.2f\n", avg_penalty);
        } else {
            log_printf("Average miss penalty:                    N/A\n");
        }
        log_printf("\n");

        // Stall Breakdown
        log_printf("Stall Breakdown\n");
        log_printf("---------------------------------------------------------\n");
        auto print_stall = [&](const char* name, uint64_t cycles) {
            if (total_cycles > 0) {
                double ratio = (double)cycles / (double)total_cycles * 100.0;
                log_printf("%-35s %10llu  %6.2f%%\n", name, (unsigned long long)cycles, ratio);
            } else {
                log_printf("%-35s %10llu  N/A\n", name, (unsigned long long)cycles);
            }
        };
        print_stall("Frontend wait:", frontend_wait_cycles);
        print_stall("Load-use hazard:", load_use_stall_cycles);
        print_stall("Other data hazard:", data_hazard_stall_cycles);
        print_stall("DCache or memory:", dcache_or_memory_stall_cycles);
        print_stall("Branch recovery:", branch_recovery_cycles);
        print_stall("Multiply/divide:", mul_div_stall_cycles);
        print_stall("Replay:", replay_stall_cycles);
        print_stall("Other:", other_stall_cycles);
        log_printf("\n");

        // Flush and Replay
        log_printf("Flush and Replay\n");
        log_printf("---------------------------------------------------------\n");
        log_printf("Total flushes:                         %llu\n", (unsigned long long)total_flush_count);
        log_printf("Branch flushes:                        %llu\n", (unsigned long long)branch_flush_count);
        log_printf("Replay events:                          %llu\n", (unsigned long long)replay_count);
        log_printf("Replay stall cycles:                   %llu\n", (unsigned long long)replay_stall_cycles);
        log_printf("\n");

        // CPI Breakdown
        log_printf("CPI Breakdown\n");
        log_printf("---------------------------------------------------------\n");
        if (retired_instructions > 0) {
            uint64_t base_cycles = total_cycles - frontend_wait_cycles - load_use_stall_cycles
                                   - data_hazard_stall_cycles - dcache_or_memory_stall_cycles
                                   - branch_recovery_cycles - mul_div_stall_cycles
                                   - replay_stall_cycles - other_stall_cycles;

            double base_cpi = (double)base_cycles / (double)retired_instructions;
            double frontend_cpi = (double)frontend_wait_cycles / (double)retired_instructions;
            double data_hazard_cpi = (double)(load_use_stall_cycles + data_hazard_stall_cycles) / (double)retired_instructions;
            double branch_cpi = (double)branch_recovery_cycles / (double)retired_instructions;
            double memory_cpi = (double)dcache_or_memory_stall_cycles / (double)retired_instructions;
            double muldiv_cpi = (double)mul_div_stall_cycles / (double)retired_instructions;
            double replay_cpi = (double)replay_stall_cycles / (double)retired_instructions;
            double other_cpi = (double)other_stall_cycles / (double)retired_instructions;

            log_printf("Base CPI:                              %.4f\n", base_cpi);
            log_printf("Frontend wait CPI:                     %.4f\n", frontend_cpi);
            log_printf("Data hazard CPI:                       %.4f\n", data_hazard_cpi);
            log_printf("Branch recovery CPI:                   %.4f\n", branch_cpi);
            log_printf("Memory stall CPI:                      %.4f\n", memory_cpi);
            log_printf("Mul/div CPI:                           %.4f\n", muldiv_cpi);
            log_printf("Replay CPI:                            %.4f\n", replay_cpi);
            log_printf("Other CPI:                             %.4f\n", other_cpi);
        } else {
            log_printf("N/A (no retired instructions)\n");
        }
        log_printf("\n");

        // Consistency Checks
        log_printf("Consistency Checks\n");
        log_printf("---------------------------------------------------------\n");

        bool all_pass = true;

        // Check 1: DCache hit + miss = accesses
        if (dcache_hit_count + dcache_miss_count == dcache_access_count) {
            log_printf("[PASS] Cache hit + miss = accesses\n");
        } else {
            log_printf("[FAIL] Cache hit (%llu) + miss (%llu) != accesses (%llu)\n",
                       (unsigned long long)dcache_hit_count,
                       (unsigned long long)dcache_miss_count,
                       (unsigned long long)dcache_access_count);
            all_pass = false;
        }

        // Check 2: Stall reason sum = total stall cycles
        uint64_t stall_sum = frontend_wait_cycles + load_use_stall_cycles
                             + data_hazard_stall_cycles + dcache_or_memory_stall_cycles
                             + branch_recovery_cycles + mul_div_stall_cycles
                             + replay_stall_cycles + other_stall_cycles;
        if (stall_sum == total_stall_cycles) {
            log_printf("[PASS] Stall reason sum = total stall cycles\n");
        } else {
            log_printf("[FAIL] Stall sum (%llu) != total stall (%llu)\n",
                       (unsigned long long)stall_sum,
                       (unsigned long long)total_stall_cycles);
            all_pass = false;
        }

        // Check 3: CPI component cycle sum = total cycles
        if (retired_instructions > 0) {
            uint64_t base_cycles = total_cycles - stall_sum;
            uint64_t component_sum = base_cycles + frontend_wait_cycles + load_use_stall_cycles
                                     + data_hazard_stall_cycles + dcache_or_memory_stall_cycles
                                     + branch_recovery_cycles + mul_div_stall_cycles
                                     + replay_stall_cycles + other_stall_cycles;
            if (component_sum == total_cycles) {
                log_printf("[PASS] CPI component cycle sum = total cycles\n");
            } else {
                log_printf("[FAIL] Component sum (%llu) != total cycles (%llu)\n",
                           (unsigned long long)component_sum,
                           (unsigned long long)total_cycles);
                all_pass = false;
            }
        }

        // Check 4: Branch correct + wrong = conditional branches
        if (branch_prediction_correct + branch_prediction_wrong == conditional_branch_count) {
            log_printf("[PASS] Branch correct + wrong = conditional branches\n");
        } else {
            log_printf("[FAIL] Branch correct (%llu) + wrong (%llu) != conditional (%llu)\n",
                       (unsigned long long)branch_prediction_correct,
                       (unsigned long long)branch_prediction_wrong,
                       (unsigned long long)conditional_branch_count);
            all_pass = false;
        }

        if (all_pass) {
            log_printf("\nAll consistency checks passed.\n");
        } else {
            log_printf("\nSome consistency checks FAILED!\n");
        }

        log_printf("\n=========================================================\n");
    }

    void write_summary(const std::string& path) const {
        FILE* fp = fopen(path.c_str(), "w");
        if (!fp) {
            fprintf(stderr, "[WARN] Cannot open performance output file '%s'\n", path.c_str());
            return;
        }

        fprintf(fp, "================ CPU Performance Summary ================\n\n");

        // Core Performance
        fprintf(fp, "Core Performance\n");
        fprintf(fp, "---------------------------------------------------------\n");
        fprintf(fp, "Total cycles:                       %llu\n", (unsigned long long)total_cycles);
        fprintf(fp, "Retired instructions:               %llu\n", (unsigned long long)retired_instructions);
        if (retired_instructions > 0) {
            double cpi = (double)total_cycles / (double)retired_instructions;
            double ipc = (double)retired_instructions / (double)total_cycles;
            fprintf(fp, "CPI:                                   %.4f\n", cpi);
            fprintf(fp, "IPC:                                   %.4f\n", ipc);
        } else {
            fprintf(fp, "CPI:                                   N/A\n");
            fprintf(fp, "IPC:                                   N/A\n");
        }
        fprintf(fp, "\n");

        // Branch Prediction
        fprintf(fp, "Branch Prediction\n");
        fprintf(fp, "---------------------------------------------------------\n");
        fprintf(fp, "Conditional branches:                 %llu\n", (unsigned long long)conditional_branch_count);
        fprintf(fp, "Correct predictions:                  %llu\n", (unsigned long long)branch_prediction_correct);
        fprintf(fp, "Wrong predictions:                     %llu\n", (unsigned long long)branch_prediction_wrong);
        if (conditional_branch_count > 0) {
            double accuracy = (double)branch_prediction_correct / (double)conditional_branch_count * 100.0;
            fprintf(fp, "Prediction accuracy:                    %.2f%%\n", accuracy);
        } else {
            fprintf(fp, "Prediction accuracy:                    N/A\n");
        }
        fprintf(fp, "Branch recovery cycles:               %llu\n", (unsigned long long)branch_recovery_cycles);
        if (retired_instructions > 0) {
            double branch_cpi = (double)branch_recovery_cycles / (double)retired_instructions;
            fprintf(fp, "Branch CPI contribution:               %.4f\n", branch_cpi);
        }
        fprintf(fp, "\n");

        // BTB
        fprintf(fp, "BTB\n");
        fprintf(fp, "---------------------------------------------------------\n");
        fprintf(fp, "BTB lookups:                           %llu\n", (unsigned long long)btb_lookup_count);
        fprintf(fp, "BTB hits:                              %llu\n", (unsigned long long)btb_hit_count);
        if (btb_lookup_count > 0) {
            double hit_rate = (double)btb_hit_count / (double)btb_lookup_count * 100.0;
            fprintf(fp, "BTB hit rate:                            %.2f%%\n", hit_rate);
        } else {
            fprintf(fp, "BTB hit rate:                            N/A\n");
        }
        fprintf(fp, "Wrong target predictions:              %llu\n", (unsigned long long)btb_target_wrong_count);
        fprintf(fp, "\n");

        // DCache
        fprintf(fp, "DCache\n");
        fprintf(fp, "---------------------------------------------------------\n");
        fprintf(fp, "DCache accesses:                    %llu\n", (unsigned long long)dcache_access_count);
        fprintf(fp, "DCache hits:                        %llu\n", (unsigned long long)dcache_hit_count);
        fprintf(fp, "DCache misses:                         %llu\n", (unsigned long long)dcache_miss_count);
        if (dcache_access_count > 0) {
            double hit_rate = (double)dcache_hit_count / (double)dcache_access_count * 100.0;
            fprintf(fp, "DCache hit rate:                        %.2f%%\n", hit_rate);
        } else {
            fprintf(fp, "DCache hit rate:                        N/A\n");
        }
        fprintf(fp, "Miss stall cycles:                    %llu\n", (unsigned long long)dcache_miss_stall_cycles);
        if (dcache_miss_count > 0) {
            double avg_penalty = (double)dcache_miss_stall_cycles / (double)dcache_miss_count;
            fprintf(fp, "Average miss penalty:                    %.2f\n", avg_penalty);
        } else {
            fprintf(fp, "Average miss penalty:                    N/A\n");
        }
        fprintf(fp, "\n");

        // Stall Breakdown
        fprintf(fp, "Stall Breakdown\n");
        fprintf(fp, "---------------------------------------------------------\n");
        auto print_stall = [&](const char* name, uint64_t cycles) {
            if (total_cycles > 0) {
                double ratio = (double)cycles / (double)total_cycles * 100.0;
                fprintf(fp, "%-35s %10llu  %6.2f%%\n", name, (unsigned long long)cycles, ratio);
            } else {
                fprintf(fp, "%-35s %10llu  N/A\n", name, (unsigned long long)cycles);
            }
        };
        print_stall("Frontend wait:", frontend_wait_cycles);
        print_stall("Load-use hazard:", load_use_stall_cycles);
        print_stall("Other data hazard:", data_hazard_stall_cycles);
        print_stall("DCache or memory:", dcache_or_memory_stall_cycles);
        print_stall("Branch recovery:", branch_recovery_cycles);
        print_stall("Multiply/divide:", mul_div_stall_cycles);
        print_stall("Replay:", replay_stall_cycles);
        print_stall("Other:", other_stall_cycles);
        fprintf(fp, "\n");

        // Flush and Replay
        fprintf(fp, "Flush and Replay\n");
        fprintf(fp, "---------------------------------------------------------\n");
        fprintf(fp, "Total flushes:                         %llu\n", (unsigned long long)total_flush_count);
        fprintf(fp, "Branch flushes:                        %llu\n", (unsigned long long)branch_flush_count);
        fprintf(fp, "Replay events:                          %llu\n", (unsigned long long)replay_count);
        fprintf(fp, "Replay stall cycles:                   %llu\n", (unsigned long long)replay_stall_cycles);
        fprintf(fp, "\n");

        // CPI Breakdown
        fprintf(fp, "CPI Breakdown\n");
        fprintf(fp, "---------------------------------------------------------\n");
        if (retired_instructions > 0) {
            uint64_t stall_sum = frontend_wait_cycles + load_use_stall_cycles
                                 + data_hazard_stall_cycles + dcache_or_memory_stall_cycles
                                 + branch_recovery_cycles + mul_div_stall_cycles
                                 + replay_stall_cycles + other_stall_cycles;
            uint64_t base_cycles = total_cycles - stall_sum;

            double base_cpi = (double)base_cycles / (double)retired_instructions;
            double frontend_cpi = (double)frontend_wait_cycles / (double)retired_instructions;
            double data_hazard_cpi = (double)(load_use_stall_cycles + data_hazard_stall_cycles) / (double)retired_instructions;
            double branch_cpi = (double)branch_recovery_cycles / (double)retired_instructions;
            double memory_cpi = (double)dcache_or_memory_stall_cycles / (double)retired_instructions;
            double muldiv_cpi = (double)mul_div_stall_cycles / (double)retired_instructions;
            double replay_cpi = (double)replay_stall_cycles / (double)retired_instructions;
            double other_cpi = (double)other_stall_cycles / (double)retired_instructions;

            fprintf(fp, "Base CPI:                              %.4f\n", base_cpi);
            fprintf(fp, "Frontend wait CPI:                     %.4f\n", frontend_cpi);
            fprintf(fp, "Data hazard CPI:                       %.4f\n", data_hazard_cpi);
            fprintf(fp, "Branch recovery CPI:                   %.4f\n", branch_cpi);
            fprintf(fp, "Memory stall CPI:                      %.4f\n", memory_cpi);
            fprintf(fp, "Mul/div CPI:                           %.4f\n", muldiv_cpi);
            fprintf(fp, "Replay CPI:                            %.4f\n", replay_cpi);
            fprintf(fp, "Other CPI:                             %.4f\n", other_cpi);
        } else {
            fprintf(fp, "N/A (no retired instructions)\n");
        }
        fprintf(fp, "\n");

        // Consistency Checks
        fprintf(fp, "Consistency Checks\n");
        fprintf(fp, "---------------------------------------------------------\n");

        bool all_pass = true;

        // Check 1: DCache hit + miss = accesses
        if (dcache_hit_count + dcache_miss_count == dcache_access_count) {
            fprintf(fp, "[PASS] Cache hit + miss = accesses\n");
        } else {
            fprintf(fp, "[FAIL] Cache hit (%llu) + miss (%llu) != accesses (%llu)\n",
                    (unsigned long long)dcache_hit_count,
                    (unsigned long long)dcache_miss_count,
                    (unsigned long long)dcache_access_count);
            all_pass = false;
        }

        // Check 2: Stall reason sum = total stall cycles
        uint64_t stall_sum = frontend_wait_cycles + load_use_stall_cycles
                             + data_hazard_stall_cycles + dcache_or_memory_stall_cycles
                             + branch_recovery_cycles + mul_div_stall_cycles
                             + replay_stall_cycles + other_stall_cycles;
        if (stall_sum == total_stall_cycles) {
            fprintf(fp, "[PASS] Stall reason sum = total stall cycles\n");
        } else {
            fprintf(fp, "[FAIL] Stall sum (%llu) != total stall (%llu)\n",
                    (unsigned long long)stall_sum,
                    (unsigned long long)total_stall_cycles);
            all_pass = false;
        }

        // Check 3: CPI component cycle sum = total cycles
        if (retired_instructions > 0) {
            uint64_t base_cycles = total_cycles - stall_sum;
            uint64_t component_sum = base_cycles + frontend_wait_cycles + load_use_stall_cycles
                                     + data_hazard_stall_cycles + dcache_or_memory_stall_cycles
                                     + branch_recovery_cycles + mul_div_stall_cycles
                                     + replay_stall_cycles + other_stall_cycles;
            if (component_sum == total_cycles) {
                fprintf(fp, "[PASS] CPI component cycle sum = total cycles\n");
            } else {
                fprintf(fp, "[FAIL] Component sum (%llu) != total cycles (%llu)\n",
                        (unsigned long long)component_sum,
                        (unsigned long long)total_cycles);
                all_pass = false;
            }
        }

        // Check 4: Branch correct + wrong = conditional branches
        if (branch_prediction_correct + branch_prediction_wrong == conditional_branch_count) {
            fprintf(fp, "[PASS] Branch correct + wrong = conditional branches\n");
        } else {
            fprintf(fp, "[FAIL] Branch correct (%llu) + wrong (%llu) != conditional (%llu)\n",
                    (unsigned long long)branch_prediction_correct,
                    (unsigned long long)branch_prediction_wrong,
                    (unsigned long long)conditional_branch_count);
            all_pass = false;
        }

        if (all_pass) {
            fprintf(fp, "\nAll consistency checks passed.\n");
        } else {
            fprintf(fp, "\nSome consistency checks FAILED!\n");
        }

        fprintf(fp, "\n=========================================================\n");

        fclose(fp);
    }
};

// ---------------------------------------------------------------------------
// 解析命令行参数
// ---------------------------------------------------------------------------
static void parse_args(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "+max_cycles=", 12) == 0) {
            g_max_cycles_en = true;
            g_max_cycles = strtoull(argv[i] + 12, nullptr, 10);
        } else if (strncmp(argv[i], "+log=", 5) == 0) {
            g_log_path = argv[i] + 5;
        } else if (strcmp(argv[i], "+no-file-log") == 0) {
            g_file_log = false;
        } else if (strncmp(argv[i], "+expect_led=", 12) == 0) {
            g_expect_led_en = true;
            g_expect_led = (uint32_t)strtoul(argv[i] + 12, nullptr, 0);
        } else if (strncmp(argv[i], "+expect_shift_stalls=", 21) == 0) {
            g_expect_shift_stalls = atoi(argv[i] + 21);
        } else if (strncmp(argv[i], "+expect_shift_commits=", 22) == 0) {
            g_expect_shift_commits = atoi(argv[i] + 22);
        } else if (strcmp(argv[i], "+expect_no_shift_late=1") == 0) {
            g_expect_no_shift_late = true;
        } else if (strncmp(argv[i], "+trace_interval=", 16) == 0) {
            g_trace_interval = strtoull(argv[i] + 16, nullptr, 10);
        } else if (strncmp(argv[i], "+trace_start=", 13) == 0) {
            g_trace_start = strtoull(argv[i] + 13, nullptr, 10);
        } else if (strncmp(argv[i], "+trace_end=", 11) == 0) {
            g_trace_end = strtoull(argv[i] + 11, nullptr, 10);
        } else if (strcmp(argv[i], "--enable-perf") == 0) {
            g_perf_enabled = true;
        } else if (strcmp(argv[i], "--disable-perf") == 0) {
            g_perf_enabled = false;
        } else if (strncmp(argv[i], "--perf-output=", 14) == 0) {
            g_perf_output_path = argv[i] + 14;
        }
    }
}

static bool is_load_inst(uint32_t inst) {
    return (inst & 0x7fu) == 0x03u;
}

static bool is_shift_inst(uint32_t inst) {
    uint32_t opcode = inst & 0x7fu;
    uint32_t funct3 = (inst >> 12) & 0x7u;
    uint32_t funct7 = (inst >> 25) & 0x7fu;

    if (opcode == 0x13u) {
        return (funct3 == 0x1u && funct7 == 0x00u) ||
               (funct3 == 0x5u && (funct7 == 0x00u || funct7 == 0x20u));
    }
    if (opcode == 0x33u) {
        return (funct3 == 0x1u && funct7 == 0x00u) ||
               (funct3 == 0x5u && (funct7 == 0x00u || funct7 == 0x20u));
    }
    return false;
}

// Simulation state
enum SimState {
    RESET,
    INITIALIZATION,
    RUNNING,
    FINISHED
};

// ---------------------------------------------------------------------------
// 主仿真循环
// ---------------------------------------------------------------------------
int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    parse_args(argc, argv);

    if (g_file_log) {
#ifdef _WIN32
        (void)system("if not exist sim\\logs mkdir sim\\logs");
#else
        (void)system("mkdir -p sim/logs");
#endif
        g_logfp = fopen(g_log_path, "w");
        if (!g_logfp) {
            fprintf(stderr, "[WARN] cannot open log file '%s', logging to stdout only\n",
                    g_log_path);
        }
    }

    time_t start_time = time(nullptr);
    log_printf("========================================\n");
    log_printf("Simulation started: %s", ctime(&start_time));
    if (g_max_cycles_en) {
        log_printf("Max cycles:   %llu\n", (unsigned long long)g_max_cycles);
    } else {
        log_printf("Max cycles:   disabled\n");
    }
    log_printf("Log file:     %s\n", g_file_log ? g_log_path : "(disabled)");
    log_printf("Perf stats:   %s\n", g_perf_enabled ? "enabled" : "disabled");
    if (g_perf_enabled) {
        log_printf("Perf output:  %s\n", g_perf_output_path.c_str());
    }
    log_printf("========================================\n\n");

    Vsim_wrapper *dut = new Vsim_wrapper;

    dut->w_cpu_clk    = 0;
    dut->w_clk_50Mhz  = 0;
    dut->w_clk_rst    = 1;
    dut->virtual_key  = 0;
    dut->virtual_sw   = 0;

    uint64_t cycle       = 0;
    uint64_t sim_time    = 0;
    const uint64_t CPU_HALF    = 2.38;  // ~250 MHz (closest to 210 MHz with integer half-period)
    const uint64_t MHZ50_HALF  = 10;

    uint64_t next_cpu_toggle   = 0;
    uint64_t next_50mhz_toggle = 0;
    int      cpu_clk_val       = 0;
    int      clk50_val         = 0;

    int      rst_counter       = 0;
    bool     rst_done          = false;

    uint32_t last_led_val      = 0;
    uint32_t last_seg_val      = 0;
    int      led_write_count   = 0;
    int      seg_write_count   = 0;
    int      shift_stall_count = 0;
    int      shift_commit_count = 0;
    bool     shift_late_seen   = false;

    const char *end_reason     = "waiting for LED write >=1 and SEG write >=2";

    // Performance statistics
    CpuPerfStats perf;
    SimState sim_state = RESET;
    bool perf_window_active = false;

    // =======================================================================
    // 主循环
    // =======================================================================
    while (!Verilated::gotFinish() &&
           (!g_max_cycles_en || cycle < g_max_cycles)) {

        uint64_t next_event = (next_cpu_toggle < next_50mhz_toggle)
                              ? next_cpu_toggle : next_50mhz_toggle;
        sim_time = next_event;
        dut->eval();

        if (sim_time == next_cpu_toggle) {
            cpu_clk_val ^= 1;
            dut->w_cpu_clk = cpu_clk_val;
            next_cpu_toggle += CPU_HALF;

            if (cpu_clk_val == 1) {
                if (!rst_done) {
                    rst_counter++;
                    if (rst_counter >= 20) {
                        dut->w_clk_rst = 0;
                        rst_done = true;
                        sim_state = INITIALIZATION;
                        log_printf("[cycle %10llu] Reset released\n",
                                   (unsigned long long)cycle);
                    }
                }

                dut->eval();

                if (rst_done) {
                    // Update simulation state
                    if (sim_state == INITIALIZATION) {
                        sim_state = RUNNING;
                        perf_window_active = true;
                    }

                    if (dut->mon_hdu_hold && dut->mon_hdu_flush &&
                        is_shift_inst(dut->mon_id_inst) &&
                        is_load_inst(dut->mon_id_ex_inst)) {
                        shift_stall_count++;
                    }

                    if (dut->mon_wb_rd_wen && is_shift_inst(dut->mon_wb_inst)) {
                        shift_commit_count++;
                    }

                    if (is_shift_inst(dut->mon_id_ex_inst) &&
                        (dut->mon_id_ex_rs1_fwd_sel == 3 ||
                         dut->mon_id_ex_rs2_fwd_sel == 3)) {
                        shift_late_seen = true;
                    }

                    // ---- LED/SEG 写入检测 ----
                    uint32_t wstrb = dut->mon_perip_wstrb;
                    if (wstrb != 0) {
                        uint32_t addr = dut->mon_perip_addr;
                        uint32_t wdata = dut->mon_perip_wdata;

                        if (addr == LED_ADDR) {
                            led_write_count++;
                            log_printf("[cycle %10llu] LED write #%d: 0x%08x "
                                       "pc=%08x mem=%08x x10=%08x x13=%08x x14=%08x x15=%08x\n",
                                       (unsigned long long)cycle, led_write_count, wdata,
                                       dut->mon_pc, dut->mon_mem_inst,
                                       dut->mon_x10, dut->mon_x13,
                                       dut->mon_x14, dut->mon_x15);
                            last_led_val = wdata;
                        }
                        if (addr == SEG_ADDR) {
                            seg_write_count++;
                            log_printf("[cycle %10llu] SEG write #%d: 0x%08x "
                                       "pc=%08x mem=%08x x10=%08x x13=%08x x14=%08x x15=%08x\n",
                                       (unsigned long long)cycle, seg_write_count, wdata,
                                       dut->mon_pc, dut->mon_mem_inst,
                                       dut->mon_x10, dut->mon_x13,
                                       dut->mon_x14, dut->mon_x15);
                            last_seg_val = wdata;
                        }
                        // 结束条件: LED 写入 >= 1 且 SEG 写入 >= 2
                        if (led_write_count >= REQUIRED_LED_WRITES &&
                            seg_write_count >= REQUIRED_SEG_WRITES) {
                            end_reason = "LED write >=1 and SEG write >=2 both reached";
                            sim_state = FINISHED;
                            goto sim_end;
                        }
                    }

                    // ---- Performance sampling ----
                    if (g_perf_enabled && perf_window_active && sim_state == RUNNING) {
                        perf.sample(dut);
                    }

                    // ---- 进度打印 ----
                    if (cycle % 100000000 == 0 && cycle > 0) {
                        log_printf("[cycle %10llu] running...\n",
                                   (unsigned long long)cycle);
                    }
                    if (g_trace_interval != 0 &&
                        cycle >= g_trace_start &&
                        cycle <= g_trace_end &&
                        cycle % g_trace_interval == 0) {
                        log_printf("[cycle %10llu] pc=%08x id=%08x idex=%08x "
                                   "fwd_rs1=%u fwd_rs2=%u "
                                   "mem=%08x wb=%08x wb_wen=%u hold=%u flush=%u late=%u "
                                   "wstrb=%x addr=%08x wdata=%08x "
                                   "x10=%08x x13=%08x x14=%08x x15=%08x\n",
                                   (unsigned long long)cycle,
                                   dut->mon_pc,
                                   dut->mon_id_inst,
                                   dut->mon_id_ex_inst,
                                   (unsigned)dut->mon_id_ex_rs1_fwd_sel,
                                   (unsigned)dut->mon_id_ex_rs2_fwd_sel,
                                   dut->mon_mem_inst,
                                   dut->mon_wb_inst,
                                   (unsigned)dut->mon_wb_rd_wen,
                                   (unsigned)dut->mon_hdu_hold,
                                   (unsigned)dut->mon_hdu_flush,
                                   (unsigned)dut->mon_late_load_miss,
                                   (unsigned)dut->mon_perip_wstrb,
                                   dut->mon_perip_addr,
                                   dut->mon_perip_wdata,
                                   dut->mon_x10,
                                   dut->mon_x13,
                                   dut->mon_x14,
                                   dut->mon_x15);
                    }

                    cycle++;
                }
            }
        }

        if (sim_time == next_50mhz_toggle) {
            clk50_val ^= 1;
            dut->w_clk_50Mhz = clk50_val;
            next_50mhz_toggle += MHZ50_HALF;
        }
    }

sim_end:
    if (Verilated::gotFinish()) {
        end_reason = "$finish called in RTL";
    } else if (g_max_cycles_en && cycle >= g_max_cycles) {
        end_reason = "max_cycles reached";
    }

    // =======================================================================
    // 仿真总结
    // =======================================================================
    time_t end_time = time(nullptr);
    log_printf("\n========================================\n");
    log_printf("Simulation finished: %s", ctime(&end_time));
    log_printf("End reason:  %s\n", end_reason);
    log_printf("Total cycles: %llu\n", (unsigned long long)cycle);
    log_printf("Final LED:    0x%08x\n", dut->virtual_led);
    log_printf("Final SEG:    0x%08x\n", dut->virtual_seg);
    log_printf("Final LED write value: 0x%08x\n", last_led_val);
    log_printf("Final SEG write value: 0x%08x\n", last_seg_val);
    log_printf("Shift load-use stalls: %d\n", shift_stall_count);
    log_printf("Shift WB commits:       %d\n", shift_commit_count);
    log_printf("Shift FWD_LATE seen:    %s\n", shift_late_seen ? "yes" : "no");
    log_printf("========================================\n");

    // Print performance summary
    if (g_perf_enabled) {
        perf.print_summary();
        perf.write_summary(g_perf_output_path);
        log_printf("\nPerformance summary written to: %s\n", g_perf_output_path.c_str());
    }

    dut->final();
    delete dut;
    if (g_logfp) fclose(g_logfp);

    int errors = 0;
    if (g_expect_led_en && last_led_val != g_expect_led) {
        fprintf(stderr, "[FAIL] expected final LED write 0x%08x, got 0x%08x\n",
                g_expect_led, last_led_val);
        errors++;
    }
    if (g_expect_shift_stalls >= 0 && shift_stall_count != g_expect_shift_stalls) {
        fprintf(stderr, "[FAIL] expected shift stalls %d, got %d\n",
                g_expect_shift_stalls, shift_stall_count);
        errors++;
    }
    if (g_expect_shift_commits >= 0 && shift_commit_count != g_expect_shift_commits) {
        fprintf(stderr, "[FAIL] expected shift commits %d, got %d\n",
                g_expect_shift_commits, shift_commit_count);
        errors++;
    }
    if (g_expect_no_shift_late && shift_late_seen) {
        fprintf(stderr, "[FAIL] shift instruction used FWD_LATE_LOAD\n");
        errors++;
    }

    return errors == 0 ? 0 : 1;
}
