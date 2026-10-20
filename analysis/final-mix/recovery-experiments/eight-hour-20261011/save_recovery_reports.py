"""Bind isolated unsuccessful experiments before releasing specialized claims."""
import hashlib
import json
from pathlib import Path

base = Path(__file__).resolve().parent
ranked = json.loads((base / 'current-ranked-proposals.json').read_text())['ranked']
subjects = {
    '0017d160': ('float-branch-layout', 'Threshold and result register allocation now matches the first thirteen words. A five-word residual swaps the scalar-helper tail return with the shared epilogue and changes the second branch polarity. Explore a source branch structure or precomputed condition representation that preserves unordered comparisons and places the shared epilogue after the tail call; do not repeat tested likelihood hints.'),
    '00105af8': ('indexed-table-scheduling', 'The complete original selects an indexed word after storing the mode, then reloads the selected global on the ordinary path. Raw low-word transport avoids unnecessary 64-bit narrowing, but index register allocation and branch layout remain different. Investigate original global-region aliasing and table types before adding more register barriers.'),
    '00102bd8': ('callback-address-scheduling', 'A live second-callback high-word carrier moves the missing LUI before the first store, but then the stack adjustment and final global LUI each swap with a store. Typed table and narrow memory dependencies did not recover the complete range. Seek a joint scheduling representation preserving high-word lifetime and prologue delay without repeating broad memory barriers.'),
    '002713a0': ('branch-delay-address-lifetime', 'Condition width, fixed pointer register and forward/reversed/ternary/label forms preserve the one-word bnel-versus-bne residual or worsen layout. Investigate a new branch-delay dependency representation that permits speculative high-word materialization; tested pointer-register and condition-width alternatives are exhausted.'),
    '00305ce0': ('primary-store-epilogues', 'Exact-size C++ and precisely described store variants all leave original ra restoration after the store rather than before it. An empty read of the return-address register did not fix scheduling. Review the original compiler ABI or return/store dependency before repeating store qualifiers.'),
    '00308cd0': ('primary-store-epilogues', 'The C++ global store matches every original word except the load-ra/store order. Volatile and precise-assembly descriptions did not fix this; address-form assembly introduced extra instructions. Review the scheduler treatment of epilogue loads with a statically known global store.'),
    '00319788': ('sdk-frame-abi', 'Original two-call routine uses daddiu with a 48-byte frame and saves ra at offset 40; the existing exact-size proposal uses addiu with a 16-byte frame and saves ra at offset zero. Calls and return flow already agree. Investigate SDK calling-frame ABI and structured assembly classification; do not assume changing C++ return types alone repairs the frame.'),
}
for address, (specialty, hypothesis) in subjects.items():
    evidence = []
    for proof_path in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
        source = proof_path.with_suffix('').with_suffix('.cpp')
        proof = json.loads(proof_path.read_text())
        assert hashlib.sha256(source.read_bytes()).hexdigest() == proof['source_sha256']
        row = proof['rows'][0]
        a, b = bytes.fromhex(row['target_hex']), bytes.fromhex(row['compiled_hex'])
        differences = sum(a[i:i+4] != b[i:i+4] for i in range(0, max(len(a), len(b)), 4))
        evidence.append(dict(source=source.name, source_sha256=proof['source_sha256'],
                             proof=proof_path.name, proof_sha256=hashlib.sha256(proof_path.read_bytes()).hexdigest(),
                             compiled_bytes=len(b), target_bytes=len(a), differing_words=differences, exact=row['exact_match']))
    assert not any(r['exact'] for r in evidence)
    best = min(evidence, key=lambda r: (r['compiled_bytes'] != r['target_bytes'], r['differing_words'])) if evidence else None
    prior = next((r for r in ranked if r['address'] == address), None)
    output = base / f'{address}-recovery-results.json'
    assert not output.exists()
    output.write_text(json.dumps(dict(address=address, specialty=specialty,
                                      hypothesis=hypothesis, prior_best=prior,
                                      completed_probes=len(evidence), best_new=best,
                                      evidence=evidence, accepted=False,
                                      limitations=['Instruction mismatch is not compiler impossibility.', 'No unsuccessful proposal is registered.']), indent=2) + '\n')
    report = base / f'{address}-recovery-report.md'
    assert not report.exists()
    report.write_text(f'# Isolated recovery investigation: {address}\n\n{hypothesis}\n\n'
                      f'This session preserved {len(evidence)} completed compiler proofs. '
                      f'The adjacent `{output.name}` binds source and proof hashes, size comparisons, and instruction differences. '
                      'Compiler-failure diagnostics remain in the corresponding probe logs. '
                      'No new accepted recovery or compiler-impossibility claim is made.\n')
    print(f'{address}: preserved {len(evidence)} new proofs; report saved.')
