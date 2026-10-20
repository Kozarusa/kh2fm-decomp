# rec182 report
Status: done
Worker: orch1-rec182, model GPT-6 inherited. Started 2026-10-18T12:37:30Z, ended 2026-10-18T12:51:51Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002a0168 | 92 | blocked:abi-layout | 0 | unavailable | none |
| 002a0360 | 60 | submitted | 4 | 0 | orch1_rec182_002a0360_v4.cpp |
| 002a1c68 | 108 | blocked:abi-layout | 2 | 8 | orch1_rec182_002a1c68_v2.cpp |
| 002a1f40 | 60 | blocked:boundary-review | 0 | unavailable | none |
| 002a4990 | 108 | submitted | 1 | 0 | orch1_rec182_002a4990_v1.cpp |
| 002a6290 | 120 | blocked:prologue-epilogue | 7 | 26 | orch1_rec182_002a6290_v4.cpp |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: 002a6290 initial next hypothesis duplicated v3; appended correction identifies untried index binding. Mechanical review and independent review remain orchestrator-owned.
Problems: 002a6290 v5 guard replacement uniqueness checked before probe; full source/diff output was buffered by PowerShell and arrived after probe completion. Exactly one guard was added; parent notified.
