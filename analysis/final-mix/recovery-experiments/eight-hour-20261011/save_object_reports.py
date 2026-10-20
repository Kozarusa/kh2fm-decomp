"""Preserve object-input and final-store tests before exclusive acceptance."""
import hashlib
import json
from pathlib import Path

base = Path(__file__).resolve().parent
for address in ['0028b7f8', '00315678', '00315700', '00316890', '001c2c98', '001c2ce8']:
    proofs = []
    for path in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
        source = path.with_suffix('').with_suffix('.cpp')
        proof = json.loads(path.read_text())
        assert hashlib.sha256(source.read_bytes()).hexdigest() == proof['source_sha256']
        row = proof['rows'][0]
        assert not row['exact_match']
        a, b = bytes.fromhex(row['target_hex']), bytes.fromhex(row['compiled_hex'])
        proofs.append(dict(source=source.name, source_sha256=proof['source_sha256'],
                           proof=path.name, proof_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                           compiled_bytes=len(b), target_bytes=len(a),
                           differing_words=sum(a[i:i+4] != b[i:i+4] for i in range(0, max(len(a), len(b)), 4))))
    assert proofs
    path = base / f'{address}-object-evidence.json'
    assert not path.exists()
    path.write_text(json.dumps(dict(address=address, accepted=False, proofs=proofs), indent=2) + '\n')
    if address in ['001c2c98', '001c2ce8']:
        finding = ('The closest original proposal swaps only the final vtable and mode stores. '
                   'Making either store individually volatile keeps that residual; making both volatile '
                   'or inserting a full memory barrier alters the preceding flag-load and register schedule. '
                   'The next experiment should describe canonical object-field aliasing or carry independent '
                   'flag dependencies into the final stores while preserving the already correct early return-address restore. '
                   'Do not repeat the four recorded volatile/barrier cases.')
    else:
        finding = ('The original first helper reads its object argument: the export at 003167f8 writes the incoming object vtable, '
                   'and 0028b8a0 writes fields of its incoming object. Making that input explicit as an address-width word '
                   'or pointer is supported by the exports, but all four new compiler profiles retain the two-word '
                   'return-address-save/vtable-store scheduling swap. These types remain provisional. '
                   'The next experiment must address joint table-address and prologue scheduling rather than repeat these argument profiles.')
    report = base / f'{address}-object-report.md'
    assert not report.exists()
    report.write_text(f'# Object recovery investigation: {address}\n\n{finding}\n\n'
                      f'`{path.name}` binds {len(proofs)} complete new source/proof pairs. '
                      'No unsuccessful proposal is registered and no compiler-impossibility claim is made.\n')
    print(f'{address}: preserved {len(proofs)} complete proofs.')
