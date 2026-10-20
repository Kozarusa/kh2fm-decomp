# rec182 progress
start 2026-10-18T12:37:30Z
claim 1 of 6: 002a0168 token 4812f9b3b5c14698ade21e350fabbfb1 attempts 1 blocker null
blocked 002a0168 -> abi-layout
claim 2 of 6: 002a0360 token dbbde8e8ca494f489a49230bedbc95ff attempts 1 blocker null
002a0360 R4.3: sole exit sets v0. v1 baseline fm_worker_b_round17_002a0360_v03.cpp; mandatory R4 corrections only: forbidden symbol asm/Ghidra names removed, decoded global and accepted callee declaration corrected.
002a0360 v1: 6 words; best v1 6 words; streak 0. v2 baseline v1; R4 semantic correction signed byte nonzero, not positive; sole change.
002a0360 v2: 5 words; best v2 5 words; streak 0. v3 baseline v2; C8 condition uses callee result as original movz; sole change.
002a0360 v3: 4 words; best v3 4 words; streak 0. v4 baseline v3; C10 remove inherited empty scheduling barrier; sole change.
002a0360 v4: 0 words; best v4 0 words; streak 0. R8 audit passed: sole v0 result, exact accepted declaration, no bindings/assembly, one function.
submitted 002a0360 v4
claim 3 of 6: 002a1c68 token 1c70eac140e644cbb0121c8316003a6d attempts 1 blocker null
002a1c68 R4.3 audit: early exit preserves s64 func_00292630 result; normal exit preserves func_00293d80 result. v1 fresh instruction mirror, accepted callee signatures copied.
002a1c68 v1: 9 words; best v1 9 words; streak 0. v2 baseline v1; C1/C20 retain word-result sign extension into s64 instead of zero extension; sole change.
002a1c68 v2: 8 words; best v2 8 words; streak 0. R12 ABI-width block.
blocked 002a1c68 -> abi-layout
claim 4 of 6: 002a1f40 token afcb043af9604fbd9e5e04b2fe01f83c attempts 1 blocker null
blocked 002a1f40 -> boundary-review
claim 5 of 6: 002a4990 token 1b64d35cd95941bebe229b85ac4460b3 attempts 1 blocker null
002a4990 R4.3 sole exit returns index v0; fresh v1 mirrors loop and signed divide; address transport unsigned.
002a4990 v1: 0 words; best v1 0 words; streak 0. R8 audit passed: one function, no asm/bindings, defined unsigned address/sum transport, signed /8, index result.
submitted 002a4990 v1
claim 6 of 6: 002a6290 token b9f4c422ad9147fead223934f7d3a8d6 attempts 1 blocker null
002a6290 R4.3: sole epilogue assigns count to v0. Fresh v1 instruction mirror. Accepted bool func_002944d0(void*) copied; packet-named func_002a6368 source has definition int func_002a6368(int param_1), no separate declaration; signature used verbatim types.
002a6290 v1: 29 words; best v1 29 words; streak 0. v2 baseline v1; C1 share global-pointer load between bottom test and next iteration using one pointer temporary; no binding/guard.
002a6290 v2: 27 words; best v2 27 words; streak 0. v3 baseline v2; C11 introduce global-address temporary only; no binding/guard.
002a6290 v3: 29 words; best v2 27 words; streak 1. v4 baseline v3; C11 bind existing global temporary to original s2 only; no guard.
002a6290 v4: 26 words; best v4 26 words; streak 0. v5 baseline v4; C11 insert exactly one global-address guard before unique first pointer load. Complete source diff inspected: one added guard site, no other changes.
002a6290 v5: 27 words; best v4 26 words; streak 1. v6 baseline v4; C5 express original rounded high-address base with unsigned integer transport instead of full-address pointer; retain existing binding, no guard.
002a6290 v6: 32 words; best v4 26 words; streak 2. v7 baseline v4; C11 reorder count initialization after first pointer load only; binding retained, no guard.
002a6290 v7: 26 words; best v4 26 words; streak 3. Stop strict R7.
blocked 002a6290 -> prologue-epilogue; K6 reached
