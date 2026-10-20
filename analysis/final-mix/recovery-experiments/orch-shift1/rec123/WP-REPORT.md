# rec123 report
Status: done
Worker: orch1-rec123, model sonnet. Started 2026-10-13T07:34:24Z, ended 2026-10-13T08:00:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001e7810 | 104 | submitted | 5 | 0 | orch1_rec123_001e7810_v5.cpp |
| 001e78e0 | 104 | submitted | 1 | 0 | orch1_rec123_001e78e0_v1.cpp |
| 001e8bb8 | 108 | blocked:privileged-instructions | 5 | 3 | orch1_rec123_001e8bb8_v2.cpp |
| 001ea458 | 128 | submitted | 1 | 0 | orch1_rec123_001ea458_v1.cpp |
| 001eb0c8 | 116 | submitted | 2 | 0 | orch1_rec123_001eb0c8_v2.cpp |
| 001eb140 | 112 | submitted | 1 | 0 | orch1_rec123_001eb140_v1.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: none. (001e8bb8 needs a real break instruction; __builtin_trap emits teq.)