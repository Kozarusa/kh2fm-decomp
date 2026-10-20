# nm10 report
Status: done
Worker: orch1-nm10, model sonnet. Started 2026-10-13T06:50:07Z, ended 2026-10-13T07:35:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001ded98 | 120 | blocked:register-allocation | 8 | 3 | orch1_nm10_001ded98_v5.cpp |
| 001dee10 | 120 | blocked:register-allocation | 7 | 2 | orch1_nm10_001dee10_v4.cpp |
| 001dddd0 | 108 | blocked:register-allocation | 4 | 5 | orch1_nm10_001dddd0_v1.cpp |
| 001e0230 | 108 | blocked:branch-layout | 8 | 3 | orch1_nm10_001e0230_v3.cpp |

Totals: 0 submitted, 4 blocked, 0 released.
Problems: I ran one unneeded read-only "recovery_queue.py status" call (not in the manual; no effect). Note: 001dee10 v4 is down to 2 words (only a move t5,t7 copy and its bne operand remain); 001e0230 v7 matches the first 13 words including bnezl and only the exit block layout differs.

