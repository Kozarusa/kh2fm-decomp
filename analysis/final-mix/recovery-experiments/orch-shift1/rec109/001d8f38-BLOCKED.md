# 001d8f38 blocked
- Range: 001d8f38, 108 bytes. Versions tried: 5. Best: v2 with 9 differing words (112/108 bytes).
- First difference of the best version: !! 001d8f50: 0000102d  move	v0,zero | 001d8f50: 0000202d  move	a0,zero
- Changes tried: v1 early returns with u32 word and u8 flag (10, sra/andi bool conversion); v2 bool result var in nested if/else with u32 bit temp (9); v3 register bool result asm("$2") (12, worse); v4 u32 result type (9); v5 typed struct slots[] (10, lbu).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: compiler puts the result in a0 then move v0,a0 and uses addu s0,v0 instead of v0,s0; not yet tried: volatile on the final load, or restructuring so the result comes straight from the sltu in v0 (for example return the comparison directly in the last branch with the init zero before the first call).
