# 0016f9e8 blocked
- Range: 0016f9e8, 108 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 boundary condition. The range contains no jr ra and ends with an unconditional b back to 0016fa08 (infinite loop), not j/jal.
- Next hypothesis: boundary-review: confirm the range is a complete never-returning function (void loop calling FlushCache(0), conditionally func_001707d8, then func_0014d430), then attempt with while(1).