# 001e41e0 blocked
- Range: 001e41e0, 104 bytes. Versions tried: 6. Best: v3 with 8 differing words (104/104 bytes).
- First difference of the best version: !! 001e41e4: ffbf0008  sd	ra,8(sp) | ffb00000  sd	s0,0(sp)
- Changes tried: v1 pointer types, plain: 23 words (tail-call j). v2 + barrier after last call: 24. v3 copy of earlier 8-word style (s32 callee3650 variadic, u64 first param of 3660, barriers after every call): 8. v4 all void* types: 24. v5 3660 takes s32: 24. v6 volatile first load: 24.
- Why it stops here: no improvement for 3 versions (v4, v5, v6 after best v3).
- Next hypothesis: original saves ra before s0 and loads 136(a0) into v0 before move s0,a0 (arg pre-loaded into v0, then moved to a0 in jal delay slot; second move a0,v0 after return without dsll32); needs a form where the u64 arg 3660 does not emit dsll32/dsrl32 and the first load is hoisted (C9/C10 ordering).