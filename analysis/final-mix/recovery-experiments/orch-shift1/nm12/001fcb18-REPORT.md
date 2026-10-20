# 001fcb18 submitted
- Range: 001fcb18, 120 bytes. Source: orch1_nm12_001fcb18_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C11c bound the loaded global pointer to $4 and used it directly for the +80 and +16 arguments (no temp).
- Emitted assembly or register bindings: register u8* global asm("$4") (original loads the global into a0). No asm instructions.
- Provisional: names and types are inferred from instructions only.
