# 0028d2a0 blocked
- Range: 0028d2a0, 128 bytes. Versions tried: 0. Best: none; differing words and compiled bytes unavailable (target 128 bytes).
- First difference of the best version: unavailable; no source drafted or probed.
- Changes tried: none. R4.3 original-exit audit: flag 0x100 path leaves entry v0/f0 untouched; unflagged paths retain outgoing 003142e0 v0, and arithmetic paths additionally write f0 before the common exit.
- Why it stops here: conservative R12 ABI block; mixed untouched-entry, outgoing-callee-result, and float-write return paths cannot use void under literal R4.3.
- Next hypothesis: resolve the mixed return-register contract without discarding callee results or inventing values for untouched paths.
- Specialty: abi-layout.
