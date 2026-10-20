# 001ad020 blocked
- Range: 001ad020, 120 bytes. Versions tried: 4. Best: v1 with 10 differing words (120/120 bytes); the earlier rec81 v3 (6 words) remains the best known overall.
- First difference of the best version: !! 001ad024: 24e7000a  addiu	a3,a3,10 | 001ad024: 240f0158  li	t7,344
- Changes tried: v1 empty "+r" guard on the product (10); v2 guard on the constant 344 (13); v3 one variable reused for constant, product and entry (16); v4 constant bound to $16 (26, extra s3 and bigger frame).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: keep rec81 v3 and make the constant 344 live across the call in s0 without binding (for example use the product variable after the call, or reorder the x/y shift temporaries so entry is allocated first).
