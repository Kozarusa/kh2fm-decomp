# rec178 report
Status: done
Worker: orch1-rec178, model GPT-6 inherited. Started 2026-10-18T02:33:26Z, ended 2026-10-18T02:38:27Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0029c958 | 124 | blocked:abi-layout | 0 | N/A | none |
| 0029dd00 | 96 | submitted | 1 | 0 | orch1_rec178_0029dd00_v1.cpp |
| 0029dda8 | 108 | submitted | 2 | 0 | orch1_rec178_0029dda8_v2.cpp |
| 0029e7b0 | 88 | submitted | 3 | 0 | orch1_rec178_0029e7b0_v3.cpp |
| 0029ea30 | 116 | blocked:boundary-review | 0 | N/A | none |
| 0029ec40 | 88 | blocked:prologue-epilogue | 8 | 2 | orch1_rec178_0029ec40_v7.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 0029ec40 v7 accidentally added guards at two sites, violating one-control rule; ineligible for submission. Valid v8 isolates default-only guard from v6 and ties 2 words. All evidence preserved; no exact result submitted for this target.
