# 002402e0 blocked
- Range: 002402e0, 124 bytes. Versions tried: 8. Best: v8 with 18 differing words (124/124 bytes).
- First difference of the best version: !! 002402f4: 240f0002 li t7,2 | 002402f4: 284e0003 slti t6,v0,3
- Changes tried: v1 branch tree (26 words); C1(a) accepted callee declaration v2 (26); C1(b) volatile return reload v3 (26); C7 inverted outer branch v4 (25); C11 destination pointer v5 (21); C11 destination binding v6 (20); C11 empty guard v7 (23); C11 value binding from best v6 in v8 (18).
- Why it stops here: budget reached.
- Next hypothesis: C11 reorder the comparison computations to match the original instruction scheduling.
