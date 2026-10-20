# rec28 progress
start 2026-10-12T21:21:41Z
claim 00166880 token e1fd68a951c04edfa55814ba0fd786bf attempts 1
v1: 7 words, first diff 14: C10 -> next: asm memory barriers
v2: 12 words, first diff 2: barriers worsened regalloc -> next: volatile stores
v3: 7 words, first diff 21 (epilogue ld interleaved): C10c -> next: trailing barrier
v4: 2 words, first diff 23 (s1/s0 restore order): trailing barrier -> next: barrier mid
v5: 7 words worse -> next: sb non-volatile with trailing barrier
v6: 4 words -> next: plain stores + trailing barrier
blocked 00166880 -> prologue-epilogue
claim 001675b0 token 01ffd827367340ea92180fafbe8ee068 attempts 1 (claim 2 of 6)
claim2 v1: 23 words, first diff 3: C9 -> next: volatile globals
claim2 v2: compile error (my edit mangled) -> v3 volatile globals
claim2 v3: 23 words, volatile no effect -> v4 asm +r pointers
claim2 v4: 9 words -> v5 sequential single pointer
submitted 001675b0 v5
claim 00167b08 token 1d5cca6c0a2646c4aca0498f28bc84ba attempts 1 (claim 3 of 6)
claim3 v1: 1 word slt vs sltu -> v2 s32 pointer
submitted 00167b08 v2
claim 00167b98 token de249fd6fe274851abcf0607738b3b0a attempts 1 (claim 4 of 6)
submitted 00167b98 v1
claim 00167f38 token 9adbbfca6fc54a9c9dbe560513f61e6b attempts 1 (claim 5 of 6)
submitted 00167f38 v1
claim 00167fc8 token 7ff407b137d84d24a093f1e8f92d2de8 attempts 1 (claim 6 of 6)
claim6 v1: 10 words -> v2 reorder reads/stores
claim6 v2: 10 words same -> v3 barrier
claim6 v3: 5 words (ra load placement) -> v4 volatile counter store
claim6 v4: 11 words worse -> v5 two barriers
claim6 v5: 7 words -> v6 Ghidra-order source
blocked 00167fc8 -> store-order
