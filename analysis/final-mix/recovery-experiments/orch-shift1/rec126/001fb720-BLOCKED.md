# 001fb720 blocked
- Range: 001fb720, 108 bytes. Versions tried: 4. Best: v1 with 11 differing words (108/108 bytes).
- First difference of the best version: !! 001fb724: ffb00000  sd	s0,0(sp) | 001fb724: 8cce000c  lw	t6,12(a2)
- Changes tried: v1 plain pointers, variadic callee (11); v2 C9 volatile f32 read (18); v3 C9 volatile u16 read (20); v4 struct types for message/entry (11, same schedule).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: scheduling hoists lw t6,12(a2) above the s-register saves and lhu above lwc1; try making the callee declared with explicit (void) / return value, or volatile read of other+12.
