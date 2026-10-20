# rec08 report
Status: done
Worker: orch1-rec08, model sonnet. Started 2026-10-12T18:02:04Z, ended 2026-10-12T18:25:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00135d00 | 116 | submitted | 2 | 0 | orch1_rec08_00135d00_v2.cpp |
| 00136a18 | 56 | blocked:boundary-review | 1 | 8 | orch1_rec08_00136a18_v1.cpp |
| 001373a0 | 56 | submitted | 1 | 0 | orch1_rec08_001373a0_v1.cpp |
| 00138190 | 124 | blocked:register-allocation | 6 | 16 | orch1_rec08_00138190_v2.cpp |
| 001385c0 | 52 | submitted | 1 | 0 | orch1_rec08_001385c0_v1.cpp |
| 001397d8 | 124 | blocked:register-allocation | 8 | 2 | orch1_rec08_001397d8_v8.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 00138190 v6 was a wasted version (replacement did not apply, source identical to v5). 00136a18 is two functions merged (tail jump to 00136a40 plus a separate 16-byte function), blocked as boundary-review. The end time above is approximate.