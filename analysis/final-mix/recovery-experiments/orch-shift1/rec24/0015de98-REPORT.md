# 0015de98 submitted
- Range: 0015de98, 92 bytes. Source: orch1_rec24_0015de98_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: R4.3 void final virtual call (no v0 use) kept; C11c register bindings t7/t6 for vtable and method pointer fixed the last 3 words.
- Emitted assembly or register bindings: register u32* table asm("$15") and register u32 method asm("$14"), to match original register choice.
- Provisional: names and types are inferred from instructions only.
