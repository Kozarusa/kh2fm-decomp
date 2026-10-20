# 001ad9c8 submitted
- Range: 001ad9c8, 108 bytes. Source: orch1_cdx1-rec12_001ad9c8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C10 rotated lower zero stores (10 to 8 words); C11 transported the limit address; C7 conditional clamp body (2 words); C10 reversed upper clamp stores (exact).
- Emitted assembly or register bindings: pointer bound to $15 with an empty read/write operand to preserve the original address materialization before the float load; both lines have why comments.
- Provisional: names and types are inferred from instructions only.
