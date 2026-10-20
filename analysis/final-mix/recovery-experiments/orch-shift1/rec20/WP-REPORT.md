# rec20 report
Status: done
Worker: orch1-rec20, model sonnet. Started 2026-10-12T20:01:36Z, ended 2026-10-12T20:08:53Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00154288 | 60 | submitted | 3 | 0 | orch1_rec20_00154288_v3.cpp |
| 001542c8 | 104 | submitted | 1 | 0 | orch1_rec20_001542c8_v1.cpp |
| 00154b98 | 120 | blocked:branch-layout | 8 | 2 | orch1_rec20_00154b98_v7.cpp |
| 00154ee8 | 72 | blocked:branch-layout | 5 | 8 | orch1_rec20_00154ee8_v1.cpp |
| 00155f40 | 124 | blocked:address-materialization | 6 | 2 | orch1_rec20_00155f40_v5.cpp |
| 00157990 | 108 | blocked:branch-layout | 7 | 9 | orch1_rec20_00157990_v4.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: none. Note for 00155f40: the only remaining difference in v5 is the jump table address (compiler emits its own table symbol instead of D_0036b2d8).