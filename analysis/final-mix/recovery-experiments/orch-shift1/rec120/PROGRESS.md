# rec120 progress
start 2026-10-13T07:08:39Z
claim 1 of 6: 001e2660 token a937f01c04e348849d1ee119c614c17f attempts 1
v1: 22 words, first diff 0: C11/C21 -> next: for loop
v2: 5 words, first diff 5: C8/C10 -> next: dest pointer var
v3: 5 words (same as v2), streak 1 -> next: rotate zero stores
v4: 3 words (best), streak 0 -> next: C8 dest var + temp
v5: 3 words, streak 1 -> next: volatile quad read
v6: 3 words, streak 2 -> next: 16-byte aligned struct copy
v7: 3 words, streak 3 -> block
blocked 001e2660 -> branch-layout
claim 2 of 6: 001e2788 token 0e19a7713b0049c8a7816863bad5d706 attempts 1
2788 v1: 8 words, first diff 1: C10 -> next: rotate zero stores
2788 v2: 2 words best, first diff 3: C11 -> next: temp var
2788 v3: 2 words, streak 1 -> next: register binding
submitted 001e2788 v4
claim 3 of 6: 001e27c0 token 84f9dad292ac47898bfc15e6d07699b4 attempts 1
submitted 001e27c0 v1
claim 4 of 6: 001e29e0 token 39e606d29801409584206edac56d8c2b attempts 1
29e0 v1: 3 words, first diff 21: C10 -> next: swap final stores
29e0 v2: 3 words, streak 1 -> next: s32 global
submitted 001e29e0 v3
claim 5 of 6: 001e2ad8 token e57b2c67fbe74b93993e81544fd64f12 attempts 1
29e0.. ad8 v1: 3 words (arg move order a2/a1 swap + break vs teq) -> block
blocked 001e2ad8 -> privileged-instructions
claim 6 of 6: 001e2c00 token c08ecaeaeeae4026ac9fcb640ba605df attempts 1
c00 v1: 11 words -> block (break 0 needs asm)
blocked 001e2c00 -> privileged-instructions
