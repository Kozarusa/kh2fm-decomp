# Worker B — Round 16 report

**Role:** isolated proposals/reports only. Primary retains active sources, `functions.tsv`, `layout.tsv`, stage sync, builds, manifests, receipts, Ghidra, `HANDOFF.md`.
**Claimed:** 16 framed, no-branch, `sd ra`-bearing ranges — all 16 range-hash OK, start/end/size agreeing with `/root/kh2fm-build/layout.tsv` (`r16_ranges.txt`, `r16_range_hashes.txt`, `r16_orig_disasm.txt`). Original ELF sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.

## Result: 6 / 16 byte-exact

| address | bytes | variant | source sha256 |
|---|---|---|---|
| 001053c0 | 60/60 | v01 | `9a361f214d319691…` |
| 0014cfc8 | 60/60 | v03 | `78e0c746846c2443…` |
| 00197be8 | 60/60 | v02 | `471169ee7bb2091f…` |
| 001c13a8 | 60/60 | v02 | `8ae689a3bf5fb051…` |
| 001e6c00 | 60/60 | v04 | `551bc20ac5fdb65c…` |
| 002d47a8 | 60/60 | v03 | `08b9aad95d90cd43…` |

Each has its own `…_solved.verification.json` with `exact_match: true`, `boundary_agreement: true`, 0 differing words, re-run from the `_solved.cpp` copy.

## Symbol rule refined — `lw` and `addiu` want DIFFERENT values

Round 15 established that a symbol used as a plain integer emits `lui` + `ori` with no carry, while a symbol **address** emits `lui` + `addiu` with the rounding form `hi = (V + 0x8000) >> 16`. This round adds the missing distinction:

* **reached by `lw`/`sw`** → `hi` is **truncating**: `hi == V >> 16`, `lo16 == V & 0xffff`. The declared value must satisfy *both*, which usually means the symbol sits one page **above** Ghidra's.
* **reached by `addiu`** (a symbol address) → `hi` **rounds**: `hi == (V + 0x8000) >> 16`.

001e6c00 was the one-word-away proof. Target `lui t7,0x1da` + `lw a0,-6428(t7)`. Declaring Ghidra's `0x1de6e4` gives `lui 0x1d` (truncating on `0x1de6e4 >> 16`). Declaring `0x1dae6e4` gives `0x1da` with the same `0xe6e4` half — exact. Applying the round-15 *addiu* rule to an `lw` is the mistake; the two rules coexist and are chosen by which instruction consumes the symbol.

## Mechanisms

**001053c0** — three calls, then the global is cleared. The target loads the global **twice** (`lw a0,-17636(s0)` in two `jal` delay slots). Declaring `DAT_0033bb1c` **`volatile`** forces the second load; without it GCC CSEs the two loads into one.
```c
extern "C" volatile u32 DAT_0033bb1c;   /* asm: DAT_0033bb1c = 0x33bb1c */
func_00109280(DAT_0033bb1c); func_00170c00(DAT_0033bb1c); func_00170320(0); DAT_0033bb1c = 0;
```

**0014cfc8** — three calls, then two global clears in the same page, each with its **own `lui`** in the target:
```
lui t7,0x35 ; ld ra ; sw zero,-25084(t7) ; lui t6,0x35 ; sw zero,-25080(t6)
```
GCC hoists both `lui`s above the first store. Declaring **both globals `volatile`** pins the pairs to their stores — exact. A memory barrier between the stores was worse (4 words).

**00197be8** — the global is loaded once into `s0` and forwarded to both calls; the trailing empty `asm volatile ("")` goes **inside** the guard block, which is what keeps the second call a real `jal` instead of a sibling tail call.

**001c13a8** — three real calls. The load of `param_1[12]` must **not** be hoisted above the first call, so it is written inline as an argument. Hoisting it into a temporary made GCC need a 32-byte frame and reordered everything (72/60).

**001e6c00** — `func_002fde18(param_1, 171, 336); func_001e7798(DAT, param_1); asm volatile ("");`. Two fixes: the trailing asm keeps the second call real, and the `lw` symbol value follows the truncating rule above.

**002d47a8** — vtable-pointer store then two calls. The third argument is `param_1 + 3208` **bytes**; spelling it as a `u32` index makes GCC fold the arithmetic to `+802`. `func_002e7328((u32)(long)((u8 *)param_1 + 3208));` is exact.

## Unresolved (10)

| address | best | measured | blocker |
|---|---|---|---|
| 0014dbc8, 0014dc08 | v01 | 60/60, 5–6 words | The target orders the six zero-stores `sb 0x1d9, sw 0x1d0, sh 0x1d4, sb 0x1d6, sb 0x1d7, sb 0x1d8`; GCC swaps the first two. All six are to the same base, so there is no aliasing reason, and neither a memory barrier nor `volatile` on every store pins the order. |
| 00170530 | v03 | 60/60, 4 words | The target keeps the two constants in **distinct** registers (`li t6,1; sh t7,58; sb t6,0`); GCC reuses `t7` for both. `param_3` must stay unmasked — a `u16` parameter adds an `andi` (8 words). Barriers and named temporaries widen the gap. |
| 00265740 | v01 | 56/60, 13 words | The target saves `ra` **before** `s0` and ends in `sltiu v0,v0,1` — it returns 1 when `(x ^ 0x8d) == 0`. The `== 0` predicate fixes the tail but regresses the prologue order; `!= 0` fixes the prologue but not the tail. Both are needed at once. |
| 002e2e18 | v01 | 56/56, 4 words | The machine form is a **likely** branch (`beql`) with `lw v0,264(s0)` in the delay slot and the load repeated after the call. `__builtin_expect(…,1)` plus a volatile reload grew the body to 64/56 instead of producing the likely-branch shape. |
| 0016e200, 0016e500 | v01 | 56/60, 7 words | Two differences: `lq t0`/`sq t0` where GCC picks `t7`, and the target emits `ld s0,0(sp)` **twice** (beq delay slot, then after the `sq`) while GCC elides the dead reload. |
| 00315678, 00315700, 00316890 | v01 | 56/56, 2 words | **New compiler-level class — prologue sink.** The target sinks the vtable-pointer store to the incoming parameter *below* both prologue saves (`sd s0,0(sp); sd ra,8(sp); sw t7,0(a0)`); GCC always schedules it *between* them. Same shape as round 15's 0028b7f8, so this is now **four** targets in one class. |

## Standing observation for primary

The prologue-sink class and the earlier `$v0`-vs-`$t7` scratch class both look like **build-wide code-generation settings** rather than per-function accidents: the prologue-sink store is always scheduled at the same point in GCC's prologue, and the scratch choice is always `$t7` where the original preferred `$v0`. Worker B cannot set compiler flags, so both are recorded rather than chased — but they are the two largest remaining classes and are worth primary's attention as possible single-setting explanations.