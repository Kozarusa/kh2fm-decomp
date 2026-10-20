# brl01 report
Status: done
Worker: orch1-brl01, model opus. Started 2026-10-12T17:18:34Z, ended 2026-10-12T17:31:30Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0010ce78 | 120 | blocked:branch-layout (first claim, superseded by claim 5) | 7 | 3 | orch1_brl01_0010ce78_v3.cpp |
| 0010f6b8 | 60 | submitted | 3 | 0 | orch1_brl01_0010f6b8_v3.cpp |
| 001124f8 | 108 | submitted | 2 | 0 | orch1_brl01_001124f8_v2.cpp |
| 0011f078 | 124 | submitted | 4 | 0 | orch1_brl01_0011f078_v4.cpp |
| 0010ce78 | 120 | submitted (re-claimed from the queue after my own block) | 4 (v8-v11) | 0 | orch1_brl01_0010ce78_v11.cpp |
| 00161548 | 76 | submitted | 6 | 0 | orch1_brl01_00161548_v6.cpp |

Totals: 5 submitted, 1 blocked, 0 released. (6 claims: 0010ce78 was blocked on claim 1, then claimed again from branch-layout as claim 5 and submitted, so the queue now shows it as submitted.)
Problems:
- On 0010ce78 claim 1 I ran v7 after three versions in a row (v4-v6) had not improved on the best, one version past the R7 stop rule. It did not improve either.
- On 0010ce78 claim 1, v1 was a new write instead of the earlier blocker's next hypothesis. The best earlier attempt had more than 6 differing words.
- On the 0010ce78 re-claim, `kh2w.py packet` refused to overwrite my existing 0010ce78-packet.md. I reused the existing packet for the same target.
- Pattern for the branch-layout specialist: the compiler folds 0/1 results into slt/movz, or merges zero stores, unless each false path has its own `= 0` / `return 0` arm. Use if/else-if/else with explicit 0 arms, `if (a && b) return 1; return 0;`, or direct global stores in both arms. A `while (ptr != 0) { ...; return ...; }` form places the guarded call block after the epilogue.
