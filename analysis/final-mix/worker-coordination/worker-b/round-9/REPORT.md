# Worker B — Round 9 report

**Result: 4 / 12 exact.** All twelve target ranges were verified against the original ELF
(`sha256 d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`) and against
`/root/kh2fm-build/layout.tsv` before any edit; evidence in `r9_range_hashes.txt` and `r9_orig_disasm.txt`.
Every exact match was re-proved from its promoted `_solved.cpp` (not from the winning experiment file).

## Exact (4)

| address | bytes | mechanism |
|---|---|---|
| 0023fb28 | 44/44 | `func_0023fc08(); DAT_0036ebe0 = 0; DAT_0036ebec = 0;` — the no-carry global convention: `lui 0x36 / sw -5152` means declare `0x36ebe0`. |
| 00180770 | 44/44 | `puVar1 = func_00180698(); (*(code *)(*(u32 *)puVar1 + 0x1c))(puVar1);` — the object arrives in `$v0` from the call, so no second temp register is needed. |
| 003197f8 | 40/40 | `param_1 = *(u32 *)(param_1 + 4);` then `(*(code *)(iVar1 + 4))(param_1);` — writing the reload back into the parameter pins the result to `$a0`. |
| 0031f940 | 40/40 | same recipe, slot `0x18` and entry offset `0x10`. |

Proofs: `analysis/final-mix/recovery-experiments/fm_worker_b_round9_<addr>_solved.verification.json`
(all `exact_match: true`, `boundary_agreement: true`).

## Open (8), each with its measured blocker

- **00305e48** — byte-identical body to round-8's 00305ce0/00305e20. Best is 40/40 with 2 words
  differing (`li t7,5` / `sw t7,0(t6)` against `li v1,5` / `sw v1,0(v0)`). GCC copies the call
  result out of `$v0` into a temp before storing and materialises the literal in `$t7`; every
  C spelling tried keeps both properties.
- **00185a68** — 48/44 (v02) then 52/44 (v04/v05). The four-argument forward makes GCC emit
  three late `move`s. Target forwards `this` in `$a3` plus three more arguments.
- **00171348 / 00171378 / 00171e58** — 44/44 with 2 differing words. Only the base register of
  the second-level load differs (target `$t6`, GCC `$t7`). Register pins
  (`register … asm("$t6")`) are unavailable on this compiler (round 5).
- **002ba3b8** — 48/44. The target passes arguments in `$9/$10/$11`, which are not an O32
  argument register set; not expressible in C.
- **002ef340** — 28/44. The target's `sd a1,0(sp)` / `sw a2,16(sp)` spills are never reloaded,
  so GCC elides them entirely.
- **00307f40** — 40/40 with 3 differing words. The target keeps `sd ra,0(sp)` in the `beqz`
  delay slot; GCC 3.2 always emits the prologue store before the branch.

## Carried compiler-level lessons

1. `param_1 = *(u32 *)(param_1 + off);` pins a reloaded base to `$a0` (solved 003197f8, 0031f940, and
   round-8's 00185a98).
2. A function-pointer-typed local plus a trailing `asm volatile("")` produces the target's
   two-distinct-temp vtable load (round 8's 002ecdb0/00322968).
3. Globals must be declared as `(hi << 16) | (lo & 0xffff)`; the compiler adds no carry.
4. Derived from the raw `.orig.hex` words, **not** from ee-objdump's printed immediates — the
   printed `lw/sw` displacement disagrees with the encoded word (e.g. 002f1898 in round 10).