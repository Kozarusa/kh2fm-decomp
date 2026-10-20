# 001db808 submitted
- Range: 001db808, 72 bytes. Source: orch1_rec112_001db808_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11c - bind inner to t5 (v2, 12 to 6 words); C11c - bind vtable to t7 and slot to t6 with explicit vtable call (v4, exact).
- Emitted assembly or register bindings: register bindings $13 (inner), $15 (vtable), $14 (slot), each with a why comment; no instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
