# Round 17 — Worker B (isolated)

**Claim:** 16 framed, no-branch, `sd ra`-bearing unregistered ranges.
**Result:** 7 / 16 byte-exact. Added to the 73 recovered in rounds 1–16.

Every claimed range was verified before any edit: the bytes were read from the
original ELF (`Public/tools/kh2-reference/SLPM_666.75`, sha256
`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`) and the
per-range sha256, start, end and size were cross-checked against
`/root/kh2fm-build/layout.tsv`. 16/16 OK. `round-17/r17_dump_orig.py --disasm`
wrote `r17_ranges.txt`, `r17_range_hashes.txt` and `r17_orig_disasm.txt`.

Selection used `round-17/pick_targets.py` — the round-16 picker with ATTEMPTED
harvested mechanically from every `round-*/claim.json` (428 addresses, rounds
1–16) and primary's live claim re-read at run time. Screening reported 5512
registered rows, 11383 layout ranges, 11398 pseudocode records, 959 candidates.

---

## The two findings worth keeping

### 1. `$9` is the 6th O32 argument — not a special register

001ca988's second parameter arrives in `$9`. Three earlier rounds had recorded
that shape as "arguments in `$9`/`$10`/`$11` — not an O32 argument set, not
expressible in C". That was wrong. `$9` is simply the sixth argument register;
signing the function with six parameters places a value there exactly as the
target does. 001ca988 went exact on v02 with no other change.

The same correction unblocked two targets that had been parked since round 9:

| target | before | after | remaining |
|---|---|---|---|
| 00158050 (r14) | 52/56 | **56/56**, 7 words | schedule only |
| 002ba3b8 (r9) | 48/44 | **44/44**, 5 words | schedule only |

```c
void func_00158050(u32 p1,u32 p2,u32 p3,u32 p4,u32 p5,u32 p6,u32 p7)
{
  func_001386e0(p1, p2, p7);
  *(u32 *)(p1 + 408) = p6;
}
/* and */
void func_002ba3b8(u32 p1,u32 p2,u32 p3,u32 p4,u32 p5,u32 p6,u32 p7)
{
  s32 local_8;
  local_8 = -1;
  func_002ba3e8(p1, (u32)(long)&local_8, p6, p7);
}
```

001231f8 stays parked for a *different* reason — it is a `jalr $v0` target, which
is the vtable-register class below, not the argument-register one.

### 2. The symbol high half is always truncating — one rule, no exceptions

The working rule is: **the declared value `V` must satisfy
`V >> 16 == hi` and `V & 0xffff == lo16`.** This holds for `lw`/`sw`
(sign-extended 16-bit displacement) and for `addiu`/`ori` materialisation alike.

The earlier "an `addiu` rounds its high half" rule was an artifact: the declared
value was Ghidra's address, and the compiler faithfully used it. 001d6538 proves
it — the whole function was one word from exact with `addiu t7,t7,-17800`
already correct and only `lui t7,0x1d6` where the target wanted `0x1d5`.
Declaring `PTR_001d6ba78 = 0x1d6ba78` instead of `0x1d5ba78` is the fix.

Practical consequences:

* a global reached by `lw`/`sw` is usually declared **one page above** Ghidra's
  address (00288610, 0023fb00, 001d6baa8);
* a global whose **address is taken** (so it is materialised with
  `lui`+`addiu`) uses the **true** address (0x320448, 0x1e389a8);
* a plain integer literal emits `lui`+`ori` with no carry adjustment.

Always derive the symbol from the raw `.orig.hex` word. ee-objdump's printed
displacement disagrees with the encoded field — for 002f1898 it printed
`lw a0,-16176(t7)` where the word `8de4c0d0` encodes `0xc0d0` = −16192.

---

## Exact (7)

Each source is copied to `fm_worker_b_round17_<addr>_solved.cpp` and re-proved
**from that copy**; all have `exact_match: true`, `boundary_agreement: true` and
zero differing words.

| address | bytes | variant | mechanism |
|---|---|---|---|
| 001ca988 | 56/56 | v02 | six-parameter signature places the second argument in `$9` |
| 001b4300 | 60/60 | v01 | two constants spelled as symbol addresses (`&func_…`) so they materialise with `addiu` rather than `ori`; `DAT_001d58cb0 = 0` first |
| 001c13e8 | 60/60 | v01 | three real calls; the `param_1[12]` load written **inline as an argument** so GCC does not hoist it above the first call (hoisting forced a 32-byte frame, 72/60) |
| 001e6648 | 60/60 | v01 | three calls then two clears in the same page — `0x1dae6b4` as `u32`, `0x1dae6b0` as `u8` |
| 002d47e8 | 60/60 | v02 | vtable-setter shape, sibling of round 16's 002d47a8 |
| 002d5dd0 | 60/60 | v02 | same shape |
| 002db8a8 | 60/60 | v02 | same shape |

The vtable-setter shape, which now reproduces the whole family on the first or
second attempt:

```c
*(u32 *)param_1 = (u32)(long)&PTR_x;
func_A((u32)(long)((u8 *)param_1 + off));
func_B(param_1);
asm volatile ("");
```

The trailing empty asm is what stops GCC rewriting the last call into a sibling
tail call. 002d47e8, 002d5dd0 and 002db8a8 failed only to link on v01 — the
`asm(".globl X … X = …")` block defines a **linker** symbol, so a matching
`extern "C" u32 PTR_x;` declaration is still required.

---

## Unresolved (9)

| target | best | measured | blocker |
|---|---|---|---|
| 001d6538 | v03 | 60/60, **1 word** | `lui t7,0x1d6` vs `0x1d5`; v04 declares `PTR_001d6ba78` |
| 001fab08 | v03 | 60/60, 2 words | intermediate register: target `lw t6,0(t7)`+`addu s0,t6,a0`, GCC folds into `lw s0,0(t7)` |
| 001fb870 | v03 | 60/60, 2 words | byte-identical twin of 001fab08 |
| 00158050 | v03 | 56/56, 1 word | argument-shuffle schedule; see §1 |
| 002ba3b8 | v03 | 44/44, 5 words | target shuffles `t3←t2`/`t2←t1` in the prologue, GCC after the spill |
| 001bb4b0 | v03 | 60/60, 6 words | target loads the global pointer into `$t5`, GCC picks `$t6` |
| 002429c0 | v03 | 60/60, 5 words | — |
| 002a0360 | v03 | 60/60, 6 words | — |
| 002cb7c8 | v03 | 64/56 | `lq t0`/`sq t0` struct copy from a call return keeps eliding the quad form (68/56, 64/56, 64/56 across three variants) |
| 002424c0 | v02 | 60/60, 7 words | target builds 999999 in `$v0` and reuses it for the `sltu`/`xori` result, GCC uses `$v1` |
| 00265c10 | v02 | 64/60 | v02 regressed; v01 was better |

## Classes still open after this round

1. `$v0`-vs-`$t7` scratch choice — 00308cd0 (r7), 0030a2d0 (r11), 0030a690 and
   0018d808 (r14), 0030df00 (r15), 001bb4b0 (r17).
2. a body load's `lui` never scheduled into the prologue region — eight members
   in round 14.
3. epilogue `ld ra` scheduled into the middle of the body.
4. leaf frame-pointer idiom `sd s8; move s8,sp; … move sp,s8; ld s8` — implies
   `-fno-omit-frame-pointer` for some original translation units.
5. `jalr $v0` vtable dispatch — nine members, parked.
6. prologue sink: a vtable-pointer store to the incoming parameter is scheduled
   *between* the two prologue saves by GCC 3.2 where the original sinks it below
   both.
7. likely-branch `beql`/`beqzl` forms.

Classes 1 and 6 are consistent enough across four rounds to look like build-wide
code-generation settings rather than per-function accidents. Worker B cannot set
compiler flags, so both are recorded rather than chased.

## Environment notes for primary

* The reference ELF is staged at **`/root/kh2fm-build/SLPM_666.75`** (same
  sha256). `/root/kh2fm-build/tools/` holds only `build_elf.py`, `common.py`,
  `objdiff.py` — there is **no** `tools/kh2-reference/` subdirectory, so an
  ee-objdump invocation pointed at `/work/tools/kh2-reference/SLPM_666.75`
  fails. `round-15/r15_disasm.sh` uses `-v /root/kh2fm-build:/work` and
  `/work/SLPM_666.75`.
* `/root/kh2fm-build/layout.tsv` is **CRLF-terminated**. A reader that splits on
  `\n` alone keeps the `\r` on every size field, `int()` raises, and a helper
  that swallows the error will silently return a two-row layout. That bug hid a
  picker for four rounds.
* Probe launches go through `worker-b/round-5/r5_probe_win.sh` from WSL.
  `bg_run` uses cmd.exe, so `MSYS_NO_PATHCONV=1 …` prefixes die instantly.