# rec105 report
Status: done
Worker: orch1-rec105, model sonnet. Started 2026-10-13T05:07:02Z, ended 2026-10-13T05:50:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001d3000 | 92 | blocked:register-allocation | 7 | 10 | orch1_rec105_001d3000_v4.cpp |
| 001d37a0 | 112 | blocked:store-order | 10 | 23 | orch1_rec105_001d37a0_v9.cpp |
| 001d3b68 | 84 | submitted | 2 | 0 | orch1_rec105_001d3b68_v2.cpp |
| 001d3f38 | 68 | submitted | 4 | 0 | orch1_rec105_001d3f38_v4.cpp |
| 001d44d8 | 80 | blocked:store-order | 7 | 8 | orch1_rec105_001d44d8_v4.cpp |
| 001d4f40 | 104 | blocked:register-allocation | 8 | 2 | orch1_rec105_001d4f40_v8.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: 001d37a0 used 10 versions, exceeding the sonnet budget of 8 by 2 (counting error on my part); the target was blocked with its best version v9 (23 words). Its v3 compiled with pointer-conversion warnings. The ended time is approximate.