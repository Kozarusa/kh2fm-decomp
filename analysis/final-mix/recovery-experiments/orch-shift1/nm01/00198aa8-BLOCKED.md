# 00198aa8 blocked
- Range: 00198aa8, 56 bytes. Versions tried: 5. Best: v1 with 2 differing words (56/56 bytes); earlier rec62 v2 had 1.
- First difference of the best version: !! 00198ad0: 01c67021  addu	t6,t6,a2  | compiled 008f7821  addu	t7,a0,t7 (operand order now right, but the two adds are swapped).
- Changes tried: v1 C11d asm +r guard on scaled index (2); v2 plus +r guard on total (2); v3 both guards volatile (4); v4 authoring error, comment swallowed code (14, invalid); v5 C11c bind scaled to register 15 (8).
- Why it stops here: no improvement for 3 versions (v5 was a retry of the v4 authoring error).
- Next hypothesis: keep earlier rec62 v2 and try a union/pointer-typed object (u8* base) with scaled added via pointer arithmetic, or store total through a separate volatile-free temp declared after the scaled multiply.
