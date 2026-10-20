# rec53 progress
start 2026-10-12T23:16:43Z
claim 001886d0 token 024a60463473456a9d5972760f79a09a attempts 1
v1: 25 words, first diff 0: C12/C1 -> next: use '< 1' for sltiu
v2: 25 words same: -> next: asm +r on result
v3: 10 words, first diff 13: sltiu form -> next: separate masked var
submitted 001886d0 v4
claim 001888c8 token 87032cdb9a6140c8b972ff056872467a attempts 1
v1: 12 words, first diff 3: C10 -> next: ascending offset order
submitted 001888c8 v2
claim 00188b68 token da2f5f50347e4e08b8e3aff26f37a476 attempts 1
v1: 13 words, first diff 0: C8 movn -> next: separate temps
v2: 9 words, first diff 1: or hoisted -> next: inline expr with s32 value, u32 high shift
v3: 9 words same: -> next: restructure loop while/for with count
v4: 13 words: -> next: v3 + asm +r on high
v5: 9 words same; stop (3 without improvement)
blocked 00188b68 -> register-allocation
claim 0018a1b8 token ddbf73e01be6452e99e0e55a715e3e65 attempts 1
v1: 7 words, first diff 9: C11(b) -> next: separate cursor var
v2: 18 words: -> next: reuse param 'current' as cursor
v3: 16 words (regs match, extra move v0,zero in delay slot): -> next: early return 0 if entry>=end
v4: 16 words: -> next: ghidra goto structure
v5: 20 words; stop
blocked 0018a1b8 -> register-allocation
claim 0018bbf8 token a10d28fc69d34d6aba49f4cf47e09688 attempts 1
v1: 2 words, first diff 6: C7(c) -> next: early return 0
submitted 0018bbf8 v2
claim 0018ca48 token b0f644f5466444ccb2b291c37ef96a5c attempts 1
v1: 15 words, compiled 68 vs 56 (no jump table): -> next: more cases to force table
v2: 10 words, compiled 56 (branch tree, no table): -> next: interleaved cases 0..18 to force table
v3: 4 words (table works; lui/addiu reloc diff + extra li 1 block): -> next: only case 1 returns 1
v4: 7 words (layout differs, 52 bytes): -> next: v3 with cases 1,3,5 merged
v5: 7 words same as v4: -> next: v3 minus case 5
v6: 4 words same as v3 (dup li block): -> next: break instead of return value
v7: 7 words: -> next: merged cases 1,3 + return value cases
v8: 7 words; budget reached
blocked 0018ca48 -> address-materialization
claim 0018caf8 token 24a94a83815c4155a1de897415f2dcd2 attempts 1 (6th, K reached)
v1: 2 words (only lui/addiu jump-table relocation); stop
blocked 0018caf8 -> address-materialization
