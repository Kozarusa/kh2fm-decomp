# 00152ab8 blocked
- Range: 00152ab8, 48 bytes. Versions tried: 8. Best: v4 (and v3) with 4 differing words (52/48 bytes).
- First difference of the best version: !! 00152ad8: ade601b4  sw	a2,436(t7)   | 00152ad8: ac8601b4  sw	a2,436(a0)
- Changes tried: v1 all-u64 callee decl 14 words; v2 value u64 14 words (sext dsll32); v3 callee decl u32 for 3rd/5th arg and last u32: 4 words (C3/C4 widths); v4 temp var base: 4 words (folded); v5 object u64 with s32 casts: 12 words; v6 register $15 alias bound mid-function: 7 words (extra move a0,a0); v7 alias bound at top: 8 words; v8 unbound alias with asm +r: 7 words.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original keeps a0 for the call but stores the last word through a t7 copy made early (move t7,a0); try a 64-bit/different-typed pointer alias for the object (e.g. u8* base used only for the 0x1b4 store) or a volatile store, to defeat the compiler moving t7 back to a0.
