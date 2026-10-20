# rec26 report
Status: done
Worker: orch1-rec26, model sonnet. Started 2026-10-12T20:53:58Z, ended 2026-10-12T21:02:43Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00160e50 | 108 | blocked:branch-layout | 8 | 4 | orch1_rec26_00160e50_v4.cpp |
| 00160f10 | 108 | blocked:branch-layout | 8 | 3 | orch1_rec26_00160f10_v6.cpp |
| 00161030 | 72 | blocked:branch-layout | 8 | 3 | orch1_rec26_00161030_v3.cpp |
| 001611a8 | 128 | blocked:branch-layout | 8 | 3 | orch1_rec26_001611a8_v1.cpp |
| 00161248 | 108 | submitted | 5 | 0 | orch1_rec26_00161248_v5.cpp |
| 001615e8 | 124 | submitted | 6 | 0 | orch1_rec26_001615e8_v6.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: none.
Key finding: the four blocked targets plus 00161248 share one loop idiom (list walk with bnezl head). A GNU statement expression with goto in the while condition (see orch1_rec26_00161248_v5.cpp) reproduces it exactly; the four blocked targets should be retried with that form (their hypotheses say so).