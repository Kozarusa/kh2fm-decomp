# Worker B — Round 8 report

**Claim:** `round-8/claim.json` (12 addresses), verified against
`Public/tools/kh2-reference/SLPM_666.75` sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
Every claimed range was dumped with `round-8/r8_dump_orig.py --disasm`; **12/12 range hashes and
`/root/kh2fm-build/layout.tsv` start/end/size checks passed**.

**Result: 8 / 12 byte-exact.** All seven have a `_solved.cpp` in
`analysis/final-mix/recovery-experiments/` plus its own `probe_fm_source.py` proof with
`exact_match: true` and `boundary_agreement: true`.

| address | bytes | source sha256 | mechanism |
|---|---|---|---|
| 00196300 | 40/40 | `ae9b30b6…` | `DAT_01c61b04 = func_001b1448(PTR_00350334);` |
| 001d9d00 | 40/40 | `60a76939…` | same shape; store encoded `lui 0x1d6 / sw -17752` ⇒ symbol declared at `0x1d6baa8` |
| 001b92d0 | 40/40 | `7799bfbd…` | two calls, second takes a global, trailing `asm volatile("")` keeps the second call a real `jal` |
| 0019fd88 | 36/36 | `e3fdb75e…` | 3-arg function-pointer typedef + literal third arg ⇒ `move a2,zero` in the delay slot |
| 002ead20 | 36/36 | `7158da44…` | same with delay-slot constant 43 |
| 00185a98 | 40/40 | `401887ff…` | first dereference assigned back into the parameter (pins result to `$a0`) |
| 002ecdb0 | 36/36 | `7aca903e…` | function-pointer-typed local + trailing empty asm ⇒ two distinct temp registers |

## Reusable mechanisms established this round

1. **Vtable dispatch, second argument forwarded.** `0019fd88`/`002ead20` only matched once the
   dispatch target was given a three-parameter type and the third argument written literally
   (`(*(code *)(*(u32 *)param_1 + 0x24))(param_1, param_2, 0)`); a one-parameter typedef puts the
   constant in `$a1` instead of the target's `$a2` delay slot.
2. **Reassignment into the parameter.** `param_1 = *(u32 *)(param_1 + 0x9f4);` makes GCC allocate
   the loaded pointer to `$a0`, which is what the targets' two-level vtable loads require.
   This single change fixed `00185a98` and the round-9 `003197f8`/`0031f940` family.
3. **Function-pointer-typed local.** `code pc; pc = *(code *)(x + off); pc(param_1); asm volatile("");`
   reproduces the target's *two-distinct-temp* vtable load where `code *pc` folds into one temporary.
4. **Trailing `asm volatile("")`.** Still the reliable way to block sibling-call rewriting
   (confirmed again on `001b92d0` and `002ecdb0`).

## Left open (documented, not guessed)

* **00305ce0 / 00305e20** (byte-identical to each other and to round 9's 00305e48, sha256
  `dce01ef1…`): v04 is now **40/40 with only 2 differing words** — writing the constant in a separate
  statement before the store (`iVar2 = 5; *func_00316d08() = iVar2;`) fixed the store base, leaving only
  `li t7,5` against `li v1,5` and `sw t7,0(t6)` against `sw v1,0(v0)`. v05 combines that with the
  single-expression store to try to get the constant live across the call.
* **00173270**: 40/40, 5 differing words — the target reloads `lw a0,0(a0)` mid-chain and keeps two
  live pointers in `$t6`/`$t7`; GCC folds the second load into the first temporary.
* **002b6ab8**: 20/36 — the leaf frame-pointer idiom (`sd s8,0(sp); move s8,sp; … move sp,s8; ld s8`)
  is not emitted by GCC 3.2 for a frameless leaf; `__builtin_alloca(0)` and forcing a stack slot
  through a `volatile` local both failed.

## Notes for primary

* The no-carry global convention keeps paying: target `lui H / off L` ⇒ declare the symbol as
  `(H<<16) | (L & 0xffff)`, which for `001d9d00` is one page above the true address.
* The probe harness auto-defines every `func_<8 hex digits>` occurrence, so external callee names must
  be exactly that shape; `DAT_*`/`PTR_*` globals still need an explicit `asm(".globl …")` block.
* Worker B used the shared harness read-only; no stage writes, no flag changes, no docker restart.
