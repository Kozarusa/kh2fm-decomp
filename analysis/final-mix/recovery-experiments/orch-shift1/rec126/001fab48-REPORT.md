# 001fab48 submitted
- Range: 001fab48, 128 bytes. Source: orch1_rec126_001fab48_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C9-like aliasing: store the pointer as s32 so the later message[1] load is not hoisted above it.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
