# lay01 report
Status: done
Worker: orch1-lay01, model opus. Started 2026-10-12T17:32:03Z, ended 2026-10-12T17:47:42Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001144e8 | 104 | submitted | 3 | 0 | orch1_lay01_001144e8_v3.cpp |
| 0017c0a0 | 104 | blocked:address-materialization | 4 | 2 | orch1_lay01_0017c0a0_v1.cpp |
| 00127f40 | 120 | blocked:store-order | 12 | 10 | orch1_lay01_00127f40_v12.cpp |
| 001c2ce8 | 76 | blocked:store-order | 4 | 2 | orch1_lay01_001c2ce8_v1.cpp |
| 001c2c98 | 76 | blocked:store-order | 4 | 2 | orch1_lay01_001c2c98_v4.cpp |
| 00137c50 | 56 | submitted | 2 | 0 | orch1_lay01_00137c50_v2.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: once listed earlier-attempt file names with a recursive read-only Get-ChildItem under recovery-experiments (no writes outside the WP directory). Finding for the next store-order worker: a non-volatile asm with a "+m" output on a field that is stored again later is deleted as a dead store and has no effect; the output must name a field that is not rewritten (this fixed 00137c50). 001c2c98 v4 is down to one swapped ori/addiu pair with all stores exact, and the same recipe should carry over to its twin 001c2ce8.
