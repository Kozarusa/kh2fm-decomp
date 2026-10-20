# rec160 report
Status: done
Worker: orch1-rec160, model GPT-6 inherited. Started 2026-10-16T14:41:02.4161001Z, ended 2026-10-16T14:48:01.7479248Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00275f08 | 92 | submitted | 3 | 0 | orch1_rec160_00275f08_v3.cpp |
| 00276438 | 116 | blocked:abi-layout | 0 | N/A | none |
| 00276a90 | 124 | submitted | 6 | 0 | orch1_rec160_00276a90_v6.cpp |
| 00276b10 | 128 | submitted | 6 | 0 | orch1_rec160_00276b10_v6.cpp |
| 002799b0 | 96 | blocked:register-allocation | 6 | 18 | orch1_rec160_002799b0_v3.cpp |
| 0027a108 | 120 | submitted | 1 | 0 | orch1_rec160_0027a108_v1.cpp |

Totals: 4 submitted, 2 blocked, 0 released.
Problems: 00276438 untouched entry-v0 exit blocked conservatively before draft. 002799b0 strict R7 streak3 including tie. No outside-WP writes. K6 exhausted. Full source changes inspected; each tested successor changes one intended control.
