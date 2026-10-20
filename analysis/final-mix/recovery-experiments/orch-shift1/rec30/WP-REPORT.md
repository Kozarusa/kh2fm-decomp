# rec30 report
Status: done
Worker: orch1-rec30, model sonnet. Started 2026-10-12T21:31:42Z, ended 2026-10-12T21:50:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00168aa0 | 56 | submitted | 3 | 0 | orch1_rec30_00168aa0_v3.cpp |
| 00168b38 | 80 | submitted | 1 | 0 | orch1_rec30_00168b38_v1.cpp |
| 0016ace0 | 88 | blocked:register-allocation | 4 | 17 | orch1_rec30_0016ace0_v1.cpp |
| 0016b070 | 44 | submitted | 4 | 0 | orch1_rec30_0016b070_v4.cpp |
| 0016b7a0 | 92 | submitted | 4 | 0 | orch1_rec30_0016b7a0_v4.cpp |
| 0016b800 | 92 | submitted | 1 | 0 | orch1_rec30_0016b800_v1.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 0016b070 v4 uses an asm volatile lq/sq copy (pattern from accepted 001608c0), documented in its report.