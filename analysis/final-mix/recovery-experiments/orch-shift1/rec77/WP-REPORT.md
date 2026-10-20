# rec77 report
Status: done
Worker: orch1-rec77, model sonnet. Started 2026-10-13T02:09:06Z, ended 2026-10-13T02:40:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001a8f10 | 84 | submitted | 4 | 0 | orch1_rec77_001a8f10_v4.cpp |
| 001a92d8 | 120 | submitted | 5 | 0 | orch1_rec77_001a92d8_v5.cpp |
| 001a9a28 | 64 | blocked:address-materialization | 6 | 7 | orch1_rec77_001a9a28_v3.cpp |
| 001aa310 | 120 | blocked:address-materialization | 5 | 14 | orch1_rec77_001aa310_v2.cpp |
| 001aa790 | 92 | blocked:store-order | 4 | 3 | orch1_rec77_001aa790_v1.cpp |
| 001aa7f0 | 92 | blocked:store-order | 5 | 3 | orch1_rec77_001aa7f0_v2.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: 001aa7f0 v4 was a compile error caused by my PowerShell -replace mangling "$15" (counted as a version). WP-REPORT end time is approximate.
