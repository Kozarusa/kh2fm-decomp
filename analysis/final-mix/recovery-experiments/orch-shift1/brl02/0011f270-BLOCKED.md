# 0011f270 blocked
- Range: 0011f270, 128 bytes. Versions tried: 4. Best: v1 with 2 differing words (128/128 bytes).
- First difference of the best version: `!! 0011f2a8: 01ec6821  addu	t5,t7,t4 | 0011f2a8: 018f6821  addu	t5,t4,t7` (same at 0011f2cc; everything else exact).
- Changes tried:
  - v1: rec05 v8 plus the t6 mask assigned inside the `parent >= 0` block (blocker hypothesis): 2 words, li/dsll32 placement now exact.
  - v2: entry as integer sum `(u32)(parent*64) + (u32)entries`: 22 words (sll goes straight into bound t5, ld s0 moves, 132 bytes).
  - v3: separate `u32 offset` temp then `offset + base`: 22 words (temp coalesced into t5).
  - v4: offset temp bound to $15: 20 words (addu t7,t7,t4 then move t5,t7, 136 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(d) on v1: keep the pointer form but make the addu operand order offset-first without letting the offset tie to t5, e.g. `asm("" : "+r"(offset))` on an unbound offset temp before `entry = (Entry*)((u8*)entries + offset)`, or index from an unbound `entries` copy so local-alloc does not tie the sll result to the cursor.
