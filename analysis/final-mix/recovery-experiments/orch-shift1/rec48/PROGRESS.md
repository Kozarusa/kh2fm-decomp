# rec48 progress
start 2026-10-12T22:58:41Z
claim 001850a0 token d47ebf0230e04c628ecca70fcb3ba07c attempts 1
v1 written
v1: 6 words, first diff at 24: C7/C11 -> next: early return on out==temp
v2: 6 words same: C7c no change -> next: register Quad q asm(\)
v3: 5 words, reg t0 fixed, remaining beql/move v0 -> next: return inside the if
v4: 5 words same -> next: separate result variable
v5: 5 words same -> next: v2 early return + register t0
v4-v6: 5 words, no improvement; blocked 001850a0 -> branch-layout
claim 00185890 token 4cf644de102c4b98b671a70eacc4192c attempts 1 (claim #2)
00185890 v1: 21 words, first diff 4: C7c -> next: single result var with nested if
00185890 v2: 21 words same -> next: u8* arithmetic
00185890 v3: 21 words, body arithmetic matches, layout differs -> next: early return structure with u8* arithmetic
00185890 v4: 21 words same -> next: last test positive with return inside
blocked 00185890 -> branch-layout
claim 00185920 token 83abfadc457d434da83f4bfe22b5f29e attempts 1 (claim #3)
00185920 v1: 18 words, first diff 3 (index arithmetic) -> next: D + row*64 + col*32 order
00185920 v2: 18 words same -> next: buffer reuse + split row pointer
00185920 v3: 3 words, first diff 10: C11 -> next: swap add operands
00185920 v4: 3 words same -> next: bind entry to a1
00185920 v5: compile error (my escaping), counted; v6 = bind entry to a1 properly
blocked 00185920 -> register-allocation
claim 00185de0 token 5c172faa9d2243afbfc81fa53009cfb4 attempts 1 (claim #4)
submitted 00185de0 v1
claim 00186078 token 8f7f9625bcb54fe6b8f7048a8e899394 attempts 1 (claim #5)
00186078 v1: 14 words, first diff 1 (return value copies): C1 -> next: void return
00186078 v2: 10 words, void: extra move v0,a0 at start -> next: separate next variable
submitted 00186078 v3
claim 00186110 token 41a00d3a7315414196c525b5002fe617 attempts 1 (claim #6, last)
00186110 v1: 13 words, no jump table, 48/56 bytes: C1 -> next: explicit cases 1,6-9 return 0
00186110 v2: 2 words (only table reloc lui/addiu differs, D_00000000): next: computed goto through extern D_0036c908
00186110 v3: 4 words, lui/addiu match; return-1 block dropped as unreachable -> next: keep label via address-taken
blocked 00186110 -> address-materialization
WP report written
