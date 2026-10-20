# 001759f0 blocked
- Range: 001759f0, 124 bytes. Versions tried: 4. Best: v1 with 20 differing words (124/124 bytes).
- First difference of the best version: !! 00175a00: 0c066144  jal 0x198510 | 00175a00: 0080802d  move s0,a0 (compiler hoists move s0,a0 before the jal and puts move s1,zero in the jal delay slot; original keeps move s0,a0 in the jal delay slot and sets s1 after the beqz; result is kept in t7 in the original but in s1 in ours).
- Changes tried: v1 do-while with result var 20; v2 for loop 20; v3 Ghidra-shaped while(1) 28 (128 bytes); v4 goto done 31 (132 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the loop index and result separate (index in s1, result via t7) e.g. write the loop as the second block reached only after the vtable call, or declare the item-pointer slot walk with a volatile read (C9) so the loop-entry move s1,zero is placed after the beqz.