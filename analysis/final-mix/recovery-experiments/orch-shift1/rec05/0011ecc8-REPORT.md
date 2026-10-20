# 0011ecc8 submitted
- Range: 0011ecc8, 128 bytes. Source: orch1_rec05_0011ecc8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C7 for-loop form with single call after the unlink; C11c cursor bound to a1; C7a negated prev test with swapped bodies.
- Emitted assembly or register bindings: register Link* node asm("$5") (original keeps the cursor in a1 and copies the key to t6).
- Provisional: names and types are inferred from instructions only.
