# 0027f2b0 blocked
- Range: 0027f2b0, 72 bytes. Versions tried: 4. Best: v1 with 3 differing words (72/72 bytes).
- First difference of the best version: !! 0027f2e4: 0c0a2b32 jal 0x28acc8 | 0027f2e4: 8de4f254 lw a0,-3500(t7).
- Changes tried: v1 direct returned calls3; v2 final result assignment3; v3 single final result guard7; v4 result v0 binding7.
- Why it stops here: no improvement for 3 versions, strict R7 tie counts.
- Next hypothesis: single empty memory barrier after final call might prevent tailcall while retaining v0 transport, instead of result operand guard.
