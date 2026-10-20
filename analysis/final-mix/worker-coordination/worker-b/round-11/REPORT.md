# Worker B — Round 11 report

**Role:** isolated proposals/reports only. Primary retains active sources, `functions.tsv`, `layout.tsv`, stage sync, full builds, manifests, receipts, Ghidra, `HANDOFF.md`.
**Original ELF:** `Public/tools/kh2-reference/SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
**Verification method:** every claimed range re-read from the original ELF and cross-checked against `/root/kh2fm-build/layout.tsv` (`round-11/r11_dump_orig.py`, output `r11_range_hashes.txt`); every source compiled through the shared harness `Public/tools/kh2-audit/probe_fm_source.py <src> --summary`.
**Claimed:** 16 ranges, all 16 range-hash OK and layout OK.

## Result: 6 / 16 byte-exact

| address | bytes | source sha256 | variant | status |
|---|---|---|---|---|
| 002f0798 | 48/48 | `3093881c6ed182778bb1ac31c364be3b93fc30d6d63a3b0c5bcab992be68612c` | v01 | EXACT |
| 002f07c8 | 48/48 | `7e79b287a39f3acb85fc2c2fce506addbbfaed865725c1379262704602c54301` | v01 | EXACT |
| 001dc4b8 | 48/48 | `476729e3ace8bae750df1f2b23e5371e2a2753d85841038a4b7aef6476445b88` | v02 | EXACT |
| 001de978 | 48/48 | `86df1bffb910dc5264ddd3dc1647226efed574d8f19c58cdb75b49e9324a183f` | v02 | EXACT |
| 001e0158 | 48/48 | `8008885144960e6ce1fb28dcd4aac788e19af8a31664047d03691376eeefd9d9` | v02 | EXACT |
| 001e01b8 | 48/48 | `b50db156629361dbfa7cfc0b68af67d67efadca7946a3159e7591e078c5bb8fe` | v02 | EXACT |

All ten proofs are `recovery-experiments/fm_worker_b_round11_<addr>_solved.verification.json` with `exact_match: true` and `boundary_agreement: true`.

## Two reusable mechanisms found this round

**1. Three-level dispatch through a call result (002f0798 / 002f07c8, v01, 48/48).**
```c
typedef void (*code)(u32);
u32 iVar1 = *(u32 *)param_1;
u32 iVar2 = func_0010c7e8(*(u32 *)(iVar1 + 4));
code pcVar2 = *(code *)(*(u32 *)iVar2 + 0x28);
pcVar2(iVar2);
asm volatile ("");
```
The object that the entry is loaded from must be a **call return value**, so it stays in `$v0` and the final `jalr` targets `$v0`; a function-pointer-typed local plus a trailing empty asm keeps the two distinct temp registers.

**2. Two-argument global dispatcher (v02 winners: 001dc4b8, 001de978, 001e0158, 001e01b8, 48/48).**
```c
typedef void (*code)(u32,u32);
void func_X(u32 param_1) { (*(code *)(*(u32 *)DAT + 4))(DAT, param_1); asm volatile (""); }
```
The **two-arg** call is what matches. The same source with a third argument compiles to a different word count and does not match — the argument arity directly determines the delay-slot scheduling.

## Unresolved, with the measured blocker

| address | best | measured difference | why |
|---|---|---|---|
| 001de948 | v07 | 56/48 | `jalr $v0` class (see below) |
| 001e0128 | v07 | 56/48 | same |
| 001e0188 | v07 | 56/48 | same |
| 001050d8 | v07 | 60/52 | same, `move a2,ra` via `__builtin_return_address(0)` |
| 0016fac8 | v07 | 60/52 | same, `move a2,ra` |
| 00171810 | v01 | 52/52, 9 words | frame/schedule mismatch, not isolated to a register class |
| 0018f218 | v01 | 48/48, 2 words | target `lw a0,4(t7)` + `lw t6,0(a0)`; compiled folds the offset into the base (`lw t6,4(t7)` + `addiu a0,t7,4`) |
| 001e6250 | v01 | 48/48, 2 words | target materialises `addiu t5,t7,18064` as a separate address before `sw zero,18064(t7)`; GCC keeps the offset in the store |
| 002bef78 | v01 | 48/48, 9 words | target frame is `addiu sp,-48`, v01 produces `-32` |
| 0030a2d0 | v01 | 44/44, 2 words | scratch register only: target `lui v0,0x36`, compiled `lui t7,0x36` (same class as round-7 00308cd0) |

### The `jalr $v0` class — not expressible in C on this compiler
Targets load the vtable entry into `$v0` (`lw t7,0(a0); lw v0,0(t7); jalr v0`). GCC 3.2 always chooses `$t6` then `$t7` (`lw t6,0(a0); lw t7,0(t6); jalr t7`). Round 11's byte-exact **001dc4b8** proves this is the compiler's only choice for the identical source shape. Six variants per target were tried — inline double deref, function-pointer-typed local with a memory barrier, two named intermediates, triple-inline deref, intermediate plus inline call, and a triple-temp copy — each combined with `__builtin_return_address(0)` for the `move a2,ra` members. None reached it; the register-pin escape hatch (`register … asm("$t7")`) is rejected outright by this compiler (`invalid register name '$t7' for register variable`). Recorded as a compiler-level blocker, not a source-search failure.