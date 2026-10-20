# rec139 report
Status: done
Worker: orch1-rec139, model GPT-6 inherited. Started 2026-10-15T01:02:47.2429501Z, ended 2026-10-15T01:11:32.8560140Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00232db0 | 100 | blocked:register-allocation | 8 | 15 | orch1_rec139_00232db0_v5.cpp |
| 00233410 | 124 | blocked:vu-macro | 0 | N/A | None; R3 blocked before source creation |
| 002338a8 | 116 | blocked:address-materialization | 6 | 26 | orch1_rec139_002338a8_v3.cpp |
| 00234098 | 84 | blocked:store-order | 8 | 8 | orch1_rec139_00234098_v6.cpp |
| 002341e8 | 84 | blocked:store-order | 8 | 4 | orch1_rec139_002341e8_v8.cpp |
| 00234298 | 88 | blocked:store-order | 8 | 4 | orch1_rec139_00234298_v7.cpp |

Totals: 0 submitted, 6 blocked, 0 released.
Problems: No exact matches. All six claims were consumed; no seventh claim was made. The VU target had no packet-supported accepted sibling for its sqc2 vf0 sequence. Targets 00232db0 and 002338a8 reached a three-version non-improvement streak; the remaining attempted targets reached the eight-version ceiling. Every target has a blocked report naming its earliest best source, count, and complete streak sequence. No shared files were edited.