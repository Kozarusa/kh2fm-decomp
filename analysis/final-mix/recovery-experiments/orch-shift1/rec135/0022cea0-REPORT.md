# 0022cea0 submitted
- Range: 0022cea0, 120 bytes. Source: orch1_rec135_0022cea0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C7 zero-flag branch first; C11 object bound to s1 restores distinct flag s0, original frame and schedule.
- Emitted assembly or register bindings: pointer bound to $17 because original keeps object in s1 separately from flag s0; own why comment. No instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
