# 0029a368 blocked
- Range: 0029a368, 116 bytes. Versions tried: 0. Best: none with unmeasured differing words (uncompiled/116 bytes).
- First difference of the best version: none; no probe.
- Changes tried: none; literal R4.3 audit before drafting.
- Why it stops here: R12 unresolved ABI contract. Direct exit at 0029a3c4 preserves untouched entry v0/f0 on initial nonzero flag paths; initialization path returns outgoing 0029a2a0 registers; tail path returns 0029a3e0 result.
- Next hypothesis: ABI review must resolve mixed untouched-entry and outgoing-callee-result paths without inventing zero or discarding results.
