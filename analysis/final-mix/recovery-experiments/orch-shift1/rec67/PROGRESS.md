# rec67 progress
start 2026-10-13T00:24:51Z
claim 0019ad00 token 4c420311bdac47e38b85df491e8f745e attempts 1
v1: 19 words, first diff 0: C9 -> next: volatile count reload
v2: 22 words (worse); v3 draft unprobed (bad idea, skipped); best v1 19; streak 1. next v4: alias copy of table
v4: 1 word, first diff 7 (addu operand order): C11 -> next: offset+table order
submitted 0019ad00 v5 (claims: 1 of 6)
claim 0019ae60 token 5bbdaa4462a34051b707aaff47c45bfb attempts 1
0019ae60 v1: 20 words, first diff 3: C3 -> next: u32 next unmasked
0019ae60 v2: 20 words; best v1 20; streak 1. next: u8 count + s32 next
0019ae60 v3: 20 words; best v1 20; streak 2. next: volatile count
0019ae60 v4: 20 words; best v1 20; streak 3 -> stop
blocked 0019ae60 -> branch-layout (claims: 2 of 6)
claim 0019b328 token f4eaccb9a080469fad5f61e248457797 attempts 1
0019b328 v1: 21 words, diff 1: C11/C7 -> next: single-return entry var
0019b328 v2: 19 words, best v2; streak 0. next: C7c if/else with return in else
0019b328 v3: 21 words; best v2 19; streak 1. next: separate result var (C8a/C12b)
0019b328 v4: 21 words; best v2 19; streak 2. next: u16 count
0019b328 v5: 19 words; streak 3. blocked 0019b328 -> branch-layout (claims: 3 of 6)
claim 0019bf00 token 36652b77f54140bb8d1daf2fa1879409 attempts 1
0019bf00 v1: 9 words, diff 9: bit test folded -> next: mask in variable
submitted 0019bf00 v2 (claims: 4 of 6)
claim 0019c090 token c0f972fceaed42db889b15b427a8ed57 attempts 1
0019c090 v1: 21 words, diff 5: C7 -> next: result var init 0, u8 flag2
0019c090 v2: 22 words (lbu from u8 flag1); best v1 21; streak 1. next: bool flag1 + u8 flag2 + return-result form
0019c090 v3: 20 words best v3; streak 0. next: literal masks
0019c090 v4: 21 words; best v3 20; streak 1. next: v2 shape with bool flag1
0019c090 v5: 21 words; best v3 20; streak 2. next: else-if for flag2
0019c090 v6: 15 words best v6; streak 0. next: mask var in else block
0019c090 v7: 15 words; best v6 15; streak 1. next: split ifs (last version)
0019c090 v8: 20 words; streak 2? (v7 15, v8 20 -> stop at budget 8). blocked 0019c090 -> branch-layout (claims: 5 of 6)
claim 0019c838 token c6e595d000c84335be10aed227f64efb attempts 1
0019c838 v1: 10 words, bit test folded -> next: mask var
submitted 0019c838 v2 (claims: 6 of 6)
