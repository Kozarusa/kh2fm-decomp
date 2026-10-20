# 001c1748 blocked
- Range: 001c1748, 96 bytes. Versions tried: 6. Best: v3 with 6 differing words (96/96 bytes).
- First difference of the best version: !! 001c1748: 78c80000  lq	t0,0(a2)  | 001c1748: 78ce0000  lq	t6,0(a2)
- Changes tried: v1 scratch rewrite with Quad copy, 23 words. v2 C7a inverted tail branch, 23 words. v3 List* list = &owner->list computed first (addiu t5), 6 words. v4 C10d asm memory barrier after quad copy, 7 words. v5 temp Quad variable, 6 words. v6 struct Quad aligned(16) instead of mode(TI), 8 words.
- Remaining diff in v3: original does lq t0 / sq t0 back to back at the start (then li, sw a3, sb, addiu t5); compiled delays sq to after sb zero,20 and uses t6 instead of t0.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(a)/(b) reorder source statements (move the quad copy after the byte stores or the list pointer later) or C11(c) register binding; or C14 volatile quad read.
