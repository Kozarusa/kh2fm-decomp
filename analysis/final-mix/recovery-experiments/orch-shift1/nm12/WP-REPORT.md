# nm12 report
Status: done
Worker: orch1-nm12, model sonnet. Started 2026-10-13T07:57:48Z, ended 2026-10-13T08:01:17Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001f0430 | 44 | submitted | 5 | 0 | orch1_nm12_001f0430_v5.cpp |
| 001fcb18 | 120 | submitted | 1 | 0 | orch1_nm12_001fcb18_v1.cpp |
| 001e7470 | 104 | blocked:store-order | 2 | 5 | orch1_nm12_001e7470_v2.cpp |
| 001fb928 | 124 | submitted | 1 | 0 | orch1_nm12_001fb928_v1.cpp |

Totals: 3 submitted, 1 blocked, 0 released.
Problems: 001f0430 v5 was written after v4 reached streak 3 by R7 (v1 was best at 2 words); it was exact and submitted. 001e7470 was blocked after only 2 versions (every barrier form reorders li/ori or leaves the delay slot filled), earlier than the 3-version streak rule would require.
