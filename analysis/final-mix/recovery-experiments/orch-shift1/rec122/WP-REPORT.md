# rec122 report
Status: done
Worker: orch1-rec122, model sonnet. Started 2026-10-13T07:23:38Z, ended 2026-10-13T08:00:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001e3590 | 96 | blocked:address-materialization | 1 | 2 | orch1_rec122_001e3590_v1.cpp |
| 001e3898 | 96 | submitted | 4 | 0 | orch1_rec122_001e3898_v4.cpp |
| 001e41e0 | 104 | blocked:store-order | 6 | 8 | orch1_rec122_001e41e0_v3.cpp |
| 001e6688 | 92 | blocked:store-order | 6 | 9 | orch1_rec122_001e6688_v3.cpp |
| 001e7538 | 108 | blocked:branch-layout | 4 | 4 | orch1_rec122_001e7538_v1.cpp |
| 001e7798 | 116 | submitted | 5 | 0 | orch1_rec122_001e7798_v5.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: 001e3590 is a switch jump table; the only differing words are the table address (lui/addiu to D_0036eaf8), an unresolved relocation in the probe, so it may be unmatchable by the probe (blocked after 1 version on that basis). 001e7538 v4 was a compile error from my own escaping typo, which used up the last streak slot; the idea is recorded in its BLOCKED.md.