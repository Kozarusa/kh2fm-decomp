# rec170 report
Status: done
Worker: orch1-rec170, model GPT-6 inherited. Started 2026-10-17T17:31:52Z, ended 2026-10-17T17:35:22Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0028ce38 | 92 | blocked:abi-layout | 0 | N/A | none |
| 0028ce98 | 120 | blocked:abi-layout | 0 | N/A | none |
| 0028d008 | 92 | submitted | 3 | 0 | orch1_rec170_0028d008_v3.cpp |
| 0028d0f8 | 72 | blocked:abi-layout | 0 | N/A | none |
| 0028d140 | 72 | blocked:abi-layout | 0 | N/A | none |
| 0028d2a0 | 128 | blocked:abi-layout | 0 | N/A | none |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: Five zero-version ABI blocks under literal R4.3, including two packet-named void tail-callee contracts. 0028d008 v2 had a missing-brace compile error, repaired in v3. Hard K6 exhausted; no extra claims. Mechanical and independent reviews remain with the orchestrator.
