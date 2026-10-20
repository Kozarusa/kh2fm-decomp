# 0015a528 blocked
- Range: 0015a528, 128 bytes. Versions tried: 7. Best: v4 with 10 differing words (128/128 bytes).
- First difference of the best version: !! 0015a530: ffb20030  sd	s2,48(sp) (compiled sd s1,40(sp)). All 10 differing words are one thing: object is in s1 and the result address in s2, the original has object in s2 and result in s1.
- Changes tried: v1 FVector copies with operator= (13 words); v2 result declared first (30, stack layout swapped); v3 local result pointer (13); v4 unguarded lq/sq inline asm for the initial copy (10); v5 resultp bound to $17 (29, extra s3); v6 object bound to $18 (16); v7 resultp declared first (13).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11d, add asm("" : "+r"(object)) or "+r"(target) after assignment in the v4 source, or compute &result before the target pointer with the asm copy placed after it.