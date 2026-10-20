# 001398d0 blocked
- Range: 001398d0, 116 bytes. Versions tried: 6. Best: v3 with 4 differing words (116/116 bytes).
- First difference of the best version: !! 001398f0: 16000012  bnez	s0,0x13993c | 001398f0: 12000012  beqz s0,13993c (and D load goes to t7 then lw a0,4(t7) in the out-of-line block; original loads D into a0 inline and puts the cur->next block out of line).
- Changes tried: v1 while(1) if(cur==0)/else 21 words; v2 while(1) ternary 19; v3 comma-in-while ternary `cur ? cur->next : D->next` 4; v4 pointer select p=cur or D then p->next 21 (movz); v5 goto layout 23; v6 v3 + register node asm("$4") 4 (no change).
- Why it stops here: no improvement for 3 versions (v4,v5,v6).
- Next hypothesis: C7 branch-sense: find a source shape making gcc place the cur->next block out of line with D load in the bnez delay slot (e.g. inlined iterator with explicit first/next, or switching arms with different pointer types).
