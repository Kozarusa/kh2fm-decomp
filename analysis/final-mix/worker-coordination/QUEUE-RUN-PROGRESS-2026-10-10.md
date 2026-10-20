# Persistent recovery queue progress

Verified at 2026-10-11 06:14:46 UTC (2026-10-10 Pacific). This is an interrupted-run progress report, not a completion report. The goal records 4,569 active work seconds against the requested minimum of 18,000 seconds. Usage-limit interruptions and elapsed calendar time do not satisfy the remaining work requirement.

## Verified accepted work

The launch baseline was 5,707 equal-size instruction-exact functions. Five accepted queue batches added 67 distinct complete functions and 5,316 instruction bytes. Current accepted state is 5,774 equal-size exact functions, 5,778 C++ ranges including four separately counted padding ranges, 5,605 tracked fallback ranges, and 2,279 verified source inputs. The full executable matched the original, and 97 cumulative recovery bundles and three switch receipts passed before publication.

The current gate, `Public/tools/kh2-audit/verify_fm_primary_queueepsilon_checkpoint.py`, passed again after correcting a reporting arithmetic error. Queuealpha contains 472 instruction bytes; its run ledger previously said 412. This correction changes no source, function proof, registered range, or accepted function count. The run ledger preserves the previous and corrected byte totals.

`Public/tools/kh2-audit/audit_fm_queue_run.py` independently checks the current saved checkpoint's bound file hashes, each accepted source's curation chain and proof hashes, full original range bytes through the ELF load segments, range boundaries, queue acceptance states, uniqueness, and batch byte totals. Its saved report is `recovery-experiments/queue-run-20261009/primary/saved-acceptance-pending-audit.json`. The audit passed for all 67 accepted functions and 10 pending functions.

Whole-executable equality still preserves original fallback and data bytes. It does not prove a complete source-only rebuild or independent runtime behavior.

## Pending proposals and separate assembly

Ten additional primary proposals match their complete original instruction ranges, totaling 608 bytes:

| Address | Bytes | Recovered operation |
|---|---:|---|
| 00162b68 | 68 | VU dot product, plane offset, scalar publication, threshold predicate |
| 0016d888 | 72 | VU cross product, guarded vector publication, pointer update |
| 00178cf8 | 48 | Clear three vector fields |
| 001a2a18 | 52 | Clear a vector and select a mode for a framed tail call |
| 001b7958 | 60 | Translate an array of vectors, reloading its count |
| 0020e138 | 40 | Mix an external integer seed into VU random state |
| 002eaba8 | 64 | Scale all four vector lanes and perform guarded copy |
| 002ece98 | 64 | Reset a mode, clear a vector, copy a scalar |
| 002f3d08 | 68 | Multiply four matrix columns through the VU accumulator |
| 002f4888 | 72 | Return VU MAC clipping flag bits |

The queue retains them as `submitted`. Curated sources, immutable submission captures and an independent probe runner are prepared as `queuezeta`. They have not been registered or accepted. Their next required steps are independent curated recompilation, exclusive registration and synchronization, full build, all cumulative checks, finalization, warning audit, and checkpoint publication.

Separate structured startup assembly for 00100228 (116 bytes) and 001002a0 (8 bytes) passed an additional primary direct assembler/linker review against complete original ranges. Its report is `recovery-experiments/queue-run-20261009/primary/startup-assembly-independent-review.json`. These artifacts remain unintegrated and contribute zero to C++ recovery counts.

## Coordination and blockers

The user requested parking one worker to reduce usage. Worker A (`recovery-a`, `/root/queue_worker_a`) is parked and must not be resumed without a user request. The future worker pool consists of recovery-b and recovery-c. The preference is saved in `worker-pool-control.json`.

All worker executions are currently terminal with usage-limit errors. Automatic approval review also rejected a WSL inspection because its usage limit prevented review from completing; this was not a determination that the inspection was unsafe. No compiler operation was performed after that rejection, and no approval mechanism was bypassed. The queue is paused with zero leases; the last accepted compiler transaction is idle. Further compilation and worker execution require usage availability to change.

The queue preserves unresolved targets in specialized queues for register allocation, prologue/epilogue scheduling, aggregate ABI layout, pointer lifetime, variadic frame layout, and structured startup assembly review. Existing historical handoffs and Worker B guidance remain unchanged.

Resume only the two authorized workers after usage availability returns. Complete queuezeta acceptance before counting its ten proposals. Continue substantive recovery and primary acceptance until the goal's active work counter reaches at least 18,000 seconds; then drain workers, integrate pending accepted proposals, revalidate cumulative evidence, and produce the final report. The goal remains incomplete.
