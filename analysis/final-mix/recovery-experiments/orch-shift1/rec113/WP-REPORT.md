# rec113 report
Status: done
Worker: orch1-rec113, model sonnet. Started 2026-10-13T06:06:18Z, ended 2026-10-13T06:50:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001db8b8 | 60 | submitted | 2 | 0 | orch1_rec113_001db8b8_v2.cpp |
| 001dba18 | 108 | blocked:branch-layout | 4 | 18 | orch1_rec113_001dba18_v1.cpp |
| 001dbb38 | 92 | submitted | 3 | 0 | orch1_rec113_001dbb38_v3.cpp |
| 001dbc58 | 116 | blocked:store-order | 4 | 19 | orch1_rec113_001dbc58_v1.cpp |
| 001dc278 | 124 | blocked:store-order | 8 | 26 | orch1_rec113_001dc278_v5.cpp |
| 001dc4e8 | 88 | submitted | 2 | 0 | orch1_rec113_001dc4e8_v2.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. Note for the orchestrator: the loop form that made 001dbb38 exact (`while ((object = f(object)) != 0) { if (cond) { ...; break; } }`) was found after 001dba18 was blocked, and may fix 001dba18 (same null-return-inline plus shared-epilogue layout).
