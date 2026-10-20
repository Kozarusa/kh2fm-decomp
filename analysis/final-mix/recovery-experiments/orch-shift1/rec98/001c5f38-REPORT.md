# 001c5f38 submitted
- Range: 001c5f38, 64 bytes. Source: orch1_rec98_001c5f38_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: pointer variable plus empty asm formed the table address separately (C5-style materialization); the same asm also listing the object pointer kept the lbu after the lui (load placement).
- Emitted assembly or register bindings: one empty asm("" : "+r"(table), "+r"(object)) with a why comment, no instruction emitted.
- Provisional: names and types are inferred from instructions only.
