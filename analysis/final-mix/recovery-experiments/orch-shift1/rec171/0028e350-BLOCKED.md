# 0028e350 blocked
- Range: 0028e350, 100 bytes. Versions tried: 0. Best: none; differing words unavailable (compiled unavailable/100 target bytes).
- First difference of the best version: unavailable; no version drafted or probed.
- Changes tried: none; literal R4.3 return-path audit only.
- Why it stops here: R12 conservative ABI block; null path preserves untouched entry v0/f0, nonnull path propagates final 00106450 result. No permitted void exception, invented zero, or discarded result.
- Next hypothesis: establish a representable mixed entry-register and outgoing-callee-result contract before recovery.
