# rec131 report
Status: done
Worker: orch1-rec131, model sonnet. Started 2026-10-13T08:37:59Z, ended 2026-10-13T08:55:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0021f5d8 | 72 | submitted | 4 | 0 | orch1_rec131_0021f5d8_v4.cpp |
| 00220c88 | 104 | submitted | 4 | 0 | orch1_rec131_00220c88_v4.cpp |
| 00222898 | 128 | blocked:vu-macro | 0 | 0 | none (not probed, R3 VU condition) |
| 002233f0 | 88 | blocked:privileged-instructions | 2 | 1 | orch1_rec131_002233f0_v2.cpp |
| 00223448 | 116 | blocked:privileged-instructions | 4 | 3 | orch1_rec131_00223448_v1.cpp |
| 00224780 | 88 | submitted | 2 | 0 | orch1_rec131_00224780_v2.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: none. Notes: 002233f0 and 00223448 differ from the original in the trap word (break vs teq from __builtin_trap), 00223448 also in two argument move orders. 00222898 blocked without a probe, so its Best words and File columns are placeholders (0 and none).
