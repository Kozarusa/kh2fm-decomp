# fam02 report
Status: done
Worker: orch1-fam02, model sonnet. Started 2026-10-12T18:37:24Z, ended 2026-10-12T18:39:14Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00139858 | 116 | submitted | 1 | 0 | orch1_fam02_00139858_v1.cpp |
| 001398d0 | 116 | submitted | 1 | 0 | orch1_fam02_001398d0_v1.cpp |
| 00139948 | 116 | submitted | 1 | 0 | orch1_fam02_00139948_v1.cpp |
| 001399c0 | 116 | submitted | 1 | 0 | orch1_fam02_001399c0_v1.cpp |
| 00139a38 | 116 | submitted | 1 | 0 | orch1_fam02_00139a38_v1.cpp |

Totals: 5 submitted, 0 blocked, 0 released.
Problems: a stray unused file orch1_fam02_139858_v1.cpp (wrong name from a PowerShell numeric-parse slip, never probed) is in the WP directory. Packet callees for 00139a38 matched the expected 001396d0; fam01's source declared func_001396e0 for 00139ab0, which was only replaced by each address's own callee.
