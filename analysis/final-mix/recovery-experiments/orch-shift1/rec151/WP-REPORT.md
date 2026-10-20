# rec151 report
Status: done
Worker: orch1-rec151, model GPT-6 inherited. Started 2026-10-15T20:23:41Z, ended 2026-10-15T20:28:31Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002519d0 | 52 | submitted | 1 | 0 | orch1_rec151_002519d0_v1.cpp |
| 00251e90 | 52 | submitted | 1 | 0 | orch1_rec151_00251e90_v1.cpp |
| 00251ec8 | 116 | blocked:abi-layout | 0 | N/A | none |
| 00252020 | 116 | blocked:abi-layout | 0 | N/A | none |
| 00252618 | 72 | submitted | 2 | 0 | orch1_rec151_00252618_v2.cpp |
| 00252710 | 76 | blocked:branch-layout | 5 | 8 | orch1_rec151_00252710_v2.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: Two fresh targets leave null-path entry v0 untouched; conservative R12 blocks preserve return contracts without void, invented zero, or prohibited fresh-v1 assembly. Read rec150 REVIEW for analogous contract. 0024eff8 was not served.
