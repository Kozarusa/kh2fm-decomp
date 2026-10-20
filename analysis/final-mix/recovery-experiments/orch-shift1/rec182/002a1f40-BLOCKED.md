# 002a1f40 blocked
- Range: 002a1f40, 60 bytes. Versions tried: 0. Best: none with unavailable differing words (unavailable/60 bytes).
- First difference of the best version: none; no probe.
- Changes tried: none; R3 boundary inspection.
- Why it stops here: R3 boundary condition: no jr ra, final branch returns to an internal tail-call epilogue rather than a never-returning loop. Range ends b plus delay slot, not j/jal plus delay slot.
- Next hypothesis: boundary review must authorize this tail-call epilogue with following shared block.
