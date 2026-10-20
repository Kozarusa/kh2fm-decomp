# 001dddd0 blocked
- Range: 001dddd0, 108 bytes. Versions tried: 4. Best: v1 with 5 differing words (108/108 bytes).
- First difference of the best version: !! 001dddd4: 24ae0010  addiu	t6,a1,16  | 001dddd4: 24af0010  addiu	t7,a1,16
- Changes tried: v1 register binding of the a1+16 temp to 14 on the rec116 v3 base (5, binding had no effect); v2 also bind the copy to 15 (9, registers right but prologue order and early object[0] store wrong); v3 v2 with object[0] stored from data (10); v4 no bindings, guard placed before the a1+16 store (5, same swap).
- Remaining diff in v1: t6 and t7 swapped (a1+16 goes in t7, copy in t6) and the dependent sw/addu/sw words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: with the copy bound to 15, keep the v1 instruction order by moving the object[1] store above the binding and storing object[0] through self after the binding; or bind only the copy to 15 and leave the a1+16 temp unbound.
