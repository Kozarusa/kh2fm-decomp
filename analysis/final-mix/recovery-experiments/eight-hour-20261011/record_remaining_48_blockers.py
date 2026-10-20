from pathlib import Path
import hashlib
import json
import subprocess
import sys
base = Path(__file__).resolve().parent
helper = base.parents[4] / 'Public/tools/kh2-audit/recovery_queue.py'
leases = {row['address']: row for row in json.loads((base / 'remaining-48-leases.json').read_text())}
specifications = {
    '00311050': ('sdk-prologue-operation-scheduling', 'Retain the validated 32-byte payload frame and signed-byte normalization. Investigate operation-register initialization scheduling relative to the return-address save; payload shape and argument width alone did not solve the two-word swap.', 'The closest ordinary C++ proposal has all 48 bytes and differs only by swapping the operation literal load into a0 and the sd ra,16(sp). Array versus struct aggregates, signed/unsigned operation prototypes, empty register markers, and precise literal transport did not produce a complete match. Keep the original function on fallback; no compiler impossibility is established.'),
    '00311460': ('sdk-range-guard-branch-layout', 'Model the invalid-result path as a distinct branch while retaining the predicate in v0 and the single common epilogue. Avoid repeating basic signed-width changes, likelihood hints, and empty result markers already tested.', 'The original checks unsigned value-13 < 35, branches to the valid helper call, and places the return-address save in that conditional branch delay slot. The invalid path branches to the common epilogue with -1 in its delay slot. Simple C++ collapses this into a shorter conditional tail call or a different shared epilogue. Preventing the tail call and marking the invalid result preserved behavior but did not match the original layout. Signed 32-bit versus 64-bit result variants did not resolve it. Keep the original on fallback; no compiler impossibility is established.'),
}
for address, (specialty, hypothesis, explanation) in specifications.items():
    rows = []
    for path in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
        proof = json.loads(path.read_text())
        if len(proof['rows']) != 1:
            continue
        row = proof['rows'][0]
        target = bytes.fromhex(row['target_hex'])
        compiled = bytes.fromhex(row['compiled_hex'])
        rows.append({'proof': path.name, 'source_sha256': proof['source_sha256'], 'proof_sha256': hashlib.sha256(path.read_bytes()).hexdigest(), 'compiled_bytes': len(compiled), 'target_bytes': len(target), 'different_words': sum(compiled[i:i+4] != target[i:i+4] for i in range(0,max(len(compiled),len(target)),4)), 'exact': row['exact_match']})
    assert rows and not any(row['exact'] for row in rows)
    report = base / f'{address}-scheduling-report.md'
    with report.open('x') as stream:
        stream.write(f'# Unresolved function {address}\n\n{explanation}\n\n## Evidence\n\n{len(rows)} complete compiler probes are preserved in the adjacent evidence manifest. Every proposal retains its source hash and complete original/compiled range. None has been registered.\n\n## Next hypothesis\n\n{hypothesis}\n')
    with (base / f'{address}-scheduling-evidence.json').open('x') as stream:
        json.dump(rows, stream, indent=2)
    result = subprocess.run([sys.executable, str(helper), 'block', '--address', address, '--token', leases[address]['token'], '--specialty', specialty, '--report', str(report), '--hypothesis', hypothesis], text=True, capture_output=True)
    assert result.returncode == 0, result.stdout + result.stderr
    print('Recorded blocker ' + address)
