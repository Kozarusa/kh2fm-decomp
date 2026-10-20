# 001ac078 blocked
- Range: 001ac078, 88 bytes. Versions tried: 6. Best: v3 with 5 differing words (88/88 bytes).
- First difference of the best version: !! 001ac084: a1cc0000  sb	t4,0(t6)  | 001ac084: a1c70002  sb	a3,2(t6)
- Changes tried: v1 s64 params (26 words); v2 s32 params (9); v3 register bindings $12 first copy and $14 object cursor (5, but store order 2,0,1 and slti result in a3 instead of t5); v4 added $13 binding for the slti result (5, ignored); v5 volatile cursor (15); v6 only $12 binding (6, only t6/t7 swap of object/value temporaries).
- Why it stops here: no improvement for 3 versions (v4, v5, v6).
- Next hypothesis: from v6, additionally bind the object copy to $14 and the value temporary to $15 via asm("" : "+r"(name)) after assignment (C11d) without disturbing store order.
