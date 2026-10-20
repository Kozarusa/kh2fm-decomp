# 0016f4b8 submitted
- Range: 0016f4b8, 100 bytes. Source: orch1_rec32_0016f4b8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C12b separate result and pointer variables (matched the early move v0,zero and s0 usage); unsigned temporary with separate xor and and statements removed the extra andi 0xff.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.