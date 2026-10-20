# 001d21c0 blocked
- Range: 001d21c0, 80 bytes. Versions tried: 5. Best: v2 with 4 differing words (80/80 bytes).
- First difference of the best version: !! 001d21c0: 27bdfff0  addiu	sp,sp,-16 | 001d21c0: 44801000  mtc1	zero,$f2
- Changes tried: v1 plain nested if (7 words); v2 separate variable for the new value (4); v3 combined || condition (21); v4 volatile load of the field (4, no change); v5 early returns (19).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the body is correct; only prologue scheduling differs (original addiu sp, mtc1, sd ra, lwc1; compiled mtc1, addiu, lwc1, sd). Try C12/prologue variants such as a zero constant held in a named f32 variable, or the call declared with an explicit u8* argument.