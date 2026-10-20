# 001aa310 blocked
- Range: 001aa310, 120 bytes. Versions tried: 5. Best: v2 with 14 differing words (116/120 bytes; v1 also 14 at 120/120 bytes).
- First difference of the best version: !! 001aa350: 25efd6a4  addiu	t7,t7,-10588   ; = D_0036d6a4  |  001aa350: dfbf0010  ld	ra,16(sp)
- Changes tried: v1 plain float code (14, int saved in s2); v2 convert to f32 before the call so it lives in $f20 (14, first 16 words now match); v3 global as f32 array deref (14); v4 local pointer to the global (14); v5 volatile float read (14).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original forms the constant address with a separate addiu and loads lwc1 0(t7) after ld ra; try keeping the address in a variable of a different kind (u32 address cast to f32*, or passing &D_0036d6a4 via a const f32* parameter-like temp), or an asm register bind of the pointer to $15.
