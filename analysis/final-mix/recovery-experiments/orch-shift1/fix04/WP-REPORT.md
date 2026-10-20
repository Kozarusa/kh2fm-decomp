# fix04 report
Status: done
Worker: orch1-fix04, model GPT-6 inherited. Started 2026-10-17T21:26:10Z, ended 2026-10-17T21:27:59Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00292a58 | 56 | submitted | 2 | 0 | orch1_fix04_00292a58_v2.cpp |

Totals: 1 submitted, 0 blocked, 0 released.
Problems: none. Rejected exact v1 was never submitted; v2 corrects signed-shift undefined behavior while preserving signed word argument transport. Complete source diff and all-pattern domain audit: 00292a58-SEMANTICS.md.
