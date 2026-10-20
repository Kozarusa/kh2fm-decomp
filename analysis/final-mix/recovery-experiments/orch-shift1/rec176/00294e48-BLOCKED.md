# 00294e48 blocked
- Range: 00294e48, 92 bytes. Versions tried: 1. Best: v1 with 8 differing words (100/92 bytes).
- First difference of the best version: !! 00294e6c: 14400009 bnez v0,0x294e94 | 00294e6c: 1440000b bnez v0,294e9c
- Changes tried: v1 literal outgoing-result transport; 8 words.
- Why it stops here: R12 conservative ABI block. R4.5 accepted declarations require s64 LoadDataIsFlushing result and u32 LeadDataSetText result; C1 audit shows s64 unification adds dsll32/dsrl32 zero-extension absent from original. Changing accepted declaration is forbidden; truncating the s64 result loses outgoing result semantics.
- Next hypothesis: resolve mixed-width outgoing callee return transport under R4.3/R4.5.
