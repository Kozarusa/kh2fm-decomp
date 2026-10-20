"""Verify an unregistered C++ recovery source in an isolated Linux directory."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

STAGE = Path('/root/kh2fm-build')
WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
sys.path.insert(0, str(STAGE / 'tools'))
from build_elf import parse_elf_function_symbols
from common import addr_to_file_offset, load_boundaries

arguments = [arg for arg in sys.argv[1:] if arg != '--summary']
source = Path(arguments[0]).resolve()
assert source.is_relative_to(WORKSPACE)
range_override = None
if len(arguments) > 1:
    range_override = Path(arguments[1]).resolve()
    assert range_override.is_relative_to(WORKSPACE)
name = source.stem
assert re.fullmatch(r'[a-zA-Z0-9_-]+', name)
scratch = STAGE / 'recovery-experiments' / name
scratch.mkdir(parents=True, exist_ok=True)
text = source.read_text().replace('#include "../common/types.h"',
                                '#include "../../src/common/types.h"')
text = text.replace('#include "../kn/fvector.hpp"', '#include "../../src/kn/fvector.hpp"')
(scratch / 'probe.cpp').write_text(text)
image = 'kh2-local/ps2-compiler:3.2-ee-040921-objdiff'
def run(command):
    subprocess.run(['docker', 'run', '--rm', '--platform', 'linux/amd64',
                    '-v', f'{STAGE}:/work', '-w', '/work', image,
                    'bash', '-lc', command], check=True)
relative = scratch.relative_to(STAGE).as_posix()
run(f'/opt/ps2/gcc/bin/ee-g++ -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections -c {relative}/probe.cpp -o {relative}/probe.o')
symbols = parse_elf_function_symbols(scratch / 'probe.o', section_name=None)
definitions = {}
for symbol in symbols:
    match = re.search(r'func_([0-9a-f]{8})', symbol.name)
    if match:
        definitions[symbol.name] = match.group(1)
assert definitions
script = [f'D_{address} = 0x{address};' for address in sorted(set(re.findall(r'D_([0-9a-f]{8})', text)))]
script += [f'func_{address} = 0x{address};' for address in sorted(set(re.findall(r'func_([0-9a-f]{8})', text)))]
script.append('SECTIONS {')
for symbol, address in definitions.items():
    script.append(f'.s_{address} 0x{address} : {{ *(.text.{symbol}) }}')
script.append('}')
(scratch / 'probe.ld').write_text('\n'.join(script) + '\n')
run(f'/opt/ps2/gcc/bin/ee-ld --no-check-sections -T {relative}/probe.ld {relative}/probe.o -o {relative}/probe.elf -L/opt/ps2/gcc/lib/gcc-lib/ee/3.2-ee-040921 -lgcc')
original = (STAGE / 'SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest() == 'd869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
elf = (scratch / 'probe.elf').read_bytes()
candidates = {row['address']: row for row in (json.loads(line) for line in
    (WORKSPACE / 'analysis/final-mix/native-pseudocode/main.jsonl').read_text().splitlines())}
boundaries = {f'{row.addr:08x}': row.size for row in load_boundaries()}
overrides = {}
if range_override is not None:
    for row in json.loads(range_override.read_text()):
        address, size = row['address'], row['body_bytes']
        assert re.fullmatch('[0-9a-f]{8}', address) and size > 0 and size % 4 == 0
        offset = addr_to_file_offset(int(address, 16))
        target = original[offset:offset + size]
        assert len(target) == size
        assert hashlib.sha256(target).hexdigest() == row['original_range_sha256']
        assert address not in overrides
        overrides[address] = row
rows = []
for symbol in parse_elf_function_symbols(scratch / 'probe.elf', section_name=None):
    if symbol.name not in definitions:
        continue
    address = definitions[symbol.name]
    candidate_size = candidates.get(address, {}).get('body_bytes')
    size = overrides[address]['body_bytes'] if address in overrides else boundaries.get(address, candidate_size)
    assert size is not None
    offset = addr_to_file_offset(int(address, 16))
    target = original[offset:offset + size]
    code = elf[symbol.foff:symbol.foff + symbol.size]
    row = dict(address=address, symbol=symbol.name, compiled_size=symbol.size,
               target_size=size, ghidra_body_size=candidate_size,
               boundary_agreement=size == candidate_size, exact_match=code == target,
               compiled_hex=code.hex(), target_hex=target.hex())
    rows.append(row)
output = source.with_suffix('.verification.json')
output.write_text(json.dumps({'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                              'source': source.relative_to(WORKSPACE).as_posix(),
                              'range_override': None if range_override is None else {
                                  'file': range_override.relative_to(WORKSPACE).as_posix(),
                                  'sha256': hashlib.sha256(range_override.read_bytes()).hexdigest()},
                              'rows': rows}, indent=2) + '\n')
print(f'Exact probe matches: {sum(row["exact_match"] for row in rows)}/{len(rows)}')
if '--summary' in sys.argv:
    print(f'Detailed proof: {output.relative_to(WORKSPACE)}')
    sys.exit(0)
for row in rows:
    print(row['address'], 'MATCH' if row['exact_match'] else
          f'{row["compiled_size"]}/{row["target_size"]} bytes',
          '' if row['exact_match'] else row['compiled_hex'] + ' target=' + row['target_hex'])
