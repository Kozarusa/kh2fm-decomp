# brl03 report
Status: done
Worker: orch1-brl03, model opus. Started 2026-10-12T18:42:07Z, ended 2026-10-12T18:55:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00138190 | 124 | blocked:register-allocation | 8 | 13 | orch1_brl03_00138190_v5.cpp |
| 001397d8 | 124 | blocked:register-allocation | 5 | 2 | orch1_brl03_001397d8_v1.cpp |
| 001c2ce8 | 76 | blocked:store-order | 6 | 2 | orch1_brl03_001c2ce8_v3.cpp |
| 001c2c98 | 76 | blocked:store-order | 4 | 2 | orch1_brl03_001c2c98_v1.cpp |
| 0010a828 | 92 | blocked:address-materialization | 5 | 7 | orch1_brl03_0010a828_v2.cpp |
| 0017c0a0 | 104 | blocked:store-order | 4 | 2 | orch1_brl03_0017c0a0_v1.cpp |

Totals: 0 submitted, 6 blocked, 0 released.
Problems: The queue served back 00138190 and 001c2ce8 after I had blocked them. I released both straight away and did not count them toward K. branch-layout was empty, and float-transport was empty for the second claim. R7 overrun: I probed past the 3-versions-without-improvement stop on 001397d8 (v5, one extra) and on 001c2ce8 (v5 and v6, two extra). None of these versions beat the best.