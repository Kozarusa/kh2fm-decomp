# 001b9d40 blocked
- Range: 001b9d40, 112 bytes. Versions tried: 5. Best: v2 with 14 differing words (104/112 bytes).
- First difference of the best version: !! 001b9d64: 1040000c  beqz	v0,0x1b9d98  (compiled beqz v0,1b9d90 with li t5,1 in the delay slot instead of move t5,zero)
- Changes tried: v1 single || chain (24 words, masks merged to andi 0x1c); v2 flag var with if/else-if chain (14); v3 flag var with || chain (24); v4 if/else-if assigning result directly (18); v5 ternary chain (16, compiler used sra/andi).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8/C7 - original keeps t5=0 live through the last test (beqz delay slot moves t5 into s1); try volatile read of flags or a nested else { if (flags & 0x10) } with a flag initialised before the virtual call test.
