# 0011f270 blocked
- Range: 0011f270, 128 bytes. Versions tried: 8. Best: v8 with 7 differing words (128/128 bytes).
- First difference of the best version: !! 0011f298: 86020004  lh	v0,4(s0)   | compiled: 240e0001  li	t6,1
- Changes tried: v1 straight nested ifs plus while (23 words, 148 bytes); v2 && conditions with assignment in condition (worse); v3 single loop (104 bytes, too small); v4 nested form with shared mask var (~140 bytes); v5 && conditions indexing entries[parent] with mask var (larger); v6 if + do-while with parent load inside (14 words, layout matches); v7 mask declared inside after entry (worse); v8 v6 plus register bindings t4/t5/t6 (7 words).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the compiler hoists li t6,1 above lh and addu has the operands swapped (t7,t4 vs t4,t7); declare the mask after the first lh in source, or compute the index offset as a separate u32 variable (offset + base) so addu operand order flips; remove the t6 binding if the mask then lands in t6 by itself.
