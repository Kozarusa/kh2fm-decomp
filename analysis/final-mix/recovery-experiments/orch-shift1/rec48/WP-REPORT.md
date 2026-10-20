# rec48 report
Status: done
Worker: orch1-rec48, model sonnet. Started 2026-10-12T22:58:41Z, ended 2026-10-12T23:20:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001850a0 | 120 | blocked:branch-layout | 6 | 5 | orch1_rec48_001850a0_v3.cpp |
| 00185890 | 124 | blocked:branch-layout | 5 | 21 | orch1_rec48_00185890_v1.cpp |
| 00185920 | 104 | blocked:register-allocation | 6 | 3 | orch1_rec48_00185920_v3.cpp |
| 00185de0 | 64 | submitted | 1 | 0 | orch1_rec48_00185de0_v1.cpp |
| 00186078 | 52 | submitted | 3 | 0 | orch1_rec48_00186078_v3.cpp |
| 00186110 | 56 | blocked:address-materialization | 4 | 2 | orch1_rec48_00186110_v2.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: 00185920 v5 was a compile error caused by my own PowerShell string escaping (counted as a version). 00186110 v2 differs only in the jump-table lui/addiu relocation (D_00000000 vs D_0036c908).
