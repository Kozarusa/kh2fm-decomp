# rec176 report
Status: done
Worker: orch1-rec176, model GPT-6 inherited. Started 2026-10-18T02:17:24Z, ended 2026-10-18T02:20:29Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00294480 | 80 | submitted | 2 | 0 | orch1_rec176_00294480_v2.cpp |
| 00294550 | 80 | blocked:abi-layout | 0 | unavailable | none |
| 00294e48 | 92 | blocked:abi-layout | 1 | 8 | orch1_rec176_00294e48_v1.cpp |
| 00295228 | 72 | submitted | 1 | 0 | orch1_rec176_00295228_v1.cpp |
| 00295810 | 80 | blocked:abi-layout | 0 | unavailable | none |
| 00296b08 | 116 | blocked:abi-layout | 0 | unavailable | none |

Totals: 2 submitted, 4 blocked, 0 released.
Problems: Three mixed untouched-entry/callee-result contracts; one mixed-width outgoing-result contract. K6 claim-attempt limit reached. No shared edits, overwrites, deletions, full builds, or reviewer calls.

Problems addendum: The 00294480 v1-to-v2 change combined an initialized s32 result temporary (C11(b)) with an empty guard (C11(d)); the original progress entry incorrectly named only the guard. No isolated temporary or guard effect is established. Final source semantics were independently approved; 00295228 is unaffected. Future temporary and guard experiments must separate these controls.
