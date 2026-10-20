# nm21 report
Status: done
Worker: orch1-nm21, model inherited GPT-6. Started 2026-10-15T03:46:11.2538278Z, ended 2026-10-15T03:48:40.8745242Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0022f528 | 120 | blocked:store-order | 4 | 2 | orch1_nm21_0022f528_v1.cpp |
| 00232110 | 60 | blocked:address-materialization | 4 | 2 | orch1_nm21_00232110_v1.cpp |

Totals: 0 submitted, 2 blocked, 0 released.
Problems: Initial progress-file creation failed because the WP directory did not exist; created the directory and progress file before probing. Both targets stopped after three consecutive versions failed to lower their best differing-word counts. No exact source was submitted.