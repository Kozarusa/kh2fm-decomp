# 00146d68 blocked
- Range: 00146d68, 120 bytes. Versions tried: 5. Best: v2 with 27 differing words (120/120 bytes).
- First difference of the best version: !! 00146d6c: 8c8e0010  lw	t6,16(a0)   | lw t2,16(a0)
- Changes tried: v1 plain struct copy, compare folded away (29 words, 104 bytes); v2 asm("" : "+r"(dest)) launder to keep dest!=source compare (27, size matches); v3 struct Block copy (27, same); v4 Block as u32[16] aligned(16) (27, same); v5 explicit Quad temporaries, load-all-then-store (27, lq order scrambled).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register allocation: original keeps count in a3, slot in t4 (a0 not reused), node t5, dest t6, src t7, quads t0-t3; try binding registers via register-asm or a different pointer/ int structure for the table walk, and copy via src pointer t7 with lq in order 0,16,32,48.
