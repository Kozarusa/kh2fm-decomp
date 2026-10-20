# 001c70e8 blocked
- Range: 001c70e8, 96 bytes. Versions tried: 5 (v1 was a link error from an invented symbol). Best: v2 with 23 differing words (96/96 bytes).
- First difference of the best version: !! 001c70e8: 3c0f0037  lui t7,0x37 | 3c0b01d5  lui t3,0x1d5 (whole-function schedule and register allocation differ).
- Changes tried: v2 plain globals with u64 cast for ld/sd (23); v3 f32 array D_01d498f0[] base (24); v4 pointers p=&D_01d498f0 and q=p-32 bytes, 88/96 bytes (24); v5 same plus source floats via pointers (23).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has bases t4=&D_01d498f0 and t5=t4-32, direct store to D_01d498f0, floats loaded via formed addresses; the D_01d49940 word op is first in time. Try a struct covering 0x1d498d0..0x1d49944 with the word op on a union member, or C10 asm memory barriers between the stores.
