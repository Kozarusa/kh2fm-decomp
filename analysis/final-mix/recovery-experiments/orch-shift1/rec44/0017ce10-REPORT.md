# 0017ce10 submitted
- Range: 0017ce10, 112 bytes. Source: orch1_rec44_0017ce10_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11d: asm("" : "+r"(pointer)) on global-address pointers forces separate lui/addiu materialization with offset-0 loads; loads moved inside each branch.
- Emitted assembly or register bindings: four empty asm("" : "+r") constraints, to force address materialization.
- Provisional: names and types are inferred from instructions only.
