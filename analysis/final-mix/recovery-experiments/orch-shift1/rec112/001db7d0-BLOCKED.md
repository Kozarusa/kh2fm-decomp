# 001db7d0 blocked
- Range: 001db7d0, 56 bytes. Versions tried: 5. Best: v2 with 9 differing words (56/56 bytes).
- First difference of the best version: !! 001db7d4: 3c0f0035  lui	t7,0x35                                      | 001db7d4: 0080702d  move	t6,a0
- Changes tried: v1 function-pointer vtable call via struct (13 words, 60 bytes); v2 real C++ virtual call inner->slot1(object->value) (9 words); v3 temporaries inner/value (13); v4 temporary inner only (9, identical to v2); v5 empty-asm hold on value (13).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps inner in t5, loads a1 from the untouched a0 before the vtable loads, and moves a0=t5 in the jalr delay slot, with lui/addiu of the vtable constant before sd ra; try binding with register T name asm("$13") (C11c) for inner or adding a base-class/virtual destructor layout (vtable at slot 1 may be slot after destructor).
