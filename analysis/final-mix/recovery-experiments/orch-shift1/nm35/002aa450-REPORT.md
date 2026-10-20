# 002aa450 submitted
- Range: 002aa450, 84 bytes. Source: orch1_nm35_002aa450_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11(c) v2 binds existing OR result to t5; C11(d) v3 adds one empty read-write result guard, matching the independently accepted sibling pattern. Baseline v1 unchanged, 4 words; v2 4 words; v3 0 words.
- Emitted assembly or register bindings: result bound to numeric $13 because original OR uses t5; empty +r result guard keeps OR before condition. Each has its own why comment; separate controls and completed guard-diff inspection before probing.
- Provisional: names and types are inferred from instructions only.
