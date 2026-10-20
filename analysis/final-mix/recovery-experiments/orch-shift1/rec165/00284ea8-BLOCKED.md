# 00284ea8 blocked
- Range: 00284ea8, 68 bytes. Versions tried: 1. Best: v1 with 3 differing words (68/68 bytes).
- First difference of the best version: !! 00284ec4: 8c4e0000 lw t6,0(v0) | 00284ec4: 8c4f0000 lw t7,0(v0)
- Changes tried: v1 scalar virtual call translation, 3 words.
- Why it stops here: orchestrator STOP after completed v1 probe.
- Next hypothesis: C11a/C11b isolate vtable pointer temporary before callback load; bind only after testing statement order.
- ABI: no parameters; outgoing virtual callback result forwarded after zero store.
