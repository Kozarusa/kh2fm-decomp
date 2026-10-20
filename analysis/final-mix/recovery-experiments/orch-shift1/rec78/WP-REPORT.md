# rec78 report
Status: done
Worker: orch1-rec78, model sonnet. Started 2026-10-13T02:19:43Z, ended 2026-10-13T02:50:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001aa8a8 | 72 | blocked:register-allocation | 7 | 9 | orch1_rec78_001aa8a8_v7.cpp |
| 001aa8f0 | 76 | blocked:register-allocation | 8 | 8 | orch1_rec78_001aa8f0_v8.cpp |
| 001aadb0 | 52 | submitted | 2 | 0 | orch1_rec78_001aadb0_v2.cpp |
| 001aae28 | 60 | submitted | 5 | 0 | orch1_rec78_001aae28_v5.cpp |
| 001aaf98 | 76 | submitted | 2 | 0 | orch1_rec78_001aaf98_v2.cpp |
| 001abba8 | 72 | blocked:store-order | 4 | 3 | orch1_rec78_001abba8_v4.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. (Best versions: 001aa8a8 v4 and v6 at 9 words, 001aa8f0 v5 at 8, 001abba8 v1 at 3. The two 001aa8xx blocks needed an empty asm memory barrier to stop a tail call.)
