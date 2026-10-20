# nm13 report
Status: done
Worker: orch1-nm13, model GPT-6. Started 2026-10-13T16:34:11Z, ended 2026-10-13T16:43:52Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001dee10 | 120 | submitted | 4 | 0 | orch1_nm13_001dee10_v4.cpp |
| 001ded98 | 120 | submitted | 1 | 0 | orch1_nm13_001ded98_v1.cpp |
| 001e0230 | 108 | submitted | 2 | 0 | orch1_nm13_001e0230_v2.cpp |
| 001dddd0 | 108 | submitted | 8 | 0 | orch1_nm13_001dddd0_v8.cpp |
| 001d4f40 | 104 | submitted | 1 | 0 | orch1_nm13_001d4f40_v1.cpp |
| 001e7470 | 104 | blocked:store-order | 3 | 3 | orch1_nm13_001e7470_v2.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 001dee10 v3 was a malformed source replacement compile error, counted under R7; repaired in v4, exact.
001e7470 stopped conservatively under R12 after 3 versions with best v2, streak 1: no justified permitted source-only change remained; no barrier retries or instruction-emitting asm.
