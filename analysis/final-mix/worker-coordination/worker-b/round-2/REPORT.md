# Worker B — Round 2 report

**Worker:** worker-b, round 2 (isolated recovery batch)
**Targets:** `002bc2e8`, `0017ee68`, `00310620`, `00180c88`, `002f3bb8`, `0019c0f8`
**Toolchain:** pinned image `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`
(`/opt/ps2/gcc/bin/ee-g++ -O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`)
**Disc image:** `tools/kh2-reference/SLPM_666.75`
sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`
(verified; every one of the six `original_range_sha256` values in `targets.json` reproduced from disk)

---

## 1. Outcome

| address | bytes | result | canonical source |
|---|---|---|---|
| `00180c88` | 72 | **exact (1/1)** | `analysis/final-mix/recovery-experiments/fm_worker_b_round2_00180c88_solved.cpp` |
| `0017ee68` | 124 | **exact (1/1)** | `analysis/final-mix/recovery-experiments/fm_worker_b_round2_0017ee68_solved.cpp` |
| `0019c0f8` | 92 | **exact (1/1)** | `analysis/final-mix/recovery-experiments/fm_worker_b_round2_0019c0f8_solved.cpp` |
| `002bc2e8` | 108 | **exact (1/1)** | `analysis/final-mix/recovery-experiments/fm_worker_b_round2_002bc2e8_solved.cpp` |
| `002f3bb8` | 56 | not recovered — 9/14 words differ (block layout only) | best: `fm_worker_b_round2_002f3bb8_v21.cpp` |
| `00310620` | 76 | not recovered — frame allocation only (6/19 words on an identical-shape probe) | see §4.2 |

4 of 6 ranges are now instruction-exact and carry a `*.verification.json`
(`exact_match: true`, `boundary_agreement: true`) bound to the SHA256 of the exact
source file they were produced from. 98 isolated probes were run in total; every
experiment file is named `fm_worker_b_round2_*` and no shared output was modified.

The four recovered sources are byte-identical in effect to the pre-existing
recoveries in `fm_call_fixed_primary_width_00_all_narrow32.cpp` and
`fm_primary_width_01_all.cpp`; they are supplied as ready-to-apply replacements.

---

## 2. Recovered sources and the mechanism that made them exact

### 2.1 `00180c88` — parameter mapping was wrong in the earlier recovery

Baseline diff: 8 words. The registered pseudocode used **`param_2`** as the struct
pointer; the original uses the incoming **`a0`**. The original also materialises a
floating `0.0` into `$f13` and passes a third floating argument.

```cpp
#include "../common/types.h"
extern "C" u32 func_0017f488(s32,s32,float,float);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
```

Findings:
- The caller's third parameter is a **float** forwarded into the callee's third
  floating argument register (`$f12`), which needs no instruction; the trailing
  `0.0f` becomes `mtc1 zero,$f13` (word `44806800`). Declaring the parameter as
  `float` is what makes GCC put it in `$f12` instead of `$a2`.
- The original `move t0,a1` (`00a0402d`) is emitted **by GCC itself** for a
  4-argument call whose last two arguments are floats; adding a fifth source-level
  argument to force it explicitly (`v01`/`v03`/`v05`) breaks the match.
- `func_001802d8` is `_ZN2YS6MOTION7CaptureEPNS_3OBJEPNS_9MOTIONSETEPN3ryj3PAXES2_ifPi`
  — 9 mangled parameters, i.e. the call really does pass 5 integer registers.

### 2.2 `0017ee68` — inline the nested call instead of pre-binding its result

Baseline diff: 4 words at each of the two call sites. Target emits
`move a1,v0` before `jal` and `move a0,s1` in the branch-delay slot; the previous
recovery emitted them in the opposite order/placement.

```cpp
#include "../common/types.h"
extern "C" u32 func_001050c8(void);
extern "C" u32 func_00127c70(u32,u32,u32);

void func_0017ee68(int param_1)
{
  u32 uVar1;
  uVar1 = *(u32 *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    func_00127c70(uVar1,func_001050c8(),*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    func_00127c70(uVar1,func_001050c8(),*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
```

Finding: the *only* difference between this and the previous recovery is writing
`func_001050c8()` **inside** the argument list instead of
`uVar2 = func_001050c8(); func_00127c70(uVar1,uVar2,...)`. That changes the RTL
argument-setup ordering and the MIPS delay-slot filler picks the other move.
Same length, same semantics, byte-exact.

### 2.3 `0019c0f8` — pre-zero the result *before* the call, and compare against a variable

Baseline diff: 12 words and a length mismatch (84 vs 92 bytes).

```cpp
#include "../common/types.h"
extern "C" s32 func_0019c090(...);

s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  s32 lVar2;
  u32 uVar2;
  u32 uVar3;
  uVar2 = *(u32 *)(*(int *)(param_1 + 0xc) + 8);
  uVar3 = 0;
  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = ((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == uVar3);
    }
  }
  return lVar1;
}
```

Findings (two independent effects):
- Declaring/zeroing the result variable **before** the call to `func_0019c090`
  makes it live across a call, so GCC must keep it in a callee-saved register —
  producing `sd s1,8(sp)`, `move s1,zero` in the call's delay slot and
  `move v0,s1` in the `beqz` delay slot. This alone took the diff from 12 words /
  84 bytes to 11 words / 96 bytes with a **byte-identical prologue**.
- Comparing against a **variable** (`uVar3`) instead of the literal `0` defeats
  GCC's `find_bit_field` canonicalisation, which otherwise rewrites
  `(x & 0x200) == 0` into `sra 9 / xori 1 / andi 1` (three instructions). With the
  variable the original pair `andi t7,t7,0x200` + `sltiu s1,t7,1` is reproduced
  exactly, and the branch offsets realign.

### 2.4 `002bc2e8` — copy parameters into locals in reverse order, pinned by an asm barrier

Baseline diff: 4 words (a callee-saved register swap: original `move s0,a1` /
`move s1,a0`, compiled `move s0,a0` / `move s1,a1`).

```cpp
#include "../common/types.h"
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;

  uVar2 = param_2;
  uVar3 = param_1;
  asm("" : "+r"(uVar2), "+r"(uVar3));
  s32 lVar2;
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,uVar3,uVar2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}
```

Findings:
- Neither parameter declaration order, nor argument order at the call, nor
  pre-binding parameters into temporaries (v01–v04) changes the entry parallel
  move: GCC always emits `s0<-a0`, `s1<-a1`.
- Copying `param_2` **before** `param_1` and constraining the copies with
  `asm("" : "+r"(uVar2), "+r"(uVar3))` **in that order** flips it to the original
  `s0<-a1`, `s1<-a0`. Both orderings are load-bearing: v08 (same copies, reverse
  asm operand order) and v03 (same copies, no asm) both fail with the original
  4-word diff, as do all five other asm-barrier placements (v05, v06, v09, v10).
- This is the round-1 "materialise the register explicitly" technique applied to
  callee-saved allocation rather than to address materialisation.

---

## 3. `002f3bb8` — not recovered (9 of 14 words)

Original (14 words):
```
addiu sp,sp,-16 / li v0,1 / bne a1,v0,+5 / ld ra,0(sp)     <- delay slot
lw v0,0(a0) / srl v0,v0,8 / b +4 / andi v0,v0,1            <- delay slot
jal 0x2f3490 / nop / move v0,zero
ld ra,0(sp) / jr ra / addiu sp,sp,16                        <- shared epilogue
```

Best candidate `fm_worker_b_round2_002f3bb8_v21.cpp` (9 words differ):
```c
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 1;
  if (param_2 == uVar1) {
    uVar1 = *param_1; uVar1 = uVar1 >> 8; uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
```
The then-block instructions (`lw v0,0(a0)`, `srl v0,v0,8`, `andi v0,v0,1`) and the
constant in `$2` now match exactly. **The only remaining difference is basic-block
placement**: GCC merges the shared epilogue into the then-path's exit and leaves the
else block at the end with a backward branch (`b -6`), whereas the original keeps the
else block inline and lets the then-path jump over it (`b +4` with `andi` in the
delay slot). Everything after `b +4` is therefore shifted, which accounts for all
9 differing words.

Shapes tried without success (all recorded with their `.verification.json`):
negated condition; `return` inside each branch; `switch` with `case 1`/`default`;
constant held in a second local; pre-zeroed result with no `else`; `goto` to a
shared label; `do { … } while (0)`; `__builtin_expect(…, 1)` and
`__builtin_expect(…, 0)`; four placements of an empty `asm`/memory-clobber barrier;
`u32` vs `s32` vs `u8` vs `bool` result types, pointer vs integer first parameter,
and the constant held in an `s32` local (9–15 words off).
The layout decision is a block-reordering/tail-merging choice in the pinned
compiler that none of ~20 source spellings steers.

## 4. `00310620` — not recovered; a whole class of 461 functions is blocked

### 4.1 The frame itself

Target prologue/epilogue:
`addiu sp,sp,-48` / `sd s0,0` / `sd s1,16(sp)` / `sd ra,32(sp)` … epilogue restores
`ra`, `s1`, `s0` in that order. The pinned compiler always emits three 8-byte-spaced
save slots (`addiu sp,sp,-32` / offsets 0, 8, 16) for this body. The body
instructions are already identical — the entire diff is the frame.

### 4.2 Proof that no body construct causes it

`analysis/final-mix/recovery-experiments/fm_worker_b_round2_00310560_probe.cpp`
rebuilds the body of `0x00310560`, which is structurally identical to `0x00310620`
(same frame, same 19-instruction shape, only the middle `jal` target differs). It
compiles to the original `0x00310560` bytes **exactly** in every instruction except
the six frame words:

```
+0000 w 0   T 27bdffd0   C 27bdffe0
+0008 w 2   T ffb10010   C ffb10008
+000c w 3   T ffbf0020   C ffbf0010
+0038 w14   T dfbf0020   C dfb10008
+003c w15   T dfb10010   C dfb00000
+0040 w16   T dfb00000   C dfbf0010
```
So the body source is correct; only the callee-save slot stride is unreachable.

### 4.3 Class-level finding

A scan of the disc for the exact prologue pattern (`addiu sp,sp,-n` followed by ≥2
`sd/ld $sN` saves at offsets that are all multiples of 16 and exactly 16 apart)
finds **461 functions** with the 16-byte save-slot stride, clustered in families
(`0x00309988`, `0x00309e50`, `0x00310130`, `0x003102e0`, `0x003103f8`,
`0x00310560`, `0x00310620` are the seven consecutive 48-byte-frame functions around
the target, all unregistered and all calling `func_0030edb0`/`func_0030ee00`).
**None of the 461 appears in the exact-match set of
`analysis/final-mix/native-build/compiler-range-verification.json`.** This is a
systematic class gap, not a one-off.

### 4.4 Ruled out

Struct-local (dead 8-byte struct → frame 48 but saves land at 0x10/0x18),
16-byte-aligned local struct, aligned file-scope union, `double[2]` local, unused
aligned static, `typedef` alignment, 1–6 callee-saved registers, dead scalar /
`long long` / `double` / unused locals, dead local through a pointer, dead local
inside a branch, variadic vs `(void)` prototypes, struct return value, `double` and
`long long` parameters, six-integer-argument calls, `alloca`, and memory-clobber
`asm` — all either leave frame 32 or give frame 48 with the saves shifted above a
local. No construct was found that interleaves two dead 8-byte slots *between* the
three save slots, which is what the original layout (`s0@0`, `s1@16`, `ra@32`,
frame 48) implies.

---

## 5. Reproduction

```sh
# exact compile + byte proof for one recovered function (run under WSL)
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- \
  python3 /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-audit/probe_fm_source.py \
  /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/recovery-experiments/fm_worker_b_round2_0017ee68_solved.cpp --summary
# -> Exact probe matches: 1/1

# word-level diff against the original bytes
python analysis/final-mix/worker-coordination/worker-b/round-2/round2_diff.py \
  analysis/final-mix/recovery-experiments/fm_worker_b_round2_002f3bb8_v21.verification.json

# dump the pinned-objdump disassembly of all six original ranges
python analysis/final-mix/worker-coordination/worker-b/round-2/round2_dump_orig.py
```

### Tooling written this round (all under `analysis/final-mix/worker-coordination/worker-b/round-2/`)

| file | purpose |
|---|---|
| `round2_dump_orig.py` | verifies the disc SHA256 and all six `original_range_sha256` values, writes `<addr>.orig.hex` and `round2_ranges.txt` |
| `round2_diff.py` | per-word diff (target vs compiled) of any `*.verification.json`, big-endian words, optional address filter |
| `round2_mine_stride16.py` | scans the disc for the 16-byte callee-save stride and maps hits through `functions.tsv` |
| `r2_gen.py`, `r2_gen2.py`, `r2_gen3.py`, `r2_gen4.py`, `r2_gen5.py` | deterministic variant generators (every variant file is reproducible from these) |
| `r2_grid.py` | builds a range-override JSON of parked real ranges so compiler-behaviour probes (frame layout, register allocation, block order) can be measured on functions that are not the target |
| `r2_probe_batch.sh` | batch probe runner (note: unreliable under `bg_run`; probes were run in the foreground) |
| `round2_orig_disasm.txt` | pinned `ee-objdump` disassembly of all six original ranges |
| `r2_list_*.txt` | probe lists per target/batch |

## 6. Boundaries

- No shared output was modified: `tools/kh2-reference/functions.tsv`,
  `layout.tsv`, `analysis/final-mix/native-pseudocode/main.jsonl`,
  `analysis/final-mix/native-build/compiler-range-verification.json`, `src/anon`,
  manifests and `HANDOFF.md` are untouched (their SHA256 values are recorded in
  `claim.json` and were re-checked before starting).
- No full build, no staged-input synchronisation, no docker restart, no Ghidra
  project mutation, no executable-byte patching.
- WSL scratch use was confined to `/root/kh2fm-build/recovery-experiments/fm_worker_b_round2_*`
  directories; the containers of other workers were not touched.
- Round-1 evidence under `analysis/final-mix/worker-coordination/worker-b/` is preserved.