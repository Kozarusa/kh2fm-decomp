# Worker B — Round 14 report

**Role:** isolated proposals/reports only. Primary retains active sources, `functions.tsv`, `layout.tsv`, stage sync, full builds, manifests, receipts, Ghidra, `HANDOFF.md`.
**Original ELF:** `Public/tools/kh2-reference/SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
**Claimed:** 14 ranges, all 14 range-hash OK and start/end/size agreeing with `/root/kh2fm-build/layout.tsv` (`round-14/r14_dump_orig.py --disasm`, output `r14_range_hashes.txt`).

## Selection

`round-14/pick_targets.py` = the round-13 picker with every worker-B address from all round claims harvested into `ATTEMPTED` (217), primary's live claim re-read from `primary-claim.json` at run time, and two new exclusions for classes already proven unreachable on this compiler: any body containing `jalr` through a loaded entry (the `jalr $v0` class), and any body with **no `sd ra`** (the leaf frame-pointer idiom). Screening kept framed, integer-only, 20–120 byte bodies and ranked NO-BRANCH first.

5512 registered rows, 11383 layout ranges, 11398 pseudocode records → **1005 candidates**.

### Two fixes carried in the picker, both worth propagating
- **`layout.tsv` is now CRLF-terminated.** The loader did `line.rstrip("\n")`, so every size field kept a trailing `\r`, `int()` raised, and `load_layout()` silently returned **2** rows — the candidate list came back empty with no error. Fixed to `rstrip("\r\n")`. This silently affected every picker back to round 9.
- **The first `no-jalr` filter was written against the wrong field.** `sd`/`ld` encode the base register in `rs` (sp = 29) and the saved register in `rt` (ra = 31); testing `rs == 31` skipped 1104 valid framed candidates and returned 0. Caught by counting skip reasons rather than trusting the zero.

## Result: 1 / 14 byte-exact

| address | bytes | source sha256 | variant | status |
|---|---|---|---|---|
| 00322ba8 | 52/52 | `ed27465497e4b5041ab6b205cd3765ed6fb6484f536e38ad54c787ca845dfbef` | v02 | EXACT |

Proof: `recovery-experiments/fm_worker_b_round14_00322ba8_solved.verification.json`, `exact_match: true`, `boundary_agreement: true`, 0 differing words.

```c
void func_00322ba8(u32 param_1)
{
  func_00108698(param_1 + 0x38);
  func_001ddd10(param_1 + 0xc0);
  asm volatile ("");
  return;
}
```
The trailing empty asm blocks the sibling-call rewrite of the second call; without it GCC emits `ld ra,8(sp)` immediately after the first `jal` and turns the second call into `j 0x1ddd10` (48/52).

## New mechanism: the address of an absolute linker symbol

**Finding.** GCC 3.2 emits `lui reg,%hi(sym)` + `addiu reg,%lo(sym)` — the relocation path — when a constant is spelled as **the address of an absolute linker symbol**, but `lui` + `ori` — `li_operand` — when the same constant is spelled as a plain integer literal. Casting an integer to `void *` or to a function-pointer typedef does **not** change this; only a genuine `SYMBOL_REF` does.

**How to exploit it.** The probe harness already auto-defines `func_<8 hex digits>` in its generated linker script, so:
```c
extern "C" char func_00320448;
...
func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, (u32)(long)&func_00320448);
```
produces `lui t0,0x32` + `addiu t0,t0,1096` exactly where the integer literal `0x320448` produced `lui t0,0x32` + `ori t0,t0,0x448`.

**Page-bias warning.** The assembler's `%hi` is conservative — `hi = (V + 0x8000) >> 16` while `%lo` keeps `V & 0xffff` unsigned. That pair is self-consistent when `V & 0xffff >= 0x8000` (confirmed: symbol-addressing `0x1e389a8` produced precisely the target's `lui a0,0x1e4` + `addiu a0,a0,-30296`), and biased one page **high** when `V & 0xffff < 0x8000` (observed: `&func_01d58d90` produced `lui t7,0x1d6` + `lw a1,-29296(t7)` = 0x1d68d90 instead of 0x1d58d90). Always check the emitted page before trusting a symbol-addressed constant.

## Unresolved, with the measured blocker

| address | best | measured | why |
|---|---|---|---|
| 001b8800 | v10 | 52/52, **2 words (one swap)** | see below |
| 001c0c38, 001c10f8, 001d22a8, 001d23e0, 001d30c0, 001d7980, 002c22b8 | v10 | 52/52, 2 words each | same single-word blocker |
| 0018d808 | v04 | 52/52, **2 words (one instruction pair)** | see below |
| 0030a690 | v02 | 52/52, 4 words | see below |
| 00311100 / 00311138 | v01 | 52/52, 4 words | see below |
| 00158050 | v01 | 52/56 | see below |

### The eight-member family — one word out
All eight are the same shape:
```
func_002fd248(param_1, DAT + 8, *(u32 *)(DAT + 4), N, C)
```
with `DAT`/`N`/`C` per member: 001b8800 `0x1d58d90`/16/`0x320448`; 001c0c38 `0x1d59360`/32/`0x320888`; 001c10f8 `0x1d59508`/64/`0x320898`; 001d22a8 `0x1d5ba00`/16/`0x321688`; 001d23e0 `0x1d5ba04`/12/`0x321698`; 001d30c0 `0x1d5ba0c`/8/`0x3216a8`; 001d7980 `0x1d5ba9c`/4/`0x3218b8`; 002c22b8 `0x1e3bd00`/16/`0x324bb0`.

The symbol-address mechanism fixed the `addiu`-vs-`ori` word, leaving exactly one difference:

```
target    lui t7,0x1d5 ; sd ra,0(sp) ; lui t0,0x32 ; lw a1,-29296(t7) ; ...
compiled  sd ra,0(sp)  ; lui t7,0x1d5 ; lui t0,0x32 ; lw a1,-29296(t7) ; ...
```

The target issues the global's `lui` **before** the prologue store and its `lw` **after**. Twelve variants were tried on 001b8800: plain, trailing empty asm, memory barrier, `volatile` global, `volatile` pointer local, address-of-global, both references inline in the argument list, two named temps, a temp holding the constant, a barrier combined with each, and the symbol-address spelling for the global. Every spelling that keeps the `lw` below the prologue store also pushes the `lui` below it; every spelling that hoists the `lui` also hoists the `lw`. **Address materialisation for a load in the body is never issued in the prologue region by this compiler.** Recorded as compiler-level.

### 0018d808 — one instruction pair
```c
typedef struct __attribute__((aligned(16))) { u64 field_0; u64 field_1; } quad;
u32 func_0018d808(u32 param_1, u32 param_2)
{
  quad *puVar1;
  puVar1 = (quad *)func_0016c028(*(u32 *)(param_2 + 8));
  *(quad *)param_1 = *puVar1;
  asm volatile ("" ::: "memory");
  return param_1;
}
```
The 16-byte aligned struct is what makes GCC emit the `lq`/`sq` pair (an unaligned quad type produced `ld`/`sd` pairs and 64/52), and the barrier after the copy is what stops it sinking `ld ra` between the `lq` and the `sq`. Everything then matches except the scratch register: target `lq t0`/`sq t0`, compiled `lq t7`/`sq t7`.

### 0030a690 — 4 words
The code constant `0x1e389a8` is now exact via the symbol-address mechanism. Two sub-issues remain: the scratch register for the global store (target `lui v0,0x36` + `sw zero,24932(v0)`, compiled `lui t7,0x36` + `sw zero,24932(t7)`), and `sd ra,0(sp)` sitting one slot early relative to the two `lui`s.

### 00311100 / 00311138 — 4 words
Target order is `move v0,a1` → `andi a2,a2,0xffff` → `sw a0,0(sp)` → `sd ra,16(sp)` → `move a1,sp` → `sw v0,4(sp)` → `li a0,-5` → `jal` → `sw a2,8(sp)`. The `move v0,a1` forces the second struct word through `$v0`, and GCC keeps `a1` in place instead. v02 (store order swapped) and v03 (memory barrier between the stores) both regressed to 48/52.

### 00158050 — 52/56
The second and third parameters arrive in `$t1` and `$t2`, which are not an O32 argument register set. Same not-expressible-in-C class as round-9's 002ba3b8 and round-10's 001231f8. The frame, both callee-saved stores, the call and the `408(s1)` store all match.

## Recurring compiler-level patterns (running list for primary)
1. **scratch register `$v0` vs `$t7`** for a global address or a 16-byte move — 00308cd0 (r7), 0030a2d0 (r11), 0030a690 and 0018d808 (r14).
2. **address-materialising `lui` for a body load is never scheduled into the prologue region** — eight members this round.
3. **epilogue `ld ra` scheduled into the middle of the body** — 001ac700 (r6), 002ef340 (r9), 0018d808 before its barrier.
4. **leaf frame-pointer idiom** `sd s8; move s8,sp; … move sp,s8; ld s8` — 002b99a0, 002b6ab8, 002b81ec, 002b8214. GCC 3.2 never emits it from C, so the original build used `-fno-omit-frame-pointer` for some translation units — a build-wide flag difference, out of worker B's scope.
5. **arguments in `$9`/`$10`/`$11`** — 002ba3b8, 001231f8, 00158050.
6. **`jalr $v0` vtable dispatch** — nine members, parked.
7. **frameless sibling-call thunks** — GCC 3.2 always allocates a 16-byte frame around a tail call.