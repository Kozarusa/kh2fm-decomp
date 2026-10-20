# fix01 progress
start 2026-10-17T07:02:57Z
claim 1 of 3: 00285d18 token 2f7b42e7098f490abc986506fa685c01 attempts 2 blocker null
00285d18 packet, review, source, proof and full diff read. R4.3: explicit zero on negative sentinel/exhaustion; one on match; s32 argument a0. R4.5: no callees. Copied unchanged rec164 v5 to v1.
00285d18 v1: 0 words; best v1 0 words; streak 0. R8 audit passed: one function, no assembly/bindings, explicit all-exit returns, no callees.
submitted 00285d18 v1
claim 2 of 3: 002865d0 token 2a54123970e04150be36af36e1f1076f attempts 2 blocker null
002865d0 packet, preserved source/proof/full diff and all five accepted callers read. Baseline copied unchanged. R4.3: original only exit retains callee v0 plus 204 through both store paths; source returns result. R4.5 correction required: copy s32(void) from 00272a00.
002865d0 v1: 0 words; best v1 0 words; streak 0. Baseline not submitted due known R4.5 mismatch. v2 changes only callee declaration return token u32 to s32; complete source/diff inspected; all controls, bindings and why comments unchanged.
002865d0 v2: 0 words; best v1 0 words; streak 1. R8 audit passed: one function, exact accepted s32(void) declaration, initialized numeric binding and empty guard each retaining why comment, explicit adjusted callee result on every exit.
submitted 002865d0 v2
claim 3 of 3: 00287430 token 3a4cb872ef634e3eb54c1b22a8fe6353 attempts 2 blocker null
00287430 packet, preserved source/proof/full diff read; same five accepted caller sources already read completely for 002865d0. R4.3: a0/a1 s32 inputs; call initializes result v0 then adds 164 and every conditional-store path preserves return. No f0 result. R4.5 requires s32(void) exact declaration from 00272a00. Copied rec164 v4 unchanged to v1.
00287430 v1: 0 words; best v1 0 words; streak 0. Baseline not submitted due known R4.5 mismatch. v2 changes only callee return declaration token u32 to s32; complete source/diff inspected; all controls, operands, bindings, guards and why comments retained.
00287430 v2: 0 words; best v1 0 words; streak 1. R8 audit passed: one function, exact accepted s32(void) declaration, call-initialized numeric result binding and empty guard each retaining its own why comment; no emitted instructions; explicit adjusted callee return on every exit.
submitted 00287430 v2
K3 claim attempts exhausted: all three named targets submitted; no further claims or versions authorized.
WP-REPORT.md written; independent mechanical and source review required before integration.
