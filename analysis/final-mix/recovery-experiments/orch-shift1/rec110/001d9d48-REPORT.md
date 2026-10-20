# 001d9d48 submitted
- Range: 001d9d48, 64 bytes. Source: orch1_rec110_001d9d48_v7.cpp (exact). Versions tried: 7.
- Changes that mattered: C11c register bindings of bit/row/index/mask (12 to 7 words); C11d empty asm keep on row and index (7 to 0).
- Emitted assembly or register bindings: register bindings $11 $13 $12 $14 and an empty asm("" : "+r"(row), "+r"(index)), to match original t3/t5/t4/t6 allocation.
- Provisional: names and types are inferred from instructions only.
