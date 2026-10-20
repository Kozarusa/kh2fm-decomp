# rec91 report
Status: done
Worker: orch1-rec91, model sonnet. Started 2026-10-13T03:59:48Z, ended 2026-10-13T04:05:12Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001bbc30 | 124 | submitted | 2 | 0 | orch1_rec91_001bbc30_v2.cpp |
| 001bbf00 | 64 | submitted | 3 | 0 | orch1_rec91_001bbf00_v3.cpp |
| 001bbfd0 | 60 | submitted | 3 | 0 | orch1_rec91_001bbfd0_v3.cpp |
| 001bc130 | 88 | submitted | 1 | 0 | orch1_rec91_001bc130_v1.cpp |
| 001bc6a8 | 84 | blocked:register-allocation | 8 | 1 | orch1_rec91_001bc6a8_v5.cpp |
| 001bc948 | 68 | blocked:branch-layout | 4 | 11 | orch1_rec91_001bc948_v1.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: the first block command for 001bc6a8 failed on a quoting error in the hypothesis argument, and I claimed 001bc948 before noticing; I then blocked 001bc6a8 correctly and the claim count stayed at 6 of 6. Version v2 of 001bc948 was a compile error from a typo (stray backtick) and counts as a version.
