# 001fcb18 blocked
- Range: 001fcb18, 120 bytes. Versions tried: 8. Best: v5 with 3 differing words (120/120 bytes).
- First difference of the best version: !! 001fcb3c: 8e24e6e8  lw	a0,-6424(s1)  | 001fcb3c: 8e26e6e8  lw	a2,-6424(s1)
- Changes tried: v1 straight (30, extra s2 saved); v2 add offset to object before first call, C12 (9); v3 local global pointer (9); v4 asm guard on object copy (28); v5 temp for global+16 argument (3); v6 local global plus temp (3); v7 register bind global to $4 (20); v8 head temp (3).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: only register choice differs (original loads the global into a0, then a2=a0+16, a0=a0+80 in the jal delay slot); try evaluating the +80 argument last via a temp assigned after the call arguments, or bind the +16 temp with an asm guard.