# 002aa8e0 blocked
- Range: 002aa8e0, 128 bytes. Versions tried: 2. Best: v2 with 27 differing words (132/128 bytes).
- First difference of the best version: !! 002aa8e4: ffb10008 sd s1,8(sp) | 002aa8e4: ffb00000 sd s0,0(sp).
- Changes tried: v1 s8 entry with exact accepted callee declaration, 31 words; C1 v2 full-width u32 entry to preserve original value transport, 27 words.
- Why it stops here: R12 conservative ABI block; all packet-named accepted sources declare func_002aa5b8(s8,s32), which introduces argument narrowing sll/sra absent from original full-register move. Cannot relax R4.5 declaration reuse.
- Next hypothesis: orchestrator ABI review of accepted func_002aa5b8(s8,s32) declaration against original full-register transport, before further scheduling work.
