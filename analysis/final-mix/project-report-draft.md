# KH2FM project report - working draft

This draft supports the requested report after the active four-hour session. It is not the final session report. Refresh counts, receipts, worker state and the range inventory after the minimum work period ends.

## Project goal

Recover the Japanese PlayStation 2 Kingdom Hearts II Final Mix executable, SLPM_666.75, into maintainable C++ that reproduces the original machine instructions. Prioritize complete instruction-exact function ranges before broad renaming. The eventual source rebuild must eliminate original-executable fallback dependencies while preserving layout, data, relocations and behavior.

Instruction equality is the immediate acceptance criterion. Plausible pseudocode, equal size alone, a filename saying solved, and a worker report are insufficient. Current whole-executable equality includes original fallback bytes and is not proof of a complete source rebuild.

## Verified status and evidence

Use worker-coordination/primary-status.md and the newest cumulative checkpoint named there for current counts. Historical HANDOFF.md and SESSION_STATUS.md are intentionally unchanged and contain older baselines. The final report must cite its exact checkpoint and hash-bound evidence.

Original executable SHA256: d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87.

Compiler image: kh2-local/ps2-compiler:3.2-ee-040921-objdiff. Compilation flags remain -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections. Types, inferred boundaries and runtime semantics remain provisional.

## Accomplishments to summarize in the final report

- Preserved and continued a reproducible source/registry/layout/build pipeline with isolated probes, original-range checks, cumulative provenance and objdiff, saved artifacts, switch receipts, finalization and warning audits.
- Relocated live work to the Codex/Public split and preserved historical proofs rather than rewriting their paths.
- Independently curated, re-probed and accepted the earlier worker backlog of 118 pending proposals. All 134 solved proposals present during that audit were accounted for, including 16 already accepted.
- Corrected full-linker support for external absolute object-address declarations. The regression preserved 21,814 previous aliases while resolving 21 missing constants.
- Checked worker rounds 23-26: 4, 5, 0 and 1 unique exact recoveries respectively, all ten accepted. Accepted all three claimed exact round-27 recoveries after independent verification.
- Recovered additional argument, branch, floating-point, allocator, relocation, framed-return, virtual-call and quad-copy functions during primary continuation. Session-specific address lists and byte totals are recorded in recovery-experiments/primary-fourhour-progress-v1.json.
- Recorded failed experiments and actionable scheduling blockers without registering them. Corrected address decoding and missing argument/pointer-level errors using original instructions.

## Remaining work, ordered by priority

1. Complete any in-flight acceptance transaction before starting another compiler operation. Revalidate source hashes, exact ranges, nonoverlap, registry aliases, named synchronization and the full cumulative checkpoint. Keep the previous accepted snapshot available for recovery.
2. Reconcile fresh worker submissions, claims and current source/proof files. Curate and independently re-probe complete exact proposals, then integrate them. Check actual contents rather than report dates or remembered summaries.
3. Recover the strongest remaining near-exact candidates. project-prioritized-range-backlog.json enumerates every currently tracked fallback range in order: equal-size proposals within three differing words first, then smaller unproven ranges, then progressively larger bodies. This is a scheduling aid, not an effort guarantee. Check active ownership and blockers before selecting an entry.
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

The primary agent owns shared registration, synchronization, full builds, receipts, checkpoints and Ghidra. Outsourced workers prepare isolated sources/proofs/logs and update their own claims/reports. Coordination is through filesystem claims and compiler-status.json. Avoid concurrent use of the shared compiler/stage. Do not regenerate worker guidance repeatedly; the existing assignment is sufficient unless explicitly changed.

For a new target, verify that it is unaccepted and unclaimed by another active worker. Inspect the original complete range, its live layout and related declarations. Write a uniquely named isolated C++ proposal in recovery-experiments. Keep every failed version and its log. Probe it using the pinned compiler. Globals must use externally resolvable D_ followed by eight hexadecimal digits; functions use func_ followed by eight digits. Decode signed low address halves correctly. Do not infer original source types from one constant instruction.

Accept only complete equal-size byte equality tied to the current source hash and original ELF. Curate the exact definition and independently probe the curated source again. Snapshot the accepted state before registry/layout changes. Register the proven ranges with aliases preserved and no overlap. Synchronize only named files after checking expected stage hashes. Run make verify MAKE_JOBS=8 in /root/kh2fm-build, followed by the cumulative acceptance matrix, finalization, warning audit and new checkpoint. Update live status and claims after acceptance, and re-run the new checkpoint to bind documentation hashes.

Do not patch executable bytes, change compiler flags to force a match, restart toolchains without evidence, overwrite historical proofs or report unaccepted proposals as completed. Four zero-padding cases remain separately identified: 0018f9f8, 0014f148, 00168370 and 00315440.

If stuck, save the target, best source/proof, differing instructions, attempted constraints and next hypothesis in primary-fourhour-blockers.md. Continue a disjoint target. If a full build fails, stop dependent acceptance and resolve or restore that transaction before advancing the accepted count.
