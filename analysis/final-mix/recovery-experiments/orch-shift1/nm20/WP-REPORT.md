# nm20 report
Status: done
Worker: orch1-nm20, model GPT-6. Started 2026-10-14T16:15:04.7149329Z, ended 2026-10-14T16:16:55.0714890Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001b27f0 | 112 | blocked:address-materialization | 4 | 12 | orch1_nm20_001b27f0_v1.cpp |

Totals: 0 submitted, 1 blocked, 0 released.
Problems: No exact match. The complete differing-word count sequence was v1=12, v2=12, v3=12, v4=12; earliest best was v1. Three consecutive versions failed to lower the best count, so strict R7 stopped the target. The single named claim consumed K1; no replacement was claimed.

All four rec85 versions and proofs were read and independently recounted as 12,12,12,12 words. The approved lq/sq primitive, explicit argument-pointer computation, initialized numeric a0 binding, and empty guard did not improve the count. Every version compiled to 112 bytes. The original target stores 0x104 before 0x100, which the existing source already expressed. The queue confirmed the block. Detailed evidence and the next hypothesis are in 001b27f0-BLOCKED.md.