# 0020eaf8 submitted
- Range: 0020eaf8, 116 bytes. Source: orch1_rec129_0020eaf8_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: reuse the incremented index variable for the count store and the array store (keeps the count in a register instead of recomputing top + 1).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
