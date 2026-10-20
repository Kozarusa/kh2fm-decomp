# rec158 progress
start 2026-10-16T14:28:46.6748442Z
claim 1 of 6: 002671e8 token 4f18c4ca09414f82bc5983fd2186484a attempts 1 blocker null
R4.3: a0 count selector; original every exit -1 or selected bit in v0. v1 baseline original; single control direct loop translation.
002671e8 v1: 9 words; best v1 9 words; streak 0. v2 baseline orch1_rec158_002671e8_v1.cpp; C11b only introduce one temporary, no guard/binding.
002671e8 v2: 2 words; best v2 2 words; streak 0. v3 baseline orch1_rec158_002671e8_v2.cpp; only empty index guard after increment scheduling control.
002671e8 v3: 2 words; best v2 2 words; streak 1. v4 baseline orch1_rec158_002671e8_v2.cpp; only empty bit/index dependency guard after increment.
002671e8 v4: 6 words; best v2 2 words; streak 2. v5 baseline orch1_rec158_002671e8_v4.cpp; C11c only binds bit t3, preserves guard.
002671e8 v5: 0 words; best v5 0 words; streak 0. R8 audit passed: one function, each binding/guard explained; all exits explicit.
submitted 002671e8 v5
claim 2 of 6: 00269ef8 token 8643b6c62d024929b3dd9f503ae198d0 attempts 1 blocker null
R4.3: no entry args; non-tail exit preserves acc8 result (zero), tail exit preserves abe0 result. v1 baseline original; single control direct conditional/tailcall translation.
00269ef8 v1: 0 words; best v1 0 words; streak 0. R8 audit passes one function/no asm, both outgoing results retained.
submitted 00269ef8 v1
claim 3 of 6: 0026e5b8 token 690404247d8541adba8212df8bfd538a attempts 1 blocker null
R4.3: a0 saved for call u64; every exit explicitly sets 1 or 0 after callees. v1 baseline original; single control switch translation.
0026e5b8 v1: 0 words; best v1 0 words; streak 0. R8 audit passes one function/no asm and explicit returns.
submitted 0026e5b8 v1
claim 4 of 6: 00271e08 token a5443cbd08c5446d9af392bd2178164b attempts 1 blocker null
R4.3: no inputs; each exit preserves most recent bc0/acc8/acb8/aa40 v0. v1 baseline original; single control nested conditional with returned result.
00271e08 v1: 0 words; best v1 0 words; streak 0. R8 audit passes one function/no asm and every callee result exit retained.
submitted 00271e08 v1
claim 5 of 6: 00273678 token 38ad593039c54bea9f6fb95ae9b09cda attempts 1 blocker null
R4.3: no arguments; final v0 getSaveRam preserved while store uses address separately. v1 baseline original; single control direct translation with callee return preserved.
00273678 v1: 9 words; best v1 9 words; streak 0. v2 baseline orch1_rec158_00273678_v1.cpp; C11b only introduce pointer temporary with original base offset.
00273678 v2: 5 words; best v2 5 words; streak 0. v3 baseline orch1_rec158_00273678_v2.cpp; C11a only swap independent addition operands to original shift-first.
00273678 v3: 6 words; best v2 5 words; streak 1. v4 baseline orch1_rec158_00273678_v2.cpp; C11b only introduce shifted offset temporary and consume it.
00273678 v4: 6 words; best v2 5 words; streak 2. v5 baseline orch1_rec158_00273678_v4.cpp; C11c only bind offset t7, no guard.
00273678 v5: 5 words; best v2 5 words; streak 3. R7 stop.
blocked 00273678 -> register-allocation
claim 6 of 6: 00275e08 token 9a5620dc1b284c79beb4d4e47ef1baed attempts 1 blocker null
R4.3: no args; exits preserve second d78 or tail510 result. Accepted oct7 declaration u32(...), rejects conflicting void accepted caller under literal rule. v1 baseline original; single control direct conditional/tailcall translation.
00275e08 v1: 0 words; best v1 0 words; streak 0. R8 audit passes one function/no asm and outgoing results retained.
submitted 00275e08 v1
R11 written 2026-10-16T14:34:22.9464443Z; K6 exhausted; root-owned review pending.
