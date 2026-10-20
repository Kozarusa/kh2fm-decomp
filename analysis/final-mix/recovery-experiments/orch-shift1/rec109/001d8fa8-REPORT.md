# 001d8fa8 submitted
- Range: 001d8fa8, 124 bytes. Source: orch1_rec109_001d8fa8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C7 negated select test (7 to 7 words, aligned branch sense); object pointer computed before vtable load (4 words); C11c bound vtable to t6 and method to t7 (exact).
- Emitted assembly or register bindings: two register bindings, vtable pointer in $14 (t6) and method pointer in $15 (t7), to match the original register allocation.
- Provisional: names and types are inferred from instructions only.
