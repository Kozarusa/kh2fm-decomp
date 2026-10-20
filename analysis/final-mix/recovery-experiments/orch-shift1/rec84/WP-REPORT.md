# rec84 report
Status: done
Worker: orch1-rec84, model sonnet. Started 2026-10-13T03:24:01Z, ended 2026-10-13T04:05:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001b2380 | 120 | blocked:store-order | 5 | 13 | orch1_rec84_001b2380_v1.cpp |
| 001b2520 | 84 | submitted | 6 | 0 | orch1_rec84_001b2520_v6.cpp |
| 001b3018 | 128 | submitted | 3 | 0 | orch1_rec84_001b3018_v3.cpp |
| 001b3208 | 100 | blocked:register-allocation | 7 | 21 | orch1_rec84_001b3208_v4.cpp |
| 001b5400 | 92 | submitted | 5 | 0 | orch1_rec84_001b5400_v5.cpp |
| 001b5878 | 48 | blocked:register-allocation | 4 | 12 | orch1_rec84_001b5878_v1.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 001b2380 got a v5 after the 3-version no-improvement streak was already reached at v4 (v4 was my own compile error); one extra probe beyond R7.