# 0010cce0 submitted
- Range: 0010cce0, 80 bytes. Source: orch1_med01_0010cce0_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C7 branch layout: a `while ((node = f(node)) != 0)` loop with the call in the loop test and `break` on the predicate keeps the unrotated test, so the shared return block sits mid-function as in the original (for(;;)/goto forms were rotated to 72-76 bytes). Callee declarations copied from accepted sources (s32 func_001b9bc8(s32), bool func_00112d28(s64)). v1 was a compile error from a UTF-8 BOM.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
