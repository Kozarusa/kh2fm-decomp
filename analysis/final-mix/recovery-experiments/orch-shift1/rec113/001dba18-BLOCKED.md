# 001dba18 blocked
- Range: 001dba18, 108 bytes. Versions tried: 4. Best: v1 with 18 differing words (96/108 bytes).
- First difference of the best version: !! 001dba3c: 14400008  bnez	v0,0x1dba60 | 001dba3c: 10400008  beqz	v0,1dba60 <func_001dba18+0x48>
- Changes tried: v1 plain while(1) with continue/return (18); v2 do-while with result var and break (23); v3 do-while Ghidra form with return 0 (18); v4 while(1) result var with breaks (23).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7 - original has null-return block inline after the call (bnez to loop body) and a beql shared epilogue; try s64 object type (Ghidra says long) or C8 volatile on the mask load.
