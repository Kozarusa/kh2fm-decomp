# 0028ce38 blocked
- Range: 0028ce38, 92 bytes. Versions tried: 0. Best: none; differing words and compiled bytes unavailable (target 92 bytes).
- First difference of the best version: unavailable; no source drafted or probed.
- Changes tried: none. R4.3 original-exit audit: the nonpositive-count path leaves entry v0/f0 untouched; the positive-count path returns the final callee result untouched.
- Why it stops here: conservative R12 ABI block; mixed untouched-entry and outgoing-callee-result paths cannot use void under literal R4.3.
- Next hypothesis: resolve the mixed return contract without discarding the outgoing result or inventing a value for the untouched path.
- Specialty: abi-layout.
