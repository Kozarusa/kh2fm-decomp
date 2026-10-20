# rec76 report
Status: done
Worker: orch1-rec76, model sonnet. Started 2026-10-13T01:52:48Z, ended 2026-10-13T02:30:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001a81f0 | 104 | blocked:register-allocation | 4 | 22 | orch1_rec76_001a81f0_v4.cpp |
| 001a8258 | 84 | submitted | 2 | 0 | orch1_rec76_001a8258_v2.cpp |
| 001a82b0 | 64 | blocked:address-materialization | 4 | 5 | orch1_rec76_001a82b0_v4.cpp |
| 001a8510 | 52 | submitted | 1 | 0 | orch1_rec76_001a8510_v1.cpp |
| 001a8c78 | 84 | blocked:register-allocation | 8 | 4 | orch1_rec76_001a8c78_v8.cpp |
| 001a8cd0 | 108 | submitted | 4 | 0 | orch1_rec76_001a8cd0_v4.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. Note: 001a81f0 is the same pattern as 001a8258 (lhu t7 then move t4,t7); the asm("" : "+r"(count)) barrier from 001a8258 v2 was found only after 001a81f0 was blocked, so it is the next hypothesis for it.