# 001fb928 submitted
- Range: 001fb928, 124 bytes. Source: orch1_nm12_001fb928_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: copied the exact sibling 001fbb20 pattern: union Cell for mixed-width access, plus the empty "+r" guard on the other pointer (C11d, C18).
- Emitted assembly or register bindings: asm("" : "+r"(other)) empty guard keeps the load of other+12 after the prologue moves. No instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
