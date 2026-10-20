# tool01: measurement tools (docs and tooling only)

| Field | Value |
| --- | --- |
| WP | tool01 |
| Model | sonnet |
| Worker id | orch1-tool01 |
| Files you may create | `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\coverage.py`, `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\status_table.py`, `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\tool01-REPORT.md` |
| Files you may read | the inputs named below, `Codex\STATUS.md`, `Codex\PLAYBOOK.md` section 5 |
| Depends on | nothing |
| Review | the orchestrator runs both scripts once (RECIPES O2 step 7) |

You do not do recovery work, do not claim queue targets, do not probe, do not use WSL or Docker. You write two read-only Python 3 scripts (standard library only, Windows host, run as `python -I <script>`). They must never write any file except what step 3 says, and never modify an input.

## Steps

1. `coverage.py` prints a Markdown table of byte coverage for the main executable and a second table of the other native inputs. Inputs:
   - `C:\Users\KoZa\Documents\AGENTS\Public\tools\kh2-reference\layout.tsv`: tab-separated, header line `addr	end	size	name`, lines starting `#` are comments. Every row is a declared code range.
   - `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\native-build\compiler-range-verification.json`: a JSON list; each item has `address`, `declared_range_size`, `size_status` (`equal_size` or `zero_padded`) and `unmodified_compiled_symbol_match`.
   - `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\native-build\native-build-verification.json`: `original_fallback_range_count`, `cpp_range_count`, `unmodified_compiled_symbol_matches`.
   - `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\native-inputs.json` (a dict keyed by module file name) and `vector-programs.json` (a list with `size` per VU program).
   - The queue database, read-only only: `sqlite3.connect('file:<path>?mode=ro', uri=True)` on `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\worker-coordination\recovery-queue.sqlite3`; table `targets(address, metadata JSON with "bytes" and "priority", state, queue)`.
   Table 1 rows: declared code ranges (count, bytes); accepted C++ (count and bytes where `unmodified_compiled_symbol_match` is true); fallback (the rest of layout.tsv); fallback bytes by queue priority 1-4 and by state (`ready`, `reserved`, `submitted`). Each row shows count, bytes and percent of declared code bytes, with one decimal. Table 2 rows: each module in native-inputs.json with its size if present, and the VU programs total; status column "not in build proof".
   Under the tables print one line: `Declared code ranges are the denominator; data, tables and undiscovered code are not included.`
   Two checks: (a) the accepted count must equal `unmodified_compiled_symbol_matches` (6,087 on 2026-10-12); (b) the number of items in compiler-range-verification.json (6,091, which includes the four `zero_padded` ranges) plus `original_fallback_range_count` (5,292) must equal the number of layout.tsv rows (11,383). If either check fails, print `CHECK FAILED: <which>` and exit 1.
2. `status_table.py` prints the "Accepted state" Markdown table exactly in the format used in `Codex\STATUS.md` (same row names, same order), filled from the latest checkpoint and `native-build-verification.json`. The latest checkpoint is `primary-<phase>-checkpoint-*.json` in `Codex\analysis\final-mix\`, where `<phase>` is `last_accepted_phase` in `worker-coordination\compiler-status.json` without the `primary-` prefix. Recovery bundles and switch batches cannot be read from these files; print them as `see O3 step 8`.
3. Run both scripts once. Write `tool01-REPORT.md` with: both outputs pasted, the exact commands, and any input field that did not exist as described (with what you found instead).
4. Reply with the contents of `tool01-REPORT.md`.

## Done when

Both scripts run without error, the checks in step 1 pass, and no file other than the three named above was created or changed.
