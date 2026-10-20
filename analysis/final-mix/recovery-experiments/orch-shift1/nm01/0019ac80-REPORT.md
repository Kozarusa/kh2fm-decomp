# 0019ac80 submitted
- Range: 0019ac80, 124 bytes. Source: orch1_nm01_0019ac80_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C7-style loop condition: comma expression result=0 in the while condition puts move t5,zero in the loop-back delay slot.
- Emitted assembly or register bindings: register s32 result asm("$13") to keep the result in t5 as the original.
- Provisional: names and types are inferred from instructions only.
