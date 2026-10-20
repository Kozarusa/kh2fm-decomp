# 00196e98 blocked
- Range: 00196e98, 104 bytes. Versions tried: 7. Best: v4 with 17 differing words (100/104 bytes).
- First difference of the best version: !! 00196eac: 10a0000f  beqz	a1,0x196eec  vs compiled  beqz a1,196ee8 (compiled lacks the extra branch and emits movn instead of beq with duplicated li a1/move a2).
- Changes tried: v1 mode=3 then override (27 words, movn, extra s2); v2 reversed condition (27, movz); v3 ternary in call args (20, obj+64 hoisted); v4 separate temp + if/else (17, registers match, movn); v5 condition other way (17); v6 s32 callee return (17); v7 s64 callee return (17).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8c make the type read volatile, or write the two arm assignments so that each arm also holds a copy of the third argument (a2 = value in both arms) to defeat movn if-conversion.
