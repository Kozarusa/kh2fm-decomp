# rec44 report
Status: done
Worker: orch1-rec44, model sonnet. Started 2026-10-12T22:41:32Z, ended 2026-10-12T23:20:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0017ce10 | 112 | submitted | 4 | 0 | orch1_rec44_0017ce10_v4.cpp |
| 0017de70 | 76 | submitted | 2 | 0 | orch1_rec44_0017de70_v2.cpp |
| 0017edf0 | 120 | submitted | 5 | 0 | orch1_rec44_0017edf0_v5.cpp |
| 0017f380 | 88 | blocked:branch-layout | 6 | 10 | orch1_rec44_0017f380_v3.cpp |
| 0017f488 | 88 | submitted | 1 | 0 | orch1_rec44_0017f488_v1.cpp |
| 0017fef0 | 120 | submitted | 6 | 0 | orch1_rec44_0017fef0_v6.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 0017fef0 had VU macro instructions; attempted because accepted siblings 001786e0 and 0018a4d8 (found by search, not in the packet) show the same lqc2/sqc2/vsub asm pattern. Its v3 was a compile error. 0017f380 v1 produced no rows (extern "C" self-prototype); the Python traceback came from running diff on it.
