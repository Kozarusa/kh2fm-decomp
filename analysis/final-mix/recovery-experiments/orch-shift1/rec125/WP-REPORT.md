# rec125 report
Status: done
Worker: orch1-rec125, model sonnet. Started 2026-10-13T07:44:59Z, ended 2026-10-13T08:20:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001f0430 | 44 | blocked:register-allocation | 7 | 3 | orch1_rec125_001f0430_v4.cpp |
| 001fb478 | 100 | blocked:store-order | 5 | 8 | orch1_rec125_001fb478_v2.cpp |
| 001fb6c8 | 84 | blocked:store-order | 6 | 10 | orch1_rec125_001fb6c8_v3.cpp |
| 001fb928 | 124 | blocked:branch-layout | 7 | 14 | orch1_rec125_001fb928_v4.cpp |
| 001fbb20 | 116 | submitted | 6 | 0 | orch1_rec125_001fbb20_v6.cpp |
| 001fcb18 | 120 | blocked:register-allocation | 8 | 3 | orch1_rec125_001fcb18_v5.cpp |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: 001fb478 v3 was an invalid draft (a PowerShell replace error left an empty file, probe failed with an assertion), so v3 was skipped and v4 used; the 001fb478 best-version name is v2. Tip: a union type with u8/u16/u32/f32 members (C18) fixed load/store order for 001fbb20 and likely helps 001fb928 (same shape, still blocked).