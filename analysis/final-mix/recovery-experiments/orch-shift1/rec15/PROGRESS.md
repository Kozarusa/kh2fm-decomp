# rec15 progress
start 2026-10-12T19:24:54Z
claim 00143dd0 token ebfbf230830d458291a36ee4e5070968 attempts 1
v1 exact; submitted 00143dd0 v1
claim 00144060 token 23443581245143edbbb01227d3e4ff70 attempts 1
v1 exact; submitted 00144060 v1
claim 00145580 token 85f980e75ac947e7af3a676fa45c68fa attempts 1
v1: 7 words, first diff 0: C7 -> next: negate conditions (a3<b0 form)
v2: 7 words, first diff 5: C7 -> next: flip operand sides of 2nd/4th/6th compare
v3: 1 word, first diff 28: xori vs sltiu -> next: unsigned <1 on compare
v4: 2 words, first diff 25: C7 -> next: flip last compare operands
v5 exact; submitted 00145580 v5
claim 00145c28 token 51df2100468a4b188cda1e9e294836f4 attempts 1
v1: 15 words, first diff 0: C11/C21 -> next: separate copy of count
v2: 1 word, first diff 6: C11 -> next: offset + base order
v3: same diff (swap ignored) -> next: u32 arithmetic
v4 exact; submitted 00145c28 v4
claim 00145c68 token b74f5defa65e42eaa6db1e34326f5d02 attempts 1
v1: 2 words, first diff 4: C11 -> next: hoist constant var before offset
v2 exact; submitted 00145c68 v2
claim 001466b0 token e14098f89cc44343bff7602d5f2174ea attempts 1
blocked 001466b0 -> vu-macro
