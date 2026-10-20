# rec59 progress
start 2026-10-12T23:45:22Z
claim 00192450 token e5877fdd9c724471a1e10ff774dfbd60 attempts 1
v1: 17 words, first diff 0: C21/C11 -> next: int params, recompute b+a
v2: 17 words, CSE of address: next volatile 2nd read
v3: 13 words (volatile 2nd read, extra andi): next volatile 1st read only
v4: 15 words worse: next ((u8*)index)[base+1]
v5: 17 words: next asm +r barrier on index
v6: 10 words, first diff 2: C11 -> next reorder result before high
v7: 9 words best: next v8 high,result,flag order
v8: 10 words. blocked 00192450 -> register-allocation
claim 001940b8 token b6fb83a3cc8c472f9575872eadffebfa attempts 1 (claim 2 of 6)
v1: 13 words, C3 -> next u32 byte params
submitted 001940b8 v2
claim 001943e8 token 999a9a3388424af8aaedc8b009343286 attempts 1 (claim 3 of 6)
submitted 001943e8 v1
claim 001947c0 token 26561e9d8e584d99af488e9a67a8119e attempts 1 (claim 4 of 6)
v1: 26 words, C7/C21 -> next: pointer var, nested b<0 recheck
v2: 23 words, first diff 4: C7 -> next: result var single exit
v3: 24 words (size 108 ok), result var gives wrong exit: next early return + return 0 end with b>=0 test
v4: 1 word, first diff 16: C11 -> next entry = b*4 + base operand order
submitted 001947c0 v5
claim 00194980 token 7201e27505c14a70b6d543a5b7913486 attempts 1 (claim 5 of 6)
v1: 18 words, C8/C12 -> next: separate temp for callee result, nested ifs
v2: 18 words same: next volatile result (C8c)
v3: 18 words worse: next bind flag to s0 asm
v4: 9 words, first diff 8: C8 slt vs bgtzl -> next flag++
v5: 9 words same: next s64 callee return
v6: 3 words (movz vs bgtzl): next combined && condition
v7: 3 words same: next v8 flag as u8 register
submitted 00194980 v8
claim 00195858 token cebac86f805547dbacab425f91cf2e19 attempts 1 (claim 6 of 6)
v1: 6 words, first diff 11: C9 -> next volatile read of object[7]
v2: 6 words same: next memory barrier asm
submitted 00195858 v3
