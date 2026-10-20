# 001dddd0 blocked
- Range: 001dddd0, 108 bytes. Versions tried: 6. Best: v3 with 5 differing words (108/108 bytes).
- First difference of the best version: !! 001dddd4: 24ae0010  addiu	t6,a1,16  |  001dddd4: 24af0010  addiu	t7,a1,16
- Changes tried: v1 straight translation (25 words); v2 separate base copy with empty asm guard (7); v3 swap head/tail stores in empty-list branch, C10a (5); v4 store object[0] from data instead of copy (10); v5 bind copy to register t7 via asm("$15") (9); v6 define copy after first store (5).
- Why it stops here: no improvement for 3 versions (v4, v5, v6).
- Next hypothesis: C11: original has t6=a1+16 and t7=copy of a1 (used only in the final sum) while object[0] is stored from a1 itself; bind the a1+16 temp to t6 ("$14") and the copy to t7 with the object[0] store left on data, as separate changes (v5 tried only the copy binding).
