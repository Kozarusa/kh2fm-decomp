# nm14 report
Status: done
Worker: orch1-nm14, model GPT-6. Started 2026-10-13T16:34:11Z, ended 2026-10-13T16:45:08Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0020cf60 | 88 | submitted | 3 | 0 | orch1_nm14_0020cf60_v3.cpp |
| 001b8988 | 72 | submitted | 2 | 0 | orch1_nm14_001b8988_v2.cpp |
| 001bdff0 | 108 | blocked:prologue-epilogue | 4 | 2 | orch1_nm14_001bdff0_v1.cpp |
| 001c05b0 | 100 | blocked:store-order | 4 | 2 | orch1_nm14_001c05b0_v1.cpp |
| 001bba88 | 52 | submitted | 3 | 0 | orch1_nm14_001bba88_v3.cpp |
| 001c0410 | 68 | submitted | 2 | 0 | orch1_nm14_001c0410_v2.cpp |

Totals: 4 submitted, 2 blocked, 0 released. Submitted code totals 280 bytes.
Problems: One initial v2 write command for 0020cf60 failed quoting before creating source or proof; the attempted probe reported the missing source. The source was then created directly and probed once. No compiler-error evidence or overwritten proof resulted. Literal $14 was initially omitted by shell expansion in the 001c05b0 BLOCKED report; corrected by direct write. All source bindings preserve literal registers.
Notes: 001b8988 first reached exact in v1; v2 retained exact after adopting its accepted sibling callee declaration. Both blocked targets obey R7 with earliest best v1 and streak 3. 001c05b0 v3 has correct instruction order with t6/t7 exchanged; its next hypothesis explicitly combines that guard with a $14 binding. No instruction-emitting assembly, integration, builds, outside-WP writes, or delegation occurred.
