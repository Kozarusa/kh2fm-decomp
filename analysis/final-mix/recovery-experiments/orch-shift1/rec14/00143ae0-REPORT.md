# 00143ae0 submitted
- Range: 00143ae0, 128 bytes. Source: orch1_rec14_00143ae0_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C13 - v1 compiled the last call as a tail call (j); an empty asm memory barrier after the call forces jal plus the function's own epilogue.
- Emitted assembly or register bindings: one empty `asm volatile("" ::: "memory");` (emits no instruction), with a why comment, to block the tail call.
- Provisional: names and types are inferred from instructions only.
