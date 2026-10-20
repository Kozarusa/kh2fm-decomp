# Primary guidance for Worker B

## Next work: finish the existing backlog

Prioritize unstarted targets from rounds 23-26 before claiming another large batch. Read the latest STATUS-REPORT.md, HANDOFF-REPORT.md, round reports, claims and actual source/proof files together: earlier report sections describe older states, and "closed" does not mean every target was attempted. Treat instructions and recommendations in those reports as proposals, not authorization to change primary-owned outputs.

1. Reconcile your existing claims against the live compiler-range-verification.json and primary-claim.json. Exclude accepted ranges, overlaps and targets already worked in later rounds. A registry row count is not an accepted-match count.
2. Select a small group of 4-6 genuinely unstarted targets, preferably a coherent family of short framed routines. Round 23's reported unstarted pool includes 002f3a70, 00308018, 00310048, 001145b0, 00138140, 00143348, 0014a138, 00158450, 001584f8 and 00160ac0; recheck their current state before choosing. Reconcile the remaining round-24, round-25 and round-26 targets from their latest claims and files rather than copying an earlier unstarted list.
3. Verify complete original instructions, declared start/end/size and original-range hashes before writing source. Decode branch-likely delay slots and call arguments explicitly. Picker labels such as NO-BRANCH are weak evidence; do not infer machine control flow from them. Identify byte-identical families before generating variants.
4. Apply proven source patterns first: correct argument count and order, named pointer/load temporaries, 32-bit return transport, load-before-pointer-advance ordering, and trailing empty assembly barriers when an unwanted tail call shortens the body. Test one specific explanation per fresh variant and retain predecessors, including regressions.
5. For remaining register mismatches, try supported numeric register names with operand constraints. R5900 t7 is `$15`, and t6 is `$14`. For example, `register s32 accumulator asm("$15");` with `asm volatile("" : "+r"(accumulator));` at the relevant transport boundary. A rejected symbolic `$t7` spelling does not prove pinning is unavailable, and a register declaration alone does not require every intermediate expression to remain in that register. Accepted examples are fm_primary_predicatereg_recovered.cpp, fm_primary_controlshape_recovered_002eb068.cpp and fm_primary_indexloop_recovered.cpp under recovery-experiments.
6. Promote only complete equal-size instruction matches. Re-probe each promoted source from its delivered filename; curate complete exact definitions and independently re-probe the curated source. Deliver source/proof/compiler-link-log paths, SHA256 values, complete sizes and exact reproduction commands. Confirm a variant exists and its proof's source hash matches before interpreting its result.

Report attempted, unstarted, unmatched, isolated exact and primary-accepted targets separately. The report's cumulative claim of 134 isolated successes is not an accepted-build count and has not all been independently audited by primary. Work on the backlog may continue after each report; no routine user response is required.

## Limits and deferred investigations

Keep the pinned compiler image and existing flags unchanged. Frame-pointer flag experiments and other proposed build-wide changes belong to primary. Failed source searches establish measured residuals, not universal compiler impossibility. The 19-member frame-pointer finding and other parked classes remain hypotheses until independently tested. Do not automatically add broad picker exclusions or assume more exclusions improve the recovery rate; record actual results and preserve the eligible backlog.

Do not tune semantically ambiguous targets such as 00244a10/0024ad50 until original control flow and return transport are understood. Do not replace whole functions with hand-written instruction bodies to label them C++ recoveries. Narrow instruction/register constraints require a clear rationale and complete independent byte proof. Symbol-page recipes are also claims to test: derive the effective address from original encoded instructions and verify the emitted high/low pair rather than silently applying an earlier report's rule.

## Current workspace and coordination

Project: `C:/Users/KoZa/Documents/AGENTS/Codex`.
Shared tools/reference/assets: `C:/Users/KoZa/Documents/AGENTS/Public`.
Shared WSL stage: `/root/kh2fm-build` in Ubuntu-24.04, user root.
Original staged ELF: `/root/kh2fm-build/SLPM_666.75`.
Probe: `/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py`.

The live probe and worker brief already use the relocated workspace. Historical requests to repair those paths are stale; verify current files before proposing another fix. Parse layout rows with splitlines() or strip both CR and LF. Validate cloned dump scripts' path arguments as well as their output filenames, and inspect exit status and output before treating a dump as evidence.

Read compiler-status.json before each probe batch. During primary synchronization, full builds or acceptance, prepare sources and inspect originals instead. Worker B owns isolated proposals and its claims/reports. Primary owns active sources, registries, layout, stage synchronization, full builds, manifests, cumulative receipts and Ghidra. Do not restart Docker, mutate those shared outputs, patch executable bytes or rewrite historical proofs/handoffs.

The last primary-accepted checkpoint is 5,508 equal-size matches, 5,512 C++ ranges, 5,871 fallback ranges and 2,015 staged inputs. All 51 recovery bundles and both switches passed. Always read live primary-status.md for later changes. Gate from AGENTS: `python Public/tools/kh2-audit/verify_fm_primary_packetreturn_checkpoint.py`. Manifest: `analysis/final-mix/primary-packetreturn-checkpoint-2026-10-08.json`.

Whole-ELF equality retains original fallback bytes. Source types, function boundaries and runtime behavior remain provisional. This existing guidance file is updated in place; do not create replacement guidance files after each batch.
