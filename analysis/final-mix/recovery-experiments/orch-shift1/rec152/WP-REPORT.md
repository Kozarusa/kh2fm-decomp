# rec152 report
Status: done
Worker: orch1-rec152, model GPT-6 inherited. Started 2026-10-16T07:42:52.8014248Z, ended 2026-10-16T07:50:14.5242967Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00253330 | 76 | blocked:register-allocation | 4 | 10 | orch1_rec152_00253330_v1.cpp |
| 002534e0 | 88 | blocked:prologue-epilogue | 2 | 19 | orch1_rec152_002534e0_v1.cpp |
| 00253888 | 108 | blocked:branch-layout | 3 | 16 | orch1_rec152_00253888_v2.cpp |
| 002576d0 | 52 | submitted | 1 | 0 | orch1_rec152_002576d0_v1.cpp |
| 00257fa8 | 80 | blocked:branch-layout | 8 | 9 | orch1_rec152_00257fa8_v6.cpp |
| 00258ce8 | 88 | blocked:store-order | 4 | 4 | orch1_rec152_00258ce8_v1.cpp |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: 00253330 v3 inline why comment accidentally swallowed offset assignment; v4 restored assignment. Both evidence files preserved; v3 cannot isolate binding effect. Strict R7 stopped at v4. No writes outside WP.
002534e0 and 00253888 stopped conservatively under R12 for delay-slot scheduling outside explicit cookbook controls.
