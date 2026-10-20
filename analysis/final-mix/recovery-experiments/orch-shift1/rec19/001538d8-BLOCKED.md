# 001538d8 blocked
- Range: 001538d8, 108 bytes. Versions tried: 7. Best: v4 with 3 differing words (108/108 bytes).
- First difference of the best version: !! 001538fc: 3c0a0035  lui	t2,0x35   | 001538fc: 0000682d  move	t5,zero
- Changes tried: v1 straight rewrite 12 words (t4/t5 swapped); v2 identical to v1 (edit failed, 12); v3 declaration order swap 12; v4 offset init inside the if (index=0 before it): 3 words; v5 for-loop form: 3; v6 asm +r after offset init: 4; v7 0<count test: 3.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: only the placement of `move t5,zero` (offset init) relative to the hoisted `lui t2` / `li t1,1` differs; try making offset a pointer-style cursor or a register-bound $13 value, or fold the 24-stride into index*24 recomputation so the init is scheduled after the hoisted constants.
