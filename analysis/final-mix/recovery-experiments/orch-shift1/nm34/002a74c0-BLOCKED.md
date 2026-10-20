# 002a74c0 blocked
- Range: 002a74c0, 108 bytes. Versions tried: 4. Best: v1 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 002a74ec: 258c0001 addiu t4,t4,1 | 002a74ec: 01ab6804 sllv t5,t3,t5.
- Changes tried: v1 unchanged rec181v2 baseline 2 words; C11(c) v2 existing bit binding to numeric register13 only 2 words; C11(c) v3 baseline v2 existing index binding to numeric register12 only 2 words; C11(c) v4 baseline v1 existing mask binding to numeric register13 only 2 words. Every binding has its own why comment; no guards or instruction-emitting assembly.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(d) add one empty read/write guard to the existing bound bit immediately after its assignment, before the mask expression, preserving source order and unsigned operands. This differs from rec181's guard after increment consuming the incremented index.
