# Worker B — Round 12 report

**Role:** isolated proposals/reports only. Primary retains active sources, `functions.tsv`, `layout.tsv`, stage sync, full builds, manifests, receipts, Ghidra, `HANDOFF.md`.
**Original ELF:** `Public/tools/kh2-reference/SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
**Selection:** `round-12/pick_targets.py` deliberately restricted the batch to **52-byte framed bodies with no branch** (`round-12/candidates.txt`, screening output 5512 registered rows, 11383 layout ranges, 11398 pseudocode records, **1133 candidates**). That shape is the most reproducible on this compiler: one or two calls, a frame, an epilogue.
**Verification:** all 12 claimed ranges re-read from the original ELF and cross-checked against `/root/kh2fm-build/layout.tsv` (`round-12/r12_dump_orig.py`, output `r12_range_hashes.txt`) — 12/12 range-hash OK and layout OK. Every source compiled through the shared harness `Public/tools/kh2-audit/probe_fm_source.py <src> --summary`.

## Result: 4 / 12 byte-exact

| address | bytes | source sha256 | variant | status |
|---|---|---|---|---|
| 0023fb90 | 52/52 | `10b5af026051f3b3a35be414941ab4e07d6c5ab3b4598c79941b6afa98f77a82` | v01 | EXACT |
| 00242368 | 52/52 | `6d9706dd63ffa764ce163c9473e65e589aec70a59998111e6adb1cb4f4db817d` | v01 | EXACT |
| 00293f78 | 52/52 | `92fecc6c41f1c4712ff0cff6f55c5522c6858d26abb8652d5e3b57ce866560cd` | v01 | EXACT |
| 001721d8 | 52/52 | `67f6f408d3ada191bd23be8a173611e7fdf33fe38dc60ac2216a7383ee47616a` | v02 | EXACT |

All four proofs are `recovery-experiments/fm_worker_b_round12_<addr>_solved.verification.json` with `exact_match: true` and `boundary_agreement: true`.

## Mechanisms

**Guard + two-argument global dispatcher (0023fb90 / 00242368 / 00293f78, v01, 52/52).**
```c
typedef void (*code)(u32,u32);
void func_X(u32 param_1) {
  if (param_1 != 0) { (*(code *)(*(u32 *)DAT_0036ebe0 + 4))(DAT_0036ebe0, param_1); }
}
```
The machine form is `bnel zero,+7` with `move a1,a0` in the delay slot; the C `if` plus a two-argument call reproduces it exactly. `DAT_0036ebe0` is **declared** as `0x36ebe0` (one page above its true address `0x35ebe0`) per the no-carry global convention — Ghidra's own address is wrong for this pair.

**Three-level chain with four named temps (001721d8, v02, 52/52).**
```c
(*(code *)(*(u32 *)iVar4 + 8))(iVar4, iVar3, iVar2);
asm volatile ("");
```
Four `u32` locals are needed to stop GCC from folding the address chain; the call forwards the three live chain values, and the trailing empty asm blocks the sibling-call rewrite.

## Unresolved, with the measured blocker

| address | best | measured difference | why |
|---|---|---|---|
| 001668f8 | v02 | 52/52, 2 words | target `sh zero,10(s0); sb t7,14(s0); sh zero,12(s0)` — one `li t7,1` then three stores of **zero**; the byte store is the odd one out and GCC reorders it. Ghidra's `0/1/0` reading matches the target, but the compiled schedule does not |
| 00166930 | v02 | 52/52, 2 words | byte-identical twin of 001668f8 |
| 001682b8 | v02 | 48/52 | target returns `$s0` with no store to `s0`; the four-byte gap is unresolved |
| 0016c7a0 | v07 | 60/52, 11 words | `jalr $v0` class (round-11 001de948 family) |
| 00288be8 | v07 | 60/52, 11 words | same |
| 0028cc08 | v07 | 60/52, 11 words | same |
| 001d2210 | v03 | 52/52 | target keeps `ld ra,0(sp)` in the `beqz` **delay slot**; GCC always emits the prologue store first (same class as round-9 00307f40) |
| 00308650 | v02 | 52/52, 16 words | two calls with `a0=5` then `sw a1,0x60d8` where `a1` comes from a load at `0x1e87d4`; the call-result plumbing does not match |

## Note on the picker
Round 12's no-branch restriction paid off: 4/12 (33%) versus 2/10 (20%) in round 6, which spent five of its ten slots on frameless sibling-call thunks that GCC 3.2 always frames. The no-branch restriction also avoids the delay-slot-filler classes (00307f40, 001d2210 above are the only two survivors and both fail on exactly that).