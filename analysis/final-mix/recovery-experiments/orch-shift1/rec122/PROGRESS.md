# rec122 progress
start 2026-10-13T07:23:38Z
claim 1 of 6: 001e3590 token 3611061a661c4f8f9d5f4138cc1381e1 attempts 1
v1: 2 words, first diff at 4: jump table reloc
001e3590 v1: 2 words; best v1 2 words; streak 0
blocked 001e3590 -> address-materialization
claim 2 of 6: 001e3898 token cb454bf33e9343cdb25ca6cbe91f2cd9 attempts 1
v1: 20 words, first diff 5: C1/R4.5 -> callee returns pointer
001e3898 v1: 20 words; best v1 20; streak 0
v2: 15 words, first diff 5: C7 -> outer do-while
001e3898 v2: 15 words; best v2 15; streak 0
v3: 17 words, first diff 6: C11(b) -> separate inner counter
001e3898 v3: 17 words; best v2 15; streak 1
v4: 0 words
submitted 001e3898 v4
claim 3 of 6: 001e41e0 token de6be2f140c4400b9c7f3659f58d6de8 attempts 1
v1: 23 words, first diff 1: C13 tail call -> barrier after last call
001e41e0 v1: 23 words; best v1 23; streak 0
v2: 24 words, first diff 1: barrier made jal but same regs
001e41e0 v2: 24 words; best v1 23; streak 1
v3: 8 words, first diff 1: copy prior attempt style
001e41e0 v3: 8 words; best v3 8; streak 0
v4: 24 words (void* types worse)
001e41e0 v4: 24 words; best v3 8; streak 1
v5: 24 words
001e41e0 v5: 24 words; best v3 8; streak 2
v6: 24 words
001e41e0 v6: 24 words; best v3 8; streak 3
blocked 001e41e0 -> store-order
claim 4 of 6: 001e6688 token 31141f50baea4a4f96689c432554245b attempts 1
v1: 20 words, first diff 0: C13 tail call -> barrier after last call
001e6688 v1: 20 words; best v1 20; streak 0
v2: 15 words, first diff 0: C10(c) volatile stores next
001e6688 v2: 15 words; best v2 15; streak 0
v3: 9 words, first diff 0: C11(b) scalar+pointer forms next
001e6688 v3: 9 words; best v3 9; streak 0
v4: 9 words (scalar/pointer, same)
001e6688 v4: 9 words; best v3 9; streak 1
v5: 17 words
001e6688 v5: 17 words; best v3 9; streak 2
v6: 14 words
001e6688 v6: 14 words; best v3 9; streak 3
blocked 001e6688 -> store-order
claim 5 of 6: 001e7538 token 85759af4361744fdbcdc81f2d1579f04 attempts 1
v1: 4 words, first diff 6: C2-ish -> state to u32
001e7538 v1: 4 words; best v1 4; streak 0
v2: 4 words (u32 state same)
001e7538 v2: 4 words; best v1 4; streak 1
v3: 4 words (> 0 same)
001e7538 v3: 4 words; best v1 4; streak 2
v4: compile error (stray backtick-n)
001e7538 v4: compile error; best v1 4; streak 3
blocked 001e7538 -> branch-layout
claim 6 of 6: 001e7798 token 8a1feba156714d158133705670e53e22 attempts 1
v1: 28 words, first diff 1: C7(b)/(c) merge join -> next
001e7798 v1: 28 words; best v1 28; streak 0
v2: 28 words, first diff 1: C10(d) barrier after flag store
001e7798 v2: 28 words; best v1 28; streak 1
v3: 25 words, first diff 4: C10(d) barrier after size store
001e7798 v3: 25 words; best v3 25; streak 0
v4: 20 words, first diff 0: C11(b) reuse body var for next
001e7798 v4: 20 words; best v4 20; streak 0
v5: 0 words
submitted 001e7798 v5
WP report written
