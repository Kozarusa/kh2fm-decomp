# 001aeb80 submitted
- Range: 001aeb80, 112 bytes. Source: orch1_cdx1-rec12_001aeb80_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11 introduced a loaded-field temporary, then bound it to $15 (4 to 2 words) and bound the loop comparison to $14 (exact).
- Emitted assembly or register bindings: loaded field uses $15; loop comparison uses $14. Both preserve original register allocation and have why comments. No emitted instructions.
- Provisional: names and types are inferred from instructions only.
