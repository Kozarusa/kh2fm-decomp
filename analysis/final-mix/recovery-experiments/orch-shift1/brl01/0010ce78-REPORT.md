# 0010ce78 submitted
- Range: 0010ce78, 120 bytes. Source: orch1_brl01_0010ce78_v11.cpp (exact). Versions tried: 11 (v1-v7 in the first claim, then v8-v11 after re-claim; see 0010ce78-BLOCKED.md for the first claim).
- Changes that mattered: C3b: keep the flag `s32` and test `(u8)flag` to get the `andi 0xff` (3 words). C7c: write the result as `if (!flag) r = 0; else if (D == 0 || x != D) r = 1; else r = 0;` so the false arm has its own zero store that the compiler cannot merge with an earlier zero; reorg then fills the `beqz`/`beq` delay slots with `li 1` / `move 0` as in the original.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
