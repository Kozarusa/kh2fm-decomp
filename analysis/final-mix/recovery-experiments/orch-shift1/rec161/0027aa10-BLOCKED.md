# 0027aa10 blocked
- Range: 0027aa10, 104 bytes. Versions tried: 4. Best: v1 with 22 differing words (104/104 bytes).
- First difference of the best version: !! 0027aa18: ffb00000 sd s0,0(sp) | 0027aa18: 0c095ddc jal 257770 <func_00257770>
- Changes tried: v1 scalar translation 22; C20 signed object transport v2 24; C11c persistent s0 binding v3 24; C11d single empty object guard v4 24.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: address materialization split through one pointer temporary preserving base+index operand order; first-call save scheduling remains unresolved.
- Return audit: tail call 0028da70 result forwarded on both paths; no entry-v0 path.
