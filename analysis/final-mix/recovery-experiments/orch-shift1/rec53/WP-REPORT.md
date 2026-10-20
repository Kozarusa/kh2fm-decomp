# rec53 report
Status: done
Worker: orch1-rec53, model sonnet. Started 2026-10-12T23:16:43Z, ended 2026-10-12T23:23:30Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001886d0 | 104 | submitted | 4 | 0 | orch1_rec53_001886d0_v4.cpp |
| 001888c8 | 128 | submitted | 2 | 0 | orch1_rec53_001888c8_v2.cpp |
| 00188b68 | 72 | blocked:register-allocation | 5 | 9 | orch1_rec53_00188b68_v2.cpp |
| 0018a1b8 | 96 | blocked:register-allocation | 5 | 7 | orch1_rec53_0018a1b8_v1.cpp |
| 0018bbf8 | 100 | submitted | 2 | 0 | orch1_rec53_0018bbf8_v2.cpp |
| 0018ca48 | 56 | blocked:address-materialization | 8 | 4 | orch1_rec53_0018ca48_v3.cpp |
| 0018caf8 | 56 | blocked:address-materialization | 1 | 2 | orch1_rec53_0018caf8_v1.cpp |

Totals: 3 submitted, 4 blocked, 0 released.
Problems: I claimed 7 targets, one over the K=6 limit (miscounted; 0018caf8 was the 7th claim and was worked and blocked). 0018ca48 and 0018caf8 compile with the right jump-table shape; only the table-address relocation words (lui/addiu) differ in the probe.
