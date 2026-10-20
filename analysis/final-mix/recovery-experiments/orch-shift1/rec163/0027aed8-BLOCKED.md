# 0027aed8 blocked
- Range: 0027aed8, 124 bytes. Versions tried: 0. Best: none, no probe (n/a/124 bytes).
- First difference of the best version: n/a; no eligible draft.
- Changes tried: none; literal R4.3 audit precedes drafting.
- Why it stops here: R12 unresolved mixed entry-v0 and callee-result return contract. a0==0 stores two zeros but never writes v0; nonzero path returns callee 0027ae20 v0 untouched. Void or explicit zero would violate R4.3. Capturing entry v0 requires asm forbidden in version 1 by R4.8.
- Next hypothesis: orchestrator ABI ruling allowing a defined entry-v0 capture in initial source, or boundary/type evidence resolving contract.
