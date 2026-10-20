# rec188 report
Status: done
Worker: orch1-rec188, model GPT-6 inherited. Started 2026-10-19T15:40:00Z, ended 2026-10-19T15:52:12Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002b4fb8 | 64 | submitted | 3 | 0 | orch1_rec188_002b4fb8_v4.cpp |
| 002b5078 | 108 | submitted | 1 | 0 | orch1_rec188_002b5078_v1.cpp |
| 002b5108 | 124 | blocked:register-allocation | 4 | 17 | orch1_rec188_002b5108_v2.cpp |
| 002b56e8 | 124 | submitted | 4 | 0 | orch1_rec188_002b56e8_v4.cpp |
| 002b5768 | 120 | submitted | 4 | 0 | orch1_rec188_002b5768_v4.cpp |
| 002b6338 | 108 | submitted | 2 | 0 | orch1_rec188_002b6338_v2.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 002b5108 requires ABI-contract resolution before register-allocation work can preserve outgoing v0 without extra moves.
