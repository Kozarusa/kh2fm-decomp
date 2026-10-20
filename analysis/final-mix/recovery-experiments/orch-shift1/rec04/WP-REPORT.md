# rec04 report
Status: done
Worker: orch1-rec04, model sonnet. Started 2026-10-12T16:58:17Z, ended 2026-10-12T17:20:00Z (approx).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001124f8 | 108 | blocked:branch-layout | 6 | 20 | orch1_rec04_001124f8_v1.cpp |
| 001129d8 | 124 | submitted | 1 | 0 | orch1_rec04_001129d8_v1.cpp |
| 00112d28 | 104 | submitted | 6 | 0 | orch1_rec04_00112d28_v6.cpp |
| 001144e8 | 104 | blocked:abi-layout | 5 | 24 | orch1_rec04_001144e8_v2.cpp |
| 001168c0 | 120 | submitted | 3 | 0 | orch1_rec04_001168c0_v3.cpp |
| 00119f48 | 112 | blocked:address-materialization | 6 | 15 | orch1_rec04_00119f48_v3.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. 001168c0 uses a register binding (register u64 zero asm("$17")) and an empty asm("" : "+r"), both with why comments.
