# 001c9958 blocked
- Range: 001c9958, 88 bytes. Versions tried: 9 (one over the 8 budget; I miscounted). Best: v7 with 17 differing words (88/88 bytes).
- First difference of the best version: !! 001c9960: 000e780a  movz	t7,zero,t6 | 001c9960: 38ad0002  xori	t5,a1,0x2 (compiler hoists xori a1,2 above the movz, omits the andi 0xff, and uses beq/jr-in-block layout instead of the shared bnel tail).
- Changes tried: v1 plain nested ifs 22; v2 bool inRange temp 20; v3 separate zeroing 21; v4 Ghidra tail 22; v5 duplicated branch tails 19; v6 xor 0 no change 19; v7 operand order `kind != 0 && kind < 7` 17; v8 u8 inRange no change 17; v9 v2-style `other` tail with v7 order 18.
- Why it stops here: no improvement for 3 versions after v7 (v8, v9 and budget exceeded).
- Next hypothesis: keep v7 head; make the tail a single shared `if (kind != other) result = true;` with `other` chosen so the compiler emits bnel (C8b/c), and force the andi 0xff via an explicit `(u8)` cast of the in-range test.