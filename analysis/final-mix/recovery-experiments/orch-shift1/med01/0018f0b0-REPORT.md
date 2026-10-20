# 0018f0b0 submitted
- Range: 0018f0b0, 80 bytes. Source: orch1_med01_0018f0b0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: two separate `priority == 0xffff && initialize == 1` guards keep the repeated guard; the Word pair follows the accepted 00170ee8 pattern (struct pointer bound to $15); C11(d) an empty asm on the float source pointer keeps the full address and the offset-0 lwc1; C10(d) a memory barrier between the float load and store keeps the store's lui after the load in t7.
- Emitted assembly or register bindings: `asm("" : "+r"(source))` (full source address before the offset-0 load); `asm volatile("" ::: "memory")` (store address formed after the load, reusing t7); `register WordPair* pair asm("$15")` (object pointer in t7, high half in t6).
- Provisional: names and types are inferred from instructions only.
