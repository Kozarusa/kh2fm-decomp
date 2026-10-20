# 001dc278 blocked
- Range: 001dc278, 124 bytes. Versions tried: 8. Best: v5 with 26 differing words (120/124 bytes).
- First difference of the best version: !! 001dc280: 25ef2b48  addiu	t7,t7,11080 | 001dc280: 3c0d0035  lui	t5,0x35
- Changes tried: v1 plain struct (29); v2 tail via Node** list=&D_00352ae0, list[1] (28, branch part now matches); v3 store order 36 before 32 (28); v4 volatile float global (28); v5 memory barriers around value store (26); v6 float temp then pad5 then value (26); v7 float global as array (26); v8 volatile float pointer (26).
- Why it stops here: budget/no improvement for 3 versions.
- Next hypothesis: original forms the float address with a separate addiu (lwc1 0(t7)), stores a2 (offset 4) before a1 (offset 8) with lui t6 between, and does not hoist the lui t5 above the vtable addiu; try a different object layout (a base-class constructor call inlined, struct members assigned in declared order) or C11 register bindings.
