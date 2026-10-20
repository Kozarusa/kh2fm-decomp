# brl01 progress
start 2026-10-12T17:18:34Z
claims so far: 0 of K=6
claim 0010ce78 token f784db77392d456fbdf1923276f35466 attempts 2 (claim 1/6)
v1: 16 words, first diff at 14: C3/C2 missing andi 0xff on flag -> next: flag as u8
v2: 16 words, first diff at 14: C3 -> next: s32 flag with (u8) cast at use (C3b)
v3: 3 words, first diff at 17: C8/C7 beqzl vs beqz, beq delay move t6,zero missing -> next: explicit nested result assignments (C7c)
v4: 15 words, first diff at 11: worse (xor/sltu) -> next: v3 base with comma-assignment && chain (C7c variant)
v5: 15 words, first diff at 11: worse -> next: v3 with outer && turned into ternary so inner || is its own value (C8a separate temp)
v6: 6 words, first diff at 15: worse than v3 -> next: v3 condition as if/else with explicit result=1 / result=0 (C7c)
v7: 22 words, first diff at 5: worse; 3+ versions without improvement -> block
blocked 0010ce78 -> branch-layout
claim 0010f6b8 token d12835b649d64d1f8b32bce700437d58 attempts 2 (claim 2/6)
v1: 7 words, first diff at 1: C8 compare folded into slt v0 -> next: C11d asm barrier on result=1
v2: 12 words, first diff at 1: movz from ifcvt -> next: C7b combined if (data && less) return 1; return 0 (shared zero block)
v3: exact
submitted 0010f6b8 v3
claim 001124f8 token 9cac4c747b0a4c51b0a4f32fa92b0084 attempts 2 (claim 3/6)
v1: (see diff) worse than rec04 best, first diff at 8: C9 volatile read -> next: C7 store the global directly in both arms
v2: exact
submitted 001124f8 v2
claim 0011f078 token 1aff13dd8d3346cd97d8f560448effe4 attempts 2 (claim 4/6)
v1 (copy of rec05 v7): 6 words, first diff at 12: C10/C7 addu/slt order + flag branch sense -> next: for(;;index++) with increment in loop tail
v2: 6 words, first diff at 14: li/addiu order + flag branch sense (C7) -> next: goto loop with increment after flag test (unconditional back edge)
v3: 6 words, first diff at 14: same as v2 -> next: C21-ish restructure as rotated while(index < call()) with return 1 in body (C7c)
v4: exact
submitted 0011f078 v4
claim 0010ce78 token a34085f2555042ccb04abdd7f857408b attempts 3 (claim 5/6; own earlier block, versions continue at v8)
packet rebuild refused (existing packet kept, same target). v8 (copy of v3): 3 words, first diff at 17: C7 -> next: if (...) return 1; return 0; shared zero block
v9: 22 words, first diff at 5: worse -> next: result var with inner if/else explicit 1/0 (separate zero block, C7c)
v10: 3 words, first diff at 17: zero merged again -> next: if/else-if/else with no shared initial zero (C7c)
v11: exact
submitted 0010ce78 v11
claim 00161548 token 7644acf7d41f4109819c02508bed2ab3 attempts 4 (claim 6/6, last)
v1: 15 words, first diff at 2: C7 result var in t6, call block inline -> next: early return on every path (C7c)
v2: 15 words, first diff at 2: same as v1 -> next: blocker hypothesis, loop form for the list test (rotated while puts call block after return)
v3: 12 words, first diff at 3: layout fixed, return value in t7 not v0 (C11) -> next: result=0 then if (item) result=item[2] so result and item conflict (C11b temporary)
v4: 4 words, first diff at 14: C11 item in v0, result in t7 (original reversed) -> next: C11b remove result temporary, return ternary
v5: 4 words, first diff at 14: same as v4 -> next: C11c bind item to $15 on v4
v6: exact
submitted 00161548 v6
K=6 claims reached; WP-REPORT.md written
