# rec159 report
Status: done
Worker: orch1-rec159, model GPT-6 inherited. Started 2026-10-16T14:28:58.5300970Z, ended 2026-10-16T14:35:17.5437341Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00267320 | 120 | submitted | 5 | 0 | orch1_rec159_00267320_v5.cpp |
| 00269f58 | 100 | submitted | 1 | 0 | orch1_rec159_00269f58_v1.cpp |
| 0026ff30 | 68 | submitted | 1 | 0 | orch1_rec159_0026ff30_v1.cpp |
| 00272ae0 | 128 | blocked:prologue-epilogue | 6 | 15 | orch1_rec159_00272ae0_v5.cpp |
| 00275c78 | 64 | submitted | 1 | 0 | orch1_rec159_00275c78_v1.cpp |
| 00275e68 | 92 | submitted | 4 | 0 | orch1_rec159_00275e68_v4.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: 00272ae0 v5 unintentionally added two guards via text replacement, violating one-control attribution. Never submitted; v6 removed second guard. Conservatively blocked under R12; best v5 is evidence only.
