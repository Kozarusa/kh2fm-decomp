# rec16 report
Status: done
Worker: orch1-rec16, model sonnet. Started 2026-10-12T19:31:01Z, ended 2026-10-12T19:50:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00146730 | 88 | submitted | 8 | 0 | orch1_rec16_00146730_v8.cpp |
| 00146d68 | 120 | blocked:register-allocation | 5 | 27 | orch1_rec16_00146d68_v2.cpp |
| 00147240 | 120 | submitted | 9 | 0 | orch1_rec16_00147240_v9.cpp |
| 00149c08 | 56 | submitted | 1 | 0 | orch1_rec16_00149c08_v1.cpp |
| 00149c40 | 96 | submitted | 1 | 0 | orch1_rec16_00149c40_v1.cpp |
| 0014a470 | 60 | submitted | 1 | 0 | orch1_rec16_0014a470_v1.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: A Remove-Item on a scratch file in my WP directory was blocked by the harness and not retried (the scratch file was never created, nothing lost). 00147240 used 9 versions: v8 was exact and v9 only added a why comment for the review rule. 00146730 and 00147240 contain emitted assembly (nops, register bindings), each with a why comment.
