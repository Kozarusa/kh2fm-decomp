# 0029ea30 blocked
- Range: 0029ea30, 116 bytes. Versions tried: 0. Best: none with N/A differing words (N/A/116 bytes).
- First difference of the best version: N/A; no probe.
- Changes tried: none.
- Why it stops here: R3 boundary condition. No jr ra; range ends with b to internal epilogue and delay slot, rather than j/jal plus delay slot. This is not the never-returning-loop exception: internal epilogue tail-jumps to a callee.
- Next hypothesis: boundary-review of tail-call range and jump-table coverage.
