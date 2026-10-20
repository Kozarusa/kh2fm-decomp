# Codex folder investigation and recovery report

This folder is a reverse-engineering workspace for **Kingdom Hearts II Final Mix, Japanese PlayStation 2 release**. The work aims to recover functions that compile into the same instructions as the original game executable. The directory also preserves an earlier US-release investigation, generated pseudocode, script reconstruction, original binaries, rejected experiments, and verification history.

The full explanation of the folder and its child-directory groups is in [FOLDER_GUIDE.md](FOLDER_GUIDE.md). [DIRECTORY_INDEX.md](DIRECTORY_INDEX.md) describes every individual directory and gives its direct and recursive file counts. Two complete directory inventories are preserved inside the run's experiment folder. The later inventory contains 409 reachable directories, 171,056 files, and 2.31 GB, with no traversal errors. It does not follow directory links. Counts describe a snapshot; this report and subsequent evidence add files. The directory enumeration is complete for that scope; the explanations draw on project instructions, manifests, registries, logs, analysis exports, and representative contents.

## Accepted result

| Measure | Start of this run | Final accepted checkpoint |
| --- | ---: | ---: |
| Complete, equal-size instruction matches | 5,806 | 6,087 |
| Registered C++ function ranges | 5,810 | 6,091 |
| Original-byte fallback ranges | 5,573 | 5,292 |
| Verified source/build inputs | 2,311 | 2,592 |

The run added **281 accepted functions covering 17,708 original instruction bytes**, across 31 accepted batches. The four size-adjusted C++ ranges are pre-existing and remain separate from the 6,087 complete equal-size matches. Experiments that merely looked similar, compiled successfully, or matched after normalization were not counted as new exact recoveries.

The last batch, `queuexiprime`, added 16 independently reproduced functions covering 1,248 bytes. Its full build and cumulative matrix passed 130 recovery bundles and three switch receipts. The publication process completed the warning audit and checkpoint gate, resolved the proposals, resumed the queue, and returned compiler ownership to idle.

The original and rebuilt main executable have the same SHA-256:

`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`

A separate final audit verified the size and SHA-256 of all **7,805 files** named by the accepted checkpoint, checked the exact-function count against compiler records, and confirmed zero active leases or unreviewed submitted proposals. Historical tool paths in that checkpoint were resolved to the documented current `Public/tools/` location. All 108 saved successful compiler probes for the selected medium-range family, including failed instruction comparisons, were also checked against original executable bytes and their source hashes.

The 31 saved batch receipts were separately reconciled with the current compiler records and registered source hashes. They contain 281 distinct new exact addresses, totaling 17,708 native instruction bytes, with no duplicate address counted across batches. The detailed receipts are indexed by `analysis/final-mix/recovery-experiments/eight-hour-20261011/final-session-additions-audit.json`.

## What was learned and changed

The recovery families included flag predicates, buffer selection, virtual callback transport, global initialization and copying, floating-point wrappers, SDK gateway wrappers, and conditional 16-byte vector copies. Each accepted range retains isolated proof, independent curated proof, registration evidence, and a cumulative acceptance checkpoint.

Decompiler text frequently omitted floating-point arguments, return values, or reloads, and some suggested integer widths led to different machine transport. Original instructions were used to constrain those choices. Source names, structures, and helper declarations remain provisional descriptions of observed behavior.

Conditional vector loads needed to remain conditional. A volatile quadword read stopped the pinned compiler from moving a load into an ordinary branch delay slot and reproduced the original branch-likely or duplicated cleanup paths. Separately, ordering Word parameters before floating-point parameters restored load scheduling while preserving the PS2 ABI's independent argument register banks. The last 16-function batch contains C++ operations and empty register or memory constraints, with no emitted assembly instruction strings.

Other accepted families require narrow assembly primitives for frame-pointer transport, precise floating conversion, variable Word shifts, or outgoing ABI arguments. These are documented individually. They should not be described as entirely plain C++.

The full build exposed an existing linker placement problem: one function's input alignment placed its entry four bytes after the required native address and changed a caller's jump relocation. The build helper now validates and reduces that executable function section's alignment metadata where the native address requires four-byte alignment. It also rejects a C++ symbol linked at the wrong native address. Compiler flags, instruction bytes, and the accepted caller source were preserved. Failed executables, rejected repair attempts, helper backups, and successful controls remain available.

Detailed explanations are saved in:

- `analysis/final-mix/recovery-experiments/eight-hour-20261011/sdk-wrapper-rationale.md`
- `analysis/final-mix/recovery-experiments/eight-hour-20261011/queue-nu-prime-constraint-rationale.md`
- `analysis/final-mix/recovery-experiments/eight-hour-20261011/medium-vector-and-scalar-rationale.md`
- `analysis/final-mix/recovery-experiments/eight-hour-20261011/recovery-lessons.md`

## Limits and continuation

The matching executable still retains original bytes for **5,292 fallback ranges** and untouched data. It is not a complete source-only reconstruction of the game. The accepted main-executable workflow does not prove runtime behavior or completed reconstruction of IOP system modules, overlays, or vector-unit programs. No whole-game completion percentage is implied.

Generated pseudocode remains an analysis aid. The saved export summary contains 18,283 function candidates across the main executable, system modules, and overlays; those candidates are not 18,283 verified recoveries. Warning triage still contains 430 warning-bearing functions and 22 unresolved priority-one findings. The category totals overlap because one function can carry several warnings.

Eight medium ranges were left unaccepted with original disassembly, failed probe files, source hashes, and individual blocker reports. Their next work concerns traversal return paths, RGB multiplication scheduling, nullable lookup cleanup, range-selection branch layout, duplicated initializer guards, boolean materialization, and six-Word snapshot transport. They are assigned to a specialist queue rather than counted as completed. The reports do not claim that these routines are impossible to recover.

The live queue and its separately saved final backup passed SQLite integrity checks. All eight immutable medium blocker reports still match the hashes stored by the queue. Focused next controls are described in `analysis/final-mix/recovery-experiments/eight-hour-20261011/medium-next-investigations.md`; those notes leave the original blocker reports unchanged.

Older `HANDOFF.md`, `WORKER_BRIEF.md`, session notes, and dated counts were preserved. For current accepted counts, use `analysis/final-mix/primary-queuexiprime-checkpoint-2026-10-08.json` and the run ledger `analysis/final-mix/worker-coordination/eight-hour-run-20261011.json`. The checkpoint's date label follows the inherited naming convention; it is not the duration of this run.

## Active work duration

The required duration is 28,800 seconds of active work. Interruptions and calendar idle time are excluded. The final measured active duration is recorded in `analysis/final-mix/recovery-experiments/eight-hour-20261011/final-active-duration.json` after the minimum is reached.
