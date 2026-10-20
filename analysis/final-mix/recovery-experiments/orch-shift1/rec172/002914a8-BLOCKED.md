# 002914a8 blocked
- Range: 002914a8, 104 bytes. Versions tried: 8. Best: v6 with 20 differing words (116/104 bytes).
- First difference of the best version: !! 002914c8: 05e20008 bltzl t7,0x2914ec | 002914c8: 05e00008 bltz t7,2914ec.
- Changes tried: v1 direct loop 29; C1 result lifetime across call v2 24; C9 volatile table v3 23; C2 explicit signed char v4 23; C20 s64 byte comparisons v5 23; C10d memory guard from v2 v6 20; C2 signed key v7 20; C7c early negative return v8 24.
- Why it stops here: budget reached.
- Next hypothesis: C7a invert initial branch and swap blocks while preserving result lifetime and memory guard.
- R4.3: sole original jr ra returns v0=s0 on every path, zero initialization or one on match; all versions preserve integer result.
- R4.5: exact extern "C" u32 func_001a80c8(...); from packet-named fm_primary_addresspair_recovered_001a6c60.cpp.
