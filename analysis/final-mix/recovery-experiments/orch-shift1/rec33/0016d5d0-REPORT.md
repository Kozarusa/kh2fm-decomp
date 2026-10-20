# 0016d5d0 submitted
- Range: 0016d5d0, 108 bytes. Source: orch1_rec33_0016d5d0_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: none; kn::FVector by-value return and operator= from fvector.hpp reproduced the self-assign check.
- Emitted assembly or register bindings: none in the source (asm lives in the shared fvector.hpp operator=).
- Provisional: names and types are inferred from instructions only.
