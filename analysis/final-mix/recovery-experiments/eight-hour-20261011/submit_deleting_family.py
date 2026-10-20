from pathlib import Path
import hashlib
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
leases = json.loads((base/'deleting-family-leases.json').read_text())
census = {row['address']:row for row in json.loads((base/'deleting-wrapper-census.json').read_text())}
controls = {row['address'] for row in json.loads((base/'deleting-control-leases.json').read_text())}
selected = []
for lease in leases:
    address = lease['address']
    suffix = 'deleting_control_0' if address in controls else 'deleting_family'
    source = base/f'eight_hour_{address}_{suffix}.cpp'
    proof_path = source.with_suffix('.verification.json')
    proof = json.loads(proof_path.read_text())
    assert hashlib.sha256(source.read_bytes()).hexdigest() == proof['source_sha256']
    assert len(proof['rows'])==1
    row = proof['rows'][0]
    assert row['address']==address and row['exact_match'] and row['target_size']==52 and row['compiled_size']==52
    assert hashlib.sha256(bytes.fromhex(row['target_hex'])).hexdigest()==census[address]['target_sha256']
    result = subprocess.run([sys.executable,str(helper),'submit','--address',address,'--token',lease['token'],'--source',str(source),'--proof',str(proof_path)],capture_output=True,text=True)
    with (base/f'deleting-family-submit-{address}.log').open('x') as stream:
        stream.write(result.stdout+result.stderr)
    assert result.returncode==0,result.stdout+result.stderr
    selected.append({'address':address,'source':source.name,'proof':proof_path.name,'source_sha256':proof['source_sha256'],'target_sha256':census[address]['target_sha256']})
with (base/'deleting-family-selected.json').open('x') as stream:
    json.dump(selected,stream,indent=2)
with (base/'deleting-family-report.md').open('x') as stream:
    stream.write('# Typed object-forwarding family\n\n57 complete original 52-byte ranges share the same stack/register behavior. Each stores a distinct table address into the object, calls a first helper with that object in a0, then forwards the same object to a final helper after restoring saved registers. The saved Ghidra export omits the object argument from many first-helper calls.\n\nTwo representative sources established the typed C++ template before the remaining 55 candidates were generated. All 57 isolated full-range probes match every original instruction, including frame setup, call delay slots, table addresses, helper targets, and the final tail jump. This report precedes independent curated recompilation and full cumulative acceptance; isolated proofs alone are not accepted recovery credit.\n\nClass names, exact C++ class layouts, and higher-level helper identities remain provisional. The sources deliberately retain address-based symbols. No compiler flags changed. No whole-function assembly was introduced.\n')
print(f'Submitted {len(selected)} independently hash-checked isolated exact proposals ({len(selected)*52} instruction bytes).')
