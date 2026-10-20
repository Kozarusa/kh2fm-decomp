# 0017c870 blocked
- Range: 0017c870, 128 bytes. Versions tried: 4. Best: v1 with 11 differing words (128/128 bytes).
- First difference of the best version: !! 0017c874: 3c0f0035  lui	t7,0x37 (original) vs 0017c874: acc00014  sw	zero,20(a2) (compiled). The compiler schedules `sw zero,20(a2)` first; the original schedules it after the two lwc1 loads, just before the jal 184540 (original 0017c8a0). Everything else is the same instructions, only shifted by one word.
- Changes tried: v1 FVector return by value from func_00184540(u8*) plus kn::FVector operator= (11 words); v2 zero store written first, then delta load (11); v3 loads of delta and current field first, then zero store (11); v4 zero store through volatile pointer (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(d) put asm volatile("" ::: "memory") between the loads and the zero store, or C10(b) a non-zero-literal store through a separate variable holding 0.