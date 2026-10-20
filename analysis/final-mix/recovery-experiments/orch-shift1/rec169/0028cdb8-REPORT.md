# 0028cdb8 submitted
- Range: 0028cdb8, 124 bytes. Source: orch1_rec169_0028cdb8_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: C11 integer address transport preserved offset+base order; vtable and callback temporaries bound to original registers.
- Emitted assembly or register bindings: table $14 matches original vtable load; callback $15 matches original indirect call target. No emitted assembly.
- Provisional: names and types are inferred from instructions only.
