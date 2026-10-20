# rec191 progress
start 2026-10-20T01:45:47Z
claim 1 of 6: 002b81b8 token c946e81312234c7783f1636d1d309f53 attempts 1
002b81b8 v1 baseline: fresh packet reconstruction; control: frame-address volatile argument stores
v1: 10 words, first diff at 0: C1 -> next: add 16-byte argument area frame constraint
002b81b8 v1: 10 words; best v1 10 words; streak 0
002b81b8 v2 baseline: v1; control: add 16-byte argument area frame constraint
v2: 8 words, first diff at 2: C19 -> next: explicit accepted frame transport
002b81b8 v2: 8 words; best v2 8 words; streak 0
002b81b8 v3 baseline: v2; control: replace builtin frame address with explicit accepted frame transport
v3: 9 words, first diff at 4: C11 -> next: bind zero result to t7
002b81b8 v3: 9 words; best v2 8 words; streak 1
002b81b8 v4 baseline: v3; control: bind zero result to t7
v4: 9 words, first diff at 4: C11 -> next: guard t7 result binding
002b81b8 v4: 9 words; best v2 8 words; streak 2
002b81b8 v5 baseline: v4; control: add empty guard for t7 result binding
v5: 9 words, first diff at 4: C11 -> next: preserve frame transport and delay result after final store
002b81b8 v5: 9 words; best v2 8 words; streak 3
blocked 002b81b8 -> abi-layout
claim 2 of 6: 002b82f8 token 181a639c9d6640cf9558d5ff9ea1637c attempts 1
002b82f8 v1 baseline: fresh packet reconstruction; control: volatile loop result with eight-argument call
v1: 28 words, first diff at 1: C1 -> next: add ninth stack argument required by original store
002b82f8 v1: 28 words; best v1 28 words; streak 0
002b82f8 v2 baseline: v1; control: add ninth zero stack argument
v2: 30 words, first diff at 0: C1 -> next: use SDK variadic callee declaration
002b82f8 v2: 30 words; best v1 28 words; streak 1
002b82f8 v3 baseline: v2; control: replace fixed callee declaration with SDK variadic contract
v3: 30 words, first diff at 0: C19 -> next: explicit accepted frame transport
002b82f8 v3: 30 words; best v1 28 words; streak 2
002b82f8 v4 baseline: v3; control: add explicit accepted frame transport
v4: 28 words, first diff at 0: C12 -> next: eliminate s0/s1 loop-invariant address caching without changing frame transport
002b82f8 v4: 28 words; best v1 28 words; streak 3
blocked 002b82f8 -> prologue-epilogue
claim 3 of 6: 002b8984 token 75c7c2d8364947bf88d7af0c8449ad79 attempts 1
002b8984 v1 baseline: fresh packet reconstruction; control: explicit frame payload preserving original loads and stores
v1: 23 words, first diff at 0: C1 -> next: remove leading argument-area constraint
002b8984 v1: 23 words; best v1 23 words; streak 0
002b8984 v2 baseline: v1; control: remove argument-area constraint
v2: 23 words, first diff at 0: C11 -> next: remove guarded t7 result transport
002b8984 v2: 23 words; best v1 23 words; streak 1
002b8984 v3 baseline: v1; control: remove guarded t7 result transport
v3: 23 words, first diff at 0: C10 -> next: add memory barrier after argument stores
002b8984 v3: 23 words; best v1 23 words; streak 2
002b8984 v4 baseline: v3; control: add memory barrier after argument stores
v4: 24 words, first diff at 0: C12 -> next: move frame-transport trigger after compiler prologue without leading nop
002b8984 v4: 24 words; best v1 23 words; streak 3
blocked 002b8984 -> prologue-epilogue
claim 4 of 6: 002b99a0 token 7c4c695c6e584262b241d4087cdf7db8 attempts 1
002b99a0 v1 baseline: fresh packet reconstruction; control: accepted explicit frame transport and restoration
v1: 6 words, first diff at 4: C11 -> next: bind result to t7
002b99a0 v1: 6 words; best v1 6 words; streak 0
002b99a0 v2 baseline: v1; control: bind global result to t7
v2: 5 words, first diff at 3: C11 -> next: bind returned copy to v0 before frame restoration
002b99a0 v2: 5 words; best v2 5 words; streak 0
002b99a0 v3 baseline: v2; control: bind returned copy to v0 and feed frame restoration
v3: 2 words, first diff at 3: C11 -> next: bind global address formation to t7
002b99a0 v3: 2 words; best v3 2 words; streak 0
002b99a0 v4 baseline: v3; control: bind global address formation to t7
v4: 2 words, first diff at 3: C11 -> next: guard t7 pointer binding
002b99a0 v4: 2 words; best v3 2 words; streak 1
002b99a0 v5 baseline: v4; control: guard t7 pointer binding
v5: 7 words, first diff at 4: C11 -> next: make global read volatile while retaining result bindings
002b99a0 v5: 7 words; best v3 2 words; streak 2
002b99a0 v6 baseline: v3; control: make global read volatile
v6: 2 words, first diff at 3: C11 -> next: force relocation base and loaded result to share t7 without instruction-emitting asm
002b99a0 v6: 2 words; best v3 2 words; streak 3
blocked 002b99a0 -> register-allocation
claim 5 of 6: 002b9b78 token 2279d326f16a497b92ea207b1d3cec63 attempts 1
002b9b78 v1 baseline: fresh packet reconstruction; control: four calls with final result tail-returned
002b9b78 v1: 0 words; best v1 0 words; streak 0
submitted 002b9b78 v1
claim 6 of 6: 002b9e80 token 1b3bab66514e4888b2e4e07f173f49d5 attempts 1
002b9e80 v1 baseline: fresh packet reconstruction; control: six calls with final result tail-returned
002b9e80 v1: 0 words; best v1 0 words; streak 0
submitted 002b9e80 v1
