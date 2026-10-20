# rec120 report
Status: done
Worker: orch1-rec120, model sonnet. Started 2026-10-13T07:08:39Z, ended 2026-10-13T07:13:22Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001e2660 | 84 | blocked:branch-layout | 7 | 3 | orch1_rec120_001e2660_v4.cpp |
| 001e2788 | 52 | submitted | 4 | 0 | orch1_rec120_001e2788_v4.cpp |
| 001e27c0 | 52 | submitted | 1 | 0 | orch1_rec120_001e27c0_v1.cpp |
| 001e29e0 | 112 | submitted | 3 | 0 | orch1_rec120_001e29e0_v3.cpp |
| 001e2ad8 | 116 | blocked:privileged-instructions | 1 | 3 | orch1_rec120_001e2ad8_v1.cpp |
| 001e2c00 | 92 | blocked:privileged-instructions | 1 | 11 | orch1_rec120_001e2c00_v1.cpp |

Totals: 3 submitted, 3 blocked, 0 released.
Problems: 001e2ad8 and 001e2c00 end in 'break 0' (assert-style trap); __builtin_trap emits 'teq', so they were blocked after one version rather than using forbidden asm. Specialty chosen is an approximation (no break-specific specialty exists).
