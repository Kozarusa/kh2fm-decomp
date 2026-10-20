# 00186d18 blocked
- Range: 00186d18, 44 bytes. Versions tried: 6. Best: v2 with 8 differing words (40/44 bytes).
- First difference of the best version: !! 00186d20: 11e00006  beqz	t7,0x186d3c | 00186d20: 11e00005  beqz	t7,186d38 (original has extra xori t7,t7,0 and value in t6 / 140-compare before 151-compare)
- Changes tried: v1 flat pointer cast (10 words); v2 sub-struct pointer at +320 giving addiu a0 (8); v3 && expression (8, sltiu range form); v4 separate below/under temps (8, movn); v5 below==0 (8); v6 (value<140)^0 ternary (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register binding of value to $14 (t6) with asm("" : "+r"(value)), or an inline bool helper returning (value>=140) so xori t7,t7,0 appears.
