# rec177 report
Status: done
Worker: orch1-rec177, model GPT-6 inherited. Started 2026-10-18T02:17:42Z, ended 2026-10-18T02:21:59Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002944f8 | 84 | blocked:prologue-epilogue | 4 | 15 | orch1_rec177_002944f8_v1.cpp |
| 00294f00 | 116 | blocked:abi-layout | 0 | unmeasured | none |
| 002953c8 | 100 | blocked:register-allocation | 4 | 18 | orch1_rec177_002953c8_v1.cpp |
| 00298f90 | 84 | submitted | 1 | 0 | orch1_rec177_00298f90_v1.cpp |
| 00299550 | 80 | blocked:abi-layout | 0 | unmeasured | none |
| 0029a368 | 116 | blocked:abi-layout | 0 | unmeasured | none |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: Three zero-version targets have unresolved mixed untouched-entry and outgoing-callee-result return paths under literal R4.3. Both probed blocked targets stopped at strict nonimprovement streak 3. All six claim attempts consumed; no further claims.
