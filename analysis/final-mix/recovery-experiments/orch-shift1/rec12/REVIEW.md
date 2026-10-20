# Review of rec12
Reviewer: sonnet. Reviewed 2026-10-12T19:12:42Z. Mechanical check: review-auto-2.json (5 PASS, 0 FAIL, 2 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 001418e8 | MERGE | PASS 64 bytes exact; plain C++ loop, no asm, report agrees (v2). |
| 0013e3b0 | MERGE | PASS 96 bytes exact; two copies of one 2-instruction lq/sq primitive (narrow, each with a why comment). (a) Accepted fm_copy_helpers.cpp uses the identical sm volatile("lq $8,0(%1); sq $8,0(%0)" ... : "$8", "memory") in func_0011a900, func_0015cea0 and func_0015ceb8, and kn::FVector::operator= is the same lq/sq pair. (b) PROGRESS.md shows C14 tried first: v1 used the Quad typedef (mode(TI)) copy, 18 words, first diff at 3; v2 inline variant 18 words; v3 kn::FVector copy 26 words (self-assign guard in operator= adds code the original lacks); only then v4 asm. v4 is the unguarded variant of the accepted primitive. |
| 0013d750 | MERGE | PASS 72 bytes exact; plain C++, no asm, report agrees (v1). |
| 00140760 | MERGE | PASS 108 bytes exact; plain C++ with a vtable call, no asm, report agrees (v1). |
| 0013aca0 | MERGE | PASS 124 bytes exact; plain C++, no asm, report agrees (v2). |

Spot check: 00140760 diff shows Differing words: 0 (yes).
Blocked reports: 1 checked, 0 incomplete ().
FLAG note: Codex/orchestration/PROGRESS.md changed outside the WP; it is under Codex/orchestration, i.e. written by the orchestrator (per orchestrator note), not the worker. Not a shared-file violation by the worker.
Other notes: 0013e3b0 has 4 emitted instructions in total but only 2 per site, the same primitive as accepted code; no Names/declaration/trickery problems found in any submitted file. 0013fd10 blocked (prologue-epilogue), BLOCKED.md has all six lines and a non-empty next hypothesis.
Mechanical output:
PASS 001418e8 64 bytes exact; source orch1_rec12_001418e8_v2.cpp
FLAG 0013e3b0 4 emitted non-VU asm instructions; reviewer must confirm these are narrow primitives, not a pasted body
PASS 0013e3b0 96 bytes exact; source orch1_rec12_0013e3b0_v4.cpp
PASS 0013d750 72 bytes exact; source orch1_rec12_0013d750_v1.cpp
PASS 00140760 108 bytes exact; source orch1_rec12_00140760_v1.cpp
PASS 0013aca0 124 bytes exact; source orch1_rec12_0013aca0_v2.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec12\review-auto-2.json
