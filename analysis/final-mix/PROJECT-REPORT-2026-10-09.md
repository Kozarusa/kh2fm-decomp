# KH2FM project report — 2026-10-09

Report verified at 2026-10-09T10:41:09.604019+00:00. The requested work period began 2026-10-09 06:32:21 UTC and exceeded four hours before this report was written. The session accepted 71 additional complete instruction-exact ranges, comprising 4,836 instruction bytes. The project remains incomplete; the four-hour work requirement has been fulfilled.

The user's subsequent request adds six disjoint subagent assignments in two waves of three, because the session permits four concurrent agents including the primary. Their assignments and exclusive paths are in [delegation-plan.md](worker-coordination/delegation-plan.md). First-wave agents are active when this report is written; proposals do not change accepted counts until independently verified and integrated. The primary retains shared integration and checkpoint ownership.


## Project goal

Recover the Japanese PlayStation 2 Kingdom Hearts II Final Mix executable, SLPM_666.75, into maintainable C++ that reproduces the original machine instructions. Prioritize complete instruction-exact function ranges before broad renaming. The eventual source rebuild must eliminate original-executable fallback dependencies while preserving layout, data, relocations and behavior.

Instruction equality is the immediate acceptance criterion. Plausible pseudocode, equal size alone, a filename saying solved, and a worker report are insufficient. Current whole-executable equality includes original fallback bytes and is not proof of a complete source rebuild.

## Verified status and evidence

The current checkpoint passed again immediately before this report. Verified counts:

| Measure | Verified total |
|---|---:|
| Equal-size instruction-exact matches | 5,702 |
| C++ ranges, including four separately counted padding ranges | 5,706 |
| Remaining tracked fallback ranges | 5,677 |
| Staged compiler inputs | 2,207 |
| Cumulative verified recovery bundles | 91 |
| Verified switch batches / code ranges / generated tables | 3 / 5 / 5 |
| Exact matches at this four-hour session start | 5,631 |
| Accepted during this session | 71 |
| Instruction bytes accepted during this session | 4,836 |

Full executable equality, cumulative provenance, objdiff, saved artifacts, recovery bundles, switch checks, finalization, warning audit and the current checkpoint passed. The two new switch functions also have 40 bytes of generated table data independently proved exact. These auxiliary table checks do not establish source ownership of all executable data: the main executable still preserves original table/fallback bytes.

Checkpoint: [primary-maskpair-checkpoint-2026-10-08.json](primary-maskpair-checkpoint-2026-10-08.json).
SHA256: `d8515ba36a3bcb10ae7bc19bd0af3bc76c80f462cee30b5a25fff3fdce0a64d4`.
Acceptance gate, run from C:/Users/KoZa/Documents/AGENTS:

```text
python Public/tools/kh2-audit/verify_fm_primary_maskpair_checkpoint.py
```

The [final session ledger](recovery-experiments/primary-fourhour-final-ledger.json) lists all 71 accepted addresses, instruction lengths, source paths and source hashes. [Live primary status](worker-coordination/primary-status.md) identifies the accepted state. Historical HANDOFF.md and SESSION_STATUS.md are intentionally unchanged and contain older baselines. Whole-executable equality currently relies on original fallback/data, so it does not establish a complete source-only rebuild or independent runtime validation.


Original executable SHA256: d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87.

Compiler image: kh2-local/ps2-compiler:3.2-ee-040921-objdiff. Compilation flags remain -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections. Types, inferred boundaries and runtime semantics remain provisional.

## Accomplishments

- Preserved and continued a reproducible source/registry/layout/build pipeline with isolated probes, original-range checks, cumulative provenance and objdiff, saved artifacts, switch receipts, finalization and warning audits.
- Relocated live work to the Codex/Public split and preserved historical proofs rather than rewriting their paths.
- Independently curated, re-probed and accepted the earlier worker backlog of 118 pending proposals. All 134 solved proposals present during that audit were accounted for, including 16 already accepted.
- Corrected full-linker support for external absolute object-address declarations. The regression preserved 21,814 previous aliases while resolving 21 missing constants.
- Checked worker rounds 23-26: 4, 5, 0 and 1 unique exact recoveries respectively, all ten accepted. Accepted all three claimed exact round-27 recoveries after independent verification.
- Recovered additional argument, branch, floating-point, allocator, relocation, framed-return, virtual-call and quad-copy functions during primary continuation. The final session ledger verifies the accepted additions. Representative completed families include callback returns and address decoding, packet aliasing, floating-point results, virtual-call guards, quad transports, bounded switch dispatch, indexed masks and mask copying.
- Recorded failed experiments and actionable scheduling blockers without registering them. Corrected address decoding and missing argument/pointer-level errors using original instructions.

## Remaining work, ordered by priority

1. Complete any in-flight acceptance transaction before starting another compiler operation. Revalidate source hashes, exact ranges, nonoverlap, registry aliases, named synchronization and the full cumulative checkpoint. Keep the previous accepted snapshot available for recovery.
2. Reconcile fresh worker submissions, claims and current source/proof files. Curate and independently re-probe complete exact proposals, then integrate them. Check actual contents rather than report dates or remembered summaries.
3. Recover the strongest remaining near-exact candidates. [project-prioritized-range-backlog.json](project-prioritized-range-backlog.json) enumerates all 5,677 currently tracked fallback ranges with unique addresses in order (53 priority-one, 1,946 priority-two, 2,963 priority-three and 715 priority-four): equal-size proposals within three differing words first, then smaller unproven ranges, then progressively larger bodies. This is a scheduling aid, not an effort guarantee. Check active ownership and blockers before selecting an entry.
4. Work through all remaining tracked fallback functions, with coherent batches by instruction/frame family. Reconstruct missing ABI arguments, signed widths, address materialization, pointer levels, loops, structures and register lifetimes from original instructions. Record evidence when stuck and move to another target.
5. Revisit documented blocker families with new evidence rather than repeating failed variants: epilogue scheduling, store ordering, split address/float lifetimes, signed table loops and global initializer allocation. Recover large control-flow functions and shared calling-convention patterns as the short-function pool declines.
6. Reconcile boundaries and code-versus-data classification, including functions where pseudocode body size disagrees with the live layout. Investigate undiscovered functions and tables separately. Do not treat the current range list as proof that discovery is complete.
7. Recover data, global layouts, jump/vtables, relocation ownership and other executable sections needed for a source-only rebuild. Audit remaining fallback dependencies and define explicit acceptance for each section. The current function count does not measure this work.
8. Improve semantic readability where justified by instruction evidence: types, structures, names, API signatures and ownership. Preserve exact code and add behavior validation where semantics cannot be established by static equality alone.
9. Reproduce the final build from documented source/toolchain inputs without using original executable bytes as fallback. Validate complete code/data/layout/provenance, both switch cases and intended runtime behavior. Archive a reproducible final source/build handoff with a verified inventory of remaining dependencies equal to zero.

The function-level JSON inventory is exhaustive only for current tracked ranges. Discovery, data recovery, semantics and final-build work cannot honestly be claimed exhaustive before their audits are complete.

## Briefing for a newcomer

The host workspace is C:/Users/KoZa/Documents/AGENTS. Project analysis/docs live in Codex. Shared tools/reference/assets live in Public. The compiler checkout is Public/tools/kh2-reference; audit scripts are Public/tools/kh2-audit. The Linux build stage is /root/kh2fm-build under WSL Ubuntu-24.04, root user. Build in Linux storage, not /mnt/c.

Start by reading Codex/HANDOFF.md, Codex/SESSION_STATUS.md, Codex/WORKER_BRIEF.md, Codex/analysis/final-mix/README.md, primary-status.md, current claims, compiler-status.json and the latest worker report. Then follow the live checkpoint in primary-status.md; older handoff counts are historical. Run that current gate before making changes. Never run an old fixed-count gate as the authority for a newer build.

The primary agent owns shared registration, synchronization, full builds, receipts, checkpoints and Ghidra. Outsourced workers prepare isolated sources/proofs/logs and update their own claims/reports. Coordination is through filesystem claims and compiler-status.json. The delegated agents may run isolated probes concurrently only in their uniquely named scratch directories. The shared full-build stage remains exclusively owned by the primary; pause or finish probes before a full integration build. Follow the delegation manifest for target and write ownership. Do not regenerate worker guidance repeatedly; the existing assignment is sufficient unless explicitly changed.

For a new target, verify that it is unaccepted and unclaimed by another active worker. Inspect the original complete range, its live layout and related declarations. Write a uniquely named isolated C++ proposal in recovery-experiments. Keep every failed version and its log. Probe it using the pinned compiler. Globals must use externally resolvable D_ followed by eight hexadecimal digits; functions use func_ followed by eight digits. Decode signed low address halves correctly. Do not infer original source types from one constant instruction.

Accept only complete equal-size byte equality tied to the current source hash and original ELF. Curate the exact definition and independently probe the curated source again. Snapshot the accepted state before registry/layout changes. Register the proven ranges with aliases preserved and no overlap. Synchronize only named files after checking expected stage hashes. Run make verify MAKE_JOBS=8 in /root/kh2fm-build, followed by the cumulative acceptance matrix, finalization, warning audit and new checkpoint. Update live status and claims after acceptance, and re-run the new checkpoint to bind documentation hashes.

Do not patch executable bytes, change compiler flags to force a match, restart toolchains without evidence, overwrite historical proofs or report unaccepted proposals as completed. Four zero-padding cases remain separately identified: 0018f9f8, 0014f148, 00168370 and 00315440.

If stuck, save the target, best source/proof, differing instructions, attempted constraints and next hypothesis in primary-fourhour-blockers.md. Continue a disjoint target. If a full build fails, stop dependent acceptance and resolve or restore that transaction before advancing the accepted count.

## Blockers and how to continue

[primary-fourhour-blockers.md](recovery-experiments/primary-fourhour-blockers.md) records experiments and unresolved families. A scheduling failure or equal-size mismatch is a blocked proposal, not accepted progress. The current delegated work concentrates on bounded searches, global quad/float copying, ordered floating-point predicates, guarded global initializers, epilogue scheduling and framed argument transport. Each agent must return a source-hash-bound exact proof or a precise blocker report. Preserve the accepted checkpoint until independent review and cumulative acceptance succeed.

Newcomers should first run the current gate, inspect the delegation plan and Worker B's latest report, and select only an unowned address. Do not rewrite Worker B's guidance merely because a new session starts. Do not edit historical handoff/status documents without authorization. Recovery is measured by proven complete ranges, not hours, variant counts or worker claims.

## Subsequent delegation checkpoint

After the report above was saved, all six requested subagents were launched with exclusive target addresses and output directories. Five new proposals were independently curated and re-probed, then accepted in one exclusive integration transaction: 00148638, 0014ec40, 00158b20, 00158fd8 and 00159c58. They total 440 instruction bytes; the last range is 104 bytes rather than the 100-byte pseudocode body. None of the unsuccessful proposals was registered.

The newer accepted state is **5,707 equal-size exact matches, 5,711 C++ ranges, 5,672 fallback ranges and 2,212 staged inputs**. All **92 recovery bundles**, three switch batches, full-build equality/provenance/objdiff, finalization, warning audit and the new checkpoint pass. Total accepted gain since the four-hour session began is now **76 ranges and 5,276 instruction bytes**. The original 71-range ledger remains preserved; [primary-delegation-accepted-ledger.json](recovery-experiments/primary-delegation-accepted-ledger.json) records the newer total.

The current checkpoint is [primary-delegatedbatch-checkpoint-2026-10-08.json](primary-delegatedbatch-checkpoint-2026-10-08.json), verified by:

Checkpoint SHA256: `84e34901da44f0b90a370a28762ac21b8ad897086f33975ed91ec389267c8a6b`.

```text
python Public/tools/kh2-audit/verify_fm_primary_delegatedbatch_checkpoint.py
```

The linked backlog has been refreshed to 5,672 unique fallback addresses: 52 priority-one, 1,942 priority-two, 2,963 priority-three and 715 priority-four. The first report's totals remain an explicitly timed historical snapshot. Follow this newer checkpoint and live primary-status.md for continuation.

[Delegated proof audit](worker-coordination/delegated-proof-audit.json) independently checks each proposal's source hash, exclusive target ownership, compared instruction lengths, byte-equality result and target bytes directly against the hash-verified original ELF. Both exact variants of 00148638 are proposals for the same function; only one was accepted. Failed probes and duplicate variants do not increase accepted counts.

All six agents subsequently completed their assignments. [Delegation results](worker-coordination/delegation-results.md) maps the five accepted functions and ten unresolved targets to their exclusive assignments. Every agent saved a report; no delegated compiler operation remains active. The project remains ongoing, with the next work chosen from the refreshed priority inventory and documented blocker hypotheses.
