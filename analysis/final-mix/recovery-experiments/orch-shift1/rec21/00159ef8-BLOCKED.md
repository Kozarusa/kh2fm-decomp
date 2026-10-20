# 00159ef8 blocked
- Range: 00159ef8, 88 bytes. Versions tried: 6. Best: v3 (also v5) with 5 differing words (88/88 bytes).
- First difference of the best version: !! 00159efc: 0080782d  move	t7,a0   | 00159efc: ffb00000  sd	s0,0(sp)
- Changes tried: v1 plain Quad copies (19 words); v2 t7 cursor + t0 quad temp register bindings (23 words, body matched, extra s1 saved); v3 bind source to s0 with asm barrier (5 words, only prologue ordering differs: original does move t7,a0 first and addiu s0,t7,128 before the jal, ours does move s0,a0 and the addiu after the jal); v4 bound base to t7 (19 words); v5 unbound base temp with barrier (5 words, no change); v6 asm volatile on source barrier (21 words, addiu before jal but no t7 copy, 84 bytes).
- Why it stops here: no improvement for 3 versions (v4, v5, v6).
- Next hypothesis: C11 - get both the t7 copy of a0 and the early addiu s0: combine asm volatile barrier on source (v6) with an unbound base temp copy of object (v5), or compute source before the func_0016c028 argument load.
