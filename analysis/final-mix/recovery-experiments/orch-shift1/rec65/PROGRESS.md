# rec65 progress
start 2026-10-13T00:11:59Z
claim 00198bd0 token 865ac7a91fbf4ea6a241996484233346 attempts 1
v1 written
v1: 1 word, first diff at 16: sltu vs slt -> next: signed pointer compare
submitted 00198bd0 v2
claim 00199030 token d6d3a562ddb1498d90f07f0377892e97 attempts 1
v1 written 00199030
00199030 v1: 25 words, first diff 1: C7/C4 -> next: pointer arg for 19f070
00199030 v2: 25 words (96 bytes), C7 -> next: negate handle cond (v3)
00199030 v3: 25 words (100 bytes) streak1 -> next: early return form (v4)
00199030 v4: 18 words best v4 -> next: negate handle cond with early return (v5)
submitted 00199030 v5
claim 00199120 token 7d09a551e3794c849a78a3b0c6034acf attempts 1
00199120 v1 written
submitted 00199120 v1
claim 00199468 token 1a39d5a458dc4096af37bdf9b9bca802 attempts 1
00199468 v1 written
00199468 v1: 12 words; C9 -> next: load head after node lookup
00199468 v2: 12 words streak1 -> next: volatile head read
00199468 v3: 12 words streak2 -> next: tail via pointer slot (v4)
00199468 v4: 12 words streak3 -> block
blocked 00199468 -> store-order
claim 001995b8 token f10270e78e7848a28f67724ef60db793 attempts 1
001995b8 v1 written
001995b8 v1: 13 words, first diff 0: C8/C7 -> next: if/else for node
001995b8 v2: 13 words streak1 -> next: volatile head
001995b8 v3: 14 words streak2 -> next: ternary in while cond
001995b8 v4: 14 words streak3 -> block
blocked 001995b8 -> branch-layout
claim 001997c0 token be2bcc1e32eb4c9db1d34d3f9d83840a attempts 1 (6th, last)
001997c0 v1 written
001997c0 v1: 19 words, first diff 4 -> next: pointer return + s32 kind
001997c0 v2: 15 words best v2 -> next: nested ifs (C8/C7)
001997c0 v3: 15 words streak1 -> next: u8 other (v4, from v2 form)
001997c0 v4: 15 words streak2 -> next: explicit early returns (v5)
001997c0 v5: 9 words best v5 -> next: result var with != returns (v6)
001997c0 v6: 9 words streak1 -> next: ghidra chain with return 0/1 (v7)
001997c0 v7: 10 words streak2 -> next: early returns with other var (v8)
001997c0 v8: 15 words streak3 -> block
blocked 001997c0 -> branch-layout
