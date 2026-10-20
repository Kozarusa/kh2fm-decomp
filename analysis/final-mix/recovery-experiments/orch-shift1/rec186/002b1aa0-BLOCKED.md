# 002b1aa0 blocked
- Range: 002b1aa0, 80 bytes. Versions tried: 0. Best: none, no differing-word count or compiled bytes available (target 80 bytes).
- First difference of the best version: unavailable, no probe.
- Changes tried: none; R4.3 audit confirms all exits return v0 (constant or global).
- Why it stops here: R12 ABI conflict. Both packet-named accepted sources declare func_002b23e0(void), while original sets a0=-1 before jal. Exact R4.5 declaration cannot express original argument without an exception.
- Next hypothesis: reconcile packet accepted callee declaration with original a0=-1 transport before recovery.

Review follow-up: accepted u32 func_002b23e0(void) conflicts with original a0=-1. No R4.5 exception is granted; reconcile declaration evidence before recovery. Static files do not independently prove historical tool timing or polling.
