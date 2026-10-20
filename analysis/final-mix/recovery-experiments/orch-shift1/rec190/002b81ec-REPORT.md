# 002b81ec submitted
- Range: 002b81ec, 40 bytes. Source: orch1_rec190_002b81ec_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C19 copied accepted 002b6b84 explicit frame transport and preserved the original symbol alias; C11 bound zero to t7 and the return to v0.
- Emitted assembly or register bindings: frame bound to $30 and explicit daddu establishes/restores sp; zero bound to $15; return bound to $2; all preserve original ABI transport.
- Provisional: names and types are inferred from instructions only.
