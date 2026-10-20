# rec127 report
Status: done
Worker: orch1-rec127, model sonnet. Started 2026-10-13T07:57:48Z, ended 2026-10-13T08:20:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00200638 | 116 | submitted | 2 | 0 | orch1_rec127_00200638_v2.cpp |
| 00201b30 | 124 | blocked:vu-macro | 0 | n/a | none (R3, not probed) |
| 00202ba0 | 124 | blocked:vu-macro | 0 | n/a | none (R3, not probed) |
| 00203ae8 | 92 | blocked:branch-layout | 4 | 8 | orch1_rec127_00203ae8_v1.cpp |
| 00205718 | 128 | submitted | 1 | 0 | orch1_rec127_00205718_v1.cpp |
| 00207050 | 128 | submitted | 1 | 0 | orch1_rec127_00207050_v1.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. (00200638 needed an empty asm memory barrier to stop a tail call; 00203ae8 stuck at 8 words because the compiler turns the final f58 test into sltu.)
