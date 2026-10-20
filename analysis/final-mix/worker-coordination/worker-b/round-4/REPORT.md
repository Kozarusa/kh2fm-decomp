# Worker B — Round 4 Report

Date: 2026-10-07 (worker-b round 4)
Toolchain: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`, `ee-g++ -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`
Original image: `tools/kh2-reference/SLPM_666.75`, ELF sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`

## Summary

| Batch | Targets | Exact | Unresolved / pending |
|---|---|---|---|
| batch1 (self-selected) | 8 | **4** | 4 |
| assigned by the primary (read late) | 6 | 0 (0 probed) | 6 pending probe |
| total | 14 | **4** | 10 |

Round 2 closed 4/6, round 3 closed 3/8. Round 4 has 4 byte-exact recoveries proven and 6
assigned targets diagnosed offline but **not probed**, because the pinned compiler became
unavailable partway through (see [Toolchain outage](#toolchain-outage)).

Two process findings are worth the primary's attention:

1. **`round-4/INSTRUCTIONS.md` existed and had not been read** when batch1 was picked. The
   self-selected batch was picked first from the standing brief's "claim further unclaimed
   unregistered ranges" instruction and is fully disjoint from the assigned six. No collision,
   but the assigned six should have been read first.
2. **Three frameless `j`-leaf functions exist in the whole disc and none is registered**
   (`0030f690`, `0030f6a0`, `0030f6b0`). This is a real but tiny class, unlike round 2's
   461-function 16-byte-save-stride gap.

## Exact recoveries (batch1)

All four are in `analysis/final-mix/recovery-experiments/fm_worker_b_round4_<addr>_solved.cpp`
with a sibling `.verification.json` carrying `exact_match: true`, `boundary_agreement: true`.

### `00150de0` (28 B) — sha256 `684660a2b1946d9c2b6cb1cc87dca65ae5aa5b7a58a8f79ff22471eea94436a1`

```cpp
#include "../common/types.h"

extern "C" void func_00150e00(u32,u32,u32,u32,u32,u32);

void func_00150de0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,u32 param_6)
{
  *(u32 *)(param_1 + 0x19a0) = param_6;
  func_00150e00(param_1,param_2,param_3,param_4,param_5,0xffffffffu);
}
```

Mechanism: the registered pseudocode wrote `in_t1_lo`, i.e. it read a *value* the caller left
in `$t1`. That is the function's **sixth** integer argument. Declaring six `u32` parameters and
passing `-1` as the sixth argument to the tail call reproduces both the store and the tail.

### `0017dec0` (36 B) — sha256 `847fa2b73865bc6f368c7eed372049d504766b3af3731d60bcd874f0c0446a3f`

```cpp
#include "../common/types.h"

asm(".globl DAT_01c60528\n\tDAT_01c60528 = 0x1c60528\n"
    ".globl DAT_01c6052c\n\tDAT_01c6052c = 0x1c6052c\n");

extern "C" u32 DAT_01c60528;
extern "C" u32 DAT_01c6052c;
extern "C" void func_001c9770(void);

void func_0017dec0(void)
{
  u32 *puVar1 = &DAT_01c60528;
  *puVar1 = 0;
  puVar1[1] = 0;
  func_001c9770();
}
```

Mechanism: two independent globals gave `lui t6,0x1c6` + `sw zero,0x52c(t6)`, reloading the
page. Routing both stores through **one pointer** makes GCC CSE the second address into
`addiu t6,t7,1320` + `sw zero,4(t6)`, which is what the original does. The inline-asm absolute
symbol definitions are what pin the addresses (plain `extern` declarations let the linker place
them elsewhere).

### `00229d40` (40 B) — sha256 `891ea3c3e6994d36aedb36adb162ed8a599fff4973292a7ee2bad048c25288d4`

```cpp
#include "../common/types.h"

extern "C" void func_00229b28(u32,u32,u32,u32,float);

void func_00229d40(u32 param_1)
{
  func_00229b28(param_1,1,200,0,(float)(*(int *)(param_1 + 0xb9c)));
}
```

Mechanism: exact on the first attempt. `cvt.s.w $f12,$f12` only appears for a genuine
int→float conversion, so the source must load an `int` and cast it; the fifth argument must be
a `float` parameter. Ghidra listed the float first in the call, which also works, but the
int→float cast is the load-bearing part.

### `002e8290` (40 B) — sha256 `2d50f1757f21678ce915af1806894c01f3ba1086ae051bd54cbf4a66d7f27bf2`

```cpp
#include "../common/types.h"

asm(".globl DAT_003637d0\n\tDAT_003637d0 = 0x3637d0\n");

extern "C" u32 DAT_003637d0;
extern "C" void func_002eda90(u32,u32,float);

void func_002e8290(u32 *param_1)
{
  u32 uVar1;
  uVar1 = DAT_003637d0;
  func_002eda90(uVar1,param_1[0],*(float *)((char *)param_1 + 4));
}
```

Mechanism: the target materialises `lui t7,0x36` immediately and keeps `a0` as the base for
`lw a1,0(a0)` / `lwc1 $f12,4(a0)`, copying the global into `a0` only in the last slot before
the jump. Writing the global directly as the first argument makes GCC copy `a0`→`t6` first and
use `t6` as the base. **Binding it to a `u32` local before the call** restores the original
scheduling. Note Ghidra's argument order for this call is wrong; the disassembly is authoritative.

## Assigned targets, third pass: `001576e8` recovered byte-exact

Probing resumed once Docker returned, using a private copy of the harness with only the stale
`WORKSPACE` constant corrected (see §Toolchain outage). Of the 27 queued variants, one landed
exactly on the first run.

**`001576e8` (112 B) — sha256 `83260af10acf16447c06c60a44f4e8bb2247a2dfc54acdeeb5414150a584718c`**, `fm_worker_b_round4_001576e8_solved.cpp`,
`exact_match: true`, `boundary_agreement: true`:

```cpp
#include "../common/types.h"

extern "C" u64 func_00155d58(...);
extern "C" void func_00138c10(...);
extern "C" void func_00154408(...);

void func_001576e8(u32 *param_1)
{
  func_00138c10((int)param_1 + 0x1a30,func_00155d58(param_1,0));
  func_00138c10((int)param_1 + 0x1bcc,func_00155d58(param_1,1));
  func_00138c10((int)param_1 + 0x20a0,func_00155d58(param_1,2));
  func_00154408((char *)param_1 + 0x40,*(u32 *)(param_1 + 6));
}
```

Mechanism, and it is the round-2 `0017ee68` mechanism generalised. All six differing words were
the relative order of `mov a1,v0` and `addiu a0,s0,<offset>` in three identical repetitions. The
inner call's result must be produced **first**, and the only way to make GCC evaluate it that way
is to write it inline in the outer call's argument list with the address argument written
*before* it — `(int)param_1 + 0x1a30` then `func_00155d58(param_1,0)`. Nesting the call the
other way round (`v03`, `v05`) still ordered the address first and missed. `v01`/`v02` wrote it
as a typed pointer, which reintroduced the `s0` base the original never forms.

Note `(int)param_1 + 0x1a30`: casting the pointer to `int` makes the offsets **byte** offsets
off the same base register, which is what produces `addiu a0,s0,0x1a30` rather than a
scaled-index load.

## Assigned targets, third pass: the four remaining blockers, now measured

The 15 targeted follow-up variants (list `r4_list_v3.txt`) produced no further exact matches,
but three of the four moved a great deal closer and the residual is now precisely characterisable.

### `00109e30` (92 B) — one word short, and it is a `nop`

`v04` (`char` parameter, non-zero arm inline) is **92/92 bytes and differs in exactly one word**:

```
   0  27bdfff0  addiu sp,sp,-16        (both)
   1  308400ff  andi a0,a0,0xff    T   |  00042600  sll a0,a0,24   C
   2  ffb00000  sd s0,0(sp)            (both)
   3  ffbf0008  sd ra,8(sp)        T   |  00042603  sra a0,a0,24   C
   4  1080000e  beq a0,zero,+14       (both)
   5  00000000  nop                T   |  ffbf0008  sd ra,8(sp)    C
```

The word count is identical; it is purely a scheduling difference. The target hoists **both**
stores ahead of the branch and leaves the delay slot empty. With a `char` parameter the mask is a
two-instruction `sll`/`sra` dependency chain, so GCC interleaves the stores into it. Switching to
`u8` (or `u32` with an explicit `& 0xff`) does produce the single `andi`, but then GCC fills the
delay slot with the remaining `sd ra` and the body shrinks to 88 bytes. I tried `u8`, `u32` with
an explicit mask, a masked value bound to a local, and an `asm("" : "+r"(...))` barrier to keep
the value out of `a0` (`v06`-`v10`): **all five give 88/92.** Reproducing the target requires GCC
to decline to fill a branch delay slot, which this compiler does not do on request.

### `0014b950` (88 B) — the `or` association order

`v03` remains the best at 4 words, all in the 64-bit pack:

```
  17  00c73025  or a2,a2,a3       T
  18  00a82825  or a1,a1,t0       T      v03 instead emits these two in the opposite order
```

together with a two-instruction pair reordered at w10/w11 and a one-slot shift at w14-w16.
Grouping the halves into named `s64` locals (`v06`, `v07`) collapses the function to 68 bytes —
GCC constant-folds the association away entirely. Restoring the right grouping but leaving the
shifts unscheduled (`v08`) keeps 88 bytes and gets the shifts right but then emits
`or t0,t0,a3 / or a2,a2,a1 / or t0,t0,a2` — the halves OR-ed into the wrong accumulators. So the
target's three `or`s are a specific left-to-right accumulation order that none of the eight
spellings I tried produces. This one still carries the R5900 64-bit-shift decode caveat, so I am
the least confident in its diagnosis of the six.

### `001e7230` (104 B) — all three counters belong in `t6`

Decoding the full body settles the question. The target uses `t6` for **every** counter and never
destroys `a1`:

```
   0  sra t6,a1,2          4  andi t6,a1,0x3      12  andi t6,a1,0x3
   2  addiu t6,t6,-1       6  addiu t6,t6,-1      14  addiu t6,t6,-1
   3  bne t6,t7            10  beq t7,t6           22  beq t7,t6
```

The compiled code emits `andi a1,a1,0x3` for the second and third counters. That is legal and
semantically identical because `(x & 3) & 3 == x & 3`, so GCC is free to destroy `a1` and
re-mask. My `v02` (separate `u32` local) did not help — GCC still coalesced the local into `a1`.
Adding a third loop (`v04`-`v07`, with and without `asm` barriers on the counters and on `a1`)
grows the body to 140-152 bytes, which means the original does **not** have three sequential
loops and my reading of the three `andi` instructions as three loops was wrong. The residual is
a register-allocation preference, not a source-structure difference, and I have not found the
spelling that pins it.

### `001ac310` (104 B) — store offsets and epilogue order trade off against each other

The two loads and the `s1` base are now both solved, but no single variant holds both:

| Variant | Loads | Store offsets | `ld ra` |
|---|---|---|---|
| `v04` (pointer only) | wrong order | **correct** (`0x148`/`0x14c` off `s1`) | after stores |
| `v05` (values pre-bound) | **correct** | wrong (`0x13c`/`0x140`) | after stores |
| `v09` (pre-bound + `asm`) | **correct** | wrong (`0x13c`/`0x140`) | after stores |

Pre-binding the two values to locals is exactly what fixes the load order (`param_1[2]` before
`param_1[1]`) and exactly what breaks the store offsets — the two requirements fight. The target
additionally places `ld ra,0x10(sp)` **before** the two stores, where every compiled variant places
it after. Given `v04` is 6 words off and `v09` is 5, this is the closest of the four.

### Proof hygiene: probe the `_solved` copy, not just the winning variant

When a winning variant is promoted by copying `..._vNN.cpp` to `..._solved.cpp`, the copy has
**no proof of its own** — the harness names its output `<stem>.verification.json`, so only the
variant stem gets one. Promoting `001576e8_v04` this way initially left the deliverable
unverified, and the final sweep caught it. The rule is: after copying, re-probe the `_solved`
file itself and confirm `source_sha256` matches the file on disk. All 12 solved sources have now
been swept and every one reports `exact_match` and `boundary_agreement` true with a matching
`source_sha256`.

## Unresolved (batch1)

### `0030f690` (16 B, compiled 20) and `0030a300` (12 B, compiled 20) — frameless sibling call

Both bodies are instruction-for-instruction correct except that GCC always opens a 16-byte
`ra`-only frame around the tail call. Ruled out: callee `__attribute__((noreturn))` (forces a
real `jal`, 24/20 B), caller `__attribute__((noreturn))` (28 B), returning the callee's `u32`
(32 B), `__builtin_unreachable()` (link failure), `long` parameters (36 B), `static` helper
indirection (32 B), literal argument (24 B).

**Class finding.** `r4_scan_frameless.py` (run with cwd = `C:/Users/KoZa/Documents/ChatGPT`)
scans 12/16-byte layout ranges with no `0x27bd` prologue that contain a `j`. Verbatim output:

```
frameless j-leaf ranges (12/16B): 3 / recovered: 0 / UNREGISTERED: 3
0030f690 16
0030f6a0 16
0030f6b0 16
```

`0030f6a0`/`0030f6b0` are the same wrapper with immediates `0x1010`/`0x1020`. So the whole class
is three functions — unlike round 2's 461-function 16-byte-save-stride gap — but all three are
unrecovered, which suggests this shape has never been matched.

### `002f1e00` (24 B) — environment-limited, not source-limited

The target loads its argument with `lw a0,-7456(gp)`, i.e. gp-relative small data addressing of
an absolute symbol at `0xffffe2e0` (the target implies **gp == 0**, since
`0xffffe2e0 + 7456 == 0x1_0000_0000`). `probe_fm_source.py` generates a linker script that
defines only `func_<8hex>`/`D_<8hex>` and never `_gp`, so GCC always falls back to
`lui a0,0x2f` + `lw a0,0x1e20(a0)`. Neither a plain `extern "C" u32 uRamffffe2e0;` nor an
inline-asm absolute definition changes this. **This one needs the real linker script**, so it is
out of reach of the probe harness as it stands.

### `001ac700` (40 B) — one word

The target emits `lw a1,128(t6)` **before** `ld ra,0(sp)`; all 35 variants emit `ld ra` first.
All other ten words match. Ruled out: the load bound to a local before or after the store,
`volatile` on the store or on the load, `asm volatile("":::"memory")` (36 B, drops the load),
non-volatile `asm("")` with `+r`/`+m`, comma-expression assignment, `u32 *`/`long`/`s32`
parameter types, a struct with a `u32` array, a `u32 *` local, reversed statement order (52 B,
allocates `s0` and emits a real `jal`), and `register u32 x asm("$t6")` (compile failure).
Conclusion: a GCC instruction-scheduling tie-break between the tail load and the epilogue restore.

## Assigned targets (read late, diagnosed offline, not yet probed)

The primary's packet assigns six ranges, each **6 differing words** from the registered baseline:

| Address | Size | Differing offsets |
|---|---|---|
| `0014b950` | 88 | 40, 44, 52, 60, 68, 72 |
| `00109e30` | 92 | 4, 12, 16, 20, 24, 76 |
| `00242500` | 92 | 20, 36, 40, 48, 80, 88 |
| `001ac310` | 104 | 44, 52, 56, 60, 64, 72 |
| `001e7230` | 104 | 16, 48, 56, 60, 72, 88 |
| `001576e8` | 112 | 24, 32, 48, 56, 72, 80 |

Full word tables (target and compiled side by side, decoded) are in `assigned_diff.txt`,
produced by `r4_decode.py`. Note the packet's `original_hex`/`compiled_hex` fields store each
4-byte group **little-endian**; they must be byte-reversed per group before decoding.

### `00109e30` — parameter is `u8`, not `char`

Target: `andi a0,a0,0x00ff` then `beq a0,zero`. Compiled: `sll a0,a0,24` / `sra a0,a0,24`
(sign-extending a `char`) then `bne`. The target also places `sd ra,8(sp)` before the branch,
and its fall-through is `func_00133f80` (the non-zero call) while `func_00133f60` sits
out-of-line at offset 76. Declaring the parameter `u8` should supply the `andi`; the branch
polarity needs the non-zero arm as the inline one. Two variants queued (`_v01` inverted
polarity, `_v02` Ghidra polarity).

### `00242500` — inverted branch polarity plus a shared tail

Target: `beq v0,zero` to the out-of-line arm at offset 72. The inline arm (offset 28) calls
`func_001058e8`, loads `lw t7,0x2440(v0)`, adds `s0`, then falls into the **shared** tail at
offset 44 which calls `func_001058e8` again, stores `sw t7,0x2440(v0)` and returns
`lw v0,0x2440(v0)`. The out-of-line arm calls `func_001058e8`, materialises the constant with
`lui t7,0x3c0f` + `ori t7,t7,0x423f`, and branches back into that same shared tail. The
registered source instead duplicates the store and the final call in both arms, which is why
its layout is inverted. One variant queued with the value computed per arm and the
store/return tail shared.

> Correction worth recording: an earlier hand-read of `0xac4f2440` said `sb` (byte store). It is
> `sw` (word store, opcode `0x2b`) — the same width on both sides. The target's `lui`/`ori` pair
> builds `0x3c0f423f`, and only the low bits of that survive the store. There is no byte-typed
> global here.

### `001ac310` — stores go through the `param_1 + 3` pointer

Target stores at `0x148(s1)` / `0x14c(s1)` where `s1 = a0 + 12`; the compiled code stores the
same effective addresses (`0x154(s0)` / `0x158(s0)`) through `s0`. The fix is to address them
through the same `param_1 + 3` pointer already passed to the callees, i.e.
`puVar1[0x52] = param_1[1]; puVar1[0x53] = param_1[2];`. The target also loads `param_1[2]`
before `param_1[1]` and interleaves `ld ra,16(sp)` between the loads and the stores; binding
both values to locals before the call is the variant that may force that order.
Two variants queued (`_v02` pointer arithmetic, `_v03` pre-bound locals).

### `001e7230` — keep `a1` alive

Target computes `andi t6,a1,0x0003` into `t6` at both loop entries and never destroys `a1`;
the compiled code overwrites `a1` itself (`andi a1,a1,0x3`, `addiu a1,a1,-1`,
`beq a1,t7`, `bne a1,t7`). Holding the masked remainder in a second `int` local instead of
assigning back to `param_2` should keep the copy in `t6`. One variant queued.

### `001576e8` — argument setup order

Three identical repetitions of `jal func_00155d58` / `jal func_00138c10`. In every one the
target emits `mov a1,v0` **before** `addiu a0,s0,<offset>`, and the compiled code does the
opposite. Nothing else differs. The address expression must be one GCC can defer until after
`a1` is set; two variants queued (plain `u32` parameter arithmetic, and a typed-pointer cast).

### `0014b950` — 64-bit field packing

The differing words are all in the 64-bit shift/`or` group. Target ends with
`or a2,a2,a3` / `or a1,a1,t0` / `or a1,a1,a2`; compiled emits `or a2,a2,t0` /
`or a1,a1,a3` / `or a1,a1,a2`. The `or` operands are crossed, so the two 32-bit halves are
combined in the opposite association order than the registered source's `|` chain.
Two variants queued with the pairs grouped into named `s64` locals.

> **Caveat on this one target.** The R5900 64-bit shift words (`dsll32`, `dsrl32`, `dsll` —
> function codes `0x38`–`0x3f`) have a different operand field order from vanilla MIPS, and I
> have not verified my decode of them against the pinned `ee-objdump`. `r4_decode.py` therefore
> prints them as `(unverified R5900 shift fields)` rather than guessing. This affects only
> `0014b950`; the other five targets' decodings are solid (verified by hand against the opcode
> tables and self-consistent).

## Assigned targets, second offline pass

With the compiler unavailable I went back to the word diffs and mined the recovered
pseudocode for the same idioms (`find_siblings.py`, `show.py`). The result: **all six
assigned targets share one mechanism with `0017ee68` from round 2**, which was solved by
writing a callee-producing expression **inline in the argument list** instead of pre-binding it
to a local. That pass produced 16 new variants, written to
`fm_worker_b_round4_<addr>_<tag>.cpp` with the run list in `r4_list_v2.txt`.

The single most useful correction from the second pass: for **two** targets the *only*
structural difference is **which arm GCC makes the fall-through**, and in both cases the
target makes the **non-zero** arm inline while the registered source has the zero arm inline.

### `00109e30` — `u8` parameter **and** inverted test

Target: `andi a0,a0,0xff` / `beq a0,zero,+56` with `sd ra,8(sp)` in the delay slot; the
out-of-line zero arm (`jal 00133f60`) sits at offset 76 and the non-zero `jal 00133f80` is the
fall-through. Compiled: `sll a0,a0,24` / `sra a0,a0,24` / `bne` with the arms swapped. Two
independent fixes, tested as a 2x2 plus a control:

| Variant | Param | Polarity |
|---|---|---|
| `v03` | `u8` | non-zero inline |
| `v04` | `char` | non-zero inline |
| `v05` | `u8` | zero inline |

The `u8` spelling removes the `sll/sra` sign-extension pair, which is what frees the branch
delay slot for `sd ra,8(sp)`.

### `00242500` — invert the test, nothing else

The compiled baseline already shares the store/return tail with the original word for word
(offsets 44-68 match exactly). The entire difference is that the target's fall-through is the
**non-zero** arm (`jal 001058e8` / `lw t7,0x2440(v0)` / `addu t7,t7,s0`) while the registered
source's fall-through is the zero arm, which builds `999999` with `lui`+`ori` and branches back
into the tail. Inverting `if (lVar2 == 0)` to `if (lVar2 != 0)` is the fix; `v03` additionally
binds the first `func_001058e8()` to a local, to check whether that perturbs the arm layout.

### `001ac310` — stores through the `param_1 + 3` pointer

Target: `addiu s1,a0,12` then `lw t6,8(s0)` / `lw t7,4(s0)` (i.e. `param_1[2]` **before**
`param_1[1]`) and `sw t7,0x148(s1)` / `sw t6,0x14c(s1)`. Since `0x148 = 12 + 0x4f*4` and
`0x14c = 12 + 0x50*4`, the stores belong to the same `param_1 + 3` pointer that both callees
receive, not to `param_1` itself. `v04` routes them through it; `v05` also pre-binds the two
loaded values; `v06` is the control that keeps the original `param_1[0x55]` spelling.

### `001e7230` — a separate local for the masked remainder

Target keeps `a1` intact and uses `t6` as the second loop's counter (`andi t6,a1,0x3` in both
loop entries). The registered source assigns back into `param_2`, costing an extra `andi a1,a1,3`
at offset 48. `v02` uses a `u32` local for the remainder; `v03` hoists that assignment above the
first loop as a control.

### `001576e8` — nest the inner call in the outer call

Target: `jal 00155d58` / `mov a1,v0` / `jal 00138c10` / `addiu a0,s0,0x1a30` (the `addiu` is the
**delay slot** of the second `jal`). The previous call's result reaches `a1` before the address
argument is materialised, three times over. The registered source pre-binds `uVar1` and
pre-computes `(int)param_1`. `v03` fully nests the calls, `v04` writes the outer argument order
result-first, `v05` nests but keeps the base pointer in a local.

### `0014b950` — same instructions, different order

Target and compiled hold the **same instruction multiset**; only the order of the independent
"and `0xffff`, add `-1`" pairs, their shifts, and two `or` operands differs. `v03` names the two
packed halves, `v04` builds the `s64` field by field, `v05` builds two 32-bit halves and shifts
the upper one. This remains the least certain of the six.

## Measured, not guessed: which arm does GCC leave inline?

The `00109e30` / `00242500` fix rests on an assumption, so I measured it against the corpus
instead of trusting it. The trick needs no compiler: **for every function the primary has already
recovered byte-exactly, the original bytes on the disc are exactly what the source must
reproduce** — so I decoded the original instruction streams straight out of `SLPM_666.75` and
correlated the branch layout with the recovered sources.

`round-4/census_polarity.py` (run under WSL; it reads `/root/kh2fm-build/src/**` and
`/root/kh2fm-build/SLPM_666.75`, output in `polarity_census.txt`):

```
exact rows with a source path  : 5201
rows whose source was readable : 5481

arm-layout census over ALL byte-exact functions with an internal branch:
   conditional branches found       : 1564
   branch target INSIDE the function: 1564   (else arm out of line, THEN arm inline)
   branch target OUTSIDE            : 0      (arms swapped)
```

**1,564 out of 1,564, with zero exceptions.** This compiler never swaps the arms: the `then`
block is always the fall-through and the `else` block is always emitted out of line at the
branch target. So inverting `== 0` ↔ `!= 0` in the source deterministically swaps which arm is
inline, and no second lever is needed. That is exactly the `00109e30` and `00242500` fix.

Two negative results worth recording, because they cost time:

- **The corpus cannot answer the polarity question directly.** Of 5,201 exact functions, 4,658
  have no `if/else` at all, and the remaining 61 that do never spell an explicit `== 0` / `!= 0`
  test. The recovered set is overwhelmingly straight-line leaf wrappers, so there is not a
  single directly comparable function. The arm-layout measurement above is the substitute.
- **I hit my own documented endianness trap.** My first version of the script read the ELF as
  big-endian and reported 4,247 of 4,249 branch targets landing *outside* their own function.
  The disc is little-endian on disk while `ee-objdump` prints big-endian words; fixed, the
  figure became 1,564/1,564 inside. The comment in `be32()` now says so explicitly so the next
  reader does not "fix" it back.

## Environment anomaly: the workspace `tools/` tree has disappeared

While checking whether the compiler outage had cleared, I found that the entire
`C:/Users/KoZa/Documents/ChatGPT/tools/` directory **no longer exists**. Verified with
`os.path.exists` on three paths: `tools`, `tools/kh2-audit/probe_fm_source.py`, and
`tools/kh2-reference/SLPM_666.75` — all `False`. The workspace top level now holds only
`analysis/`, `HANDOFF.md`, and `WORKER_BRIEF.md`.

This is a **shared-resource event that the primary worker needs to know about**, because the
primary's checkpoint gates live under `tools/kh2-audit/` (`verify_fm_primary_*.py`,
`prepare_fm_worker_roundfour.py`, `update_worker_b_round2.py`, …). I did not restore, move, or
sync anything.

What survives, and where:

| Missing from the workspace | Status |
|---|---|
| disc image `SLPM_666.75` | **intact** in `analysis/final-mix/binaries/SLPM_666.75` and `/root/kh2fm-build/SLPM_666.75`, both sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87` |
| `layout.tsv`, `functions.tsv` | **intact** in `/root/kh2fm-build/` (layout.tsv 403,687 bytes, modified Oct 8 01:06) |
| `analysis/final-mix/native-pseudocode/main.jsonl` | **intact** (12,804,982 bytes) |
| `/root/kh2fm-build/tools/{build_elf.py,common.py,objdiff.py}` | **intact** (the harness imports these) |
| `tools/kh2-audit/probe_fm_source.py` | **missing from the workspace**, but an identical 5,305-byte copy (sha256 `e34f87ce2f4ff97f…`) exists at `C:\Users\KoZa\Documents\AGENTS\Public\tools\kh2-audit\probe_fm_source.py` |

I read the surviving copy and diffed it against the contract I had recorded from the missing one;
it is identical in every respect: `STAGE=/root/kh2fm-build`,
`WORKSPACE=/mnt/c/Users/KoZa/Documents/ChatGPT`, flags
`-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`, image
`kh2-local/ps2-compiler:3.2-ee-040921-objdiff`, both `#include` rewrites, the
`<stem>.verification.json` output naming, and the `D_<8hex>`/`func_<8hex>` linker-script
generation. So it is a usable stand-in and `r4_probe_assigned.sh` now falls back to it,
preferring the workspace copy if it reappears. I deliberately did **not** copy it back into the
workspace, since that tree belongs to the primary.

`C:\Users\KoZa\Documents\AGENTS\Public` looks like a fuller, actively-maintained copy of the same
project (it has `kh2-reference/.git`, the `SLUS_210.05` and overlay decompiles, and the whole
`verify_*`/`prepare_*` gate family). That is a separate tree from the one my brief pins; I made
no changes there beyond reading one file.

## Toolchain outage

Partway through round 4 the pinned compiler stopped being reachable:

- Windows service `com.docker.service` is `STOPPED` (exit code 1077).
- `npipe:////./pipe/dockerDesktopLinuxEngine` does not exist.
- `/var/run/docker.sock` is absent inside `Ubuntu-24.04`.
- `probe_fm_source.py` consequently fails on its internal `docker run` of
  `kh2-local/ps2-compiler:3.2-ee-040921-objdiff` with
  `subprocess.CalledProcessError ... returned non-zero exit status 1`.

I did **not** attempt to start or restart Docker; the brief forbids a docker restart. All four
batch1 exact recoveries were compiled and proven before the outage, so nothing already claimed
is unverified. The six assigned targets have 26 variants queued across two passes
(`r4_list_v2.txt` holds the 16 refined ones) and a one-command runner.

Also worth knowing: the pinned `ee-g++` exists only inside the probe container. Invoking
`/opt/ps2/gcc/bin/ee-g++` by hand from WSL fails with `No such file or directory`, which is why
`register u32 x asm("$t6")` pinning could not be explored as a workaround for `001ac700`.

To resume once Docker is back:

```
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- bash \
  /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/worker-coordination/worker-b/round-4/r4_probe_assigned.sh
```

then re-probe each winner with `probe_fm_source.py <src> --summary` and copy the survivors to
`fm_worker_b_round4_<addr>_solved.cpp`.

## Reproduction

```
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- python3 \
  /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-audit/probe_fm_source.py \
  /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/recovery-experiments/<name>.cpp --summary
```

writes `<name>.verification.json` next to the source; `exact_match` and `boundary_agreement`
are the two fields that matter. All probes for this round are named `fm_worker_b_round4_*` and
use isolated scratch directories under `/root/kh2fm-build/recovery-experiments/`.

## Tool inventory (this round)

| File | Purpose |
|---|---|
| `pick_targets.py` | screens unregistered/unclaimed ranges, ranks branchless leaves by size (1,393 candidates after screening) |
| `make_targets.py` | emits `batch1.targets.json` with per-range sha256 recomputed from the disc |
| `r4_dump_orig.py` | verifies ranges, writes `<addr>.orig.hex`, `r4_ranges.txt`, `r4_range_hashes.txt`, and with `--disasm` the pinned disassembly |
| `r4_dis.py` | word-level target-vs-compiled diff of a verification JSON row |
| `r4_scan_frameless.py` | finds frameless `j`-leaf ranges (the 3-function class finding) |
| `r4_decode.py` | offline MIPS decoder + full word tables for the assigned six |
| `find_siblings.py` | mines `main.jsonl` for other callers of each target's distinctive callees |
| `show.py` | dumps the pseudocode for given addresses |
| `r4_assigned_v2.py` | emits the 16 second-pass assigned variants and `r4_list_v2.txt` |
| `census_polarity.py` | offline corpus census: measures GCC's if/else arm-inlining rule from the 1,564 byte-exact functions containing an internal branch (needs WSL; reads `/root/kh2fm-build/src` + the disc) |
| `assigned_diff.txt` | its output; the six per-target diagnosis tables above come from here |
| `assigned.targets.json`, `assigned_ranges.txt` | the six assigned ranges with hashes and objdump ranges |
| `r4_probe_assigned.sh` | probes the six assigned targets; falls back to the surviving harness copy while the workspace one is missing |
| `make_claim.py` | builds `claim.json` |