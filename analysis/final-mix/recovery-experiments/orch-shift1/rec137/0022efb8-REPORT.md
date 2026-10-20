# 0022efb8 submitted
- Range: 0022efb8, 96 bytes. Source: orch1_rec137_0022efb8_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: C10 memory guard preserves store order and source reload. C11 numeric register binding with an empty read-write guard preserves t6.
- Emitted assembly or register bindings: value is bound to $14 because the original first halfword uses t6; its empty guard preserves that allocation. The empty memory guard preserves store order. Each has its own why comment. No instruction-emitting assembly.
- Provisional: names and types are inferred from instructions only.
