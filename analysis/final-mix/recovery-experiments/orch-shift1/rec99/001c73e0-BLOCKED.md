# 001c73e0 blocked
- Range: 001c73e0, 60 bytes. Versions tried: 4. Best: v1 with 12 differing words (52/60 bytes).
- First difference of the best version: !! 001c73e8: 25efdfa8  addiu	t7,t7,-8280   ; = D_0036dfa8 | 001c73e8: ffb00000  sd	s0,0(sp)
- Changes tried: v1 return func_7440 (12, tail call j emitted); v2 void (C13, 12, still sibcall); v3 empty asm memory barrier after last call (13, jal+jr ra now correct, 56 bytes); v4 volatile f32* pointer read (C9, 13, lwc1 still folds -8280(t7)).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps lui/addiu pointer formed before sd s0/ra and loads lwc1 0(t7); try an array or struct-member declaration (f32 D_0036dfa8[] with a register-held pointer, or a non-tail wrapper such as a trailing real statement) so the address is materialized with addiu and the call is not a sibcall.
