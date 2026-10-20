"""Bind unsuccessful parent-byte scheduling while retaining exact child recoveries."""
import hashlib
import json
from pathlib import Path

base = Path(__file__).resolve().parent
evidence = []
for path in sorted(base.glob('eight_hour_001b1bb8_*.verification.json')):
    source = path.with_suffix('').with_suffix('.cpp')
    proof = json.loads(path.read_text())
    assert hashlib.sha256(source.read_bytes()).hexdigest() == proof['source_sha256']
    row = proof['rows'][0]
    assert not row['exact_match']
    a, b = bytes.fromhex(row['target_hex']), bytes.fromhex(row['compiled_hex'])
    evidence.append(dict(source=source.name, source_sha256=proof['source_sha256'],
                         proof=path.name, proof_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                         compiled_bytes=len(b), target_bytes=len(a), differing_words=sum(a[i:i+4] != b[i:i+4] for i in range(0, max(len(a), len(b)), 4))))
path = base / '001b1bb8-byte-forwarding-evidence.json'
assert not path.exists()
path.write_text(json.dumps(dict(address='001b1bb8', accepted=False, evidence=evidence), indent=2) + '\n')
report = base / '001b1bb8-byte-forwarding-report.md'
assert not report.exists()
report.write_text('''# Byte-store and float forwarding at 001b1bb8

The original routine preserves incoming f12 and the object in a0 when tail
transferring to 001b1be0. The child moves the scalar to f14, supplies zero in
f12 and a bound in f13, and forwards object+8 to 001ad990. Separate exact
child proofs now exist; the parent remains unaccepted.

The 40-byte parent writes four low-byte values at offsets 20, 23, 21 and 22.
An explicit register-15 cursor with the correct float/object helper signature
matches the prologue but rotates the final three byte stores. Cursor lifetime
outputs recover all three store positions but swap the first store with the
stack adjustment and the cursor address with the ra save. Volatile cursor,
precise first-byte store, memory inputs, and volatile first-store descriptions
do not match the entire original range. Byte-valued formal parameters add
four narrowing instructions and produce 56 bytes; retain the word-valued
transport hypothesis rather than repeating that profile.

The adjacent evidence JSON binds all source/proof hashes and complete-range
differences. No unsuccessful parent source is registered. No compiler
impossibility is established. A new experiment must coordinate prologue timing
with byte-store order without broad memory barriers or the tested cursor
markers. Original source parameter meanings remain provisional.
''')
print(f'Preserved {len(evidence)} complete parent proofs; child sources remain separate exact proposals.')
