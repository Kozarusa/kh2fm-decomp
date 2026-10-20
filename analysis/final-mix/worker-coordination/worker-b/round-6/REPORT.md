# Worker B — Round 6 Report

Date: 2026-10-08
Assignment: 10 unregistered ranges claimed in `round-6/claim.json`, all re-derived
from the original ELF `SLPM_666.75`
(sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`),
cross-checked against `/root/kh2fm-build/layout.tsv`. **All 10 range hashes
matched** (`round-6/r6_range_hashes.txt`, helper `round-6/r6_dump_orig.py`).

## Result: 2 / 10 byte-exact

| address | size | source | proof |
| --- | --- | --- | --- |
| 0016e8f8 | 36 | `fm_worker_b_round6_0016e8f8_solved.cpp` | `…_solved.verification.json` |
| 00288610 | 40 | `fm_worker_b_round6_00288610_solved.cpp` | `…_solved.verification.json` |

Both proofs carry `exact_match: true` and `boundary_agreement: true`, probed from
the promoted `_solved.cpp` copies.

```
0016e8f8 e4cead726324535d426a4959816aeceb02fbff9e5a21a7fb65a58c2ea965c1d2
00288610 908c674d6e843374052947ccf04e15e042b5305b254bbc2808e5620ee639b575
```

### Mechanisms

- **0016e8f8** — `u64 uVar1 = func_001b1448(PTR_0035dc28); func_001d3390(uVar1);`
  with `PTR_0035dc28 = 0x35dc28`. The call result flows into the void second call
  with `move v0,a0` in the delay slot and the second call as a tail jump.
- **00288610** — `u64 uVar1 = func_002537c8(0); func_0023fa08(DAT_0036f334, uVar1);`
  with `DAT_0036f334 = 0x36f334`. **Key finding:** the compiler materialises a
  global as `lui (V >> 16)` + `lw|sw (sign_extend(V & 0xffff))` with **no carry
  adjustment**. A target pair `lui 0x36 / lw -3276` therefore needs the symbol
  declared as `0x36f334`, not Ghidra's `0x35f334` and not the arithmetically
  obvious `0x35f33c`. This was confirmed independently by 0023fb00 and 00196170
  in round 7.

## Open, with measured reasons

### Frameless sibling-call thunks (compiler-level) — 001002a0, 0030f690, 0030f6a0, 0030f6b0, 0030a300

These targets have **no stack frame at all**: e.g. 0030f690 is
`move a1,a0; lui a0,0xb000; j 0x0030f620; ori a0,a0,0x1000`, where the constant
sits in the jump's delay slot. Every pure-C spelling produces a frame:

| spelling | size |
| --- | --- |
| plain call / plain return | 32 B |
| `__attribute__((noreturn))` on the callee | 24 B (`addiu sp,-16 … addiu sp,sp,16`) |
| noreturn on caller *and* callee | 24 B |
| noreturn caller with a trailing `return` | 32 B |

Inline-asm fallbacks fail as well: `move $a1,$a0` is rejected
(`Error: illegal operands`), the numeric spelling `$5,$4` assembles but GCC's
scheduler reorders it to `move; j; lui; jr ra; ori` (20 B) and still emits
`jr ra`; a bare `asm("j 0x0030f468\n\t nop")` matches the first two words but
GCC appends `jr ra; nop`. Conclusion: GCC 3.2 -O2 has no path to a frameless
sibling call. These five were reported rather than forced.

- **0030a300** note: v01 used the Ghidra runtime name `SignalSema` and failed to
  link (`undefined reference`); the harness only auto-defines symbols named
  `func_<8 hex digits>`. v02 renamed the callee to `func_00305640` and compiled
  to 28 B against a 12 B target — the same frameless blocker.

### 001ac700 — 2 differing words

Target: `addiu sp,-16; addiu t7,zero,4; sd ra,0(sp); move t6,a0; sw t7,0x70(a0);
lw a1,0x80(t6); ld ra,0(sp); addiu a0,zero,34; j 0x1991a8; addiu sp,sp,16`.

The compiler always restores `ld ra,0(sp)` one slot **before** the target's
`lw a1,0x80(t6)`. Eight spellings were tried: inline load (the 2-word baseline),
a temp local (5 diffs — GCC folds the offset into `t6` as `a0+0x80`), `u8*` +
casts, `u32*` with indices 0x1c/0x20, load-then-store with `u32*` indexing,
`char*` parameter, `void*` parameter, and a temp local with
`asm volatile("" : "+r"(iVar1))` (7 diffs and a 36 B body — the `move t6,a0`
disappears). The scheduler puts the epilogue restore ahead of the tail-call
argument setup in every case.

### 0021cda0 — 5 differing words (best v01)

Target uses `bnezl a0,+6` (likely-branch encoding) and materialises `lui a0,0x33`
twice. `s64` parameter with `param_1 == 0` gives 5 diffs; `s32` with the inverted
test gives 9. Neither spelling reaches the likely-branch form.

### 002f1e00 — unreachable

Target loads its argument gp-relative (`lw a0,-7456(gp)`). The probe harness links
each candidate at a fixed absolute address and cannot place a symbol for
gp-relative small data, so this target cannot be reproduced through the harness.

## Isolation / ownership

No compiler-flag changes, no executable byte patching, no shared-stage writes,
no docker restarts. Round-6 artifacts are worker-B-owned only: `round-6/claim.json`
(this report's machine-readable form), `round-6/r6_dump_orig.py`,
`r6_range_hashes.txt`, `r6_orig_disasm.txt`, `<address>.orig.hex`, and the
`fm_worker_b_round6_*` sources and proofs in `analysis/final-mix/recovery-experiments/`.

## Cumulative worker-B exact recoveries

round 2: 4, round 3: 3, round 4: 5, round 5: 5, round 6: 2 → 19 at round-6 close
(27 after round 7).
