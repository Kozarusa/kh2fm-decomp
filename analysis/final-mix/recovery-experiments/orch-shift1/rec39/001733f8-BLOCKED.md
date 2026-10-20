# 001733f8 blocked
- Range: 001733f8, 88 bytes. Versions tried: 8. Best: v6 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 00173428: dfbf0000  ld ra,0(sp)  (compiled has sw zero,12(t7) there; original puts the zero store after the ra reload, just before the tail j).
- Changes tried: v1 baseline 15; v2 post-decrement on field (C7) 16 words but head matched; v3 Vec4 struct global 9; v4 temps z,x,y 8; v5 direct x,y,z,w 10; v6 temps x,y,z then stores x,y,z,w 2; v7 volatile w store (C10c) worse; v8 asm memory barrier before w store (C10d) 5.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: make the w store depend on the end of the block, e.g. store 0 through a separate local pointer copy or write w=0 before the func call as part of the call argument sequence, or try w as f32/u32 type.
