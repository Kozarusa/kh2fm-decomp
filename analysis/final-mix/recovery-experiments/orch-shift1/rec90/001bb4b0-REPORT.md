# 001bb4b0 submitted
- Range: 001bb4b0, 60 bytes. Source: orch1_rec90_001bb4b0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C10-style statement split: mask stored in its own statement (flags = flags & 4) before the == 0 compare, with an explicit if/else on the call result.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
