# 0028ff68 blocked
- Range: 0028ff68, 128 bytes. Versions tried: 0. Best: none with unmeasured differing words (uncompiled/128 bytes).
- First difference of the best version: none; no version, ABI audit blocked before drafting.
- Changes tried: none.
- Why it stops here: R12 conservative unresolved ABI block under literal R4.3.
- Next hypothesis: resolve mixed untouched-entry and outgoing-callee-result return contract without inventing a zero or discarding results.
- R4.3 every exit: sole jr ra receives entry v0 when both object words are zero; receives func_00139d78 v0 when its condition is false; receives indirect callee v0 when called. Paths converge through branches 0028ff7c, 0028ff8c, 0028ffac, 0028ffbc. No f0 assignment in range. Mixed contract unresolved.
- R4.5: no declaration drafted; packet requires accepted 00139d78 declaration if resumed.
