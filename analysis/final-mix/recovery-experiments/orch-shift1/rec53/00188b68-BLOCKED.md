# 00188b68 blocked
- Range: 00188b68, 72 bytes. Versions tried: 5. Best: v2 with 9 differing words (72/72 bytes).
- First difference of the best version: !! 00188b6c: 30ad7fff  andi	t5,a1,0x7fff  | 00188b6c: 30a57fff  andi	a1,a1,0x7fff
- Changes tried: v1 inline u16 value + ((flag!=0)<<15) gave movn (13 words); v2 separate low/high temps (9, or hoisted before loop into a1); v3 s32 value with high temp inline in or (9); v4 for-loop with u16 entry pointer (13, movn); v5 v3 plus asm "+r" on high (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps low in t5 and high in a1 and the or inside the found block (not hoisted); try making low and high separate loop-variant-looking values (asm +r on both, or a volatile read of the flag) to stop the or being hoisted and force a fresh register for low.
