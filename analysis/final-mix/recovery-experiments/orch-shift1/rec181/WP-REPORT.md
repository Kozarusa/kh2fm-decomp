# rec181 report
Status: done
Worker: orch1-rec181, model GPT-6 inherited. Started 2026-10-18T12:37:00Z, ended 2026-10-18T13:01:02Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 002a00f0 | 120 | blocked:prologue-epilogue | 5 | 27 | orch1_rec181_002a00f0_v2.cpp |
| 002a1ec8 | 120 | blocked:address-materialization | 8 | 4 | orch1_rec181_002a1ec8_v8.cpp |
| 002a6308 | 92 | blocked:abi-layout | 0 | unavailable | none |
| 002a6878 | 112 | submitted | 3 | 0 | orch1_rec181_002a6878_v3.cpp |
| 002a74c0 | 108 | blocked:register-allocation | 5 | 2 | orch1_rec181_002a74c0_v2.cpp |
| 002a7678 | 92 | blocked:prologue-epilogue | 5 | 2 | orch1_rec181_002a7678_v2.cpp |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: Blocked 002a1ec8 v3/v7 guard source differences and probes were batched; output was buffered until after probing. Complete differences subsequently showed exactly one added guard site each. No submitted guards. Later guard edits were inspected in completed tool calls before separate probes. No remedy reprobes.
Initial PROGRESS write failed because the WP directory was absent; created only the assigned WP directory, then wrote PROGRESS. An early packet read failed while packet generation was still running; read the complete packet after generation finished. No files outside the assigned WP were written.
