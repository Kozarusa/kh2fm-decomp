# 001b7df0 submitted
- Range: 001b7df0, 120 bytes. Source: orch1_nm19_001b7df0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: The authorized four-operation VU subtraction prefix from accepted 00163210 reconstructed the vector operation. C11 bound the initialized destination to numeric register 15 and added an empty read/write guard, preventing folded memory addressing. Version word counts were v1 3, v2 3, v3 3, v4 0; v4 is the earliest best.
- Emitted assembly or register bindings: The lqc2/lqc2/vsub/sqc2 primitive follows the verified accepted precedent because ordinary C++ cannot express VU macro operations. The initialized $15 destination binding preserves the target register. The empty +r destination guard preserves a single computed address. Every primitive, binding and guard has its own why comment. No unassigned register reads or other emitted instructions occur.
- Provisional: names and types are inferred from instructions only.
