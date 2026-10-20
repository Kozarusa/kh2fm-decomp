# nm31 progress
start 2026-10-17T21:33:38Z
claim 1 of 1: 0028f690 token 66ff8552ddbb475588300d2ea62a7e0b attempts 2 blocker rec172/0028f690-BLOCKED.md
R4.3: sole exit returns selected pointer in v0; no f0 or callees. R4.5: no callees. v1 unchanged rec172v4, including initialized count binding; source verified against packet.
0028f690 v1: 4 words; best v1 4 words; streak 0. First diff instruction7 C11b. Baseline nm31v1; v2 initialized address temporary only, preserving D_0035f480 + index * 884 + 388 operand order and parenthesization; full source diff checked. No added binding or guard.
0028f690 v2: 2 words; best v2 2 words; streak 0. First diff instruction8 C11a. Baseline nm31v2; v3 reverse base/cursor initialization order only; full source diff checked, address expression and all other controls preserved.
0028f690 v3: 2 words; best v2 2 words; streak 1. First diff instruction8 C11c. Baseline nm31v2; v4 initialized base $11 binding only, separate why; full source diff checked. No pointer/value binding repeated.
0028f690 v4: 0 words; best v4 0 words; streak 0. R8 source audit passes: one function, sole defined selected-pointer return, no callees, numeric initialized bindings each with why, no emitted instruction asm or trailing declarations.
submitted 0028f690 v4; K1 exhausted
