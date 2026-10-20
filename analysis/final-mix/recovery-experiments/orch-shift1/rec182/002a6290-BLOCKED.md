# 002a6290 blocked
- Range: 002a6290, 120 bytes. Versions tried: 7. Best: v4 with 26 differing words (124/120 bytes).
- First difference of the best version: !! 002a629c: 3c120036 lui s2,0x36 | 002a629c: ffb10008 sd s1,8(sp).
- Changes tried: v1 fresh loop 29 words; v2 C1 shared pointer temporary 27; v3 C11 global-address temporary 29; v4 C11 s2 binding 26; v5 C11 one global guard 27; v6 C5 integer high-address transport 32; v7 C11 count-initialization reorder 26.
- Why it stops here: no improvement for 3 versions after v4; strict streak3 at v7.
- Next hypothesis: C12 remove s2 binding from v4, preserving shared pointer loop, to assess prologue scheduling independently.
- Correction to next hypothesis: removing s2 binding reproduces v3, already tried. Next untried C11 control: bind existing index to original s0 independently, preserving v4 otherwise.
