`timescale 1ns / 1ps

// HC-SR04 pulse generator and echo-width capture engine.
//
// The asynchronous ECHO input is synchronized before edge detection.  A
// software START command launches exactly one measurement; DONE remains set
// until the next START or an explicit CLEAR command.  The CPU never measures
// the pulse in software, so RT-Thread scheduling latency does not affect the
// captured result.
module hcsr04_controller #(
    parameter integer P_CLK_HZ       = 200000000,
    parameter integer P_TRIGGER_US   = 10,
    parameter integer P_TIMEOUT_US   = 30000
)(
    input  logic        clk,
    input  logic        rst,
    input  logic        start,
    input  logic        clear,
    input  logic        echo_async,
    output logic        trig,
    output logic        busy,
    output logic        done,
    output logic        timeout,
    output logic        echo_level,
    output logic [31:0] echo_cycles,
    output logic [31:0] echo_us
);
    localparam integer CYCLES_PER_US_CALC =
        (P_CLK_HZ + 999999) / 1000000;
    localparam integer CYCLES_PER_US =
        (CYCLES_PER_US_CALC < 1) ? 1 : CYCLES_PER_US_CALC;
    localparam integer TRIGGER_CYCLES = CYCLES_PER_US * P_TRIGGER_US;
    localparam integer TIMEOUT_CYCLES = CYCLES_PER_US * P_TIMEOUT_US;
    localparam integer HALF_US_CYCLES = CYCLES_PER_US / 2;

    typedef enum logic [1:0] {
        HC_IDLE,
        HC_TRIGGER,
        HC_WAIT_RISE,
        HC_MEASURE
    } hc_state_t;

    hc_state_t state;
    logic [31:0] phase_cycles;
    logic [31:0] pulse_cycles;
    logic [31:0] pulse_us_work;
    logic [31:0] us_subcycle;

    (* ASYNC_REG = "TRUE" *) logic echo_meta;
    (* ASYNC_REG = "TRUE" *) logic echo_sync;
    logic echo_previous;

    wire echo_rise = echo_sync && !echo_previous;

    assign echo_level = echo_sync;

    always_ff @(posedge clk) begin
        if (rst) begin
            echo_meta     <= 1'b0;
            echo_sync     <= 1'b0;
            echo_previous <= 1'b0;
        end else begin
            echo_meta     <= echo_async;
            echo_sync     <= echo_meta;
            echo_previous <= echo_sync;
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin
            state         <= HC_IDLE;
            trig          <= 1'b0;
            busy          <= 1'b0;
            done          <= 1'b0;
            timeout       <= 1'b0;
            phase_cycles  <= 32'd0;
            pulse_cycles  <= 32'd0;
            pulse_us_work <= 32'd0;
            us_subcycle   <= 32'd0;
            echo_cycles   <= 32'd0;
            echo_us       <= 32'd0;
        end else begin
            if (clear && !busy) begin
                done    <= 1'b0;
                timeout <= 1'b0;
            end

            case (state)
                HC_IDLE: begin
                    trig <= 1'b0;
                    busy <= 1'b0;
                    if (start) begin
                        state         <= HC_TRIGGER;
                        trig          <= 1'b1;
                        busy          <= 1'b1;
                        done          <= 1'b0;
                        timeout       <= 1'b0;
                        phase_cycles  <= TRIGGER_CYCLES - 1;
                        pulse_cycles  <= 32'd0;
                        pulse_us_work <= 32'd0;
                        us_subcycle   <= 32'd0;
                    end
                end

                HC_TRIGGER: begin
                    if (phase_cycles == 0) begin
                        state        <= HC_WAIT_RISE;
                        trig         <= 1'b0;
                        phase_cycles <= 32'd0;
                    end else begin
                        phase_cycles <= phase_cycles - 1'b1;
                    end
                end

                HC_WAIT_RISE: begin
                    if (echo_rise) begin
                        state         <= HC_MEASURE;
                        phase_cycles  <= 32'd0;
                        pulse_cycles  <= 32'd1;
                        pulse_us_work <= (CYCLES_PER_US == 1) ? 32'd1 : 32'd0;
                        us_subcycle   <= (CYCLES_PER_US == 1) ? 32'd0 : 32'd1;
                    end else if (phase_cycles >= TIMEOUT_CYCLES - 1) begin
                        state   <= HC_IDLE;
                        busy    <= 1'b0;
                        done    <= 1'b1;
                        timeout <= 1'b1;
                    end else begin
                        phase_cycles <= phase_cycles + 1'b1;
                    end
                end

                default: begin // HC_MEASURE
                    if (!echo_sync) begin
                        state       <= HC_IDLE;
                        busy        <= 1'b0;
                        done        <= 1'b1;
                        timeout     <= 1'b0;
                        echo_cycles <= pulse_cycles;
                        echo_us     <= pulse_us_work +
                            ((us_subcycle >= HALF_US_CYCLES) ? 32'd1 : 32'd0);
                    end else if (phase_cycles >= TIMEOUT_CYCLES - 1) begin
                        state       <= HC_IDLE;
                        busy        <= 1'b0;
                        done        <= 1'b1;
                        timeout     <= 1'b1;
                        echo_cycles <= pulse_cycles;
                        echo_us     <= pulse_us_work;
                    end else begin
                        phase_cycles <= phase_cycles + 1'b1;
                        pulse_cycles <= pulse_cycles + 1'b1;
                        if (us_subcycle >= CYCLES_PER_US - 1) begin
                            us_subcycle   <= 32'd0;
                            pulse_us_work <= pulse_us_work + 1'b1;
                        end else begin
                            us_subcycle <= us_subcycle + 1'b1;
                        end
                    end
                end
            endcase
        end
    end
endmodule
