# 00123ba8 submitted
- Range: 00123ba8, 116 bytes. Source: orch1_rec06_00123ba8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C13 (block tail call with empty memory-clobber asm, v3: 16 words still); for-loop form with *cursor re-read (v5: exact).
- Emitted assembly or register bindings: asm volatile("" ::: "memory") emits no instruction; it only prevents the tail call that the original lacks.
- Provisional: names and types are inferred from instructions only.
