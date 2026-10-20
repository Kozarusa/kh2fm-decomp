# 0016ffc8 submitted
- Range: 0016ffc8, 80 bytes. Source: orch1_med01_0016ffc8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C8(a) keeping the candidate separate from the returned original (no shared result variable) stops the movz/movn if-conversion and keeps candidate in a0; C7(c) a nested `if` that returns the candidate on any in-range test with a single trailing `return original` gives the hoisted `move v0,a0` and the final branch-likely restore. Unsigned range comparisons are kept explicit.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
