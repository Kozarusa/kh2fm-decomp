# tool03: packets list the queue's recorded best proposal (tooling only)

| Field | Value |
| --- | --- |
| WP | tool03 |
| Model | sonnet |
| Worker id | orch1-tool03 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\tool03` |
| Files you may change | `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\kh2w.py` (the functions `prior_attempts` and, if needed, `packet`) |
| Files you may create | files inside your WP directory only (`PROGRESS.md`, `tool03-REPORT.md`, test packets) |
| Depends on | nothing; runs while no other worker uses kh2w.py |
| Review | the orchestrator re-runs the test commands (RECIPES O2 step 7) |

You do not do recovery work, do not claim or touch queue targets, do not probe. You may run `kh2w.py packet` (read-only).

## Problem

`prior_attempts(address)` only finds `*<address>*.verification.json` files. The queue database also records, per target, a `best_proposal` in its `metadata` JSON (`proof`, `source`, `compiled_bytes`, `target_bytes`, `different_words`; paths relative to `Codex\`). Those proposals often live in batch files whose names do not contain the address (example: target `001702e0`, best proposal `analysis/final-mix/recovery-experiments/fm_global_probes_00_0.verification.json`, 14 differing words). Packets then say "Earlier attempts: none found" and workers start from scratch.

## Steps

1. R0 (your own `PROGRESS.md`). Copy `kh2w.py` to `<WP directory>\kh2w.py.orig` first.
2. In `prior_attempts`, also read the target's queue row read-only (the file already has a `queue_row(address)` helper; reuse it, or open the database with `sqlite3.connect('file:<path>?mode=ro', uri=True)`) and, when `metadata` has a `best_proposal` whose `proof` file exists, add it to the proofs list. For a multi-row proof file, take the row whose `address` equals the target, exactly as the existing code does; skip it if no row matches. Do not list the same proof path twice.
3. Make sure the packet's "Earlier attempts" section shows it like the other entries (path, exact or not, sizes, differing words) and that rule R4's "start from the best earlier attempt" can find its source: if the proof's `source` path exists, print it next to the proof path.
4. Test 1: `python -I Codex\orchestration\tools\kh2w.py packet 001702e0 <WP directory>`. The "Earlier attempts" section must now list `fm_global_probes_00_0.verification.json` with 14 differing words and its source path.
5. Test 2 (no regression): `python -I Codex\orchestration\tools\kh2w.py packet 00146730 <WP directory>\t2` must still list the earlier `orch-shift1\rec16\` attempts it listed before, and still show the zero (nop) words.
6. Write `tool03-REPORT.md` with the diff against `kh2w.py.orig` (summarised), the two commands and their key output lines, and confirm no other file changed. Reply with its contents.

## Done when

Both tests pass, `kh2w.py` changed only in the named functions, and nothing outside `kh2w.py` and your WP directory changed.
