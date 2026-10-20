# 001bb890 submitted
- Range: 001bb890, 96 bytes. Source: orch1_rec90_001bb890_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: declaring D_01d49320 as u32 (address value) so the u32 store aliases it, forcing the reload and separate or-instructions (C10-like; volatile variants failed).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
