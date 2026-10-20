# 001997c0 blocked
- Range: 001997c0, 76 bytes. Versions tried: 8. Best: v5 with 9 differing words (72/76 bytes).
- First difference of the best version: !! 001997dc: 11cf0008  beq t6,t7,0x199800 | 11cf0007  beq t6,t7,1997fc (compiled uses xori t7,t6,K + sltiu v0,t7,1 for the final compares instead of li t7,K + bnel with move v0,zero).
- Changes tried: v1 u64 callee (19), v2 pointer callee and s32 kind (15), v3 nested ifs (15), v4 u8 other (15), v5 explicit early returns (9), v6 result var (9), v7 return 0/1 chain (10), v8 other var with early returns (15).
- Why it stops here: no improvement for 3 versions after v5.
- Next hypothesis: Force the two final compares into one shared branch-likely: li t7,K in the delay slot then bnel to move v0,zero (C8: volatile on the compared constant, or C6 xor-zero form) instead of xori+sltiu.
