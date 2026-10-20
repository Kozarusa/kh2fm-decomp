# 002b16d8 submitted
- Range: 002b16d8, 44 bytes. Source: orch1_rec185_002b16d8_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11d guard preserves second-field early load; C11c binding restores t5 allocation and scheduling.
- Emitted assembly or register bindings: second bound to $13 because original keeps second field in t5; empty read-write guard keeps early load. Both have individual why comments.
- Provisional: names and types are inferred from instructions only.
