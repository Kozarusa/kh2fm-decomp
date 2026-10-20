# rec131 progress
start 2026-10-13T08:37:59Z
claim 1 of 6: 0021f5d8 token a9247d2cb072494595ce5e9171c2a24d attempts 1
v1: 6 words, first diff at 12: address folded into lwc1 -> next: array decl
v2: check next
0021f5d8 v1: 6 words; best v1 6; streak 0
0021f5d8 v2: 6 words; best v1; streak 1
0021f5d8 v3: 6 words; streak 2 (volatile)
v4: exact
submitted 0021f5d8 v4
claim 2 of 6: 00220c88 token c284cfbe31464db19a9e42533233b5e7 attempts 1
00220c88 v1: 26 words (v0 live-in fragment, no spill); best v1 26; streak 0 -> try volatile spill slot
00220c88 v2: 25 words; best v2 25; streak 0 -> copy v0 into plain local
00220c88 v3: 4 words; best v3 4; streak 0 -> reorder tail statements (C10)
v4: exact
submitted 00220c88 v4
claim 3 of 6: 00222898 token bf54bad8ca2c457fb399737cb578ffac attempts 1
blocked 00222898 -> vu-macro
claim 4 of 6: 002233f0 token cdea24d77a7c43acb76c2b7f1cb23055 attempts 1
002233f0 v1: 12 words, tail call j instead of jal+break; best v1 12; streak 0 -> try __builtin_trap
002233f0 v2: 1 word (break vs teq); best v2 1
blocked 002233f0 -> privileged-instructions
claim 5 of 6: 00223448 token 147ceecc9be54ff99dedcf104d5deace attempts 1
00223448 v1: 3 words (a1/a2 move order + break); best v1 3; streak 0 -> try u64 params
00223448 v2: 3 words; best v1 3; streak 1 -> typed decl (u8*, u32, ...)
00223448 v3: 3 words; streak 2 -> asm guard on third
00223448 v4: 3 words; streak 3 -> block
blocked 00223448 -> privileged-instructions
claim 6 of 6: 00224780 token f34ca1624f5843e585eb172b18f6a0c0 attempts 1
00224780 v1: 4 words (store order dac4/dadd, dacc/dac8); best v1 4; streak 0 -> C10 swap pairs
v2: exact
submitted 00224780 v2
