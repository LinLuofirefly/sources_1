#!/usr/bin/env python3
import argparse
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Convert 32-bit readmemh words into a Vivado COE file."
    )
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    words = []
    for line_number, line in enumerate(
        args.input.read_text(encoding="ascii").splitlines(), start=1
    ):
        word = line.strip()
        if not word:
            continue
        if len(word) != 8:
            raise SystemExit(f"{args.input}:{line_number}: expected 8 hex digits")
        try:
            int(word, 16)
        except ValueError as error:
            raise SystemExit(
                f"{args.input}:{line_number}: invalid hex word {word!r}"
            ) from error
        words.append(word.lower())

    if not words:
        raise SystemExit(f"{args.input}: no memory words found")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("w", encoding="ascii", newline="\n") as stream:
        stream.write("memory_initialization_radix=16;\n")
        stream.write("memory_initialization_vector=\n")
        for index, word in enumerate(words):
            terminator = ";\n" if index == len(words) - 1 else ",\n"
            stream.write(word + terminator)


if __name__ == "__main__":
    main()
