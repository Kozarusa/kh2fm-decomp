# nm11 report
Status: done
Worker: orch1-nm11, model sonnet. Started 2026-10-13T07:17:48Z, ended 2026-10-13T07:35:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001e2660 | 84 | submitted | 1 | 0 | orch1_nm11_001e2660_v1.cpp |
| 001e2ad8 | 116 | blocked:register-allocation | 4 | 3 | orch1_nm11_001e2ad8_v1.cpp |
| 001e2c00 | 92 | blocked:privileged-instructions | 4 | 1 | orch1_nm11_001e2c00_v4.cpp |

Totals: 1 submitted, 2 blocked, 0 released.
Problems: 001e2c00 trap only (break vs teq is the sole differing word). 001e2ad8 still has the a1/a2 move order swapped plus the trap word (3 words); guards on third, second and both did not fix the order.
