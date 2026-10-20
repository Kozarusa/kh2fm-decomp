# 0013fd10 blocked
- Range: 0013fd10, 100 bytes. Versions tried: 6. Best: v3 with 10 differing words (100/100 bytes).
- First difference of the best version: !! 0013fd10: 27bdffc0  addiu sp,sp,-64 | 0013fd10: 27bdffb0  addiu sp,sp,-80
- Changes tried: v1 FVector operator= twice (19 words, second self-assign guard kept, no s2 save); v2 second copy as unguarded asm lq/sq (21, body matches, s2 save missing, 92 bytes); v3 same plus "$18" clobber (10, s2 saved as 128-bit sq, frame 80 instead of 64); v4 dead asm output bound to $18 (21, dropped); v5 volatile asm output at start (23, s2 holds &second); v6 volatile asm output after last call (23, same).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: find a way to get an unused s2 saved with sd (frame 64, ra at 56) without a 128-bit save, e.g. a real but dead s2 value kept across the call, or a third kn::FVector-style operand whose address is held in s2 and optimised away after reload.
