# brl03 progress
start 2026-10-12T18:42:07Z
claims: 0/6
branch-layout: empty
claim 00138190 token b690cf3ff28a498cbdd07392541023d2 attempts 2 (claim 1/6)
v1: 16 words, first diff at 4: C11(a) used-before-next reorder (no effect) -> next: struct rewrite C11(b)
v2: 23 words (120 bytes), struct folds offsets: worse -> next: C11(c) bind tail/used to $14
v3: 15 words, first diff at 6: C11(c) -> next: C11(c) bind used+8 to t4 (12)
v4: 25 words, worse (extra move) -> next: from v3, bind only tail to t6, used plain
v5: 13 words, first diff at 6 (t4/t7 swapped): C11 -> next: C11(a) compute next%8 before the if
v6: 23 words, worse -> next: from v5, C11(b) temp variable biased = used + 8
v7: 13 words, no change -> next: from v5, C11(d) asm +r on used
v8: 15 words -> 3 versions without improvement, block
blocked 00138190 -> register-allocation
claim 001397d8 token 322344e82a284bd1a5f74ea4ff8eebef attempts 2 (claim 2/6)
v1 (copy of rec08 v8): 2 words, first diff at 9: C11 -> next: drop volatile on next read
v2: 14 words (116 bytes), drop volatile worse -> next: C11(c) bind list pointer to $4
v3: 12 words (a0 bound, but delay slot not filled) -> next: C11(b) sentinel form, list is a Node whose next is the head
v4: 22 words, sentinel worse -> next: C11(b) plain temp list in the head arm
v5: 2 words, no change -> block (3+ versions without improvement)
blocked 001397d8 -> register-allocation
re-served 00138190 (blocked here): released, not counted; moving to store-order
claim 001c2ce8 token eb98b5fe32cf4d1ab7db75589332fc6b attempts 6 (claim 3/6)
v1 (copy lay01 v1): 2 words, first diff at 14: C10 store swap -> next: blocker hypothesis, asm-opaque object copy for table store
v2: 15 words (80 bytes, extra move), stores ordered -> next: twin 001c2c98 v4 recipe (asm ties + t5/t6/t7 bindings)
v3: 2 words, first diff at 12: ori/addiu swapped (C10 order) -> next: add +r(mode) to the first asm tie
v4: 4 words, first diff at 6: ori/addiu fixed, 0x200000 now in t4 because table bound to t7 early (C11) -> next: remove the t7 binding of table
v5: 4 words, no change (lui 0x35 hoisted, 0x200000 in t4) -> next: from v3, separate mode tie before the table address
v6: 7 words -> block (no improvement for 3 versions)
blocked 001c2ce8 -> store-order
claim 001c2c98 token dec6b41a934149138948a75811b314d7 attempts 7 (claim 4/6)
v1 (copy lay01 v4): 2 words at 12 ori/addiu swap; v2 combined +r(mode) tie: 4 words at 6 (0x200000 in t4, C11) -> next: bind the 0x200000 constant to $15
v3: 4 words at 8: lui 0x35 now after the or, but or result moved to t7 (C11) -> next: C11(d) asm +r(flags) after the or
v4: 11 words -> block (no improvement for 3 versions)
blocked 001c2c98 -> store-order
re-served 001c2ce8 (blocked here): released, not counted; moving to float-transport
claim 0010a828 token ed60179ce85d4386ac303c064f23e2c2 attempts 2 (claim 5/6)
v1: 11 words (92/92), asm-opaque constant pointers fixed size; first diff at 4: C10 schedule/final stores swapped -> next: swap the two final stores in source
v2: 7 words, first diff at 4: C10 (eb4 store shares lui t6; mul early) -> next: C10(a) move the scale multiply after the two parameter stores
v3: 17 words, worse -> next: from v2, C10(c) volatile parameter stores
v4: 11 words, worse -> next: from v2, C11(b) separate range temporary
v5: 11 words -> block (no improvement for 3 versions)
blocked 0010a828 -> address-materialization
float-transport: empty
claim 0017c0a0 token 13261153675940a088aa63050da1dbb0 attempts 5 (claim 6/6)
v1 (copy lay01 v1): 2 words at 3, a0/a2 setup order swapped -> next: blocker hypothesis (natural copy, slots rotated): nested call passed by value
v2: 15 words (108 bytes, s1 saved), worse -> next: from v1, C11 remove the asm +r tie on the a0 binding
v3: 2 words, no change -> next: from v1, make the a0 tie asm volatile (scheduling barrier)
v4: 6 words -> block (no improvement for 3 versions)
blocked 0017c0a0 -> store-order
K=6 reached
WP report written
