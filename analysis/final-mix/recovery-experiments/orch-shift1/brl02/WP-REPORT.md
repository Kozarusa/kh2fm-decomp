# brl02 report
Status: partial
Worker: orch1-brl02, model opus. Started 2026-10-12T17:52:45Z, ended 2026-10-12T18:01:06Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0018dbd8 | 80 | submitted | 2 | 0 | orch1_brl02_0018dbd8_v2.cpp |
| 00108930 | 84 | submitted | 2 | 0 | orch1_brl02_00108930_v2.cpp |
| 00109788 | 96 | submitted | 4 | 0 | orch1_brl02_00109788_v4.cpp |
| 0011f270 | 128 | blocked:register-allocation | 4 | 2 | orch1_brl02_0011f270_v1.cpp |
| 0011f270 | 128 | released (re-served right after my block, claim 5) | 0 | - | - |
| 0011f270 | 128 | released (re-served again, claim 6) | 0 | - | - |

Totals: 3 submitted, 1 blocked, 2 released.
Problems: the register-allocation queue gave 0011f270 straight back to me twice after I blocked it (attempts 3 and 4). The brief forbids claiming it again, so I released both leases without doing any work, and they used up claims 5 and 6 of K=6.
Exact next step (only if partial or stopped): make the queue stop re-serving a blocked address to the worker that just blocked it, then give the two unused claims to another register-allocation target. 0011f270 needs only the addu operand order fixed (2 words, see brl02\0011f270-BLOCKED.md).
