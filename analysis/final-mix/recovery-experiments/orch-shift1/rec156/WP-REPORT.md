# rec156 report
Status: done
Worker: orch1-rec156, model GPT-6 inherited. Started 2026-10-16T14:15:35.2225831Z, ended 2026-10-16T14:21:20.2082548Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002636b0 | 112 | submitted | 2 | 0 | orch1_rec156_002636b0_v2.cpp |
| 002638e0 | 124 | submitted | 2 | 0 | orch1_rec156_002638e0_v2.cpp |
| 00263e18 | 128 | submitted | 1 | 0 | orch1_rec156_00263e18_v1.cpp |
| 002642a8 | 108 | blocked:address-materialization | 4 | 2 | orch1_rec156_002642a8_v4.cpp |
| 00266678 | 48 | blocked:prologue-epilogue | 5 | 2 | orch1_rec156_00266678_v2.cpp |
| 002670f8 | 88 | submitted | 2 | 0 | orch1_rec156_002670f8_v2.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: 002642a8 compiler-generated jump table has two unresolved relocation words; R12 stopped without unauthorized workaround. 00266678 stopped strict R7 streak3. No outside-WP writes. K6 exhausted.
