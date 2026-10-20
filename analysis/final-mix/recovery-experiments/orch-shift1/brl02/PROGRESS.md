# brl02 progress
start 2026-10-12T17:52:45Z
R0 done; claims so far: 0/6
claim 0018dbd8 token f139deea841e4352adf74c27e34e4d88 attempts 4 (claim 1/6) blocker med01\0018dbd8-BLOCKED.md
v1: 20 words, first diff at 0: report hypothesis (nested inline-style stmt exprs, !=0 bools) -> next: v5 base with stmt-expr value 'selected != 0'
v2: 0 words exact (C8 truth-value form: stmt-expr value 'selected != 0')
submitted 0018dbd8 v2
claim 00108930 token 3bd0a721b35f4e89882563348fb28f07 attempts 2 (claim 2/6) blocker rec02\00108930-BLOCKED.md
00108930: best earlier rec02 v3 17 words (>6, fresh). v1 = rec02 v3 shape with mask computed before first flags load (C9/C10 hoist, blocker's 'hoisting the constant')
v1: 3 words, first diff at 15: C11 (lw t7 + move t6 vs lw t6/bnezl) -> next: C11(b) separate temp 'next' tested by the while
v2: 0 words exact
submitted 00108930 v2
claim 00109788 token afdaace7e05a478095851c342a94a680 attempts 2 (claim 3/6) blocker rec02\00109788-BLOCKED.md
00109788 v1 = copy of rec02 v1 (6 words)
v1: 6 words, first diff at 1: C11 s0/s1 swapped -> next: blocker hypothesis param types (second as u32, first stays u64)
v2: 6 words (no change), first diff at 1: C11 -> next: C11(d) asm +r on first (back to u64 params)
v3: 6 words (no change): C11 -> next: C11(c)+(d) bind owner to \ and pin it with asm +r so the binding is honoured
v4: 0 words exact
submitted 00109788 v4
claim 0011f270 token 817b34f776514660977616514dd21535 attempts 2 (claim 4/6) blocker rec05\0011f270-BLOCKED.md
0011f270: best earlier rec05 v8 7 words (>6, R4 fresh, but building on its shape). v1 = v8 with mask assigned inside the parent>=0 block (blocker hypothesis: mask after first lh)
v1: 2 words, first diff at 14: C11 addu operand order -> next: blocker hypothesis, offset as integer added before base ((u32)(parent*64) + (u32)entries) at both sites
v2: 22 words (132 bytes), sll went straight into bound t5 -> next: C11(b) separate u32 offset temp, then entry = offset + base
v3: 22 words (offset temp coalesced into t5) -> next: C11(c) bind offset to \ so sll lands in t7 and addu keeps offset-first order
v4: 20 words (136 bytes); 3 versions without improvement -> block
blocked 0011f270 -> register-allocation
claim 0011f270 token d857ecc1c7e948489b201bb874b5eaa9 attempts 3 (claim 5/6): re-served the address I just blocked; released without work (brief forbids reclaiming)
claim 0011f270 token 97c6138ec8c046ecb05703aaf0986cfa attempts 4 (claim 6/6): re-served again; released without work. K reached -> WP report
