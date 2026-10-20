# 001124f8 blocked
- Range: 001124f8, 108 bytes. Versions tried: 6. Best: v1 with 20 differing words (112/108 bytes).
- First difference of the best version: !! 00112518: 240e0808  li	t6,2056 | 00112518: 95eebae0  lhu	t6,-17696(t7)   ; = D_0032bae0
- Changes tried: C7 if/else (20); C7 result=2 default then if (20); comma form (result=2, mode==0x30d) (20); ternary on globals (20); switch with two cases (20); C11 register-bound result to $14 (20, registers fixed but schedule still differs).
- Why it stops here: no improvement for 3 versions. Compiler emits one extra instruction: it hoists "lui t7,0x34" into the bne delay slot and duplicates the li 1 path; original loads constant 0x808 before the lhu and has one shared lui after the merge.
- Next hypothesis: C9 volatile read of D_0032bae0 or C10 asm barrier to stop the lui hoist; or compare against a 0x808 held in a separate s32 variable to force constant-first order.
