# Review of rec22
Reviewer: sonnet. Reviewed 2026-10-12T20:27:18Z. Mechanical check: review-auto-2.json (2 PASS, 0 FAIL, 3 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0015a768 | MERGE | Exact (100 bytes). Ordinary C++ control flow (two guarded ifs, a load/store, one call). Asm is only five narrow `register ... asm("$15")` pins with empty "+r" constraints plus one memory barrier, each with a why comment on the previous line; no instructions are emitted. Declarations before the function, one function, clean names. |
| 0015a810 | MERGE | Exact (60 bytes). Plain C++ (vtable call through a struct, global store), no asm, no trickery, report agrees. |

Spot check: 0015a768 diff shows Differing words: 0 (yes).
Blocked reports: 4 checked, 0 incomplete (). All have the six R9 lines and a non-empty next hypothesis. 0015a098 (R3 vu-macro): its packet shows lqc2 (x2), vsub.wxyz and sqc2 in the range, and the only accepted siblings listed are atan2f callers with no VU sequence, so a zero-version block is correct under the vu-macro row of _shared.md.
FLAG paths: Codex/orchestration/ORCHESTRATION.md, Codex/orchestration/PROGRESS.md and Codex/orchestration/briefs/rec22.md were written by the orchestrator (orchestrator note 1), not by rec22; none is under Public\tools, layout.tsv, functions.tsv or the queue database, so they do not affect the verdict.
Mechanical output:
PASS 0015a810 60 bytes exact; source orch1_rec22_0015a810_v1.cpp
PASS 0015a768 100 bytes exact; source orch1_rec22_0015a768_v7.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec22.md
Blocked reports: 4. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec22\review-auto-2.json
