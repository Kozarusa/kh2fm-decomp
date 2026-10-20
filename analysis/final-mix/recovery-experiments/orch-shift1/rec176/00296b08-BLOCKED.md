# 00296b08 blocked
- Range: 00296b08, 116 bytes. Versions tried: 0. Best: none, differing words unavailable (uncompiled/116 bytes).
- First difference of the best version: none; zero versions.
- Changes tried: none; R4.3 audit before drafting.
- Why it stops here: R12 conservative ABI block. Initial nonzero flag and second nonzero flag path returns untouched entry v0/f0. Other exits preserve outgoing 002969e0 result or tail-call 00296b80(1) result. Mixed untouched-entry and callee-result exits cannot use void under literal R4.3.
- Next hypothesis: resolve mixed entry-register and outgoing-callee-result return contract before source recovery.
