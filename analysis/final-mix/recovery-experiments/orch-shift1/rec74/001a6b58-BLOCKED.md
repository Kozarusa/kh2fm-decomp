# 001a6b58 blocked
- Range: 001a6b58, 108 bytes. Versions tried: 4. Best: v1 with 11 differing words (108/108 bytes).
- First difference of the best version: !! 001a6b74: 8e0d0600  lw	t5,1536(s0)   vs   8e0e0600  lw t6,1536(s0)
- Changes tried: v1 straight field order c,a,state,b (11 words); v2 source order b,a,table,c,state (15); v3 mask of flags_b computed in a temp first, stores c,a,state,b (11, identical output); v4 asm memory barrier after the state store (17).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the call and body are right; only scheduling/register choice differs (original loads b,a,c into t5,t4,t6 and stores table,c,a,state,b). Try C11 temps with different declaration order (separate u32 locals loaded in order b,a,c then stored in order c,a,state,b), or volatile flags_c read (C9).
