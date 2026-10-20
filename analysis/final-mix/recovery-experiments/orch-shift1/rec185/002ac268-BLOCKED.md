# 002ac268 blocked
- Range: 002ac268, 128 bytes. Versions tried: 2. Best: v2 with 27 differing words (132/128 bytes).
- First difference of the best version: !! 002ac26c: ffb10008 sd s1,8(sp) | 002ac26c: ffb00000 sd s0,0(sp).
- Changes tried: v1 fresh s8 parameter, explicit masked return and unsigned shifts/address transport, 31 words. C1/R4.3 v2 s32 parameter, 27 words.
- Why it stops here: conservative R12 ABI block. Every packet-named accepted func_002abf40 declaration is exactly extern "C" s32 func_002abf40(s8,s32); original transports a0 unchanged into that call, but this compiler normalizes s8 at entry (v1) or before call (v2). Changing the accepted callee declaration would violate R4.5; skipping the literal outgoing masked result would violate R4.3.
- Next hypothesis: resolve accepted callee s8 contract against original unchanged argument transport before further scheduling work; no declaration exception attempted.
