# 001ad0f8 submitted
- Range: 001ad0f8, 92 bytes. Source: orch1_nm05_001ad0f8_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C11 -> same as 001ad098 v3: pointers bound to $15 with empty "+r" guards for the float global and the vtable address.
- Emitted assembly or register bindings: two register bindings to $15 (t7) plus empty "+r" guards, to match original register reuse; no instructions.
- Provisional: names and types are inferred from instructions only.
