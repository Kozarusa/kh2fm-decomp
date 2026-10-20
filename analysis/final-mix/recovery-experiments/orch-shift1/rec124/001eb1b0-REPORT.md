# 001eb1b0 submitted
- Range: 001eb1b0, 120 bytes. Source: orch1_rec124_001eb1b0_v5.cpp (exact). Versions tried: 5 (v1 and v2 failed to link on the callee declaration).
- Changes that mattered: callee declared as plain extern "C" func_002f3d08(u32,u32,u32); global typed u8* so +16 is a byte offset; C10 store order of cell[5] before cell[0].
- Emitted assembly or register bindings: none
- Provisional: names and types are inferred from instructions only.
