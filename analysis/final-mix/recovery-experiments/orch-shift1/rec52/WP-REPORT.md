# rec52 report
Status: done
Worker: orch1-rec52, model sonnet. Started 2026-10-12T23:16:43Z, ended 2026-10-12T23:50:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00188670 | 96 | submitted | 3 | 0 | orch1_rec52_00188670_v3.cpp |
| 00188758 | 128 | submitted | 3 | 0 | orch1_rec52_00188758_v3.cpp |
| 00189228 | 44 | submitted | 4 | 0 | orch1_rec52_00189228_v4.cpp |
| 0018a100 | 96 | blocked:branch-layout | 5 | 14 | orch1_rec52_0018a100_v1.cpp |
| 0018b200 | 108 | submitted | 1 | 0 | orch1_rec52_0018b200_v1.cpp |
| 0018c528 | 64 | blocked:branch-layout | 7 | 6 | orch1_rec52_0018c528_v4.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: 00189228 v4 uses one empty asm("" : "+r"(value)) barrier (with a why comment) to keep an andi 0xffff.