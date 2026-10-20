# 00170ee8 submitted
- Range: 00170ee8, 76 bytes. Source: orch1_med01_00170ee8_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: two separate `priority == 0xffff && initialize == 1` guards (no early return) keep the repeated guard alive across the join; C11(b) a two-Word struct accessed through a pointer gives the native address-then-store order; C11(c) binding the pointer to $15 gives the t6/t7 assignment.
- Emitted assembly or register bindings: `register WordPair* pair asm("$15")` in each guarded block, so the object pointer lands in t7 and the high half in t6 as in the original.
- Provisional: names and types are inferred from instructions only.
