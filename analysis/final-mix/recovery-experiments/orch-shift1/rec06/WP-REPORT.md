# rec06 report
Status: done
Worker: orch1-rec06, model sonnet. Started 2026-10-12T17:33:18Z, ended 2026-10-12T18:05:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001231f8 | 48 | submitted | 1 | 0 | orch1_rec06_001231f8_v1.cpp |
| 00123ba8 | 116 | submitted | 5 | 0 | orch1_rec06_00123ba8_v5.cpp |
| 00123c20 | 116 | submitted | 1 | 0 | orch1_rec06_00123c20_v1.cpp |
| 00123c98 | 120 | submitted | 1 | 0 | orch1_rec06_00123c98_v1.cpp |
| 00124748 | 64 | submitted | 1 | 0 | orch1_rec06_00124748_v1.cpp |
| 001286d0 | 128 | blocked:address-materialization | 4 | 26 | orch1_rec06_001286d0_v1.cpp |

Totals: 5 submitted, 1 blocked, 0 released.
Problems: none. (00123ba8 and 00123c20 use asm volatile("" ::: "memory") with a why comment to block a tail call; 00123c20 v1 note: it is the version with that asm; 00123c98 needs none.)