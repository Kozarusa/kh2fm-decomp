# rec133 report
Status: done
Worker: orch1-rec133, model GPT-6 inherited. Started 2026-10-13T16:56:02Z, ended 2026-10-13T17:06:22Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00224f38 | 104 | submitted | 3 | 0 | orch1_rec133_00224f38_v3.cpp |
| 00225328 | 116 | submitted | 1 | 0 | orch1_rec133_00225328_v1.cpp |
| 00225690 | 52 | submitted | 1 | 0 | orch1_rec133_00225690_v1.cpp |
| 00225aa8 | 84 | submitted | 1 | 0 | orch1_rec133_00225aa8_v1.cpp |
| 00226050 | 64 | blocked:store-order | 6 | 3 | orch1_rec133_00226050_v3.cpp |
| 002278e0 | 80 | submitted | 2 | 0 | orch1_rec133_002278e0_v2.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 00224f38 v1 source write failed from quoting; missing-source probe counted as failed version, no source/proof exists for v1. One attempted multiline source-write command returned exit 1 with empty output; replaced with direct byte writes.
Review correction: after parent O4 returned the same sixth target, 002278e0 v2 unified func_00227930 return declaration to u32, retained ignored call, probed exact and resubmitted. Old source and proof retained.
