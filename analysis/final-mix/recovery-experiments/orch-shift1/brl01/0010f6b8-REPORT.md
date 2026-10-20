# 0010f6b8 submitted
- Range: 0010f6b8, 60 bytes. Source: orch1_brl01_0010f6b8_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C7b: combining the null check and the compare into one `if (a && b) return 1; return 0;` gives both failure paths one shared zero block, which stops if-conversion from folding the compare into `slt v0`/`movz`; reorg then steals `move v0,zero` and `li v0,1` into the branch delay slots exactly like the original.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
