# 00139a38 blocked
- Range: 00139a38, 116 bytes. Versions tried: 0. Best: none; no probe performed.
- First difference of the best version: unavailable (R3 boundary check).
- Changes tried: none.
- Why it stops here: R3 condition. The range ends with b 0x139a64 and its lw delay slot, rather than jr ra or j/jal plus a delay slot.
- Next hypothesis: Review the function boundary and authorize treatment of the backward branch after the internal epilogue.
