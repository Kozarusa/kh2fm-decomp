# rec125 progress
start 2026-10-13T07:44:59Z
claim 1 of 6: 001f0430 token 30dbf466df204abbb6f15c16656da363 attempts 1
v1: 11 words, first diff 0: C4 -> next: float zero in fpr via empty asm
v2: 6 words, first diff 3: C10 -> next: memory barrier before zero stores
v3: 6; best v2 6; streak 1 (barrier no effect) -> next: rotate zero stores
v4: 3; best v4 3; streak 0 -> next: drop temp variable
v5: 3; best v4 3; streak 1 -> next: two temps
v6: 6; best v4 3; streak 2 -> next: guard on first temp
v7: 5; best v4 3; streak 3 -> stop
blocked 001f0430 -> register-allocation
claim 2 of 6: 001fb478 token f5ef2cf65a2642a495bc0a7a52132b7d attempts 1
v1: 10 words, first diff 9: C10 -> next: temp for D load + ghidra order
v2: 8; best v2 8; streak 0 -> next: swap 192/193 source order
v3: broken draft (empty file, not valid); streak 1
v4: 9; best v2 8; streak 2 -> next: C9 volatile global
v5: 8; best v2 8; streak 3 -> stop
blocked 001fb478 -> store-order
claim 3 of 6: 001fb6c8 token daa93297777b4c97bd85b49f2d3597a0 attempts 1
v1: 13 words, first diff 1: C11 -> next: separate copy of object pointer
v2: 13; best v1 13; streak 1 -> next: ascending field order
v3: 10; best v3 10; streak 0 -> next: source order = original store order
v4: 11; best v3 10; streak 1 -> next: v3 with inner first
v5: 14; best v3 10; streak 2 -> next: v3 with table last
v6: 11; best v3 10; streak 3 -> stop
blocked 001fb6c8 -> store-order
claim 4 of 6: 001fb928 token 58ef0c0c0c50456ab9ab5d3af885ea6f attempts 1
v1: 24 words, first diff 1: C11 -> next: single-expression base
v2: 16; best v2 16; streak 0 -> next: C9 volatile source
v3: 25; best v2 16; streak 1 -> next: memory barriers between stores
v4: 14; best v4 14; streak 0 -> next: volatile read of other+12
v5: 14; best v4 14; streak 1 -> next: single barrier
v6: 20; best v4 14; streak 2 -> next: v4 plus trailing barrier
v7: 14; best v4 14; streak 3 -> stop
blocked 001fb928 -> branch-layout
claim 5 of 6: 001fbb20 token a52277070a35438d838a67b4ea68f5c0 attempts 1
v1: 15 words, first diff 1: C10 -> next: barriers
v2: 14; best v2 14; streak 0 -> next: volatile stores no barriers
v3: 21; best v2 14; streak 1 -> next: early return with barriers
v4: 14; best v2 14; streak 2 -> next: C18 union aliasing, no barriers
v5: 7 words; best v5 7; streak 0 -> next: guard on other pointer
v6: exact; submitted 001fbb20 v6
claim 6 of 6: 001fcb18 token 0ffabffb2cec4887ae9e2870c8e412e3 attempts 1
v1: 30 words (132 bytes), extra s2: C12 -> next: add offset to object before first call
v2: 9 words, first diff 6: C11 -> next: local pointer for global in first call
v3: 9; best v2 9; streak 1 -> next: asm guard on copy of object
v4: 28; best v2 9; streak 2 -> next: v2 with temp for +16 arg
v5: 3 words; best v5 3; streak 0 -> next: local g plus third
v6: 3; best v5 3; streak 1 -> next: bind global to a0
v7: 20; best v5 3; streak 2 -> next: v5 plus head temp
v8: 3; best v5 3; budget reached -> block
blocked 001fcb18 -> register-allocation
