# Worker B — round 5 report

**Round:** 5 (2026-10-08)
**Assignment:** `round-5/INSTRUCTIONS.md` / `assignment.json` (sha256 `cd49cab66f4333ca20257e56591866180388c83a49714f2f8fa1f35d559918cf`)
**Result:** **5 / 5 assigned ranges recovered as byte-exact, equal-size matches.**

| priority | address | range | bytes | source | sha256 |
|---|---|---|---|---|---|
| 1 | `00109e30` | 92 B | 92/92 | `fm_worker_b_round5_00109e30_solved.cpp` (v72) | `c183e71c2ad724f8f8fcbe1b92b4ab2ea7ec0a0b4e29bb0e3f3dfb4f29e97d7a` |
| 2 | `0014b950` | 88 B | 88/88 | `fm_worker_b_round5_0014b950_solved.cpp` (v44) | `84d356aad202f7da5842345b956f6f75bc18795ac9cb7b8f7d4a908859dada1e` |
| 3 | `001e7230` | 104 B | 104/104 | `fm_worker_b_round5_001e7230_solved.cpp` (v12) | `ef84402491861a9cd5a604e03f2a06db3b70d340fcfba089171a6cd495c8afa0` |
| 4 | `001ac310` | 104 B | 104/104 | `fm_worker_b_round5_001ac310_solved.cpp` (v11) | `beefabea48e109c5879ce59da4c7f3d954764bea1caf581d1efd025423a5f3fc` |
| 5 | `00242500` | 92 B | 92/92 | `fm_worker_b_round5_00242500_solved.cpp` (v23) | `fc97a5b80fd28242f09797e4a84af1642aee8fd9ec216523bb35987c34780863` |

Each solved source was re-probed from its own `_solved.cpp` file; the proof files
`recovery-experiments/fm_worker_b_round5_<address>_solved.cpp.verification.json` all report
`exact_match: true`, `boundary_agreement: true`, `compiled_size == target_size`.

## Evidence chain

1. **Original-range binding.** `r5_dump_orig.py` recomputed sha256 over each declared byte
   range of `AGENTS/Public/tools/kh2-reference/SLPM_666.75`
   (ELF sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`) and
   cross-checked start/end/size against `/root/kh2fm-build/layout.tsv`: **5/5 OK**
   (`r5_range_hashes.txt`, `r5_orig_disasm.txt`, `<address>.orig.hex`).
2. **Authoritative target bytes.** Pinned `ee-objdump` 3.2-ee-040921 inside
   `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`. Note the ELF stores R5900 words
   little-endian while `ee-objdump` prints big-endian, so raw `.orig.hex` groups are decoded
   byte-reversed (`r5_dis.py <hex> <addr> rev`).
3. **Compilation.** `AGENTS/Public/tools/kh2-audit/probe_fm_source.py <src> --summary`, driven
   by `r5_probe.sh`; byte comparison by `r5_cmp.py`.
4. **Round-four carry-in.** Each round-four best was re-measured first so the delta attributable
   to round five is known (see `claim.json → prior_evidence_reused`).

## Per-target mechanism (the non-obvious part)

### 00109e30 — `u8` parameter + one `nop` statement
Round four had 88/92: the mask and branch were right, but GCC 3.2 pulled `sd ra,8(sp)` into the
`beqz` delay slot, costing one word. Two independent constraints had to be satisfied at once:

* the `andi a0,a0,0xff` must be hoisted **above** both prologue stores, and
* the delay slot must stay a `nop`.

An empty `asm volatile ("" ::: "memory")` achieves (2) but blocks the hoist (the `andi` then
lands after the stores — 92/92 with 3 words differing). A single `asm volatile ("nop");`
statement achieves **both**: the emitted `nop` is absorbed into the delay slot and the mask is
freely hoisted. `u8` (not `s8`, not `u32`) gives the `andi`; an `s8` parameter makes GCC
sign-extend with `sll/sra 24` instead.

### 0014b950 — permutation search over a commutative OR
The four value terms are OR-ed together, so the only free variable is the **source order**. All
24 orderings were generated as v21–v44; permutation `D,C,B,A` (param_2, param_2-term<<0x10,
param_3<<0x20, param_3-term<<0x30) is the only one that reproduces the target's `dsll32`/`dsra32`
schedule and its two crossed accumulators (`or a2,a2,a3` / `or a1,a1,t0` / `or a1,a1,a2`).
Neighbouring permutations v23 (3 words) and v24/v26 (4 words) show the schedule is schedule-
sensitive, not just size-sensitive.

### 001e7230 — one reused counter
The target keeps both loops' counters in `$t6`. Reusing a single `s32` local for both loops (and
testing the second with `!= -1` as well) is sufficient; splitting into two locals, or `register …
asm("$t6")` pinning, and the Ghidra-faithful `param_2 = param_2 & 3` reassignment all land the
counter in `$a5` and mismatch.

### 001ac310 — Ghidra-style base plus `[1]`/`[2]` load order
Stores must be written through `puVar1 = param_1 + 3` at indices `0x52`/`0x53` (Ghidra's
`param_1[0x55]`/`[0x56]`), and the loads must appear in source order `[1]` then `[2]`. That
combination makes GCC emit `lw t6,8(s0)` before `lw t7,4(s0)` (target order) while still storing
through `s1` at `0x148`/`0x14c`. Writing the stores directly as `param_1[0x55] = param_1[1]`
gets the offsets right but reverses the load order.

### 00242500 — two statements instead of one expression
The store-then-call-then-load tail (`*(int *)(uVar1 + 0x2440) = iVar1; uVar1 = func_001058e8(); return *(int *)(uVar1 + 0x2440);`)
lets GCC keep `v0` live across the last call so `sw t7,0x2440(v0)` occupies that `jal`'s delay slot, and the
`999999` constant is materialised in the other arm's delay slot. The last obstacle was register allocation: with
`iVar1 = *(int *)(uVar1 + 0x2440) + param_1;` as a single expression GCC puts the accumulator in `$a0`, and the
target uses `$t7`. Writing the accumulation as two statements

```c
iVar1 = *(int *)(uVar1 + 0x2440);
iVar1 = iVar1 + param_1;
```

moves it to `$t7` and the function becomes byte-exact. Register pinning is not available on this compiler:
`register s32 iVar1 asm("$t7")`, `asm("t7")`, `asm("7")` and `asm("$7")` are all rejected with
`invalid register name ... for register variable`, so the fix had to come from the source shape.
Pointer-typed callees (`u8 *`/`char *` returns), a `u32` accumulator, swapped arms, hex constant and
`s32` return type were all tried first and all stayed at 4 differing words.

## Search volume

~72 isolated candidate sources were compiled for this round in five probe batches
(v21–v44 permutation sweep, v25–v40 spelling sweep, v41–v64 barrier sweep, v65–v72 nop-asm sweep).
Every batch was preceded by a re-read of the primary-owned `compiler-status.json`; probes are
short single-file compiles into per-source scratch directories.

## Boundaries observed

* Only files under `analysis/final-mix/recovery-experiments/` (worker-B proposals) and
  `analysis/final-mix/worker-coordination/worker-b/**` were written.
* No primary-owned artefact was modified: active sources, `functions.tsv`, `layout.tsv`, stage
  sync, full builds, manifests, receipts, Ghidra, checkpoints, `HANDOFF.md`.
* No docker restart, no compiler-flag change, no executable byte patching, no stage input writes.
* Round-four winners (`00150de0`, `001576e8`, `0017dec0`, `00229d40`, `002e8290`) were read-only
  inputs and were not modified or renamed.

## Unresolved

None of the five assigned targets remains open.

## Next step

`pick_targets.py` (round-5 copy, attempted/reserved sets extended with every worker-B round 1–5
address and primary's 21 claimed addresses) selects disjoint unregistered fallback ranges; the
round-six claim records them. Primary's registration had reached 5,504 rows when this round
closed.