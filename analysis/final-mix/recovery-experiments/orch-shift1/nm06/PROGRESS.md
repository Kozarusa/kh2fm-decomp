# nm06 progress
start 2026-10-13T03:42:37Z
claim 1 of 4: 001b6d88 token 66586a4a92a0480cafd53ea790eb4771 attempts 2
v1: 11 words, first diff at 1: C10/C9 u8 next local worsened -> next: s32 next
v2: 7+ words (s32 next worse; best remains rec87 v3 = 2) streak 1 -> next: barrier
v3: 2 words, first diff at 4; best v3 2; streak 1(vs rec87 v3) -> next: u32 value + barrier + mask in compare
v4: 2 words; best v3 2; streak 1 -> next: no barrier, u32 value, (u8) cast compare
v5: 7 words; best v3 2; streak 2 -> next: asm +r on value (C11d)
v6: 2 words; best v3 2; streak 3 -> stop
blocked 001b6d88 -> store-order
claim 2 of 4: 001b0498 token a9840e90c0494060b5b90002e2164cbf
v1 (001b0498): 16 words, result init 1 shape bad -> next: v4 base with result var only for last test
v2 (001b0498): 6 words; best none beats rec82 v4=3; streak 1 -> next goto shared return 1
v3 (001b0498): 9 words; streak 2 -> next result=1 in both branches
v4 (001b0498): 6 words; best v2 6; streak 2 -> next rec82v4 base with return (cond != 0) ? 1 : 0 ternary form
v5 (001b0498): 3 words; best v5 3; streak 0 -> next: C7 final test negated
v6 (001b0498): 3 words; best v5 3; streak 1 -> next: C7c if/else with owner local
v7 (001b0498): 9 words; best v5 3; streak 2 -> next: volatile flags read on v5
v8 (001b0498): 3 words; best v5 3; streak 3 -> stop
blocked 001b0498 -> branch-layout
claim 3 of 4: 001ad158 token d707b5bd71134b32b79bfe2d2d3142eb
v1 (001ad158): 2 words; best v1 2; streak 0 -> next copy fourth to local, no result binding
v2 (001ad158): 2 words; best v1 2; streak 1 -> next bind pointer to \ instead of result
v3 (001ad158): 11 words; best v1 2; streak 2 -> next bind fourth to \ + result \
v4 (001ad158): 23 words; best v1 2; streak 3 -> stop
blocked 001ad158 -> register-allocation
claim 4 of 4: 001ac2a8 token 3247c5adfc784e8297e182abfd9c161f
v1 (001ac2a8): 2 words; best v1 2; streak 0 -> next only second copied
v2 (001ac2a8): 2 words; streak 1 -> next only third copied
v3 (001ac2a8): 2 words; streak 2 -> next copies in order and one barrier removed
v4 (001ac2a8): 10 words; best v1 2; streak 3 -> stop
blocked 001ac2a8 -> register-allocation
