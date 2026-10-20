# KH2FM current status

This is the single current-state page for the Codex workspace. When a count here disagrees with an older document, this page and the checkpoint it names win. Older handoffs, session notes and README changelog paragraphs describe earlier states and are kept as history.

Last reconciled: 2026-10-20, from the orchfe checkpoint.

## Goal

Recover the Japanese PS2 Kingdom Hearts II Final Mix executable `SLPM_666.75` as C++ that the pinned original-era compiler turns into exactly the original instructions. Instruction-exact function ranges come before renaming. No whole-game completion percentage is claimed.

## Accepted state

| Measure | Value |
| --- | ---: |
| Complete, equal-size instruction matches | 6,800 |
| Registered C++ ranges (includes 4 padding cases) | 6,804 |
| Original-byte fallback ranges still remaining | 4,579 |
| Verified staged compiler inputs | 3,305 |
| Cumulative recovery bundles passing | 264 |
| Switch batches passing | 3 |

The padding cases are `0018f9f8`, `0014f148`, `00168370` and `00315440`.

- Latest checkpoint: `analysis/final-mix/primary-orchfe-checkpoint-2026-10-08.json`. The date in the name is hard-coded by the tooling; the checkpoint was produced by Shift 2 on 2026-10-20.
- Gate, run from `C:/Users/KoZa/Documents/AGENTS`: `python Public/tools/kh2-audit/verify_fm_primary_orchfe_checkpoint.py`
- Run ledger: `analysis/final-mix/worker-coordination/eight-hour-run-20261011.json`
- Gates for older checkpoints have fixed counts and will fail against the current build. That is expected and is not evidence of corruption.

## Byte coverage (main executable code ranges)

Produced by `python -I orchestration/tools/coverage.py` after the orchfe checkpoint. Declared code ranges are the denominator; data, tables, overlays, IOP modules, VU programs and undiscovered code are not included, so this is not a completion figure.

| Row | Ranges | Bytes | Share of declared code bytes |
| --- | ---: | ---: | ---: |
| Declared code ranges | 11,383 | 1,989,428 | 100.0% |
| Accepted C++ (exact symbol match) | 6,800 | 392,956 | 19.8% |
| Fallback (includes the 4 zero-padded ranges) | 4,583 | 1,596,472 | 80.2% |

## What is and is not proven

- A return-contract consistency audit found seven accepted void signatures in orchdz/orchea conflict with literal worker rule R4.3. Exact instruction bytes remain proven; source ABI policy compliance requires resolution. See `orchestration/return-contract-audit-2026-10-15.md` and DEVIATIONS #7. Accepted sources and checkpoints have not been altered.

- Whole-ELF equality holds, but the build starts from the original ELF and swaps in the registered C++ ranges. It is not a source-only rebuild.
- Not yet recovered or rebuilt: the 4,579 fallback function ranges, original data and tables, IOP modules, overlays, and VU microprograms.
- Types, names, boundaries and runtime behavior are provisional.
- All 2,503 scripts (733 AI, 727 area, 1,043 event) rebuild byte-exact. Three raw event records remain semantically unresolved.
- Ghidra pseudocode has 18,283 candidates. They are analysis aids and not verified recoveries. 430 functions carry warnings; 22 jump-table functions are unresolved.

## Where things live

| What | Where |
| --- | --- |
| Project, analysis, experiments, worker coordination | `C:/Users/KoZa/Documents/AGENTS/Codex` |
| Shared tools, compiler reference, original assets | `C:/Users/KoZa/Documents/AGENTS/Public` |
| Accepted source tree, `functions.tsv`, `layout.tsv` | `Public/tools/kh2-reference` |
| Audit, probe, curation and checkpoint helpers | `Public/tools/kh2-audit` |
| Linux build stage (WSL `Ubuntu-24.04`, user root) | `/root/kh2fm-build`. Never build under `/mnt/c`. |
| Pinned compiler image | `kh2-local/ps2-compiler:3.2-ee-040921-objdiff` |

Historical paths written as `analysis/...` resolve under Codex. Paths written as `tools/...` resolve under Public. The old `Documents/ChatGPT` root is retired. Do not rewrite hash-bound manifests to change paths.

## Reading order for a newcomer

1. This page.
2. `HANDOFF.md` (short workflow and rules).
3. `WORKER_BRIEF.md` (if you are a cooperating worker).
4. `PLAYBOOK.md` (how the project should be run) and `GLOSSARY.md` (terms).
   - To run the project with an orchestrator and subagent workers, start with `orchestration/ORCHESTRATION.md` instead; it has its own read order.
5. `FOLDER_GUIDE.md`, then `DIRECTORY_INDEX.md` only if you need a specific directory.
6. `analysis/final-mix/README.md` for detailed history. It is a long, append-only changelog, so read its top and the sections you need.

## Open work

1. Keep recovering fallback ranges. Priorities are in `analysis/final-mix/project-prioritized-range-backlog.json`, served through the persistent queue (`worker-coordination/QUEUE.md`).
2. Eight medium ranges are blocked with individual reports and next hypotheses: `analysis/final-mix/recovery-experiments/eight-hour-20261011/medium-next-investigations.md`.
3. The 22 unresolved jump-table functions (2 main, 20 overlay), overlay loader placement, and the three raw event variants.
4. Data, tables, vtables and relocation ownership, as required for a source-only rebuild. VU and IOP disassembly and verification.
5. Documentation upkeep. Update this page after each accepted checkpoint instead of appending to README, brief or handoff files.

## Archive

`archive/2026-10-12-housekeeping/` holds unmodified copies of the documents that were rewritten or trimmed on 2026-10-12, with `SHA256SUMS.txt`. Current docs refer to them as history only.

`archive/2026-10-19-housekeeping/` holds the superseded root `PROGRESS.md` and `SESSION_STATUS.md`, plus the superseded "October 16 handoff" paragraph of this page, stray copies of five `orch1_rec*.cpp` sources (byte-identical to their `orch-shift1/recNN/` originals) and two orchestrator preflight logs, with `SHA256SUMS.txt`.


