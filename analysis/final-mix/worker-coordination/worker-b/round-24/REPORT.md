# Round 24 — worker B (isolated)

5 of 16 claimed ranges recovered byte-exact. Each is delivered as
`analysis/final-mix/recovery-experiments/fm_worker_b_round24_<addr>_solved.cpp`
with its own `.verification.json` (`exact_match: true`, `boundary_agreement: true`,
0 differing words), re-run from the delivered copy.

All 16 ranges verified before any source was written: ELF sha256
`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`, per-range
sha256, and start/end/size agreement against `/root/kh2fm-build/layout.tsv`.

## Recovered

| address | bytes | variant | mechanism |
|---|---|---|---|
| 001c0ce8 | 76/76 | v02 | register barrier on a masked boolean |
| 002db808 | 76/76 | v02 | vtable setter; trailing asm |
| 002db858 | 76/76 | v02 | byte-identical to 002db808 |
| 002ed2b0 | 76/76 | v01 | seven-argument dispatch, argument list read off the register shuffle |
| 002ed300 | 76/76 | v01 | byte-identical to 002ed2b0 |

002ed2b0, exact on the first probe:

```c
func_001c23a8(param_1, param_2, 0, 1, 0, 128, param_3);
*(u32 *)param_1 = (u32)(long)&func_00363758;
DAT_00363748 = param_1;
```

The argument list comes from reading the target's register shuffle
(`move t2,a2` / `a2=0` / `a3=1` / `t0=0` / `t1=128`), not from the decompilation,
which would have required guessing the arity. Third independent confirmation that
the shuffle is the more reliable source.

## Two things worth carrying forward

**One-word misses are usually the tail call.** Every 72/76 result in this batch was
GCC turning the final call into a sibling tail call and dropping `ld ra`. A trailing
`asm volatile ("")` fixed all six at once. This lever was already recorded in round
8; the round-20 post-mortem ("apply what you already know") is what surfaced it.

**A register barrier on a masked boolean.** `asm volatile ("" : "+r"(uVar1))` on the
result of an AND stops GCC rewriting `(x & 0x80) != 0` into `sra`+`andi` — that was
001c0ce8's only defect. The same barrier was tried on round 19's parked `lhu`
sign-extension family (001bb9b0, 001bbec0, 001bbf00) and **did not work**; all three
stayed at 68/64 or got worse. The lever is specific to the boolean-and form, and I
am recording that rather than letting the round-19 family look reopened.

## Unresolved

| address | best | measured | reason |
|---|---|---|---|
| 0017a6c8 | v01 | 60/76 | target holds the global page in a callee-saved register across the body |
| 001c2c98, 001c2ce8 | v02 | 76/76 | 2 words: last two stores transposed; v03 and v04 both regress |
| 002007e0, 00209e80 | v02 | 76/76 | 3 words: GCC folds a two-level indirection; v03/v04 regress |
| 00252710 | v01 | 72/76 | 14 words |
| 002956c0 | v02 | 76/76 | 2 words: target shifts the callee return in `$v0`; v03 regressed |
| 00224cf0, 003015a8, 00307f90 | — | — | not attempted |

## Note on the picker

The picker tags (NO-BRANCH etc.) come from the decompiled pseudocode, not from the
instruction words. 0017a6c8 was tagged NO-BRANCH and is the worst result in the
batch — the machine code plainly branches. Treat the tag as weak evidence.

Four of this round's variants regressed against their own predecessors and are
recorded that way rather than quietly replaced.

## Standing materialised constants

1. The probe harness should stage the reference ELF at
   `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; `WORKSPACE` currently points at the
   retired `Documents/ChatGPT` root.
2. `layout.tsv` is CRLF-terminated — split on `\r\n` or every size field fails to
   parse and the picker silently returns nothing.
3. Dump-script clones inherit the previous round's output filenames.
