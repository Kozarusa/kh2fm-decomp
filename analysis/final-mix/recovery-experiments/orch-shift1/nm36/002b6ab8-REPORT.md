# 002b6ab8 submitted
- Range: 002b6ab8, 36 bytes. Source: orch1_nm36_002b6ab8_v8.cpp (exact). Versions tried: 1 (v8).
- Changes that mattered: C19 explicit frame restoration immediately before the epilogue reproduced the original `move sp,s8` while preserving t7 and v0 transports.
- Emitted assembly or register bindings: frame bound to `$30` and initialized by `daddu` to establish s8; result bound to `$15` with an empty guard to preserve t7; returned bound to `$2` with an empty guard to preserve v0; accepted C19 `daddu` restores sp from the frame before the epilogue.
- Provisional: names and types are inferred from instructions only.
