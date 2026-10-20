# rec13 report
Status: done
Worker: orch1-rec13, model sonnet. Started 2026-10-12T19:06:27Z, ended 2026-10-12T19:40:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0013b9e0 | 108 | submitted | 1 | 0 | orch1_rec13_0013b9e0_v1.cpp |
| 0013d1d0 | 56 | blocked:branch-layout | 5 | 5 | orch1_rec13_0013d1d0_v1.cpp |
| 0013efe8 | 56 | submitted | 2 | 0 | orch1_rec13_0013efe8_v2.cpp |
| 0013f050 | 128 | blocked:branch-layout | 4 | 16 | orch1_rec13_0013f050_v1.cpp |
| 00140480 | 128 | blocked:large-control-flow | 3 | 31 | orch1_rec13_00140480_v1.cpp |
| 001407d0 | 128 | submitted | 3 | 0 | orch1_rec13_001407d0_v3.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. Note for 00140480: the asm lq/sq through $8 trick that solved 001407d0 was not tried there (original also moves quads via t0); a retry with it is promising.