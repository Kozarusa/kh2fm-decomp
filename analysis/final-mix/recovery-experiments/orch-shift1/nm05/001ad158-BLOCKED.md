# 001ad158 blocked
- Range: 001ad158, 116 bytes. Versions tried: 6. Best: v3 with 2 differing words (116/116 bytes).
- First difference of the best version: !! 001ad174: ffbf0028  sd	ra,40(sp) | 001ad174: ffb00000  sd	s0,0(sp) (only the ra and s0 prologue saves are swapped)
- Changes tried: v1 bind third to $19 and second to $20 with empty guards (4); v2 memory barrier between the two stores (7); v3 store +4 before +8 (2); v4 drop first barrier (4); v5 drop second barrier (2); v6 swap guard order (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: change which value is bound/guarded for the callee result (for example bind result to $16 explicitly, or copy fourth to a local) to move the s0 save after the ra save.
