# rec107 report
Status: done
Worker: orch1-rec107, model sonnet. Started 2026-10-13T05:21:12Z, ended 2026-10-13T05:50:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001d5198 | 124 | submitted | 2 | 0 | orch1_rec107_001d5198_v2.cpp |
| 001d53e8 | 100 | blocked:register-allocation | 4 | 4 | orch1_rec107_001d53e8_v1.cpp |
| 001d59b0 | 108 | submitted | 7 | 0 | orch1_rec107_001d59b0_v7.cpp |
| 001d5cd0 | 76 | submitted | 3 | 0 | orch1_rec107_001d5cd0_v3.cpp |
| 001d5ec0 | 108 | blocked:address-materialization | 5 | 11 | orch1_rec107_001d5ec0_v2.cpp |
| 001d6d00 | 88 | submitted | 5 | 0 | orch1_rec107_001d6d00_v5.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: none. (001d5cd0 uses one empty asm to keep the table base in its own register, with a why comment.)
