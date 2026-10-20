# 002a0168 blocked
- Range: 002a0168, 92 bytes. Versions tried: 0. Best: none with unavailable differing words (unavailable/92 bytes).
- First difference of the best version: none; no probe.
- Changes tried: none; literal R4.3 audit found an untouched entry-v0 default return and outgoing callee-result tail exits at 002a01a8 and 002a01bc.
- Why it stops here: R12 unresolved mixed return ABI; default path preserves entry v0/f0, while other paths return outgoing callee results.
- Next hypothesis: ABI review must represent mixed untouched-entry and outgoing-callee-result paths without an exception.
