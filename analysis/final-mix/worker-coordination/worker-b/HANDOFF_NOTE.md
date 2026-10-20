# Handoff note — KH2FM initializer batch (worker-b)

For: the primary worker / integrator.
From: worker-b. Written at the end of the initializer batch.

**Status: 4 of 8 claimed addresses recovered byte-exact. The other four are
stuck for a reason that is worth knowing before anyone re-runs the search.**

---

## Delivered

`analysis/final-mix/recovery-experiments/fm_worker_b_initializers_recovered.cpp`
sha256 `9211fc593534d9c8c9f2d0d81497770de34188116c007158b5b97a305e0f4203`

Re-probes clean against the current `tools/kh2-reference` files:

```
$ python3 tools/kh2-audit/probe_fm_source.py \
    analysis/final-mix/recovery-experiments/fm_worker_b_initializers_recovered.cpp
Exact probe matches: 4/4
00161410 MATCH
001995f8 MATCH
001ba060 MATCH
001c8e00 MATCH
```

**Not registered.** `functions.tsv`, `layout.tsv`, the build inputs, the
manifests and `HANDOFF.md` are shared outputs and were deliberately left
untouched. No full build was run. Integration requires adding
`00161410`, `001995f8`, `001ba060`, `001c8e00` and re-running the full build
plus `verify_fm_oct7_clamp_checkpoint.py`.

## Two structural findings (reusable beyond this batch)

These unlocked 4 of the 8 on their own, and should apply to any other
guarded-initializer function:

1. **Flat, barrier-free guards.** The archived draft nested each store block
   inside `if (priority == 0xffffu) { if (phase == 1) … }` and separated blocks
   with `asm volatile("" : "+r"(phase), "+r"(priority));`. The original has one
   independent `if (priority == 0xffffu && phase == 1) { … }` per store block:
   it re-materialises `li $t7,0xffff` and re-tests **both** arguments in front
   of every block, and each inter-block branch skips the next block's
   `li $t7,0xffff` and lands on its `bne`. Removing the nesting and the
   barriers is most of the work.
2. **Register-materialised addresses.** An address the original keeps in a
   register (`lui $r,hi; addiu $r,$r,lo; op 0($r)`) must be spelled with a
   `register T* p asm("$nn")` local plus `asm("" : "+r"(p));`, otherwise GCC
   folds it to `op lo($r)` and uses two registers. Which of `$t6`/`$t7` gets
   the page can also depend on statement order.

## Not delivered — 00104210, 001c7ab8, 001d6850, 00241f20

All four are **semantically correct** reconstructions: right instruction
count, right constants, right branch edges, same data flow as the original.
What is missing is a codegen decision that GCC 3.2 did not reproduce, in each
case somewhere C source cannot reach directly.

| Address | Residual | Words off | Closest variant |
|---|---|---|---|
| 001c7ab8 | `li $t7,0xffff` / `sd $ra` swapped inside the prologue; probe fills a `nop` delay slot with `lui $a0` | 7 | `variants7/u_top_nopost_none_1c7ab8` |
| 001d6850 | target allocates the address pair **base-high/index-low**; `ee-g++ 3.2` emits base-low/index-high for that shape | 14 | `variants5/z01_1d6850_fsv` |
| 00241f20 | target holds both loaded globals in `$t2`/`$t3` (long live ranges); probe serialises them through `$t6` | 10 | `variants9/a_bar3567_241f20` |
| 00104210 | prologue scheduling (`slt`/`move`/`li` reordered, `slti` hoisted) | 15 | `variants7/w_a_104210` |

507 variant sources were probed and ranked. Treat the source-shape search as
exhausted. **If you want these four, the lever is the toolchain hypothesis, not
more variants** — `00241f20`'s target pair is base-low and the probe reproduces
it exactly, while `001d6850`'s is base-high and nothing moves it, which means
the two differ in a property of the RTL that no C-level spelling reached. The
retail build may have used different `-O2` scheduling parameters or a
non-default `-mips` configuration; that single answer would plausibly explain
all four.

## Blocker for the primary worker

`tools/kh2-audit/verify_fm_oct7_clamp_checkpoint.py` fails at line 64:

```
  File "tools/kh2-audit/verify_fm_oct7_clamp_checkpoint.py", line 64
  assert summary['unmodified_compiled_symbol_matches'] == prior['active_exact_matches'] + len(selected)
AssertionError
```

It passed at claim time (`October7 checkpoint PASS: +6 exact functions, 5303
total, 1860 inputs.`). The shared outputs moved under this batch:

| File | Hash at claim | Hash now |
|---|---|---|
| `tools/kh2-reference/SLPM_666.75` | `d869ce4b…8bc87` | `d869ce4b…8bc87` (unchanged) |
| `tools/kh2-reference/functions.tsv` | `e9136d82…0597b` | `4ef6d0d6…c848` |
| `tools/kh2-reference/layout.tsv` | `b384f076…f2bf` | `60803af0…7f1c` |

worker-b wrote nothing outside `worker-coordination/worker-b/` and
`recovery-experiments/fm_worker_b_*`, and ran no full build. Re-establish the
checkpoint before integrating.

## Tooling worth keeping

Under `analysis/final-mix/worker-coordination/worker-b/`:

- `score.py <dir> [address] [limit]` — ranks every probed variant by how many
  words differ from the target. Reads only the harness's `.verification.json`
  files, so it needs no compiler and no WSL and runs sub-second over 500
  variants. This is the fast loop; use it before reading any diff.
- `worddiff.py <proof.json> <address>` — aligned per-word target-vs-compiled
  table, which is where the diagnoses above come from.
- `dis_probe.sh <stem> <start> <end>` — disassembly of a compiled probe range.
- `gen_variants*.py` + `probe_dir.sh` — generate and probe a variant grid.

Two gotchas that cost time: `probe_dir.sh` must be given an **absolute**
directory (`probe_fm_source.py` asserts `source.is_relative_to(WORKSPACE)`), and
helper declarations need `extern "C"` because the harness only stubs
`func_<addr>` symbols.

Full write-up, including the per-address disassemblies and the rejected levers:
`analysis/final-mix/worker-coordination/worker-b/REPORT.md`.