# rec186 report
Status: done
Worker: orch1-rec186, model GPT-6 inherited. Started 2026-10-18T17:39:49Z, ended 2026-10-18T17:52:03Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002aae30 | 84 | submitted | 1 | 0 | orch1_rec186_002aae30_v1.cpp |
| 002ab100 | 128 | blocked:register-allocation | 8 | 13 | orch1_rec186_002ab100_v8.cpp |
| 002ad338 | 88 | blocked:register-allocation | 8 | 2 | orch1_rec186_002ad338_v7.cpp |
| 002b1660 | 120 | blocked:branch-layout | 4 | 11 | orch1_rec186_002b1660_v1.cpp |
| 002b1aa0 | 80 | blocked:abi-layout | 0 | unavailable | none |
| 002b23e0 | 72 | blocked:register-allocation | 8 | 2 | orch1_rec186_002b23e0_v5.cpp |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: 002ab100 v5 bundled base temporary with addition operand reversal. Exact v4/v5 comparison and separate v6 restoration preserved in PROGRESS and blocker; no isolated effect claimed. v5 ineligible as future baseline pending source-policy review. Normal budgets and streaks retained.
002b23e0 v5 tally initially recorded as 4 before diff inspection; corrected to 2 before v6 probe and subsequent decisions.
002b1aa0 blocked without probes: packet-named accepted callee declarations take void, while original supplies a0=-1; R4.5 exception required to proceed.

Review follow-up (additive correction): DEVIATIONS22 remains. 002ab100 v5 is ineligible as a future baseline. v6 restores addition operand order but retains reassociation; v7 branches from valid v4. Any future 002ab100 submission must establish the s32 entry argument domain: original bgez tests the incoming register, while v2 onward narrowed the initial s64 parameter. No isolated temporary or operand-order effect is established for v5.
002b1aa0 retains the ABI conflict between packet-named accepted u32 func_002b23e0(void) and original a0=-1. No R4.5 exception is granted.
Static files verify guard sites, not historical tool-call timing or shell polling. No independent proof of timing or polling is claimed. Independent review approves only submitted 002aae30, with this follow-up.
