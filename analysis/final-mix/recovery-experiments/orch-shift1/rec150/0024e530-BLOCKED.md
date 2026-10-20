# 0024e530 blocked
- Range: 0024e530, 124 bytes. Versions tried: 1. Best: v1 with 22 differing words (124/124 bytes).
- First difference of the best version: !! 0024e554: 0222102a slt v0,s1,v0 | 0024e554: 0202102a slt v0,s0,v0.
- Changes tried: initial instruction-derived reconstruction v1 22.
- Why it stops here: R12 conservative block: sole accepted caller declares func_0024dfe0 as void(u32), but original sets no argument and consumes v0. v1 instruction-derived declaration differs from required copied declaration. No submission.
- Next hypothesis: reconcile func_0024dfe0 ABI before further probes; then C11 bind index s1 and offset s0, followed by branch layout.
