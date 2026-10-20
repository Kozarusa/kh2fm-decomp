# rec36 report
Status: stopped: permission
Worker: orch1-rec36, model sonnet. Started 2026-10-12T22:01:24Z, ended 2026-10-12T22:40:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00171418 | 72 | submitted | 6 | 0 | orch1_rec36_00171418_v6.cpp |
| 00171810 | 52 | submitted | 2 | 0 | orch1_rec36_00171810_v2.cpp |
| 00171c60 | 92 | submitted | 5 | 0 | orch1_rec36_00171c60_v5.cpp |
| 00171fa8 | 96 | submitted | 1 | 0 | orch1_rec36_00171fa8_v1.cpp |
| 00172158 | 124 | released | 1 | 13 | orch1_rec36_00172158_v1.cpp |

Totals: 4 submitted, 0 blocked, 1 released.
Problems: A Remove-Item command (deleting my own stray, unprobed file orch1_rec36_00172158_v2.cpp, created by a failed text replace) was blocked as a protected path; not retried, so that file remains and its content is not a valid v2 (it duplicates v1). 00172158 was released with one probed version (13 words, first diff at store/arg scheduling: compiler hoists move a1,sp and swaps the two final stores); the intended v2 was memory barriers between the two final stores.
Exact next step: re-claim 00172158 and probe v1 plus an asm memory barrier between the 260 and 256 stores (use a new file name, e.g. _v3).
