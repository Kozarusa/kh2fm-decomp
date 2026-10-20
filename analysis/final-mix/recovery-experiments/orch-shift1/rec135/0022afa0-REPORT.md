# 0022afa0 submitted
- Range: 0022afa0, 68 bytes. Source: orch1_rec135_0022afa0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11 guarded pointer retains separate address materialization; $f0 conversion binding restores all float registers.
- Emitted assembly or register bindings: empty pointer guard retains separate address materialization; converted bound to $f0 because original converts preserved integer through $f0. No instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
