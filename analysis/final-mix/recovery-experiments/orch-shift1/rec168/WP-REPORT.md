# rec168 report
Status: done
Worker: orch1-rec168, model GPT-6 inherited. Started 2026-10-17T07:32:36Z, ended 2026-10-17T07:35:41Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00288f60 | 120 | blocked:abi-layout | 0 | not applicable | not applicable |
| 00288fd8 | 92 | blocked:abi-layout | 0 | not applicable | not applicable |
| 0028a908 | 120 | blocked:abi-layout | 0 | not applicable | not applicable |
| 0028ae28 | 112 | submitted | 2 | 0 | orch1_rec168_0028ae28_v2.cpp |
| 0028ae98 | 124 | submitted | 1 | 0 | orch1_rec168_0028ae98_v1.cpp |
| 0028b040 | 56 | submitted | 2 | 0 | orch1_rec168_0028b040_v2.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 00288f60 and 00288fd8 were incorrectly ABI-blocked: root corrected that pure no-call/no-v0/no-f0 functions permit void under literal R4.3. Correction appended to PROGRESS; original evidence preserved; no reclaims. Root will issue separate FIX brief.
0028ae28 v1 link error corrected with extern C linkage; accepted signature types unchanged.
