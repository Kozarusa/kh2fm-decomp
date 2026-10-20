# 001c7148 blocked
- Range: 001c7148, 108 bytes. Versions tried: 6. Best: v3 with 22 differing words (108/108 bytes).
- First difference of the best version: !! 001c714c: 3c0f01d5  lui t7,0x1d5 | 3c0e01d5  lui t6,0x1d5 (register numbering of the D_01d498d0 base).
- Changes tried: v1 Quad pointer copies (25); v2 advance source variable (26); v3 aligned Vec structs with struct assignment (22); v4 same with Dest* local (25); v5 kn::FVector operator= from ../kn/fvector.hpp, lq t0 matches, but float stores go through the symbol (23, 116/108 bytes); v6 kn::FVector with Dest* local (23, 104/108 bytes, structure matches, registers differ).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: v6 is the right shape (kn::FVector copies, dest base in a register). Original keeps dest in t6, owner in t7, a separate t4 holding the address of D_0036df90 (lwc1 0(t4)) and t5=dest+16: try reading the constant through a pointer f32* c=&D_0036df90 (extra register), then C11 temporaries.
