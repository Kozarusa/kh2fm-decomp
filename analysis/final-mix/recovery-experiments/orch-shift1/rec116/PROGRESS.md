# rec116 progress
start 2026-10-13T06:25:49Z
claim 1 of 6: 001dcfb0 token 6520ccf6cafb424abd63ee7dcbee9ff7 attempts 1
submitted 001dcfb0 v1
claim 2 of 6: 001dd2b8 token dfd7f0517d704c8abcbc15e15ea1b4dc attempts 1
submitted 001dd2b8 v1
claim 3 of 6: 001ddc08 token 44d190c285aa40bea1c1286fee64903a attempts 1
submitted 001ddc08 v1
claim 4 of 6: 001ddc48 token f02c80c0102249f9949d3c034260f20c attempts 1
submitted 001ddc48 v1
claim 5 of 6: 001ddd30 token cb481476551c4d2c8d56de9a1d696dc7 attempts 1
v1: 19 words, first diff at 1: C21/C7 -> next: restructure loop
v2: 19 words, best v1 19, streak 1: peeled first iteration -> next: asm guard on node
v3: 18 words, best v3 18, streak 0: -> next: found=1 before compare
v4: 18 words, best v3 18, streak 1: -> next: do-while with found after
v5: 17 words, best v5 17, streak 0: -> next: D-first then conditional override, no asm
v6: 18 words, best v5 17, streak 1: -> next: found=1 inside loop, goto
v7: 18 words, best v5 17, streak 2: -> next: asm guard on found
v8: 17 words, best v5 17, streak 3: budget reached
blocked 001ddd30 -> branch-layout
claim 6 of 6: 001dddd0 token ec7614ef1b4c408f971716d022150104 attempts 1
v1 (001dddd0): 25 words, first diff 1: C11 -> next: separate base copy for t7
v2 (001dddd0): 7 words, best v2 7, streak 0: C10a swap head/tail stores
v3 (001dddd0): 5 words, best v3 5, streak 0: C11 store [0] from data not copy
v4 (001dddd0): 10 words, best v3 5, streak 1: -> next: C11c bind base to t7
v5 (001dddd0): 9 words, best v3 5, streak 2: -> next: C11a copy defined after first store
v6 (001dddd0): 5 words, best v3 5, streak 3: budget stop
blocked 001dddd0 -> register-allocation
WP report written
