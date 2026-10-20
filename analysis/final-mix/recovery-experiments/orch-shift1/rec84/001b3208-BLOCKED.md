# 001b3208 blocked
- Range: 001b3208, 100 bytes. Versions tried: 7. Best: v4 with 21 differing words (96/100 bytes).
- First difference of the best version: !! 001b3208: 8c8e0000  lw	t6,0(a0)  (compiled lw t4/t3; register allocation of header/index/offset differs and compiled has no `move t6,t5` loop-carried copy; original has 25 instructions, compiled 24).
- Changes tried: v1 do-while inside if (23 words); v2 separate base/current header vars (23, coalesced by compiler); v3 integer-address form (25); v4 for loop (21); v5 asm pin on loop-carried header (26); v6 base declared inside while loop (21); v7 do-while with index++ in subscript (21).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind index/offset/header to the original registers (t4=12 index, t3=11 offset, t6=14 header, t5=13 current) with // why comments, to force the extra `move t6,t5` loop-carried copy.
