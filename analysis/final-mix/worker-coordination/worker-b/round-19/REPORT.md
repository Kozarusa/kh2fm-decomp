# Worker B — Round 19

16 unregistered ranges claimed, all 16 verified against the original ELF
(`SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`)
and against `/root/kh2fm-build/layout.tsv` by `round-19/r19_dump_orig.py`.

**Result: 6 exact, 10 unresolved.**

## Exact

| address | bytes | variant | mechanism |
|---|---|---|---|
| 001d9eb0 | 64/64 | v01 | vtable pointer stored as a symbol address, three stores after one call |
| 001d9ef0 | 64/64 | v01 | byte-identical to 001d9eb0 |
| 001e0f90 | 64/64 | v01 | call, second call, two stores to the derived pointer |
| 001b6d00 | 64/64 | v03 | non-volatile global keeps one load in `$t7`; `__builtin_expect` |
| 001c1890 | 64/64 | v02 | trailing `asm volatile ("")` prevents the sibling-call rewrite |
| 00275ec8 | 64/64 | v02 | global holds a pointer value — declare `volatile u32`, take its address |

Each has a `_solved.cpp` re-proved by `probe_fm_source.py` with `exact_match: true`
and `boundary_agreement: true`.

### Two declarations worth getting right

`001d9eb0` and `00275ec8` differ only in how their global is declared, and both were
wrong on the first attempt for the same reason — the machine code reaches the global
with `lw` and then uses the *loaded value* as a pointer, so the declaration has to be
`volatile u32` with the address taken, not `volatile u32 *`. Declaring it as a pointer
makes GCC load the pointer into a register and dereference it, adding a word.

`001b6d00` is the mirror image: `volatile` was the problem there. The target loads the
global exactly once and indexes the loaded value with `lw a1,24(t7)`. Marking it
`volatile` forces the reload that `0014cfc8` and `001053c0` need elsewhere.

The rule: **`volatile` when the target re-reads the global, plain when it indexes the
value it already loaded.** Both spellings occur in the original, so it has to be decided
per function from the machine code, not by habit.

## New compiler-level finding — the spurious sign-extension mask

Seven targets (001bb9b0, 001bb9f0, 001bbec0, 001bbf00, 001bbf40, 001bc010, 001bc050)
all come to within one word of exact and all fail the same way. The target does:

```
lhu   t7,4(t5)
srl   t7,t7,SHIFT
andi  t7,t7,1
```

GCC 3.2 emits an extra `andi t7,t7,0xffff` first, zero-extending the 16-bit load before
the shift. Six spellings were tried — named pointer temp, pointer-to-pointer, unsigned
mask `1u`, `volatile u16 *`, `u16` vs `u32` return type, and a fully inline form. None
removes it; the inline form and the `volatile` form both made the code worse.

This is the same shape as the round-5 `00242500` finding, where splitting one expression
into two statements moved GCC's allocation from `$a0` to `$t7`. There the source change
matched the original; here no source change reaches it, so the family is recorded as
blocked with a one-word diagnosis rather than chased further.

## Unresolved

| addresses | best | measured | blocker |
|---|---|---|---|
| 001bb9b0, 001bb9f0 | v05 | 68/64, 6 words | spurious `andi 0xffff` after `lhu` |
| 001bbec0, 001bbf00, 001bbf40, 001bc010, 001bc050 | v05 | 76/64, 13 words | same, plus `addiu+lw` instead of one `lw t6,8(v0)` |
| 001c5f38 | v02 | 64/64, 7 words | GCC folds `base+offset` into the `lui` immediate |
| 001d5b78 | v01 | 60/64, 8 words | ninth member of the round-14 `func_002fd248` family |
| 00242980 | v02 | 64/64, 5 words | `ld ra` interleaved between two `lh`/store pairs |

## Process note

Several sources this round silently failed to compile: a template substitution dropped
the `func_` prefix and produced `u32 001bbec0(void)`. Their missing verification json was
at first misread as a link failure, which sent two rounds of variants chasing a cast
expression that was never the problem. Any stem should have its source checked for a
valid `func_<8 hex digits>` declaration before its probe output is interpreted.
