# nm19 report
Status: partial
Worker: orch1-nm19, model GPT-6 inherited. Started 2026-10-14T01:44:47.633394+00:00, ended 2026-10-14T01:46:29.659171+00:00.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001b27f0 | 112 | unavailable | 0 | n/a | none |
| 001b7df0 | 120 | submitted | 4 | 0 | orch1_nm19_001b7df0_v4.cpp |

Totals: 1 submitted, 0 blocked, 0 released.
Problems: The named 001b27f0 claim returned no lease because the brief listed stale register-allocation queue metadata. The parent confirmed the address is ready in store-order and instructed no third claim. Both named claim attempts counted toward K.
Version sequence for 001b7df0: v1 3 words, v2 3 words, v3 3 words, v4 0 words. The earliest best source is orch1_nm19_001b7df0_v4.cpp, with exact proof 1/1 and equal 120-byte size. Queue submission succeeded.
Exact next step (only if partial or stopped): A fresh authorized WP can retry 001b27f0 using its current store-order queue.
