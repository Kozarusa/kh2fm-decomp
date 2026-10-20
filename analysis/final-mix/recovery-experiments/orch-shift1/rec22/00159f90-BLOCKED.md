# 00159f90 blocked
- Range: 00159f90, 64 bytes. Versions tried: 5. Best: v2 with 13 differing words (64/64 bytes).
- First difference of the best version: !! 00159f90: 3c0e0035  lui	t6,0x35 (compiled lui t7,0x37; the original keeps the D_0034aa44 base in t6 and puts sw zero in the first beqz delay slot, while the compiled code reorders the pointer selection and inverts the first branch).
- Changes tried: v1 direct float loads, no pointer (11 words, size 60); v2 Ghidra-shaped f32* pointer nested if/else (13); v3 zero store first plus nested pointer (16); v4 zero store first plus else-if chain (18); v5 dest pointer to hold D_0034aa44 base (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7/C8, make the shared lwc1 pointer load volatile or tie the t6 base via register binding (C11c), keeping the beqz a1 -> flags&8 test layout of v1 with a pointer.