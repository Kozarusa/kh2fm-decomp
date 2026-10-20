# 001286d0 blocked
- Range: 001286d0, 128 bytes. Versions tried: 4. Best: v1 with 26 differing words (120/128 bytes).
- First difference of the best version: !! 001286d8: 25efaa14  addiu	t7,t7,-21996   ; = D_0036aa14 | 001286d8: c5e7aa14  lwc1	$f7,-21996(t7)   ; = D_0036aa14
- Changes tried: v1 straight translation of Ghidra expression, f32 globals (26); v2 u8[] globals cast to f32* (26); v3 volatile f32 globals (29); v4 f32[] arrays read through a pointer (26).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original builds each global address with separate lui+addiu and loads via 0(reg) (so the aa14 and aa18 reads are separate pointer values, load of aa18 scheduled after the first mul); try reading the constants through an extern pointer table or non-CSE'd pointer variables, and reorder the mul statements to match the original ($f5=t*t first, then $f2=sq*t, $f3=sq*D2, $f1=inv*inv, $f5=sq*inv).
