import shutil
import subprocess
from pathlib import Path


PROJECT = Path(__file__).resolve().parents[1]
ROOT = PROJECT / "sim"
BIN = PROJECT / "sim" / "obj_dir" / "Vsim_wrapper"

TESTS = [
    {
        "name": "late_load_shift",
        "asm": ROOT / "tests" / "late_load_shift.s",
        "dram": ROOT / "tests" / "late_load_shift.dram.mem",
        "expect_led": "0x0A550001",
        "extra": [
            "+expect_shift_stalls=6",
            "+expect_shift_commits=6",
            "+expect_no_shift_late=1",
        ],
    },
    {
        "name": "refill_store_conflict",
        "asm": ROOT / "tests" / "refill_store_conflict.s",
        "dram": ROOT / "tests" / "refill_store_conflict.dram.mem",
        "expect_led": "0x0A550002",
        "extra": [],
    },
    {
        "name": "store_merge_replay",
        "asm": ROOT / "tests" / "store_merge_replay.s",
        "dram": ROOT / "tests" / "store_merge_replay.dram.mem",
        "expect_led": "0x0A550004",
        "extra": [],
    },
    {
        "name": "late_load_speculative",
        "asm": ROOT / "tests" / "late_load_speculative.s",
        "dram": ROOT / "tests" / "late_load_speculative.dram.mem",
        "expect_led": "0x0A550006",
        "extra": [],
    },
]


def run(cmd):
    print("+", " ".join(str(part) for part in cmd))
    subprocess.run(cmd, cwd=PROJECT, check=True)


def main():
    irom = PROJECT / "sim" / "irom.mem"
    dram = PROJECT / "sim" / "dram.mem"
    irom_bak = irom.with_suffix(".mem.directed.bak")
    dram_bak = dram.with_suffix(".mem.directed.bak")

    shutil.copyfile(irom, irom_bak)
    shutil.copyfile(dram, dram_bak)
    try:
        run(["make", "-f", "sim/Makefile", "build"])
        for test in TESTS:
            log = PROJECT / "sim" / "logs" / f"{test['name']}.log"
            run(["python3", "sim/asm_to_irom.py", str(test["asm"]), "sim/irom.mem"])
            shutil.copyfile(test["dram"], dram)
            run([
                str(BIN),
                "+max_cycles=20000",
                f"+log={log}",
                f"+expect_led={test['expect_led']}",
                *test["extra"],
            ])
        print("directed tests passed")
    finally:
        shutil.copyfile(irom_bak, irom)
        shutil.copyfile(dram_bak, dram)
        irom_bak.unlink(missing_ok=True)
        dram_bak.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
