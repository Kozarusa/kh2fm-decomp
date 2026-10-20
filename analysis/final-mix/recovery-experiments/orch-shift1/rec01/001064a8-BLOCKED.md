# 001064a8 blocked
- Range: 001064a8, 120 bytes. Versions tried: 4. Best: v1 with 13 differing words (108/120 bytes).
- First difference of the best version: !! 001064bc: 04800014  bltz	a0,0x106510 (branch offset differs only because compiled is shorter); first real divergence is 001064dc: original addiu t7,t7,-24424 then lwc1 $f0,0(t7); compiled lwc1 $f0,-24424(t7).
- Changes tried: v1 baseline u32 arg, f32 scale*random/D (13). v2 D as array [0] and callee s32 return (13). v3 callee returns f32 (13). v4 volatile f32* divisor (13).
- Why it stops here: no improvement for 3 versions. Core mismatch: the original calls func_00313bc0 with jal plus a full epilogue (non-tail call, delay slot nop), while the compiler always emits a tail call (j with addiu sp in the delay slot); also the divisor address is formed with addiu then lwc1 0(reg).
- Next hypothesis: find a source construct that prevents sibling-call optimisation (e.g. a statement or local after the call, or a different callee/return type combination) and that also forces the divisor address into a register (pointer variable loaded before the multiply).
