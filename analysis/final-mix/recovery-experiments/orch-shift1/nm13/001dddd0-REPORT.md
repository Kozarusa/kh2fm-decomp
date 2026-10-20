# 001dddd0 submitted
- Range: 001dddd0, 108 bytes. Source: orch1_nm13_001dddd0_v8.cpp (exact). Versions tried: 8.
- Changes that mattered: C11 guarded end in t6 and data copy in t7 after first store; guarded self preserves object store; store data instead of copied base; C10 object and effect guards sequence stores, address calculation and load.
- Emitted assembly or register bindings: t6 end binding and guard, t7 base binding and guard; self guard; object and effect guards with memory clobber. Each has its own why comment. All asm empty.
- Provisional: names and types are inferred from instructions only.
