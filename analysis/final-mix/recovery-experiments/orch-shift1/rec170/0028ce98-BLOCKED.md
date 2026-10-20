# 0028ce98 blocked
- Range: 0028ce98, 120 bytes. Versions tried: 0. Best: none; differing words and compiled bytes unavailable (target 120 bytes).
- First difference of the best version: unavailable; no source drafted or probed.
- Changes tried: none. R4.3 original-exit audit: equal-value path leaves entry v0/f0 untouched; changed-value paths tail-call 00138c10 and pass its result outward.
- Why it stops here: conservative R12 ABI block; mixed untouched-entry and outgoing-callee-result paths cannot use void under literal R4.3.
- Next hypothesis: resolve the mixed return contract without discarding the outgoing result or inventing a value for the untouched path.
- Specialty: abi-layout.
