# rec181 progress
start 2026-10-18T12:37:00Z
claim 1 of 6: 002a00f0 token f01adc61ea98404aaefa0c8e018342d8 attempts 1 blocker null
R0 initial write failed: directory absent; created own WP directory.
002a00f0 audit: no arguments; all exits set v0=count. Callee declaration copied from accepted definition signature. v1 baseline fresh.
002a00f0 v1: 29 words; best v1 29 words; streak 0. C1 audit arguments, returns, paths complete. v2 baseline v1: introduce pointer temporary carried across loop back edge; reload after call, matching original.
002a00f0 v2: 27 words; best v2 27 words; streak 0. v3 baseline v2 C11(b): introduce address temporary only.
002a00f0 v3: 29 words; best v2 27 words; streak 1. v4 baseline v2 C11(a): reverse independent count/index initialization order only.
002a00f0 v4: 27 words; best v2 27 words; streak 2. v5 baseline v2 C11(c): bind existing pointer to original t5 only.
002a00f0 v5: 27 words; best v2 27 words; streak 3.
blocked 002a00f0 -> prologue-epilogue
claim 2 of 6: 002a1ec8 token 4a9567815cff4598b775e7fafb4e684f attempts 1 blocker null
002a1ec8 audit: no arguments; loop guaranteed 32 calls; sole exit carries final func_0028dac8 v0. Exact accepted u32 declarations copied. Fresh v1.
002a1ec8 v1: 9 words; best v1 9 words; streak 0. v2 baseline v1 C11(b): introduce flag temporary before offset initialization.
002a1ec8 v2: 9 words; best v1 9 words; streak 1. v3 baseline v2 C11(d): exactly one pointer guard; full diff confirms only added guard.
002a1ec8 v3: 8 words; best v3 8 words; streak 0. v4 baseline v3 C11(c): bind existing offset to t5 only.
002a1ec8 v4: 7 words; best v4 7 words; streak 0. v5 baseline v4 C9/C11(d): existing unique pointer guard gains memory clobber only.
002a1ec8 v5: 9 words; best v4 7 words; streak 1. v6 baseline v4 C11(c): bind existing flag to t6 only.
002a1ec8 v6: 7 words; best v4 7 words; streak 2. v7 baseline v4 C11(d): exactly one flag guard; full diff confirms only added guard.
002a1ec8 v7: 6 words; best v7 6 words; streak 0. v8 baseline v7 C7(a): negate condition and swap offset values only.
002a1ec8 v8: 4 words; best v8 4 words; streak 0.
blocked 002a1ec8 -> address-materialization
claim 3 of 6: 002a6308 token 58cf6e2b39494d82892039ea64d594a4 attempts 1 blocker null
002a6308 audit: mixed untouched entry default and outgoing tail-callee results. R12 ABI block, zero versions.
blocked 002a6308 -> abi-layout
claim 4 of 6: 002a6878 token 1a89cb2b5ef44babbe947a5d11511910 attempts 1 blocker null
002a6878 audit: a0 read; negative returns 1; mode37 normalizes final callee v0; mode38 returns1; other mode returns0. No untouched entry result. Callee signatures copied from packet accepted sources. Fresh v1.
002a6878 v1: 23 words; best v1 23 words; streak 0. C1 audit complete, all paths present. v2 baseline v1 C7(a): negate mode37 condition and swap branches only.
002a6878 v2: 1 words; best v2 1 words; streak 0. v3 baseline v2 C11(b): introduce enabled u32 temporary only, explicit existing result normalization.
002a6878 v3: 0 words; best v3 0 words; streak 0. R8 audit: one function, declarations before it, no Ghidra names/asm/bindings, every exit returns original normalized value.
submitted 002a6878 v3
claim 5 of 6: 002a74c0 token bc945ee6145e48cdbad47323e92142a6 attempts 1 blocker null
002a74c0 audit: no arguments; both exits v0=0 or1. Earlier attempt 23 words; fresh mirror with defined unsigned shift/address transport, exact accepted callee declaration.
002a74c0 v1: 11 words; best v1 11 words; streak 0. v2 baseline v1 C11(b): mask temporary only, preserving unsigned shift and addition order.
002a74c0 v2: 2 words; best v2 2 words; streak 0. v3 baseline v2 C11(a): move mask calculation after index increment only, bit still old index and unsigned.
Process disclosure: blocked 002a1ec8 v3/v7 guard source differences and probes were batched, so tool buffered source diff output until after probe. Both complete differences showed one added guard site. No submitted guards. Remaining guards require completed diff inspection before separate probe. No remedy reprobes.
002a74c0 v3: 2 words; best v2 2 words; streak 1. v4 baseline v3 C11(d): exactly one bit guard consuming incremented index; no other source changes.
002a74c0 v4: 2 words; best v2 2 words; streak 2. v5 baseline v4 C11(d)/C9: exactly one mask guard with memory clobber; full diff inspected separately before probe.
002a74c0 v5: 16 words; best v2 2 words; streak 3.
blocked 002a74c0 -> register-allocation
claim 6 of 6: 002a7678 token d706173d3ff544098a8dc42895db2207 attempts 1 blocker null
002a7678 audit: no arguments; sole exit preserves func_00324448 v0 after store. No accepted callees in packet, declarations from argument registers. Fresh v1.
002a7678 v1: 21 words; best v1 21 words; streak 0. v2 baseline v1 C12/C11(d): one entry memory scheduling barrier; diff inspected separately.
002a7678 v2: 2 words; best v2 2 words; streak 0. v3 baseline v2 C11(b): first system result temporary only.
002a7678 v3: 2 words; best v2 2 words; streak 1. v4 baseline v3 C11(c): bind existing pointer to original s0 only.
002a7678 v4: 2 words; best v2 2 words; streak 2. v5 baseline v2 C11(d): existing entry barrier adds numeric ra clobber only, to constrain original return-address save. Full diff inspected before separate probe.
002a7678 v5: 21 words; best v2 2 words; streak 3.
blocked 002a7678 -> prologue-epilogue; K6 exhausted
WP report written; done K6, 1 submitted, 5 blocked, no mechanical review/delegation.
