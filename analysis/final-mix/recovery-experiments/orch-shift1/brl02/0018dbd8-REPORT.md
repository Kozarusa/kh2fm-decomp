# 0018dbd8 submitted
- Range: 0018dbd8, 80 bytes. Source: orch1_brl02_0018dbd8_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C8 (blocker hypothesis): ending the inner statement expression with `selected != 0` instead of `selected` removed the extra `sltu` normalisation; v1 (nested bool stmt exprs with `!= 0`) was worse (20 words).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
