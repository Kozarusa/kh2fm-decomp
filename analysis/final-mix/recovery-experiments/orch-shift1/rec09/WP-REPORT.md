# rec09 report
Status: done
Worker: orch1-rec09, model sonnet. Started 2026-10-12T18:55:39Z, ended 2026-10-12T19:25:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00139b28 | 116 | submitted | 8 | 0 | orch1_rec09_00139b28_v8.cpp |
| 00139ba0 | 116 | submitted | 1 | 0 | orch1_rec09_00139ba0_v1.cpp |
| 00139c18 | 116 | submitted | 5 | 0 | orch1_rec09_00139c18_v5.cpp |
| 00139d78 | 72 | blocked:branch-layout | 8 | 8 | orch1_rec09_00139d78_v7.cpp |
| 0013a820 | 116 | blocked:branch-layout | 5 | 13 | orch1_rec09_0013a820_v2.cpp |
| 0013a958 | 116 | submitted | 4 | 0 | orch1_rec09_0013a958_v4.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: 00139d78-BLOCKED.md says best v7 is "68/72 bytes"; the correct figure is 64/72. 00139c18 uses an empty asm("" : "+r"(object)) with a why comment.
