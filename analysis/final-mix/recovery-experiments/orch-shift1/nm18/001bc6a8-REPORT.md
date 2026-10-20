# 001bc6a8 submitted
- Range: 001bc6a8, 84 bytes. Source: orch1_nm18_001bc6a8_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C11d combined initialized object read/write guard with memory clobber; C10d added a source read/write memory guard after the byte store, preventing its argument move from crossing the store.
- Emitted assembly or register bindings: empty asm only; object bound to $16 to preserve the original saved pointer; each guard has a separate reason comment.
- Provisional: names and types are inferred from instructions only.
