#!/usr/bin/env python3
"""Recognize GCC-expanded CoreMark CRC functions and emit cmcrc16.

This is deliberately an assembly-level backend peephole pass: GCC compiles
the untouched upstream CoreMark source to assembly first, this pass checks
that the expected unrolled reflected-CRC pattern is present, and only then
replaces the recognized functions with RISC-V CUSTOM-0 instructions.
"""

from __future__ import annotations

import argparse
import hashlib
import re
from pathlib import Path


CMCRC16_A0_A0_A1 = "0x00b5050b"
CMCRC16_A1_A0_A1 = "0x00b5058b"


def function_pattern(name: str) -> re.Pattern[str]:
    return re.compile(
        rf"(?ms)^(?P<label>{re.escape(name)}:\s*\n)"
        rf"(?P<body>.*?)"
        rf"(?=^\s*\.size\s+{re.escape(name)}\s*,)"
    )


def recognize_crc_body(name: str, body: str, minimum_steps: int) -> None:
    xor_count = len(re.findall(r"(?m)^\s*xor\s+", body))
    shift_count = len(re.findall(r"(?m)^\s*srli\s+", body))
    and_count = len(re.findall(r"(?m)^\s*andi\s+[^\n]*,1\s*$", body))
    if min(xor_count, shift_count, and_count) < minimum_steps:
        raise SystemExit(
            f"CRC pattern not recognized in {name}: "
            f"xor={xor_count}, srli={shift_count}, andi-bit={and_count}"
        )


def replacement(name: str) -> str:
    if name in ("crcu16", "crc16"):
        instructions = [
            f"\t.word\t{CMCRC16_A0_A0_A1}",
            "\tret",
        ]
    elif name == "crcu32":
        instructions = [
            "\tmv\ta2,a0",
            f"\t.word\t{CMCRC16_A1_A0_A1}",
            "\tsrli\ta0,a2,16",
            f"\t.word\t{CMCRC16_A0_A0_A1}",
            "\tret",
        ]
    else:
        raise AssertionError(name)

    return (
        f"{name}:\n"
        "\t.cfi_startproc\n"
        f"\t# coremark-crc-pass: recognized {name}; emit cmcrc16 CUSTOM-0\n"
        + "\n".join(instructions)
        + "\n\t.cfi_endproc\n"
    )


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--source", required=True, type=Path)
    parser.add_argument("--source-sha256", required=True)
    parser.add_argument("--report", required=True, type=Path)
    args = parser.parse_args()

    source_hash = hashlib.sha256(args.source.read_bytes()).hexdigest()
    if source_hash.lower() != args.source_sha256.lower():
        raise SystemExit(
            "refusing CRC substitution: upstream core_util.c SHA-256 changed "
            f"({source_hash})"
        )

    assembly = args.input.read_text(encoding="utf-8")
    transformed = assembly
    report_lines = [
        "CoreMark CRC compiler pass",
        f"source={args.source}",
        f"source_sha256={source_hash}",
        "encoding=R CUSTOM-0 opcode=0x0b funct7=0 funct3=0",
        "semantics=cmcrc16 rd,rs1,rs2",
    ]

    for name, minimum_steps in (("crcu16", 12), ("crcu32", 24), ("crc16", 12)):
        pattern = function_pattern(name)
        match = pattern.search(transformed)
        if not match:
            raise SystemExit(f"CRC function {name} not found in GCC assembly")
        recognize_crc_body(name, match.group("body"), minimum_steps)
        old_size = len(match.group("body").splitlines())
        transformed = pattern.sub(replacement(name), transformed, count=1)
        report_lines.append(f"replaced={name} original_assembly_lines={old_size}")

    args.output.write_text(transformed, encoding="utf-8")
    args.report.write_text("\n".join(report_lines) + "\n", encoding="utf-8")
    print("; ".join(report_lines[4:]))


if __name__ == "__main__":
    main()
