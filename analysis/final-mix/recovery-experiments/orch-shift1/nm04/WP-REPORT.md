# nm04 report
Status: partial
Worker: orch1-nm04, model sonnet. Started 2026-10-13T02:30:59Z, ended 2026-10-13T03:10:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001aa7f0 | 92 | submitted | 8 | 0 | orch1_nm04_001aa7f0_v8.cpp |
| 001aa790 | 92 | submitted | 1 | 0 | orch1_nm04_001aa790_v1.cpp |
| 001abba8 | 72 | blocked:store-order | 7 | 3 | orch1_nm04_001abba8_v4.cpp |
| 001aa8f0 | 76 | blocked:register-allocation | 6 | 5 | orch1_nm04_001aa8f0_v3.cpp |

Totals: 2 submitted, 2 blocked, 0 released.
Problems: none.
Exact next step (only if partial or stopped): for 001abba8 try binding the t6/t7 values to registers so ld ra follows the second load; for 001aa8f0 bind object to t7 only for the object[14] read.
