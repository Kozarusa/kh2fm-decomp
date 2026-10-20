# rec121 report
Status: done
Worker: orch1-rec121, model sonnet. Started 2026-10-13T07:23:38Z, ended 2026-10-13T07:27:56Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001e3468 | 116 | submitted | 1 | 0 | orch1_rec121_001e3468_v1.cpp |
| 001e35f0 | 96 | blocked:address-materialization | 1 | 2 | orch1_rec121_001e35f0_v1.cpp |
| 001e3c18 | 128 | blocked:register-allocation | 5 | 25 | orch1_rec121_001e3c18_v1.cpp |
| 001e60b0 | 80 | submitted | 1 | 0 | orch1_rec121_001e60b0_v1.cpp |
| 001e65d0 | 96 | submitted | 2 | 0 | orch1_rec121_001e65d0_v2.cpp |
| 001e7470 | 104 | blocked:store-order | 4 | 3 | orch1_rec121_001e7470_v1.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 001e35f0 was blocked after one version because only the switch jump-table address (lui/addiu, link-time relocation of D_0036eb28) differs, which source cannot control; one version (v4) of 001e3c18 was a compile error from a bad generated source.
