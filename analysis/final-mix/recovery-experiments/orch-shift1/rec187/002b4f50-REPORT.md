# 002b4f50 submitted
Range: 002b4f50, 100 bytes. Source: orch1_rec187_002b4f50_v4.cpp (exact). Versions tried: 4.
Changes that mattered: C11b isolated the callback temporary. C11c bound callback to $13 and object separately to $15.
Emitted assembly or register bindings: callback uses $13 to preserve the original indirect call target; object uses $15 to preserve its original register. No emitted assembly.
Provisional: names and types are inferred from instructions only.
