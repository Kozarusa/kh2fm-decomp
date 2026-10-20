# 002b4fb8 submitted
- Range: 002b4fb8, 64 bytes. Source: orch1_rec188_002b4fb8_v4.cpp (exact). Versions probed: 3; source version: v4.
- Changes that mattered: C13: defined capture of outgoing v0 prevented a tail call. C7: shared result fallthrough removed the extra zero-return block.
- Emitted assembly or register bindings: `call_result` bound to `$2`, with an empty output asm defining the outgoing callee result left in v0.
- Provisional: names and types are inferred from instructions only.
