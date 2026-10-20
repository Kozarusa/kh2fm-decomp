# rec100 report
Status: done
Worker: orch1-rec100, model sonnet. Started 2026-10-13T04:39:53Z, ended 2026-10-13T05:10:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001c7950 | 76 | submitted | 7 | 0 | orch1_rec100_001c7950_v7.cpp |
| 001c9958 | 88 | blocked:branch-layout | 9 | 17 | orch1_rec100_001c9958_v7.cpp |
| 001c9b90 | 112 | submitted | 1 | 0 | orch1_rec100_001c9b90_v1.cpp |
| 001c9c00 | 120 | submitted | 1 | 0 | orch1_rec100_001c9c00_v1.cpp |
| 001c9db0 | 72 | submitted | 2 | 0 | orch1_rec100_001c9db0_v2.cpp |
| 001ca950 | 56 | submitted | 1 | 0 | orch1_rec100_001ca950_v1.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 001c9958 used 9 versions, one over the 8-version budget (miscount; v9 was written after the streak reached 2 but before I tallied the total). An extra scratch file _claim.txt (claim JSON output) was created inside the WP directory. 001c7950 v7 uses an empty memory-barrier asm and a register binding to $8, both with why comments.