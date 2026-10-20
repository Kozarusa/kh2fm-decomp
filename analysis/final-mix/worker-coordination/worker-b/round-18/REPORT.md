# Worker B — Round 18

16 unregistered ranges claimed, all 16 verified against the original ELF
(`SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`)
and against `/root/kh2fm-build/layout.tsv` by `round-18/r18_dump_orig.py`.

**Result: 8 exact, 8 unresolved with measured blockers.**

## Exact

| address | bytes | variant | mechanism |
|---|---|---|---|
| 002db8e8 | 60/60 | v01 | vtable-setter recipe |
| 002dc708 | 60/60 | v01 | byte-identical to 002dc748 |
| 002dc748 | 60/60 | v01 | byte-identical to 002dc708 |
| 0031a508 | 60/60 | v01 | byte-identical to 0031c8e8 |
| 0031c8e8 | 60/60 | v01 | byte-identical to 0031a508 |
| 001b5c78 | 64/64 | v01 | one derived pointer, two calls, result read first |
| 002e2dd8 | 60/60 | v02 | `__builtin_expect` |
| 001aa940 | 64/64 | v04 | six arguments + trailing `asm volatile ("")` |

Each has a `_solved.cpp` in `analysis/final-mix/recovery-experiments/` re-proved by
`probe_fm_source.py` with `exact_match: true` and `boundary_agreement: true`.

### The vtable-setter recipe (five of the eight)

```c
*(u32 *)param_1 = (u32)(long)&PTR_x;
func_A((u32)(long)((u8 *)param_1 + off));
func_B(param_1);
asm volatile ("");
```

Getting all four members of this family right on the first attempt is the strongest
evidence yet that this is the original spelling: Ghidra's pseudocode is wrong about the
byte-vs-word width of the offset, and the trailing empty asm is what keeps the second
call a real `jal`.

### `__builtin_expect` (002e2dd8)

The target branches with `beqzl` and restores `ld ra` before `ld s0`. A plain
`if (puVar1 != 0)` gave the same size but the non-likely form and the opposite restore
order; `__builtin_expect(puVar1 != 0, 1)` reproduced both.

### Argument counts are readable off the machine code (001aa940)

Rounds 9 and 14 each parked a target as "parameters arrive in `$9`/`$10`, not expressible
in C". That reading was wrong. `$4..$11` **are** the O32 argument registers; a
`move tN,tM` in a body or in a `jal` delay slot simply records that argument 6+ has to be
moved. Reading the moves literally as an argument list recovered:

- **00158050** (round 14): `func_001386e0(p1,p2,p3,p4,p5,p7);` — only `$9←$10` was needed.
- **002ba3b8** (round 9): eight arguments, last three `(&local_8, p6, p7)`.
- **001aa940** (round 18): `func_001ab598(*(u32*)p1, p1+64, p2, p3, p4, p5);`

All three are now byte-exact. A sweep of every round's disassembly for `move t0..t3`
turned up only these plus 001231f8 (blocked separately by the `jalr $v0` class),
00307fe0 (correct already, pure register allocation) and 00180c88 (solved in round 2),
so the class is now closed.

## Unresolved

| address | measured | blocker |
|---|---|---|
| 00181a90 | 64/64, 3 words | page of the byte-store target comes out one high; second constant interleaves with the first `sb` |
| 001906f0 | 60/64, 9 words | GCC folds the `lq`/`sq` destination into `sp+32` on the next `jal` delay slot |
| 00165830 | 68/64 | four `lq`/`sq` stack copies |
| 001037b8 | 60/64 | target splits `0x5910` into `lui`+`ori`, GCC emits one `li` |
| 001358c0 | 64/64, 7 words | target saves `ra` before the vtable store and restores `ld ra` before `ld s0` |
| 00135900 | 64/64, 7 words | byte-identical sibling of 001358c0 |
| 002dd790 | 44/60 | `beql`-guarded `lq`/`sq` copy expands into branches |
| 00180408 | 56/64 | needs an unreachable `b` back-edge plus two likely-branch forms |

## Compiler-level classes still open

1. `$v0`-vs-`$t7` scratch choice for a global address or 16-byte move (~7 instances).
2. A body load's address-materialising `lui` never scheduled into the prologue region (eight members, round 14).
3. Epilogue `ld ra` scheduled into the middle of the body.
4. Leaf frame-pointer idiom — implies `-fno-omit-frame-pointer` for some original TUs.
5. `jalr $v0` vtable dispatch (nine members).
6. Prologue sink of a vtable-pointer store.
7. Frameless sibling-call thunks.

Register pins (`register … asm("$t7")`) are rejected outright by this compiler, so none
of these are reachable from C. Classes 1 and 6 look like build-wide code-generation
settings rather than per-function accidents; both are flagged to primary, which owns
compiler flags.
