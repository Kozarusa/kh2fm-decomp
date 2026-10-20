# 001ded98 submitted
- Range: 001ded98, 120 bytes. Source: orch1_nm13_001ded98_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C7 for-loop compares counter before decrement with decrement as increment; C11 t7/t6 bindings preserve allocation.
- Emitted assembly or register bindings: t7 loop counter, t6 compare base; two empty memory guards preserve original call epilogue.
- Provisional: names and types are inferred from instructions only.
