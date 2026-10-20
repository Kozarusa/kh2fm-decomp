# 001c2ce8 blocked
- Range: 001c2ce8, 76 bytes. Versions tried: 4. Best: v1 (also v3) with 2 differing words (76/76 bytes).
- First difference of the best version: !! 001c2d20: ae0f0000  sw	t7,0(s0)  | 001c2d20: ae0e0abc  sw	t6,2748(s0)
- Changes tried: v1 copy of eight_hour_001c2ce8_revisit_store_order_2 with names fixed (2); v2 canonical struct (typed table pointer, natural |= order) (7: t5/t6 swapped plus same store swap); v3 non-volatile asm "+m"(mode field) : "m"(table field) between the final stores (2, no effect at all); v4 raw casts in order flags, table, mode read-modify-write (7: same register swap as v2, same store swap).
- Why it stops here: no improvement for 3 versions.
- Observations: the t5/t6 assignment needs the mode value computed before the flags value in source (v1 order); the final mode store is scheduled before the table store in every form, and a non-volatile memory-output asm tie does not reorder it (earlier workers: volatile on either store keeps it, both volatile or a barrier perturb the flag loads).
- Next hypothesis: write the table store through a base the alias analysis cannot separate from the mode field (for example a second pointer to the object such as a base-class or reinterpret view, or an asm-opaque copy of the object pointer used only for the table store) so the stores get an output dependence while the v1 load order and registers stay.
