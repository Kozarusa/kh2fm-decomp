# 0015cff0 submitted
- Range: 0015cff0, 104 bytes. Source: orch1_rec24_0015cff0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C14/C18-style: plain Quad copies fold offsets into lq/sq (92 bytes); the asm lq/sq pattern from accepted 001407d0 keeps pointer registers and gives exact.
- Emitted assembly or register bindings: three asm volatile "lq $8,0(%1); sq $8,0(%0)" copies (t0 move through pointer registers, as in accepted 001407d0).
- Provisional: names and types are inferred from instructions only.
