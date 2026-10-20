# rec164 report
Status: done
Worker: orch1-rec164, model GPT-6 inherited. Started 2026-10-16T20:38:34.4563547Z, ended 2026-10-16T20:45:28.3856045Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00283e48 | 112 | blocked:register-allocation | 7 | 13 | orch1_rec164_00283e48_v4.cpp |
| 002853b8 | 92 | blocked:abi-layout | 0 | N/A | none |
| 00285d18 | 60 | submitted | 5 | 0 | orch1_rec164_00285d18_v5.cpp |
| 002865d0 | 84 | submitted | 4 | 0 | orch1_rec164_002865d0_v4.cpp |
| 00287430 | 124 | submitted | 4 | 0 | orch1_rec164_00287430_v4.cpp |
| 00287b30 | 60 | blocked:abi-layout | 0 | N/A | none |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 00283e48 strict R7 streak3. 002853b8 and 00287b30 outgoing result conflicts with sole accepted void callee declarations, conservatively blocked before drafting. K6 exhausted. No outside-WP writes. Successor full source diffs inspected against named baselines.
