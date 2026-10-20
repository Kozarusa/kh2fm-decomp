# rec177 progress
start 2026-10-18T02:17:42Z
claim 1 of 6: 002944f8 token af1f359af9fc49f8a4e20599f23570b2 attempts 1
002944f8 R4.3: no parameters; final callee v0 flows through sole exit, return u32. R4.5: no packet accepted declarations. v1 baseline original instructions.
002944f8 v1: 15 words; best v1 15 words; streak 0. First diff 6 C12 prologue scheduling. v2 baseline orch1_rec177_002944f8_v1.cpp: C11b introduce first call temporary only.
002944f8 v2: 15 words; best v1 15 words; streak 1. First diff 6. v3 baseline orch1_rec177_002944f8_v2.cpp: C10d one memory guard after zero stores.
002944f8 v3: 18 words; best v1 15 words; streak 2. First diff 3. v4 baseline orch1_rec177_002944f8_v1.cpp: C10c make first global volatile only.
002944f8 v4: 15 words; best v1 15 words; streak 3.
blocked 002944f8 -> prologue-epilogue
claim 2 of 6: 00294f00 token 286652c4213542568c7bf308682be6fb attempts 1
00294f00 R4.3 audit: mixed entry registers and outgoing callee results; zero-version R12 ABI block.
blocked 00294f00 -> abi-layout
claim 3 of 6: 002953c8 token d78a142ee757423392248f2e8ae4f0d5 attempts 1
002953c8 R4.3: a0 full word value; every exit returns computed v0 pointer. R4.5 copied u32 func_00294000(u32) from packet accepted calltransport source. v1 baseline original; unsigned shift/address transport.
002953c8 v1: 18 words; best v1 18 words; streak 0. First diff 6 C11. v2 baseline orch1_rec177_002953c8_v1.cpp: C11c bind offset to initialized $2 only.
002953c8 v2: 22 words; best v1 18 words; streak 1. C1 audit confirms return and argument paths. v3 baseline orch1_rec177_002953c8_v1.cpp: C7c put zero offset assignment in else only.
002953c8 v3: 18 words; best v1 18 words; streak 2. v4 baseline orch1_rec177_002953c8_v1.cpp: C11d add one guard after loop-head offset assignment.
002953c8 v4: 18 words; best v1 18 words; streak 3.
blocked 002953c8 -> register-allocation
claim 4 of 6: 00298f90 token e7888296566a457391a76e4a5b511818 attempts 1
00298f90 R4.3: no entry arguments; every exit carries last 00293d80 v0, return u32. R4.5 copied u32 func_0023fad0(...) exactly from packet accepted 0023f8c8 source. v1 baseline original.
00298f90 v1: 0 words; best v1 0 words; streak 0. R8 manual source audit passed; one function, no bindings/asm, literal R4.3 and exact R4.5 declarations.
submitted 00298f90 v1
claim 5 of 6: 00299550 token e60586d1514f42eca4ab89f5e615bb16 attempts 1
00299550 R4.3: mixed untouched-entry null path and outgoing indirect callee result path; zero-version R12 block.
blocked 00299550 -> abi-layout
claim 6 of 6: 0029a368 token 7d6cb3d60b3b40a4ab4089991f167bee attempts 1
0029a368 R4.3: mixed untouched-entry and outgoing callee results; zero-version R12 ABI block.
blocked 0029a368 -> abi-layout; claim limit 6 reached
R11 WP-REPORT.md written; done 2026-10-18T02:21:59Z.
