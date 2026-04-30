import os
try:
    from capstone import *
except ImportError:
    print("报错：请先运行 pip install capstone 安装反汇编引擎！")
    exit()

# ==========================================
# 1. 配置区 (修改为你的实际文件名)
# ==========================================
coe_file = 'irom.coe'   # 👈 确保这里填你真实的 coe 文件名！
out_file = 'irom.txt'      # 导出的反汇编结果文件名
START_ADDRESS = 0x80000000   # 👈 你的 CPU 起始 PC 地址

hex_strings = []

# ==========================================
# 2. 读取并清洗 COE 文件
# ==========================================
print(f"正在读取 {coe_file}...")
try:
    with open(coe_file, 'r') as f:
        for line in f:
            line = line.strip()
            # 过滤掉 coe 文件的头部配置 (memory_initialization...) 和空白行
            if line.startswith('memory') or line.startswith('radix') or line.startswith(';') or not line:
                continue
            # 移除数据末尾的逗号和分号
            line = line.replace(',', '').replace(';', '').strip()
            if line:
                hex_strings.append(line)
except FileNotFoundError:
    print(f"找不到文件 {coe_file}，请确保它和 Python 脚本在同一个目录下！")
    exit()

# ==========================================
# 3. 转换为二进制字节流 (处理 RISC-V 小端序)
# ==========================================
machine_code = b''
for hex_str in hex_strings:
    # 如果不足 8 位，前面补 0
    hex_str = hex_str.zfill(8)
    # 核心：将 16 进制字符串转为 bytes，并反转顺序 (因为 RISC-V 是小端序)
    instruction_bytes = bytes.fromhex(hex_str)[::-1]
    machine_code += instruction_bytes

# ==========================================
# 4. 调用 Capstone 引擎进行反汇编，并写入文件
# ==========================================
print(f"正在反汇编并保存到 {out_file}...")
md = Cs(CS_ARCH_RISCV, CS_MODE_RISCV32)

with open(out_file, 'w') as f:
    # 写入漂亮的表头
    header = f"{'PC 地址':<12} | {'机器码':<10} | {'汇编指令'}\n"
    header += "-" * 55 + "\n"
    f.write(header)

    # 遍历翻译每一条指令
    for i in md.disasm(machine_code, START_ADDRESS):
        # 将反转的 bytes 再转回人类习惯阅读的十六进制字符串
        mac_code_hex = "".join(f"{b:02x}" for b in i.bytes[::-1])
        # 格式化输出：地址 | 机器码 | 助记符 操作数
        line = f"0x{i.address:08x} | {mac_code_hex:<10} | {i.mnemonic} {i.op_str}\n"
        f.write(line)

print("✅ 大功告成！快去打开 dram.txt 查看结果吧！")