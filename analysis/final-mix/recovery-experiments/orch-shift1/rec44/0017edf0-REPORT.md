# 0017edf0 submitted
- Range: 0017edf0, 120 bytes. Source: orch1_rec44_0017edf0_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C11c: result bound to t7 ($15) via register asm.
- Emitted assembly or register bindings: register s32 result asm("$15"), to keep the result in t7 and copy to v0 at the shared return.
- Provisional: names and types are inferred from instructions only.
