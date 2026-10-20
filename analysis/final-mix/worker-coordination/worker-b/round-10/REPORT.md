# Worker B — Round 10 report

**Result: 4 / 12 exact.** All twelve target ranges verified against the original ELF
(`sha256 d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`) and
`/root/kh2fm-build/layout.tsv` before any edit; evidence in `r10_range_hashes.txt`,
`r10_orig_disasm.txt`.

## Exact (4)

| address | bytes | mechanism |
|---|---|---|
| 003068d8 | 40/40 | Four parameters, so the forwarded object reaches `$a3`: `func_00305650(param_4); asm volatile("sync"); asm volatile("ei"); return 0;`. Bare intrinsics land exactly where Ghidra shows them. |
| 0018f858 | 48/48 | `u32 uVar1 = func_001a4550(*param_1, param_1[1]); *param_1 = uVar1;` — reusing the parameter as the store base reproduces the target's two loads off `s0`. |
| 001b81e8 | 48/48 | `func_001b7f88(); DAT_003511c1 = 1; return PTR_003511b8;` — the byte store needs a `u8` global; both symbols sit at their true `0x35…` addresses. |
| 002f1898 | 44/44 | Same shape, with the symbol re-derived **from the raw word**: target `lui 0x1e3` / `lw 0xc0d0` means `DAT_01e3c190 = 0x1e3c0d0`, not Ghidra's `0x1e2c0d0`. |

Proofs: `analysis/final-mix/recovery-experiments/fm_worker_b_round10_<addr>_solved.verification.json`
(`exact_match: true`, `boundary_agreement: true`).

### Tooling correction worth keeping
`ee-objdump` prints `lw a0,-16176(t7)` for 002f1898 while the encoded word is `8de4c0d0`
(offset `0xc0d0` = −16192). **Symbols must be derived from the raw `.orig.hex` words, not from
the disassembly text.**

## Open (8)

- **002b81ec / 002b8214** (byte-identical) — 20/40. Target uses the s8 leaf frame-pointer idiom
  (`sd s8; move s8,sp; … ; move sp,s8; ld s8`). GCC 3.2 never emits it from C. The same class
  blocked round-7's 002b99a0 and round-8's 002b6ab8, so the original build used
  `-fno-omit-frame-pointer` for some translation units — a build-wide difference, not a source bug.
- **0030ec28** — 40/40 with 3 differing words at best (v02 regressed to 48/40). The target keeps
  `lui v1,0x1; and v0,v0,v1; sltu v0,zero,v0` as an explicit mask test; GCC 3.2 strength-reduces
  the constant into a `dsll`/`andi` bit test.
- **00315418** — 28/40. The target keeps an unreachable `jal 0x3166f0` behind a plain branch;
  GCC deletes provably dead calls.
- **003155c0** — 44/40. The target builds the constant with `lui`+`ori` (0x3785f8) where GCC
  wants `addiu`; marking the trailing callee `noreturn` did not help.
- **0016fb00 / 001dc488** — Ghidra's `(**(code**)*DAT)` hides one vtable level; corrected in v02
  to `*(code *)(*(u32 *)DAT + off)`.
- **001231f8** — arguments passed in `$9/$10/$11` (t1/t2/t3), which are not an O32 argument
  register set. Not expressible in C.