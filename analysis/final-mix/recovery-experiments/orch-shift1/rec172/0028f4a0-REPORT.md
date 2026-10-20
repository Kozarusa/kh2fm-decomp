# 0028f4a0 submitted
- Range: 0028f4a0, 52 bytes. Source: orch1_rec172_0028f4a0_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: direct indexed halfword loop.
- Emitted assembly or register bindings: none.
- R4.3: sole return path never sets v0/f0, no callees; pure leaf void.
- R4.5: no callees.
- Manual audit: one function, nothing after, no forbidden names or asm.
- Provisional: names and types are inferred from instructions only.
