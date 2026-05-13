import re

with open('/mnt/c/Users/hp/Downloads/src2/irom.coe', 'r') as f:
    content = f.read()

lines = content.split('\n')
mem = []
for line in lines:
    line = line.strip()
    if re.match(r'^[0-9a-fA-F]', line):
        val = line.replace(',', '').replace(';', '')
        mem.append(val)

with open('/mnt/c/Users/hp/Downloads/src2/irom.mem', 'w') as f:
    f.write('\n'.join(mem) + '\n')

print(f'Converted {len(mem)} lines')
