# 001c05b0 submitted
- Range: 001c05b0, 100 bytes. Source: orch1_nm16_001c05b0_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C11 bind pair to $14 in nm14 v3, retaining its input-only empty volatile asm with memory clobber.
- Emitted assembly or register bindings: pair binding to $14 reproduces original t6; empty input guard materializes pair before ordered global stores. Each has its own why comment. No instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
