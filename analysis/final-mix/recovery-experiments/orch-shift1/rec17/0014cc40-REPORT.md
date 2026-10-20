# 0014cc40 submitted
- Range: 0014cc40, 116 bytes. Source: orch1_rec17_0014cc40_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11d empty asm register constraint on the table base stops folding the offset into the load; u64 parameters give the 64-bit moves.
- Emitted assembly or register bindings: one empty asm (no instructions) to stop address folding.
- Provisional: names and types are inferred from instructions only.
