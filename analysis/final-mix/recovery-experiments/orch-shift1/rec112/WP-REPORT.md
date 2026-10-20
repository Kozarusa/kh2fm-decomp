# rec112 report
Status: done
Worker: orch1-rec112, model sonnet. Started 2026-10-13T05:56:06Z, ended 2026-10-13T06:02:18Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001db198 | 104 | blocked:prologue-epilogue | 5 | 21 | orch1_rec112_001db198_v2.cpp |
| 001db250 | 68 | blocked:store-order | 4 | 16 | orch1_rec112_001db250_v1.cpp |
| 001db5a8 | 104 | submitted | 2 | 0 | orch1_rec112_001db5a8_v2.cpp |
| 001db7d0 | 56 | blocked:register-allocation | 5 | 9 | orch1_rec112_001db7d0_v2.cpp |
| 001db808 | 72 | submitted | 4 | 0 | orch1_rec112_001db808_v4.cpp |
| 001db850 | 56 | submitted | 3 | 0 | orch1_rec112_001db850_v3.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. Hint for the 001db7d0 follow-up: 001db808 became exact with the same vtable-call shape by binding inner to $13, vtable to $15 and slot to $14 (see orch1_rec112_001db808_v4.cpp); 001db5a8 needed an empty asm barrier after the last call to stop a tail call.

