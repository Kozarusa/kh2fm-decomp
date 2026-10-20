# rec27 report
Status: done
Worker: orch1-rec27, model sonnet. Started 2026-10-12T21:10:01Z, ended 2026-10-12T22:00:00Z (approximate).

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001616f0 | 124 | submitted | 8 | 0 | orch1_rec27_001616f0_v8.cpp |
| 00161770 | 88 | blocked:register-allocation | 8 | 2 | orch1_rec27_00161770_v5.cpp |
| 00162bb0 | 116 | blocked:vu-macro | 0 | n/a | none |
| 00165830 | 64 | submitted | 5 | 0 | orch1_rec27_00165830_v5.cpp |
| 00165968 | 80 | blocked:register-allocation | 7 | 11 | orch1_rec27_00165968_v4.cpp |
| 001659b8 | 88 | submitted | 3 | 0 | orch1_rec27_001659b8_v3.cpp |
| 00165ef0 | 52 | released | 0 | n/a | none |

Totals: 3 submitted, 3 blocked, 1 released.
Problems: I claimed a 7th target (00165ef0) after already resolving 6 (K=6) and released it unworked at once. The packet and diff tools hide five zero (nop) words at 00165980-00165990 of 00165968; they show only in verification.json target_hex.
