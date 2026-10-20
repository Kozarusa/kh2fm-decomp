# Worker B — FM initializer batch: recovery report

Worker: **worker-b**
Claimed addresses: `00104210 00161410 001995f8 001ba060 001c7ab8 001c8e00 001d6850 00241f20`
Workspace: `C:\Users\KoZa\Documents\ChatGPT`
Isolation: worker-b owned everything under this directory plus
`analysis/final-mix/recovery-experiments/fm_worker_b_*. No shared output was
modified (`functions.tsv`, `layout.tsv`, `src/anon`, manifests, `HANDOFF.md` were
read only), and the full project build was **not** run — see *Pending* below.

---

## 1. Result summary

| Address | Bytes | Status | Recovered source |
|---|---|---|---|
| 00161410 | 120 | **byte-exact** | `recovery-experiments/fm_worker_b_initializers_recovered.cpp` |
| 001995f8 | 112 | **byte-exact** | same file |
| 001ba060 | 152 | **byte-exact** | same file |
| 001c8e00 | 96 | **byte-exact** | same file |
| 001c7ab8 | 144 | single-cause residual (§4.2) | `variants4/y03_1c7ab8_regptr.cpp` |
| 001d6850 | 112 | single-cause residual (§4.3) | `variants5/z01_1d6850_fsv.cpp` |
| 00241f20 | 88 | single-cause residual (§4.4) | `variants8/z_bar0123_241f20.cpp` |
| 00104210 | 104 | two-cause residual (§4.5) | `variants7/w_a_104210.cpp` |

Verification (compiler gate, complete declared ranges, pinned toolchain):

```
$ python3 tools/kh2-audit/probe_fm_source.py \
    analysis/final-mix/recovery-experiments/fm_worker_b_initializers_recovered.cpp
Exact probe matches: 4/4
00161410 MATCH
001995f8 MATCH
001ba060 MATCH
001c8e00 MATCH
```

Re-verified at the end of this batch (still 4/4 against the current
`tools/kh2-reference` files).

No whole-game completion percentage is claimed; this report covers only the eight
claimed addresses.

## 2. Artifacts

| Path | SHA256 |
|---|---|
| `recovery-experiments/fm_worker_b_initializers_recovered.cpp` | `9211fc593534d9c8c9f2d0d81497770de34188116c007158b5b97a305e0f4203` |
| `recovery-experiments/fm_worker_b_initializers_recovered.verification.json` | `c251c5d003805c6c419c2b38dea297aff00c8054cf88f64d882898a38a035c1f` |
| `recovery-experiments/fm_worker_b_initializers_recovered.probe.log` | `7af6837c0c9429c3d79654a8ed4bf4eb84dee37e0d97914eeebe0676e67d6e5a` |
| `recovery-experiments/fm_worker_b_initializers_recovered.curation.json` | `8de9e3b2c289eeeef71362c7fadc9c1a5f3e2c10100adcb049071fc40ad9e257` |
| `recovery-experiments/fm_worker_b_initializers_v2.cpp` | archived draft, alias-free copy |
| `worker-coordination/worker-b/gen_variants10.py` | `b1c189094119face548a85bad10646cf43fd179f96cac167258104b4b094f681` |
| `worker-coordination/worker-b/gen_variants11.py` | `0e75b04bf31fc85be8e8d4508045af9c6312b265512e17beef85d444bc896a45` |
| `worker-coordination/worker-b/score.py` | `3ff010d6f1f230a227d8d5e039b056d9a125f0c562b36bbbd3ad23c0e63a1bbc` |
| `worker-coordination/worker-b/worddiff.py` | `b5e9a75a5fb8985d81c124d37d63cc61c1b8161477f9d95d2979657bcfe29a25` |

The curated file is the **deliverable**: it is the four exact functions in
dependency-clean form, already probed by the project curator
(`Exact probe matches: 4/4`, recorded in the probe log). The curation record
notes the selected addresses in integration order `001c8e00, 00161410,
001ba060, 001995f8` and the one limitation that still applies: it needs a new
probe, registration and a full build before it counts toward the project's
total.

Baseline hashes at claim time (unchanged by worker-b) are recorded in
`claim.json`: reference `SLPM_666.75`
`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`,
`functions.tsv` `e9136d82…`, `layout.tsv` `b384f076…`, upstream commit
`8b5bc4790ac3fe951ffaf15b6933d186ebab7a43`.

**Checkpoint gate state.** At claim time worker-b re-ran
`python tools/kh2-audit/verify_fm_oct7_clamp_checkpoint.py` and it passed:
`October7 checkpoint PASS: +6 exact functions, 5303 total, 1860 inputs.`
It was re-run again at the end of this batch and now fails:

```
  File "tools/kh2-audit/verify_fm_oct7_clamp_checkpoint.py", line 64
  assert summary['unmodified_compiled_symbol_matches'] == prior['active_exact_matches'] + len(selected)
AssertionError
```

This is **shared-state drift, not a worker-b regression**: the shared outputs
changed under this batch, and worker-b never wrote to them. Comparing the hashes
recorded in `claim.json` with the files on disk now:

| File | Hash at claim | Hash now |
|---|---|---|
| `tools/kh2-reference/SLPM_666.75` | `d869ce4b…8bc87` | `d869ce4b…8bc87` (unchanged) |
| `tools/kh2-reference/functions.tsv` | `e9136d82…0597b` | `4ef6d0d6…c848` |
| `tools/kh2-reference/layout.tsv` | `b384f076…f2bf` | `60803af0…7f1c` |

The failing assertion compares the last full build's symbol-match count against
the recorded prior state in `/root/kh2fm-build`; worker-b ran no full build and
wrote nothing outside its own directory and `recovery-experiments/`. The primary
worker needs to re-establish that checkpoint before integrating §7.

Tooling written for this batch (all advisory, all under this directory):
`gen_variants*.py` + `probe_dir.sh` / `probe_glob.sh` (probe drivers, 507 variant
sources in `variants*/`), `dis_probe.sh` / `objdump_orig.sh` +
`objdump_orig_inner.sh` (original-vs-compiled disassembly), `first_diff.sh` +
`fd_list.sh` + `grep_filter.sh` (aligned instruction diff), `show_diff.py` and
`disasm_r5900.py` (byte-level diff and advisory decoder — the hand decoder proved
unreliable and was superseded by `ee-objdump`).

Two later additions make the search cheap enough to be worth repeating:
`score.py <dir> [address] [limit]` ranks every probed variant by how many words
differ from the target, reading only the `.verification.json` files (no
compiler, no WSL, sub-second over 500 variants), and `worddiff.py <proof.json>
<address>` prints the aligned per-word target-vs-compiled table that the §4
diagnoses below are quoted from. Anyone continuing should generate variants,
`probe_dir.sh` them, and rank with `score.py` rather than reading diffs by eye.

## 3. The two structural findings

These unlock four of the eight and explain most of the residual diffs.

1. **Flat, barrier-free guards.** The archived draft nested each store block
   inside `if (priority == 0xffffu) { if (phase == 1) … }` and separated blocks
   with `asm volatile("" : "+r"(phase), "+r"(priority));`. The original instead
   has one independent `if (priority == 0xffffu && phase == 1) { … }` per store
   block: it re-materialises `li $t7,0xffff` and re-tests **both** arguments in
   front of every block, and each inter-block branch skips the next block's
   `li $t7,0xffff` and lands on its `bne`. Removing the nesting and the barriers
   alone converts three of the four exact matches.

2. **An address the original materialises in a register** (`lui $r,hi; addiu
   $r,$r,lo; op 0($r)`) must be written so GCC keeps a register variable
   (`register T* p asm("$nn"); asm("" : "+r"(p));`), otherwise GCC folds to
   `op lo($r)` and uses two registers. When GCC does allocate an address
   *(page, full)* pair, which of `$t6`/`$t7` receives the page depends on
   statement order — proven on `00161410`, where swapping `.second` before
   `.first` flips the pair and is required for the match.

A third, function-specific finding: `001995f8` needs both a separate `u8* base`
variable *and* a `s32` loop index — the former forces `addiu $t4,$t7,0x20c8;
addiu $t5,$t4,96` instead of a folded offset, the latter produces `slti` rather
than `sltiu`.

## 4. Unmatched addresses — first differing instruction and cause

All four are **semantically equivalent** reconstructions with the correct
instruction count and correct branch targets in most cases; each residual is a
register-allocation or scheduling decision, not a semantic difference.

### 4.1 00104210 (104 bytes, `w_a_104210.cpp`) — two causes
```diff
  1  T: slt  $t7,$zero,$a0        C: move $t6,$a0
  2  T: move $t6,$a0             C: slt  $t7,$zero,$a0
 10  T: li   $t7,2               C: slti $t5,$t6,3
 11  T: beq  $t6,$t7,0x10425c    C: beql $t6,$t7,…
```
(a) `positive` must occupy `$t7` across the `movz`; pinning it with
`register s32 positive asm("$15")` plus `asm("" : "+r"(positive));` still leaves
GCC recomputing it in `$a0`.
(b) the probe hoists `slti $t5,$t6,3` above `li $t7,2` and emits branch-likely
forms (`beql`) where the target uses plain `beq` / `beqzl`; four different
control-flow shapes (`SHAPES a–d` in `gen_variants7.py`) all produce the same
scheduling.

Confirmed semantics: `current = (0 < value) ? 1 : value; D_0032ba84 = current;`
then a three-way dispatch (`2` → tail call with 2, `1` → dead store `1` then
return, `3` → tail call with 3, anything else → tail call with 2). The dead
`li $a0,1` in the target is preserved only while `selected` is a
`register u32 … asm("$4")` local.

### 4.2 001c7ab8 (144 bytes, `y03_1c7ab8_regptr.cpp`) — one cause, two words
```diff
  2  T: li $t7,0xffff        C: bne $a1,$t7,…   (1c7ab8..1c7b44)
  3  T: sd $ra,0(sp)         C: sd $ra,0(sp)
  4  T: bne $a1,$t7,0x1c7b1c C: li $t7,1
```
Everything else — both `lwc1`/`swc1` float copies through a `$15`-pinned source
pointer, the `jal 0x0031b9e0` (not a sibcall), and all three branch edges — is
identical, and the function length is already right. The whole residual is
**two single words**, and `worddiff.py` locates both:

```
+0004  ffff0f34 / 0000bfff   target `li $t7,0xffff` sits where the probe has `sd ra`
+0008  0000bfff / ffff0f34   …and vice versa
+0074..+0084                 the probe fills the third guard's `bne` delay slot
                            with `lui $a0,0x1d5`; the target leaves `nop` there
```

GCC's delay-slot filler moves `sd ra,0($sp)` into the first `bne`'s delay slot
unless something stops it, and independently it fills the last `bne`'s delay
slot with the `lui` that belongs to the `jal` argument setup. Rejected levers,
all probed (36 further variants, `e_*_1c7ab8`): source pin at `$15`/`$13`/none;
memory barrier at top, after block 1, after block 2, before the call and
everywhere; `volatile` float destinations; opaque input operands; a pinned
`$30`. A top memory barrier moves `sd ra` to word 2 (before `li $t7,0xffff`)
instead of word 3. The 7-word best in the whole search is
`e_pin15_top_n_1c7ab8`, which ties `u_top_nopost_none_1c7ab8`.

Conclusion: this needs a compiler-scheduling difference, not a source shape —
no source construct found moves a constant load into the middle of a MIPS
prologue.

### 4.3 001d6850 (112 bytes, `z01_1d6850_fsv.cpp`) — one cause, register numbering
Block 1 matches instruction-for-instruction; only the address pair is reversed:
```diff
  T: lui  $t7,0x1d6 ; sw $zero,-17800($t7) ; addiu $t6,$t7,-17800
  C: lui  $t6,0x1d6 ; sw $zero,-17800($t6) ; addiu $t7,$t6,-17800
```
Block 2 has the same 9-instruction shape with a different schedule: the target
stores `D_01d5ba88.first = 3` through the page *before* materialising the
`D_0036e5f0` address (`lui $t7,0x37; addiu $t7,$t7,-6672; lwc1 $f0,0($t7)`).
Exhaustive levers tried and all rejected: all six field-store permutations
(`t_*_1d6850`), source pointer pinned/unpinned in each block
(`y_*_1d6850`), guard constants pinned to `$12`/`$11` (correct length and
branch targets, wrong pair), plain locals instead of pinned ones.

Two further grids (96 variants, all landing on exactly 14 differing words with
the right size and branch targets) attacked the pair direction from both ends:

* `gen_variants10.py` — 6 field orders × {struct field access, `(u32*)`+index
  access} × {source pinned `$13`, `$15`, none}.
* `gen_variants11.py` — 4 spellings of the destination address that change the
  RTL shape of the `plus` the reload splits (struct fields, `u8*` base with
  `+0/+4/+8`, `(u8*)&x + n`, `u32*` + index) × 3 source pins × 5 placements of
  an extra pinned live value at `$14`/`$12`/`$15`/`$30`/none, to change how many
  hard registers are already allocated when the pair is allocated.

None moved it. The evidence now points past the source: the target allocates
the page/base pseudo *after* the low-half pseudo, while `ee-g++ 3.2-ee-040921`
always emits base-low/index-high for this shape. Note `00241f20`'s target pair
*is* base-low (`lui $t4,0x1db` / `addiu $t5,$t4,-6520`) and the probe reproduces
that one exactly, so the two functions differ in some property of the RTL that
no C-level spelling tried here reaches.

### 4.4 00241f20 (88 bytes, `z_bar0123_241f20.cpp`) — length and store order exact
```diff
  T: lui $t4,0x1db ; addiu $t5,$t4,-6520 ; lw $t2,-5128($t7)
  C: lui $t4,0x1db ; addiu $t4,$t4,-6520 ; lw $t6,-5128($t7)
```
Store order, all six stores, both constants (`li $t6,964`; `lui $t6,0x1` +
`ori $t6,$t6,0xfc0`) and the instruction count already match. Remaining:
(i) the target keeps **two** address registers (`$t4` = page, `$t5` = full) and
stores `D_0035ebf8` as `sw $t2,-6520($t4)` while the probe folds the address into
one register; (ii) the two loaded globals must land in `$t2`/`$t3` (allocated
before the page pseudos) rather than `$t6`/`$t7`. Enumerated without success:
248 barrier-subset variants (`a_bar*`), `volatile u32*` destinations (correct
store order but hoists both loads early), split page/full pointers
(`b_split_241f20`), base pointer pinned to `$11`–`$14`, and hoisted loads.
A final grid (`gen_variants10.py`, 16 variants: each load independently hoisted
to the top of the block or left in place × {plain, `volatile` destination,
barrier chain} × barrier subsets of size 1 and 2) produced nothing better than
12 differing words; the best remains `a_bar3567_241f20` at 10.

### 4.5 Search size, and what the exhaustion means

507 variant sources across `variants*/`, all probed, all ranked by
`score.py`. Four exact, four stuck at a small constant residual:

| Address | Best residual | Differing words (of 36 / 28 / 22 / 26) | Best variant |
|---|---|---|---|
| 001c7ab8 | prologue order + one delay slot | 7 | `variants7/u_top_nopost_none_1c7ab8` |
| 001d6850 | address-pair direction | 14 | `variants5/z01_1d6850_fsv` |
| 00241f20 | live-range/register choice | 10 | `variants9/a_bar3567_241f20` |
| 00104210 | prologue scheduling | 15 | `variants7/w_a_104210` |

Every residual is a codegen decision, not a semantic difference: in all four
cases the reconstructed function has the right instruction count, the right
constants, the right branch edges and the same data flow as the original. What
is missing is the specific order and register choice GCC 3.2 made in the build
that produced the retail disc, in each case in a spot that C source cannot reach
directly (a constant load inside a prologue, a `nop` in a delay slot, the
direction of an address pair, a long live range). Continuing on this batch has a
low expected yield per probe; the productive next step is either accepting the
semantic-equivalent forms for these four, or changing the toolchain question
(e.g. whether the retail build used different `-O2` scheduling parameters or a
non-default `-mips` config) rather than searching more C shapes.

## 5. Reproduction

```bash
export MSYS_NO_PATHCONV=1                      # required before wsl /mnt/c/... paths
WS=/mnt/c/Users/KoZa/Documents/ChatGPT
W=$WS/analysis/final-mix/worker-coordination/worker-b

# 1. the four exact recoveries (compiler gate, ~1.4 s)
wsl -d Ubuntu-24.04 -u root -- bash -lc \
  "python3 $WS/tools/kh2-audit/probe_fm_source.py \
     $WS/analysis/final-mix/recovery-experiments/fm_worker_b_initializers_recovered.cpp"

# 2. regenerate + probe the whole search space, then rank it
wsl -d Ubuntu-24.04 -u root -- bash -lc \
  "for g in 5 6 7 8 9 10 11; do python3 $W/gen_variants\$g.py $W/variants\$g >/dev/null; \
     bash $W/probe_dir.sh $W/variants\$g; done"
python $W/score.py $W/variants11 001d6850

# 3. aligned original-vs-compiled diff for one variant
wsl -d Ubuntu-24.04 -u root -- bash $W/first_diff.sh z_bar0123_241f20 00241f20 00241f7c
python $W/worddiff.py $W/variants8/z_bar0123_241f20.verification.json 00241f20
```

`probe_dir.sh` must be handed an **absolute** directory: `probe_fm_source.py`
asserts `source.is_relative_to(WORKSPACE)`, which fails for a relative path.
Likewise a variant that declares a helper with C++ linkage (`extern void
func_0031b9e0(void*)`) fails to link, because the harness only stubs
`extern "C"` `func_<addr>` names — use `extern "C"`.

Toolchain facts that matter for anyone continuing this:
`ee-g++ (GCC) 3.2-ee-040921`, flags `-O2 -g0 -x c++ -fno-exceptions -fno-rtti
-fpermissive -ffunction-sections`; the FM executable is **little-endian**
(`r5900:LE:32:default`, objdump reports `elf32-littlemips`), so decode with
`int.from_bytes(b,'little')`. `probe_fm_source.py` locates functions by regex on
the **emitted symbol name**, so an isolated probe source must not carry the
`_Z16wtarget_<addr>jjjj` asm aliases or the function is silently skipped. Probe
scratch is confined to `/root/kh2fm-build/recovery-experiments/<stem>/`.

## 6. Boundaries

No disagreement with `layout.tsv` was found. For all eight addresses the Ghidra
`body_bytes` equals the gap to the next declared layout start, and none of the
eight is a layout start row, so the declared ranges this work used are exactly
the ranges the project already claims. The four exact functions compile to
precisely the declared sizes (96 / 120 / 152 / 112 bytes) with no padding.

## 7. Pending — not done by worker-b

- The four recovered functions are **not registered** anywhere: `functions.tsv`,
  the build inputs and the manifests are shared outputs and were deliberately
  left untouched. Integration requires the primary worker to add
  `00161410`, `001995f8`, `001ba060`, `001c8e00` and re-run the full build plus
  `verify_fm_oct7_clamp_checkpoint.py`.
- The four residual functions (§4.1–4.4) still need the register-allocation
  and scheduling decisions recovered; they are **not** safe to register. Per
  §4.5 the source-shape search is exhausted at 507 variants, so the next
  attempt on them should change the toolchain hypothesis, not add more C
  variants.
- Because no full build was run, there is no evidence about any function
  outside the eight claimed addresses, and none is claimed.
- The checkpoint gate that passed at claim time now fails because the shared
  `functions.tsv` / `layout.tsv` and the staged build moved under this batch
  (§2). That must be resolved by the primary worker before any integration;
  worker-b's own probe evidence is independent of it and re-runs clean.