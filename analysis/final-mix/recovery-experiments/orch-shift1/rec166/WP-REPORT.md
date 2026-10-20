# rec166 report
Status: stopped: orchestrator
Worker: orch1-rec166, model GPT-6 inherited. Started 2026-10-17T07:17:26Z, ended 2026-10-17T07:18:45Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00287ed8 | 84 | blocked:abi-layout | 0 | N/A | 00287ed8-BLOCKED.md |
| 00287f30 | 92 | blocked:abi-layout | 0 | N/A | 00287f30-BLOCKED.md |
| 00287f90 | 120 | released | 0 | N/A | none |

Totals: 0 submitted, 2 blocked, 1 released.
Problems: The first two targets contain outgoing callee-result paths and untouched entry-v0 paths; literal R4.3 prevents a supported common return contract without an exception. No sources drafted or probes run. Orchestrator STOP at the 60% single-worker threshold interrupted claim 3 before drafting; K6 and R7 budgets were not exhausted.
Exact next step (only if partial or stopped): Orchestrator reviews both ABI blockers and schedules remaining general queue work when capacity permits.

Timing correction: ended 2026-10-17T07:19:04Z; the earlier end timestamp was recorded prematurely.
