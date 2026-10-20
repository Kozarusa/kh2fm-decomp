# 0017fef0 submitted
- Range: 0017fef0, 120 bytes. Source: orch1_rec44_0017fef0_v6.cpp (exact). Versions tried: 6 (v3 was a compile error).
- Changes that mattered: C11c/C11d: t7/t6 register bindings plus a volatile empty asm on the scratch pointer to fix address computation order.
- Emitted assembly or register bindings: VU macro asm block (lqc2/vsub.wxyz/sqc2/vadd.wxyz, pattern from accepted 001786e0 and 0018a4d8); registers $15, $14 and $8 bound as in the original; empty volatile asm for ordering.
- Provisional: names and types are inferred from instructions only.
