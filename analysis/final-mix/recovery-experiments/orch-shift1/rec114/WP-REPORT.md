# rec114 report
Status: done
Worker: orch1-rec114, model sonnet. Started 2026-10-13T06:06:18Z, ended 2026-10-13T06:10:57Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001db9a8 | 112 | submitted | 2 | 0 | orch1_rec114_001db9a8_v2.cpp |
| 001dba98 | 52 | submitted | 1 | 0 | orch1_rec114_001dba98_v1.cpp |
| 001dbad0 | 104 | blocked:register-allocation | 5 | 4 | orch1_rec114_001dbad0_v2.cpp |
| 001dbcd0 | 104 | submitted | 4 | 0 | orch1_rec114_001dbcd0_v4.cpp |
| 001dc018 | 84 | submitted | 2 | 0 | orch1_rec114_001dc018_v2.cpp |
| 001dc418 | 108 | submitted | 3 | 0 | orch1_rec114_001dc418_v3.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: none. Note: sibling 001dbcd0 became exact with register bindings (destination to $15 plus empty asm guard, quad temp to $8), which is the next hypothesis for blocked 001dbad0.

