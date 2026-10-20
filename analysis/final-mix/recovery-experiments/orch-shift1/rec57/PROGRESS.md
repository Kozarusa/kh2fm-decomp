# rec57 progress
start 2026-10-12T23:37:11Z
claim 001904f0 token 8d247082c6ad4efb83bcc3382c190523 attempts 1
v1: 14 words, first diff 12: C7 -> next: swap branches + 3-arg 1902a8
v2: 8 words, first diff 14: extra a2=zero -> next: 2-arg 1902a8
v3: 11 words (2-arg worse): hoist of a1/a2 shows 1902a8 takes 3 args; next: result > 0 so compiler cannot fold a2 to zero
v4: 8 words no change; next: D_ as array deref
v5: compile error (bad replace); v6 retry array
v6: 8 words no change; v7: s64 result + pointer local (two changes, desperate)
blocked 001904f0 -> branch-layout (1 of 6 claimed)
claim 001907e0 token 54557d3005604c7baad37cc9c255160e attempts 1
v1: 24 words first diff 0: C21 -> next: struct global with entry/freeList/count and struct copy
submitted 001907e0 v2 (2 of 6 claimed)
claim 00190920 token 167c613c1f7b402196515876b9ae5e1b attempts 1
blocked 00190920 -> boundary-review (3 of 6 claimed)
claim 00190a28 token 4183d643ea2d4d6281aa7155f1f7e3ec attempts 1
submitted 00190a28 v1 (4 of 6 claimed)
claim 001918c8 token ba08bd0c5469435bb08c5777415311ee attempts 1
v1: 27 words first diff 2: s0 saved, lwu; C12/C2 -> next: s32 global + early returns
submitted 001918c8 v2 (5 of 6 claimed)
claim 00191938 token b95517c1b4f04e99927fc0d4bf25eb63 attempts 1
v1: 19 words first diff 4: C20 s64 wrong -> next: s32 param
v2: 17 words first diff 4: compare merged unsigned -> next: nested ifs
v3: 16 words: nested; next: negate with else
v4: 1 word (nop vs li a0,6 in jal delay slot); next: u64 arg for 1c1130
submitted 00191938 v5 (6 of 6 claimed)
