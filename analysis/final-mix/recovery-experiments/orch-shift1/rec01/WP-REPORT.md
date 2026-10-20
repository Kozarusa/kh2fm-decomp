# rec01 report
Status: done
Worker: orch1-rec01, model sonnet. Started 2026-10-12T16:39:16Z, ended 2026-10-12T17:20:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00105de0 | 104 | submitted | 2 | 0 | orch1_rec01_00105de0_v2.cpp |
| 00105fc8 | 124 | submitted | 3 | 0 | orch1_rec01_00105fc8_v3.cpp |
| 001064a8 | 120 | blocked:address-materialization | 4 | 13 | orch1_rec01_001064a8_v1.cpp |
| 00109360 | 104 | submitted | 1 | 0 | orch1_rec01_00109360_v1.cpp |
| 00109708 | 124 | blocked:store-order | 8 | 19 | orch1_rec01_00109708_v4.cpp |
| 00109cc0 | 64 | submitted | 2 | 0 | orch1_rec01_00109cc0_v2.cpp |
| 00109f58 | 116 | submitted | 3 | 0 | orch1_rec01_00109f58_v3.cpp |

Totals: 5 submitted, 2 blocked, 0 released.
Problems: I claimed 7 targets instead of K=6 (miscount; the 7th, 00109f58, was exact and is submitted). 00109708 had one wasted version (v7, my own typo compile error). 00109f58 v3 uses a computed goto plus a local static label array; it may emit a small unused data object.
