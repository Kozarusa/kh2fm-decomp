# 001973f0 blocked
- Range: 001973f0, 60 bytes. Versions tried: 4. Best: v1 with 14 differing words (44/60 bytes).
- First difference of the best version: !! 001973f4: ffbf0000  sd	ra,0(sp)  (compiled has mtc1 zero,$f12 there; original keeps a beqz/b branch pair around li a2,2 / move a2,zero).
- Changes tried: v1 plain if (mode=0; if(flag) mode=2) -> compiler folds to andi+sll (14). v2 u8 flag + if/else s32 mode, C3 -> still sll (14). v3 u64 mode + volatile u16 read (C8c/C9) -> movz (14, 48 bytes). v4 u64 mode non-volatile -> movz, lbu narrowed (14, 48 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has andi 1 then andi 0xff on an lhu, i.e. the u8 result of an inline helper (C3/C8): try a static inline u8 helper returning the flag, plus moving the 0.0f/6 argument setup so a real branch is kept (e.g. a non-foldable condition such as volatile mode temp, C12/C8a).
