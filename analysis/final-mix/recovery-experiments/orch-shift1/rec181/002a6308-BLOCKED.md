# 002a6308 blocked
- Range: 002a6308, 92 bytes. Versions tried: 0. Best: none, differing words unavailable (uncompiled/92 bytes).
- First difference of the best version: unavailable; no probe.
- Changes tried: none; literal R4.3 return audit before drafting.
- Why it stops here: R12 unresolved ABI. The default path returns untouched entry v0/f0. Cases 37 and 38 tail-call callees and expose their results. A void declaration would discard outgoing results; returning zero would invent the default result.
- Next hypothesis: establish a permitted ABI representation for mixed untouched-entry and outgoing-callee-result paths.
