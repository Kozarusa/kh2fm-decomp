# 001bb7f8 submitted
- Range: 001bb7f8, 92 bytes. Source: orch1_rec89_001bb7f8_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C12 inverse (v2): bind result to s0; C7c (v3): restructure to early return plus fallthrough set of result.
- Emitted assembly or register bindings: register s32 result asm("$16"), because the original keeps result in s0 across both calls.
- Provisional: names and types are inferred from instructions only.
