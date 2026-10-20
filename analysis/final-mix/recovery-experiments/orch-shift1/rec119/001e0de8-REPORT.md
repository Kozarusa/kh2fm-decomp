# 001e0de8 submitted
- Range: 001e0de8, 84 bytes. Source: orch1_rec119_001e0de8_v7.cpp (exact). Versions tried: 7.
- Changes that mattered: C14 Quad copy through TI-mode type; C10(d) empty memory barrier after the zero store keeps the argument move there (16 to 6 words); C11(c) register bindings to $8 for both quad copies (6 to 2 words); call with dest++ moved the pointer increment into the delay slot (2 to 0).
- Emitted assembly or register bindings: empty asm volatile memory barrier (no instruction); two register bindings to $8 (t0) for the quad temporaries, matching the original.
- Provisional: names and types are inferred from instructions only.
