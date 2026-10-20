# 001e03b0 blocked
- Range: 001e03b0, 80 bytes. Versions tried: 0. Best: none.
- First difference of the best version: n/a (not probed).
- Changes tried: none.
- Why it stops here: R3 boundary condition. The range holds three functions: a wrapper (prologue, sd ra, ld ra, j 001e03d8, delay-slot sp restore), two dead jr ra stubs, and the real body at 001e03d8 (zero-store of 9 words, jr ra). One func_001e03b0 cannot emit this layout.
- Next hypothesis: boundary-review, split the range at 001e03d8 and possibly 001e03c8/001e03d0.
