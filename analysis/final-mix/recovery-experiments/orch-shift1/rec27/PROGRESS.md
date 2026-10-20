# rec27 progress
start 2026-10-12T21:10:01Z
claim 001616f0 token 112a8de463cd41eaa89fcb3a4328745c attempts 1
v1: 20 words, first diff at 5: C7 -> next: swap branches
v2: 12 words, first diff at 19: C10/C14 -> next: struct assignment of 64 bytes
v3: 12 words, same: C11 -> next: explicit quad temporaries
v4: 12 words, same: C10/C14 -> next: volatile source reads
v5: 10 words, first diff 21 (volatile src helped): C10 -> next: volatile dst too
v6: 8 words, regs only: C11 -> next: bind a..d to 8..11
v7: compile error (bad scripted edit); counts as version
v8: exact
submitted 001616f0 v8
claim 00161770 token d14aba5a80534543a20d515887e6a83c attempts 1
v1 (00161770): 19 words, first diff 0: C12/C11 -> next: box var first, bind max pointer to s1
v2: 20 words: binding ignored, buffers swapped: C11 -> next: array of 2 quads + asm +r on pointer
v3: 8 words, s0/s1 swapped: C11 -> next: declare maxp before box
v4: 8 words, same: C11 -> next: register bind box=s0, maxp=s1 with asm +r
v5: 2 words (arg move order a0/a2 at 13): C11 -> next: asm for maxp only (separate), box plain bound
v6: 12 words worse: -> next: v5 with swapped asm operand order
v7: 2 words same: C11 -> next: asm on maxp after first call
v8: 12 words worse
blocked 00161770 -> register-allocation
claim 00162bb0 token 4e3d9b841e604e3cba248ff8785f3172 attempts 1
blocked 00162bb0 -> vu-macro (R3)
claim 00165830 token 1b1d9c8387824465af9f5600ba261d38 attempts 1
v1 (00165830): 16 words: C9/C10 -> next: volatile read of object+4
v2: compile-ish bad edit (comment swallowed return), counts
v3: 16 words, lw in jal delay slot, extra move t7: C18 -> next: pass 64-byte struct by value
v4: 16 words same: -> next: v3 plus memory barrier
v5: exact
submitted 00165830 v5
claim 00165968 token 884aaef3b86d422da4ef711bbfa8aa67 attempts 1
v1 (00165968): 14 words; packet/diff hide 5 zero words (nops) at 00165980-00165990 inside the loop (seen in verification.json target_hex) -> next: asm nops in loop
v2: 13 words, first diff 3 (a0 vs t5 base; loop copies counter): C11 -> next: Ghidra form with flag
v3: 13 words worse (xor): C11 -> next: v2 form with base bound a0, cursor bound t7
v4: 11 words, extra move t6,t7: C11 -> next: post-decrement of 16-byte element cursor
v5: 11 words same: C11 -> next: bind only base, cursor plain
v6: 12 words worse: -> next: v5 with cursor as plain u8* decrement by 16 in condition
v7: 12 words worse
blocked 00165968 -> register-allocation
claim 001659b8 token 5925c6bfce8046aca94755c8edac6112 attempts 1
v1 (001659b8): 5 words regs t6/t7: C11 -> next: entry temporary
v2: 5 words worse operand order: C11 -> next: array indexing form
v3: exact
submitted 001659b8 v3
extra claim 00165ef0 (7th, over K=6 by my counting error) released unworked
