# rec25 report
Status: done
Worker: orch1-rec25, model sonnet. Started 2026-10-12T20:45:52Z, ended 2026-10-12T20:50:56Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0015ee10 | 124 | submitted | 1 | 0 | orch1_rec25_0015ee10_v1.cpp |
| 00160430 | 84 | submitted | 1 | 0 | orch1_rec25_00160430_v1.cpp |
| 001608c0 | 124 | submitted | 4 | 0 | orch1_rec25_001608c0_v4.cpp |
| 00160b10 | 120 | blocked:branch-layout | 6 | 23 | orch1_rec25_00160b10_v3.cpp |
| 00160d70 | 108 | blocked:branch-layout | 6 | 12 | orch1_rec25_00160d70_v3.cpp |
| 00160de0 | 108 | blocked:branch-layout | 4 | 12 | orch1_rec25_00160de0_v1.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. (001608c0 uses one asm volatile lq/sq quad copy copied from the accepted 00159ce0 pattern.)
