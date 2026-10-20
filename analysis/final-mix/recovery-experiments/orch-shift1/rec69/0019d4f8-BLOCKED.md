# 0019d4f8 blocked
- Range: 0019d4f8, 80 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 boundary condition. The range holds two functions: 0019d4f8..0019d514 (32 bytes, tail-calls 0x19d518 with j, then a nop pad) and 0019d518..0019d548 (separate prologue and epilogue, calls 1bc688 then tail-calls 190128). One func_ cannot emit both.
- Next hypothesis: boundary review: split the range into 0019d4f8 (32 bytes) and 0019d518 (48 bytes).
