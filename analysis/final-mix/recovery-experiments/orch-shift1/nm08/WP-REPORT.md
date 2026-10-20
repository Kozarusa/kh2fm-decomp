# nm08 report
Status: done
Worker: orch1-nm08, model sonnet. Started 2026-10-13T05:56:06Z, ended 2026-10-13T05:58:26Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001d7a08 | 68 | submitted | 1 | 0 | orch1_nm08_001d7a08_v1.cpp |
| 001d9d48 | 60 | submitted | 1 | 0 | orch1_nm08_001d9d48_v1.cpp |
| 001d4f40 | 104 | blocked:register-allocation | 3 | 2 | orch1_nm08_001d4f40_v1.cpp |
| 001da420 | 56 | submitted | 1 | 0 | orch1_nm08_001da420_v1.cpp |

Totals: 3 submitted, 1 blocked, 0 released.
Problems: 001d4f40 v3 was a compile error caused by my own malformed comment line, so it spent a version and ended the R7 streak at 3 without evaluating the asm guard on the bound constant. The 001d9d48 byte count in the table is not confirmed against the queue.
