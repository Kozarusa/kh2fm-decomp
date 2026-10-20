# 00294f00 blocked
- Range: 00294f00, 116 bytes. Versions tried: 0. Best: none with unmeasured differing words (uncompiled/116 bytes).
- First difference of the best version: none; no probe.
- Changes tried: none; literal R4.3 audit before drafting.
- Why it stops here: R12 unresolved ABI contract. Direct exit at 00294f5c preserves untouched entry v0/f0 on initial nonzero flag paths; the initialization path returns outgoing 00294e48 registers; tail path returns 00294f78 result.
- Next hypothesis: ABI review must resolve mixed untouched-entry and outgoing-callee-result paths without inventing zero or discarding results.
