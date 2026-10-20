# 001ad158 blocked
- Range: 001ad158, 116 bytes. Versions tried: 4. Best: v1 with 2 differing words (116/116 bytes).
- First difference of the best version: !! 001ad174: ffbf0028  sd	ra,40(sp) (original) vs sd s0,0(sp) (compiled); the ra and s0 prologue saves are swapped.
- Changes tried: v1 bind result to $16 with why comment (2, same as nm05 v3); v2 copy fourth to a local, no result binding (2); v3 bind pointer copy to $16 instead of result (11, registers shift); v4 also bind fourth to $17 and result to $16 (23, extra s5 and bigger frame).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the s0/ra save order is a prologue scheduling effect, not allocation; try dropping the first memory barrier between the calls but keeping the second, or placing the object store before the +4/+8 stores via a local pointer copy, to change when s0 becomes live relative to the ra save.