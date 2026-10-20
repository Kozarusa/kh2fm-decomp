# 001a81f0 submitted
- Range: 001a81f0, 104 bytes. Source: orch1_nm03_001a81f0_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C11(d) empty asm guard on the loop bound copy forces lhu into t7 then move t4,t7.
- Emitted assembly or register bindings: empty asm("" : "+r"(count)) guard, to keep the bound in its own register copy like the original.
- Provisional: names and types are inferred from instructions only.
