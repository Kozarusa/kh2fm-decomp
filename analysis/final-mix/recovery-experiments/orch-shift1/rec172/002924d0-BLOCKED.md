# 002924d0 blocked
- Range: 002924d0, 76 bytes. Versions tried: 2. Best: v1 with 14 differing words (64/76 bytes).
- First difference of the best version: !! 002924d4: ffb00000 sd s0,0(sp) | 002924d4: 24822b3c addiu v0,a0,11068.
- Changes tried: v1 direct integer address translation 14; C11d one object guard before fallback v2 15.
- Why it stops here: orchestrator STOP under R12.
- Next hypothesis: C7 explicit if/else assignments for initial result, preserving fallback guard and unsigned address transport.
- R4.3: sole original jr ra returns defined v0 on both paths: object+11068 for zero a1; outgoing 001a8190 result or fallback otherwise. No f0 flow.
- R4.5: exact extern "C" u32 func_001a80c8(...); copied from fm_primary_addresspair_recovered_001a6c60.cpp; extern "C" u32 func_001a8190(s32); copied from fm_primary_sixwordnext_recovered_002ba140.cpp.
