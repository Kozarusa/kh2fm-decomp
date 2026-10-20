# 001b1e80 submitted
- Range: 001b1e80, 100 bytes. Source: orch1_rec83_001b1e80_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C10(d) local temp plus memory barrier between the global store and the field store fixed store order.
- Emitted assembly or register bindings: asm volatile("" ::: "memory") emits no instructions; keeps store order.
- Provisional: names and types are inferred from instructions only.
