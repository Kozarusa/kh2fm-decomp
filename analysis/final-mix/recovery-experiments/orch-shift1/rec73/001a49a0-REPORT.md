# 001a49a0 submitted
- Range: 001a49a0, 56 bytes. Source: orch1_rec73_001a49a0_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: C14 Quad copies; C11d asm pointer barrier (v3, 9 words); C11c register binding of the quad temp to $8 (v6, exact).
- Emitted assembly or register bindings: two empty asm pointer barriers (keep the destination pointer in a register so sq uses offset 0); quad temp bound to $8 to match t0.
- Provisional: names and types are inferred from instructions only.
