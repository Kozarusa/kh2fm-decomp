# 001d6d00 submitted
- Range: 001d6d00, 88 bytes. Source: orch1_rec107_001d6d00_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C20/types - entry as a 32-bit pointer (removed dsll32/dsrl32 extension, 96 to 88 bytes); C7 - loop written as while ((entry = f(entry)) != 0) with return 0 after the loop (15 to 0 words).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
