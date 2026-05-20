import re
import sys


REGS = {
    "x0": 0, "zero": 0,
    "x1": 1, "ra": 1,
    "x2": 2, "sp": 2,
    "x3": 3, "gp": 3,
    "x4": 4, "tp": 4,
    "x5": 5, "t0": 5,
    "x6": 6, "t1": 6,
    "x7": 7, "t2": 7,
    "x8": 8, "s0": 8, "fp": 8,
    "x9": 9, "s1": 9,
    "x10": 10, "a0": 10,
    "x11": 11, "a1": 11,
    "x12": 12, "a2": 12,
    "x13": 13, "a3": 13,
    "x14": 14, "a4": 14,
    "x15": 15, "a5": 15,
    "x16": 16, "a6": 16,
    "x17": 17, "a7": 17,
    "x18": 18, "s2": 18,
    "x19": 19, "s3": 19,
    "x20": 20, "s4": 20,
    "x21": 21, "s5": 21,
    "x22": 22, "s6": 22,
    "x23": 23, "s7": 23,
    "x24": 24, "s8": 24,
    "x25": 25, "s9": 25,
    "x26": 26, "s10": 26,
    "x27": 27, "s11": 27,
    "x28": 28, "t3": 28,
    "x29": 29, "t4": 29,
    "x30": 30, "t5": 30,
    "x31": 31, "t6": 31,
}


def parse_imm(token):
    token = token.strip()
    if token.startswith("-0x"):
        return -int(token[3:], 16)
    return int(token, 0)


def reg(name):
    key = name.strip().lower()
    if key not in REGS:
        raise ValueError(f"unknown register: {name}")
    return REGS[key]


def encode_r(funct7, rs2, rs1, funct3, rd, opcode):
    return ((funct7 & 0x7F) << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def encode_i(imm, rs1, funct3, rd, opcode):
    imm &= 0xFFF
    return (imm << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def encode_s(imm, rs2, rs1, funct3, opcode):
    imm &= 0xFFF
    return (((imm >> 5) & 0x7F) << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((imm & 0x1F) << 7) | (opcode & 0x7F)


def encode_b(imm, rs2, rs1, funct3, opcode):
    imm &= 0x1FFF
    bit12 = (imm >> 12) & 0x1
    bit11 = (imm >> 11) & 0x1
    bits10_5 = (imm >> 5) & 0x3F
    bits4_1 = (imm >> 1) & 0xF
    return (bit12 << 31) | (bits10_5 << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | (bits4_1 << 8) | (bit11 << 7) | (opcode & 0x7F)


def encode_u(imm20, rd, opcode):
    return ((imm20 & 0xFFFFF) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def encode_j(imm, rd, opcode):
    imm &= 0x1FFFFF
    bit20 = (imm >> 20) & 0x1
    bits10_1 = (imm >> 1) & 0x3FF
    bit11 = (imm >> 11) & 0x1
    bits19_12 = (imm >> 12) & 0xFF
    return (bit20 << 31) | (bits10_1 << 21) | (bit11 << 20) | (bits19_12 << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def split_operands(text):
    return [part.strip() for part in text.split(",") if part.strip()]


def expand_line(op, operands):
    op = op.lower()
    if op in {".section", ".globl"}:
        return []
    if op == "li":
        rd = operands[0]
        imm = parse_imm(operands[1])
        if -2048 <= imm <= 2047:
            return [("addi", [rd, "zero", str(imm)])]
        hi20 = (imm + 0x800) >> 12
        lo12 = imm - (hi20 << 12)
        return [("lui", [rd, str(hi20)]), ("addi", [rd, rd, str(lo12)])]
    if op == "mv":
        return [("addi", [operands[0], operands[1], "0"])]
    if op == "beqz":
        return [("beq", [operands[0], "zero", operands[1]])]
    return [(op, operands)]


def parse_mem_operand(token):
    match = re.fullmatch(r"(.+)\((.+)\)", token.replace(" ", ""))
    if not match:
        raise ValueError(f"bad memory operand: {token}")
    return parse_imm(match.group(1)), reg(match.group(2))


def load_source(path):
    lines = []
    with open(path, "r", encoding="utf-8") as f:
        for raw in f:
            line = raw.split("#", 1)[0].strip()
            if not line:
                continue
            lines.append(line)
    return lines


def first_pass(lines, base_addr):
    labels = {}
    pc = base_addr
    items = []
    for line in lines:
        rest = line
        while ":" in rest:
            label, tail = rest.split(":", 1)
            label = label.strip()
            if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", label):
                break
            labels[label] = pc
            rest = tail.strip()
            if not rest:
                break
        if not rest:
            continue
        parts = rest.split(None, 1)
        op = parts[0]
        operands = split_operands(parts[1]) if len(parts) > 1 else []
        expanded = expand_line(op, operands)
        for inst in expanded:
            items.append((pc, inst[0], inst[1]))
            pc += 4
    return labels, items


def assemble_inst(pc, op, operands, labels):
    op = op.lower()
    if op == "lui":
        return encode_u(parse_imm(operands[1]), reg(operands[0]), 0x37)
    if op == "addi":
        return encode_i(parse_imm(operands[2]), reg(operands[1]), 0x0, reg(operands[0]), 0x13)
    if op == "andi":
        return encode_i(parse_imm(operands[2]), reg(operands[1]), 0x7, reg(operands[0]), 0x13)
    if op == "srli":
        shamt = parse_imm(operands[2])
        return encode_i(shamt, reg(operands[1]), 0x5, reg(operands[0]), 0x13)
    if op == "slli":
        shamt = parse_imm(operands[2])
        return encode_i(shamt, reg(operands[1]), 0x1, reg(operands[0]), 0x13)
    if op == "add":
        return encode_r(0x00, reg(operands[2]), reg(operands[1]), 0x0, reg(operands[0]), 0x33)
    if op == "sub":
        return encode_r(0x20, reg(operands[2]), reg(operands[1]), 0x0, reg(operands[0]), 0x33)
    if op == "and":
        return encode_r(0x00, reg(operands[2]), reg(operands[1]), 0x7, reg(operands[0]), 0x33)
    if op == "or":
        return encode_r(0x00, reg(operands[2]), reg(operands[1]), 0x6, reg(operands[0]), 0x33)
    if op == "sll":
        return encode_r(0x00, reg(operands[2]), reg(operands[1]), 0x1, reg(operands[0]), 0x33)
    if op == "mulhu":
        return encode_r(0x01, reg(operands[2]), reg(operands[1]), 0x3, reg(operands[0]), 0x33)
    if op == "lw":
        imm, rs1 = parse_mem_operand(operands[1])
        return encode_i(imm, rs1, 0x2, reg(operands[0]), 0x03)
    if op == "sw":
        imm, rs1 = parse_mem_operand(operands[1])
        return encode_s(imm, reg(operands[0]), rs1, 0x2, 0x23)
    if op == "jalr":
        imm, rs1 = parse_mem_operand(operands[1])
        return encode_i(imm, rs1, 0x0, reg(operands[0]), 0x67)
    if op == "jal":
        target = labels[operands[1]]
        return encode_j(target - pc, reg(operands[0]), 0x6F)
    if op == "beq":
        target = labels[operands[2]]
        return encode_b(target - pc, reg(operands[1]), reg(operands[0]), 0x0, 0x63)
    if op == "bne":
        target = labels[operands[2]]
        return encode_b(target - pc, reg(operands[1]), reg(operands[0]), 0x1, 0x63)
    raise ValueError(f"unsupported op: {op}")


def main():
    if len(sys.argv) != 3:
        print("usage: asm_to_irom.py <input.s> <output.mem>")
        sys.exit(1)

    src_path = sys.argv[1]
    out_path = sys.argv[2]
    base_addr = 0x80000000

    lines = load_source(src_path)
    labels, items = first_pass(lines, base_addr)
    words = [assemble_inst(pc, op, operands, labels) for pc, op, operands in items]

    with open(out_path, "w", encoding="ascii") as f:
        for word in words:
            f.write(f"{word:08x}\n")

    print(f"assembled {len(words)} words to {out_path}")


if __name__ == "__main__":
    main()
