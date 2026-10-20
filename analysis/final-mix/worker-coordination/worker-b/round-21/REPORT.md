# Worker B — Round 21

19 unregistered ranges claimed, all 19 verified against the original ELF and against
`/root/kh2fm-build/layout.tsv`.

**Result: 12 exact, 7 unresolved.** Best rate since round 7, and the first round where
a whole family landed from a single source template on the first attempt.

## Exact

All twelve have a `_solved.cpp` re-proved by `probe_fm_source.py` with
`exact_match: true` and `boundary_agreement: true`.

| address | bytes | mechanism |
|---|---|---|
| 00242b10 | 68/68 | read-modify-write of a flag bit: `sltu` from `(param_1 & 0xff) != 0`, mask `~0x8`, shift 3 |
| 00242b88 | 68/68 | same shape, `sltiu` from `== 0`, mask `~0x10`, shift 4 |
| 00242ca0 | 68/68 | same shape, `sltiu`, mask `~0x40`, shift 6 |
| 00242d10 | 68/68 | same shape, `sltu`, mask `~0x80`, shift 7 |
| 00242d80 | 68/68 | same shape, `sltu`, mask `~0x100`, shift 8 |
| 001a2710 | 68/68 | test-bit-then-clear at `*(u32 *)param_1` index 148 |
| 001c6e58 | 68/68 | seven-argument callee recovered from the register shuffle |
| 001c6ea0 | 68/68 | byte-identical to 001c6e58 |
| 002beb90 | 64/64 | three `lui`+`addiu` symbol addresses plus one `lw`-reached global |
| 001d3f98 | 68/68 | same shape, fourth argument is `param_1 + 4` |
| 002cf3f8 | 64/64 | two globals in one page; memory barrier pins `ld ra` below the stores |
| 00174858 | 68/68 | six-argument call, sixth argument through a named `u32 *` temp |

### The flag family

The five 00242b\* members are one source template differing only in test polarity,
mask and shift, and all five were exact on the **first** attempt. The polarity has to be
read off the machine: `sltu s0,zero,s0` means `!= 0` and `sltiu s0,s0,1` means `== 0`.
The pointer is `func_001058e8() + 16800` and the field is the next word.

### Two declaration rules that keep costing time

**Argument lists come from the register shuffle, not from the pseudocode.** 00174858's
callee takes six arguments including a literal `1` in the fourth slot, which is why the
target emits `li a3,1` in its prologue. 001c6e58 takes seven. Reading `move tN,tM`
literally gives the list; guessing from Ghidra does not.

**Read the immediates off `dis.py` rather than recomputing them.** Four of these
recoveries — 001c6e58, 001c6ea0, 002beb90, 001d3f98 — were one or three words away and
turned on nothing but my own arithmetic: 7480 read as `0x1d28` instead of `0x1d38`, and
`0xcaf4` read as `0xca34`. Every one of those was a silent self-inflicted error, not a
compiler behaviour.

## Unresolved

| address | best | measured | blocker |
|---|---|---|---|
| 001cf998 | v02 | 56/68, 13 words | GCC if-converts `(r > 0) ? 1 : 0` into a branchless `slti` tail |
| 00194830 | v02 | 76/68, 14 words | target tests the call result before doing any work and sends the zero path out of line |
| 00188fe0 | v01 | 96/68, 20 words | multiply-and-add chain expands differently |
| 001585a0 | v01 | 48/68, 16 words | `movz`/`movz` pair around the callee result |
| 001af778 | v01 | 76/68, 15 words | two-call argument order and register assignment |
| 00308f00 | v03 | 68/64, 7 words | `movn` if-conversion plus a prologue `lui` order |
| 003091c8 | v03 | 68/64, 8 words | same |

### New compiler-level class — if-conversion refusal

GCC 3.2 will not emit the conditional-move form the target uses:

```
li   v1,2048
...
movn v1,zero,v0
move v0,v1
```

For `(x == 0) ? 2048 : 0` it emits a compare and a branch instead. Three spellings were
tried — multiplication by the predicate, a ternary, and an explicit conditional
assignment to a named variable — and none produced `movn`. 00308f00 and 003091c8 carry
this; 001cf998 and 00194830 are the same refusal in a different shape. Recorded rather
than chased further.

## Process notes

- A partial string replacement over a multi-line `asm` block left `.globl DAT_0034ca34`
  and `DAT_0034caf4 = 0x34caf4` as two different symbols, so a corrected value never
  reached the compiler and the probe output came back byte-identical to the previous
  run. I first read that as the harness caching a stale source. These files must be
  written whole, never patched with `sed`.
- An `asm` block defining a symbol still needs a matching `extern` declaration of the
  right type, and a helper emitting both a `char` and a typed declaration will not link.
