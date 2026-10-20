# 001375f0 blocked
- Range: 001375f0, 64 bytes. Versions tried: 4. Best: v1 with 2 differing words (64/64 bytes).
- First difference of the best version: `!! 00137600: 25efac9c  addiu	t7,t7,-21348   ; = D_0036ac9c              | 00137600: ffbf0008  sd	ra,8(sp)`
- Changes tried:
  - v1: copy of eight_hour_001375f0_v4_helper_word_widths_3 ($15 binding + `asm("" : "+r"(scale))` marker): 2 words (addiu t7 / sd ra swapped).
  - v2: C9 volatile read of D_0036ac9c without marker: 14 words (low half folded into lwc1, 60-byte layout shifted).
  - v3: v1 without the $15 register binding (marker kept): 2 words, identical residual.
  - v4: asm `lwc1` that only reads the address (so the native addiu stays the last writer of t7): 8 words (lui/addiu/lwc1 sink below the argument moves).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the `+r` marker becomes the last setter of t7, so the call's t7 clobber no longer depends on the addiu and the addiu loses the depend-count tie-break against `sd ra`; find a way to keep the low half out of the lwc1 offset without an insn that writes t7 after the addiu (for example an input-only, non-barrier use of the address placed before the call setup), or accept a provisional emitted address add.
