# Worker B — Round 3 report

Small call-free leaf functions. Closed after ~60 isolated probes. **3 of 8 exact**, 5 documented as
compiler-level blockers.

Round 2 is closed at 4/6 (`round-2/REPORT.md`). The two remaining round-2 targets
(`002f3bb8`, `00310620`) were given one final bounded experiment each before closing:

- `00310620` frame — hypothesis: the 16-byte gaps in `s0@0 / s1@16 / ra@32` are outgoing
  stack-argument areas built for the callees. **Refuted**: `fm_worker_b_round2_00310620_v01..v06`
  (callees with 5/6 int args, `double` params, 64-bit returns, struct-by-value, own `long long`
  return) all still open `27bdffe0 / ffb10008 / ffb00000`. v06 failed to compile entirely
  (aggregate init unsupported by this compiler).
- `002f3bb8` — no new attempt; basic-block placement remains the blocker.

---

## Exact recoveries

All three: `exact_match: true`, `boundary_agreement: true`, source + proof in
`analysis/final-mix/recovery-experiments/`.

### `0028af90` (20 B) — `fm_worker_b_round3_0028af90_solved.cpp`
sha256 `fa6c7659b4eebc0bbbe394374825e2b1581ea817305c5f122f54659e2d08d079`

Baseline was 1 word off: the target puts `move t7,a1` in the `bgez` delay slot, GCC emitted
`andi t7,a1,0xffff` because the branch condition itself needed a `u16`. Keeping the value in a
`u32` moves the truncation to the `sh`, which is where the original has it.

```cpp
#include "../common/types.h"

void func_0028af90(u16 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 >= 0) {
    uVar1 = (u32)param_2;
  }
  else {
    uVar1 = param_1[2];
  }
  *(u16 *)((char *)param_1 + 0x16) = (u16)uVar1;
}
```

### `002d5c20` (28 B) — `fm_worker_b_round3_002d5c20_solved.cpp`
sha256 `bdc41fa90292fe766490c05875ba36e3594527964d37724f906d5cec1c8bb675`

Two independent effects:

1. `0.0f` written inline folds to `sw zero` (an integer store of the zero bit pattern). The target
   uses `mtc1 zero,$f0` + `swc1`, so the constant must be materialised in an FP register — bind it
   to a `float` local. (`volatile float *` stores, v02, do **not** defeat the fold.)
2. Store order is source order. The Ghidra body lists the stores 3,0,1,2; the original order is
   ascending offsets 0,1,2,3. GCC faithfully emits whichever order is written — v03 (3,0,1,2)
   produced a rotated 8,12,0,4.

```cpp
#include "../common/types.h"

float *func_002d5c20(float *param_1)
{
  float fVar1 = 0.0f;
  param_1[0] = fVar1;
  param_1[1] = fVar1;
  param_1[2] = fVar1;
  param_1[3] = fVar1;
  return param_1;
}
```

### `002f8870` (24 B) — `fm_worker_b_round3_002f8870_solved.cpp`
sha256 `7cf4e8f14f2a5899971a0d9ece26e02c21e45acac75308c05c15cf2376bf1b2a`

Only 2 words off at baseline. The target reuses **one** register for the whole round trip
(`mfc1 t6,$f12` / `and t6,t6,t7` / `mtc1 t6,$f0`); every union-based spelling allocates a fresh one
(`mfc1 t4` / `and t5,t4,t7` / `mtc1 t5,$f0`) because the union forces a float↔int mode change that
blocks coalescing. `__builtin_memcpy` out, mask, `__builtin_memcpy` back into the **same parameter**
(which is then returned) keeps everything on one pseudo. Extra union locals (v05) and
`asm("" : "+r"(uVar1.i))` (v06) do not; `__builtin_fabs` (v02) compiles to 92 B.

```cpp
#include "../common/types.h"

float func_002f8870(float param_1)
{
  unsigned int uVar1;
  __builtin_memcpy(&uVar1,&param_1,4);
  uVar1 &= 0x7fffffff;
  __builtin_memcpy(&param_1,&uVar1,4);
  return param_1;
}
```

---

## Blocked targets (all documented, none pursued further)

### `0028ac98` (32 B) — 2 words, register choice only
Target `sll t6,a1,3` / `addu v0,t7,t6`; compiled `sll v0,a1,3` / `addu v0,v0,t7`. Every branch,
delay slot and the out-of-line `b -3` tail already match. Best sources
`fm_worker_b_round3_0028ac98_v05` / `_v08`:
`s32 iVar2 = param_2 * 8;` before the branch, `iVar1 = *(s32 *)((char *)param_1 + 0x30) + iVar2;`
in each arm. Ruled out: pointer-variable arms (v02, 36 B), `s32*` indexing (v03, 36 B), `u32`/`<<3`
(v10), `return iVar1 + param_2 * 8` (v09, 28 B), and every asm barrier tried — v06 collapsed the
body to 28 B, v11 hoisted the load and reordered the branches.

### `00152598` (28 B) — 4 words, same class
Target holds the computed address in **t7** across the branch; GCC uses **v0** / clobbers **a1**.
Ruled out: inverted test (v02 turns `bnez` into `beq` and swaps the loads), all-`int` types (v06),
`(char*)0` base (v07), `long` return (v08), all-`u32` params (v09), integer-then-cast base (v10),
asm pinning of the pointer (v04, v12), and a reverse-order asm on the parameters (v11, which grew
the function to 32 B with an `sd`).

### `00308da0` (28 B) — 6 words, constant-expansion path
Body is right except the mask: every spelling folds `0xfffffffe` to `addiu v0,zero,0xfffe`, while
the target builds it with `lui v0,0xffff` + `ori v0,v0,0xfffe`; the target also loads into **v1**
rather than t7. Ruled out: `& ~1`, `& ~0u << 1`, `(u32)(-1) << 1`, `& 0xfffffffe` with and without
`u`/`L` suffixes, a named `static const` mask, a `struct` with named fields, `char *` parameter,
`^= (x & 1u)`, reversed statement order, `long long` return (32 B), `long` intermediate.
**Lesson:** this pinned `ee-g++ 3.2` always prefers the single-instruction `addiu` form in
`li_imm`; the two-instruction form must come from a different expansion path that no C spelling
found here reaches.

### `001c8a90` (28 B) — address materialisation
Instruction shape matches (three `sw zero` with the third in the `jr ra` delay slot). Pinning the
three globals with inline-asm absolute definitions (`nm` confirms `A 01d49960` etc.) reproduces the
exact offsets `sw zero,-26272(t7)` / `-26264(t7)` and the `addiu t6,t7,-26272` CSE, but GCC emits
`lui $t7,0x1d4` where the target has `lui $t7,0x1d5`, and orders the last `lui`/`sw` pair
differently. Best source `fm_worker_b_round3_001c8a90_v03` (addressing the second global through a
pointer derived from the first).

### `00100338` / `001003b0` / `00101d38` (20 B each) — frame with no body
```
addiu sp,sp,-16 / sd ra,0(sp) / ld ra,0(sp) / jr ra / addiu sp,sp,16
```
**Key finding: the frame is produced by the call, not by a local.** Declaring a real callee
`__attribute__((const))` and calling it reproduces the prologue and epilogue *byte for byte* and
emits `j func_XXXX` where the original has `jr ra` (`fm_worker_b_round3_00100338_v02`,
`fm_worker_b_round3_00101d38_v02`, both 20/20). Ruled out: empty body (8 B), `if (0) { call; }`
(call deleted, no frame, 8 B), `asm volatile("" ::: "memory")` alone (8 B), call + asm (28 B,
call kept), two const calls (28 B), `__builtin_alloca(0)` (8 B), `__builtin_alloca(8)` (32 B),
`__builtin_alloca_with_align(8,16)` (compile error), C++ local with destructor (8 B — with
`-fno-exceptions` the cleanup region is not emitted). The original was almost certainly built
with exceptions enabled and these are cleanup stubs; they are not reproducible under the pinned
`-fno-exceptions -fno-rtti` probe flags.

---

## Reproduction

```sh
# verify originals + per-range hashes, and dump the pinned disassembly
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- \
  python3 /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/worker-coordination/worker-b/round-3/r3_dump_orig.py \
    --disasm

# prove one source
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- \
  python3 /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-audit/probe_fm_source.py \
    /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/recovery-experiments/fm_worker_b_round3_0028af90_solved.cpp --summary

# word-level target-vs-compiled diff for any verification JSON
python /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/worker-coordination/worker-b/round-3/r3_dis.py \
  /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/recovery-experiments/fm_worker_b_round3_00152598_v01.verification.json
```

## Tools added

| file | purpose |
|---|---|
| `batch1.targets.json` | the eight ranges with per-range sha256, recomputed from the disc |
| `r3_dump_orig.py` | verifies the ELF + range hashes, writes `<addr>.orig.hex`, range lists and the pinned disassembly (`--disasm`) |
| `r3_dis.py` | decodes a verification row's target and compiled words side by side; reverses each 4-byte group because both `target_hex` and `compiled_hex` are stored byte-reversed |
| `claim.json` | ownership, selection rationale, and the `round3_result` block |

Note for future work: the probe harness's generated linker script only defines `func_<8hex>` and
`D_<8hex>`. A probe that declares any other `extern` name (e.g. `func_00100338_helper`) fails to
link — call an existing `func_XXXX` symbol instead, or pin an address with an inline `asm`
absolute definition as in `fm_worker_b_round3_001c8a90_v02.cpp`.

## Boundaries respected

No full build, no docker restart, no Ghidra mutation, no executable-byte patching, no edit to
`functions.tsv`, `layout.tsv`, `main.jsonl`, `compiler-range-verification.json`, `src/anon`, any
manifest or `HANDOFF.md`. All probe scratch directories are named `fm_worker_b_round3_*`; round-1
and round-2 evidence is untouched.
