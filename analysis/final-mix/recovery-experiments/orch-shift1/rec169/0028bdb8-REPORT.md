# 0028bdb8 submitted
- Range: 0028bdb8, 92 bytes. Source: orch1_rec169_0028bdb8_v8.cpp (exact). Versions tried: 8.
- Changes that mattered: C11 numeric result binding and empty guard preserve outgoing v0. C7 shared guarded exit merges epilogues and preserves branch layout.
- Emitted assembly or register bindings: result bound to $2 to retain outgoing callee result; empty +r guard at shared exit prevents result substitution. No emitted assembly.
- Provisional: names and types are inferred from instructions only.
