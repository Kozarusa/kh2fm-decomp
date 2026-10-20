# 0020df70 submitted
- Range: 0020df70, 128 bytes. Source: orch1_rec128_0020df70_v8.cpp (exact). Versions tried: 8.
- Changes that mattered: C13 barrier after last call (jal not tail j); C11c bind loop counter to t4; C10d barriers after each sq for store order.
- Emitted assembly or register bindings: empty memory-barrier asm (3) and register binding of the loop counter to $12, each with a why comment.
- Provisional: names and types are inferred from instructions only.
