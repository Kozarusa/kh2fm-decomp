# Round 23 — worker B (isolated)

4 of 22 claimed ranges recovered byte-exact. Each recovered range is delivered as
`analysis/final-mix/recovery-experiments/fm_worker_b_round23_<addr>_solved.cpp`
with its own `.verification.json` (`exact_match: true`, `boundary_agreement: true`,
0 differing words), re-run from the delivered copy rather than from the winning
variant.

All 22 ranges were verified before any source was written: ELF sha256
`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`, per-range
sha256, and start/end/size agreement against `/root/kh2fm-build/layout.tsv`.

## Recovered

| address | bytes | variant | mechanism |
|---|---|---|---|
| 002f1808 | 72/72 | v01 | three-symbol global chain, result forwarded through two calls |
| 0031cd90 | 72/72 | v03 | vtable setter, page-biased symbol |
| 00322d70 | 72/72 | v03 | byte-identical to 0031cd90 |
| 00325aa0 | 72/72 | v02 | vtable setter, no page bias needed |

Source sha256:

- 002f1808 — `recovery-experiments/fm_worker_b_round23_002f1808_solved.cpp`
- 0031cd90 — `26b63c5ffd7172ff2a3c97a6cdc0af45a4f43df36ff4ebe51eaf418e3a4c3754`
- 00322d70 — `876a71d1c0bb9979ffb825c634fcdf433615178d5526c157febec31132f5698a`
- 00325aa0 — delivered from `v02`

002f1808:

```c
uVar1 = func_001708f8(DAT_00363c20, -1);
DAT_01e3c0d0 = uVar1;
uVar1 = func_00168b38(uVar1, 2, 0);
DAT_00363c24 = *(u32 *)((u8 *)uVar1 + 8);
```

0031cd90 / 00322d70 / 00325aa0:

```c
*(u32 *)param_1 = (u32)(long)&func_0035eb98;      /* target: lui 0x36 ; addiu -5224 */
func_0023c098(param_1 + 48);
func_002369f0(param_1 + 24);
asm volatile ("" ::: "memory");                   /* pins ld ra above the final store */
*(u32 *)param_1 = (u32)(long)&func_00347f98;
return;
```

## The correction this round is worth

An earlier note recorded that a page bias observed in round 15 was an artifact
and that the symbol rule was simply truncating. **That over-generalised, and this
round disproved it.** The high half depends on how the symbol is reached:

- reached by `lw` / `sw` — the high half **truncates**: `hi == V >> 16`
  (this is what round 16's 001d6538 measured);
- used as an **address**, materialised `lui` + `addiu` — the assembler's `%hi`
  is conservative and **rounds**: `hi == (V + 0x8000) >> 16`
  (this is what round 15 measured).

0031cd90 is the proof. Declaring the vtable symbol as `0x36eb98` gave
`lui 0x37`; its low half `0xeb98` is `>= 0x8000`, so the assembler rounds the page
up. Declaring `0x35eb98` yields the target's `lui 0x36` + `addiu -5224`, and the
target is exact. 00325aa0 needed no adjustment because both of its low halves
fall below `0x8000`.

## Unresolved

| address | best | measured | reason |
|---|---|---|---|
| 001003b0, 00101d38 | v01/v02 | 8/20 | empty-body frame |
| 00271828 | v01/v03 | 72/72 | 2 words: GCC strength-reduces the table index |
| 002925c0 | v01 | 80/72 | callee argument count wrong; body already too long |
| 00295228 | v01 | 80/72 | frame 32, GCC widens further |
| 002be770, 002be7b8 | v03 | 68–76/72 | needs `lui t6,0x4000`; literal and symbol forms both fail |
| 002ef708 | v03 | 72/72 | 4 words: two byte-store addresses, GCC reuses one register |
| 002f3a70, 00308018, 00310048, 001145b0, 00138140, 00143348, 0014a138, 00158450, 001584f8, 00160ac0 | — | — | no source written this round |

### New class — empty-body frame (2 members)

001003b0 and 00101d38 are 20-byte bodies containing nothing but
`addiu sp,-16 / sd ra / ld ra / jr ra / addiu sp,sp,16`. GCC 3.2 gives a function
with no work no frame at all (8 bytes). Forcing it with inline stack manipulation
is rejected by this assembler (`illegal operands 'sd $ra,0($sp)'`). **Recorded as
not reachable in C rather than counted** — hand-writing the instructions is not a
recovery.

### Solved class — epilogue restore placement (3 members)

The vtable setters all wanted `ld ra,8(sp)` *between* the second `lui` and the
second `addiu`, where GCC emitted it after the store. One
`asm volatile ("" ::: "memory")` immediately before the final store pins it in the
correct slot. This is the same lever that fixed 002cf3f8 in round 21.

## Notes on this round's process

Three of the misses here were my own errors rather than compiler behaviour:
`param_1[0x162]` written against a `u32` parameter (a compile error, not a link
failure), a "fix" that regressed its own predecessor, and the truncating-only page
rule above. 00271828 sits two words from exact across three differently-shaped
attempts and is recorded rather than chased further.

## Standing materialised constants

1. The probe harness should stage the reference ELF at
   `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; `WORKSPACE` currently points at the
   retired `Documents/ChatGPT` root.
2. `layout.tsv` is CRLF-terminated — split on `\r\n` or every size field fails to
   parse and the picker silently returns nothing.
3. Dump-script clones inherit the previous round's output filenames; sed
   `r22_`→`r23_`, not just `r21_`→`r22_`.