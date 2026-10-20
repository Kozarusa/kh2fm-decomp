# 0028b7f8 submitted
- Range: 0028b7f8, 56 bytes. Source: orch1_pro01_0028b7f8_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C10/C13 variant: the trailing `asm volatile("")` that earlier attempts used to stop the sibling call is a full scheduling barrier and gives the `sw` extra dependents (t7 uses), so it outranked `sd ra`. Replacing it with a dead assignment after the last call (`object = 0;`) still blocks the sibling call at expansion, is deleted before scheduling, and restores the original `sd ra`/`sw` order.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
