# rec171 progress
start 2026-10-17T17:32:19Z
Ultracave skill applied.
claim 1 of 6: 0028cf28 token 1fc7a2e0f717485a877278631df89414 attempts 1 blocker null
0028cf28 R4.3 audit: first/second BeginLeave results propagate to shared return; tail SetFlag result propagates. No entry-result path. R4.5 declarations copied from fm_primary_capacity_recovered_00303c48.cpp. v1 baseline original packet; direct scalar translation.
0028cf28 v1: 0 words; best v1 0 words; streak 0
R8 audit: all exit results preserved; accepted callee declarations exact; one function, no assembly/bindings/Ghidra names.
submitted 0028cf28 v1
claim 2 of 6: 0028d068 token 2efceba790f142be9c26d2af8e326196 attempts 1 blocker null
0028d068 R4.3 audit: pure leaf, no v0/f0 writes or outgoing callee result; void permitted. v1 baseline packet; direct loop translation with volatile globals to preserve repeated loads.
0028d068 v1: 5 words; best v1 5 words; streak 0
v1: 5 words, first diff at 3: C11(a) -> next: move count initialization inside positive-count branch. v2 baseline orch1_rec171_0028d068_v1.cpp; full source diff only relocation of count declaration; volatility/operands/conditions preserved.
0028d068 v2: 4 words; best v2 4 words; streak 0
v2: 4 words, first diff at 5: C11(c) -> next bind count to $13. v3 baseline orch1_rec171_0028d068_v2.cpp; full source diff only count register binding and its why comment.
0028d068 v3: 10 words; best v2 4 words; streak 1
v3: 10 words, first diff at 5: C11(d) -> next count guard. v4 baseline orch1_rec171_0028d068_v2.cpp; full source diff only one empty count guard after initialization, no bindings or other changes.
0028d068 v4: 2 words; best v4 2 words; streak 0
v4: 2 words, first diff at 15: C7(a) -> next negate loop exit. v5 baseline orch1_rec171_0028d068_v4.cpp; full source diff only do-while condition converted to unconditional loop and negated break, preserving body and guard.
0028d068 v5: 2 words; best v4 2 words; streak 1
v5: 2 words, first diff at 15: C9 -> next nonvolatile pointer global; aliasing store still requires reload. v6 baseline orch1_rec171_0028d068_v4.cpp; full source diff only removal of pointer-global volatile qualifier, guard/operands/condition preserved.
0028d068 v6: 14 words; best v4 2 words; streak 2
v6: 14 words, first diff at 2: C11(b) -> next explicit loop pointer temporary with conditional reload. v7 baseline orch1_rec171_0028d068_v4.cpp; full source diff only introduction of initialized pointer temporary and transport of same volatile reload to continuation expression; count guard/conditions/operands preserved.
0028d068 v7: 25 words; best v4 2 words; streak 3
blocked 0028d068 -> branch-layout
claim 3 of 6: 0028dd90 token df53f0e6ee184afcb29bdac5dff3a954 attempts 1 blocker null
0028dd90 R4.3 audit: every exit sets v0 (0,1,2), s32 return. v1 baseline packet; modulus and ordered conditional translation.
0028dd90 v1: 11 words; best v1 11 words; streak 0
v1: 11 words, first diff at 1: C1 audit passed exits/arguments; C7(c) -> next switch conditional layout. v2 baseline orch1_rec171_0028dd90_v1.cpp; full source diff only conditional chain replaced with switch on unchanged remainder, values preserved.
0028dd90 v2: 6 words; best v2 6 words; streak 0
v2: 6 words, first diff at 8: C7(c) -> next explicit zero case in switch. v3 baseline orch1_rec171_0028dd90_v2.cpp; full source diff only explicit case 0 break, preserving return values.
0028dd90 v3: 0 words; best v3 0 words; streak 0
R8 audit: all returns set 0/1/2; one function, no asm/bindings/Ghidra names; break trap compiler-generated.
submitted 0028dd90 v3
claim 4 of 6: 0028e350 token df2b67bc4edf4e919291230ea0738958 attempts 1 blocker null
0028e350 literal R4.3 audit: null path preserves entry v0/f0; nonnull path propagates final 00106450 result. Mixed entry/callee-result contract unresolved; zero-version R12 ABI block.
blocked 0028e350 -> abi-layout
claim 5 of 6: 0028e5e0 token e4bfe6ae731b4a0cbc8cc346fcfd1a25 attempts 1 blocker null
0028e5e0 R4.3 audit: initial callee result propagates if count<=0; last loop callee result otherwise. u32 result preserved. R4.5 declarations copied exactly from packet-named fm_primary_close_recovered.cpp and fm_primary_threeword_recovered_0028e710.cpp. v1 baseline packet direct pointer loop.
0028e5e0 v1: 0 words; best v1 0 words; streak 0
R8 audit: all exit callee results preserved; declarations exact; no asm/bindings/Ghidra names; one function.
submitted 0028e5e0 v1
claim 6 of 6: 0028eb88 token 45ebacd6a1c842519a273fe344a855b7 attempts 1 blocker null
0028eb88 R4.3 audit: outgoing 00139d78 v0 untouched by following float stores; return u32 callee result. f12/f13 two float parameters. R4.5 exact declaration from packet-named fm_primary_close_recovered.cpp. v1 baseline packet direct two-store translation.
0028eb88 v1: 16 words; best v1 16 words; streak 0
v1: 16 words, first diff at 3: C1 audit passes all exits/args; C9 missing second pointer reload -> next volatile field reads. v2 baseline orch1_rec171_0028eb88_v1.cpp; full source diff only volatile pointer-field access type at both uses; stores and operands unchanged.
0028eb88 v2: 13 words; best v2 13 words; streak 0
v2: 13 words, first diff at 3: C11(a) statement reorder already store original; C10(c) -> next volatile float stores to keep read/store order. v3 baseline orch1_rec171_0028eb88_v2.cpp; full source diff only float store access qualifier at both stores; field volatility preserved.
0028eb88 v3: 0 words; best v3 0 words; streak 0
R8 audit: outgoing callee result preserved; two float params correctly ordered; accepted declaration exact; one function no asm/bindings/Ghidra names.
submitted 0028eb88 v3
K6 reached. No further claims.
