# rec153 report
Status: done
Worker: orch1-rec153, model GPT-6 inherited. Started 2026-10-16 07:43:03 UTC, ended 2026-10-16 07:48:53 UTC.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00253380 | 88 | submitted | 3 | 0 | orch1_rec153_00253380_v3.cpp |
| 002535d0 | 104 | blocked:store-order | 5 | 28 | orch1_rec153_002535d0_v2.cpp |
| 00256a58 | 68 | blocked:abi-layout | 0 | n/a | none |
| 00257970 | 108 | submitted | 4 | 0 | orch1_rec153_00257970_v4.cpp |
| 00257ff8 | 80 | submitted | 1 | 0 | orch1_rec153_00257ff8_v1.cpp |
| 00258a30 | 88 | submitted | 1 | 0 | orch1_rec153_00258a30_v1.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: 00253380 v1-to-v2 combined a result register binding and empty guard, violating single-control attribution; exact submitted v3 retained. No isolated-effect claim for that transition.
002535d0 compiler emitted lbu plus explicit sign extensions instead of original lb; strict streak3 stopped work.
00256a58 outgoing tail callee has accepted void signature, which cannot resolve literal R4.3 return contract; blocked before drafting.
Mechanical review: four PASS, zero FAIL; review-auto-1.json flags concurrent outside-WP changes, none authored by this worker. Reviewer agent remains pending with orchestrator.
