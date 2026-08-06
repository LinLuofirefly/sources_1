#!/usr/bin/env python3
import argparse
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Convert a little-endian binary image into 32-bit readmemh words."
    )
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--words", type=int, required=True)
    args = parser.parse_args()

    data = args.input.read_bytes()
    capacity = args.words * 4
    if len(data) > capacity:
        raise SystemExit(
            f"{args.input} is {len(data)} bytes, larger than {capacity}-byte memory"
        )

    data += bytes(capacity - len(data))
    args.output.parent.mkdir(parents=True, exist_ok=True)

    with args.output.open("w", encoding="ascii", newline="\n") as stream:
        for offset in range(0, len(data), 4):
            word = int.from_bytes(data[offset : offset + 4], "little")
            stream.write(f"{word:08x}\n")


if __name__ == "__main__":
    main()
