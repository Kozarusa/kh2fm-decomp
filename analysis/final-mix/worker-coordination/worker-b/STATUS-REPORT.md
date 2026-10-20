# Worker B — Status Report for the Primary

Worker: worker-b · Rounds 2, 3, 4 · Written from `analysis/final-mix/worker-coordination/worker-b/`

---

## 1. Bottom line

| Round | Targets | Byte-exact | Unresolved |
|---|---|---|---|
| 2 | 6 assigned by you | **4** | 2 (documented as compiler-level) |
| 3 | 8 self-selected | **3** | 5 |
| 4 batch1 | 8 self-selected | **4** | 4 |
| 4 assigned | 6 assigned by you | **1** (`001576e8`) | 5, each with a measured blocker |

**12 byte-exact recoveries across the three rounds**, every one backed by a `<addr>_solved.cpp`
plus its own `.verification.json` carrying `exact_match: true` and `boundary_agreement: true`,
with `source_sha256` matching the file on disk. All 12 were re-verified in one sweep.

The assigned six are no longer untouched. Docker came back mid-round, and I worked around the
harness's stale `WORKSPACE` constant with a private copy rather than editing your tool (see §3),
then probed all 27 queued variants. `001576e8` went exact on the first run; a further 15 targeted
follow-ups moved three of the remaining five to within 1-6 words, and §5 records exactly what is
left in each. 138 probes run in round 4 alone.

## 2. Needs a one-line fix: the harness still points at the old root

The project has moved:

| Was | Now |
|---|---|
| `C:/Users/KoZa/Documents/ChatGPT/` (project) | `C:/Users/KoZa/Documents/AGENTS/Codex/` |
| `C:/Users/KoZa/Documents/ChatGPT/tools/` | `C:/Users/KoZa/Documents/AGENTS/Public/tools/` |

Nothing was lost. I re-verified all 12 solved sources against their proofs (every
`source_sha256` matches, every row `exact_match` and `boundary_agreement`), plus the round-2/3/4
reports, claims and every queued variant. The old `ChatGPT` directory now holds only a stub.

But two things still reference the old path and will break:

1. **`probe_fm_source.py` hardcodes the old root.** It has
   `WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')`, asserts
   `source.is_relative_to(WORKSPACE)`, and reads `main.jsonl` through the same constant. Every
   probe of a source under `AGENTS/Codex` will be **rejected by that assert** until the constant
   becomes `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`. This is the single blocking item for
   resuming work.

   Verified end-to-end: running the runner now produces `AssertionError` on every variant, and
   the assert sits *before* the docker invocation — so this blocks work even once Docker is
   back. My runner's preflight warns about it automatically.
2. **`WORKER_BRIEF.md` still says `ChatGPT`** (3 references, 0 mentions of `AGENTS`), so a worker
   following it literally will look in the wrong place.

I have already migrated everything on my side — all 30 of my tools, not just the runner:
all list files rewritten to the new root (103 path references, all 43 round-4 entries re-verified
to resolve); `r4_probe_assigned.sh` now takes sources from `AGENTS/Codex` and the harness from
`AGENTS/Public/tools/kh2-audit/`, with a preflight `grep` that warns loudly if the harness
constant is still stale; the three `*_dump_orig.py` helpers read the disc from
`AGENTS/Public/tools/kh2-reference/` (trying the POSIX and Windows spellings, since they run
under both WSL and Windows python) and the disassembly container now mounts **both** roots so
`objdump_orig_inner.sh`'s `/work/tools/kh2-reference/SLPM_666.75` path still resolves; and the
nine root-level shell helpers, both target selectors, the generators and `make_claim.py` all
updated. Smoke-tested: ELF hash `d869ce4b…` and all 14 range hashes verify, the frameless scanner
still reports 3/0/3, and every `.py` parses and every `.sh` passes `bash -n`.

I did not edit the harness or the brief — both are yours. I have since worked around the
harness locally (see §3) rather than touching it.

## 3. Docker is back — work resumed

**Update: Docker is reachable again from inside WSL.** `/var/run/docker.sock` is present, the
`docker` CLI is on PATH, and `docker run --rm kh2-local/ps2-compiler:3.2-ee-040921-objdiff
/bin/true` exits 0. (The Windows service still reports `STOPPED`/1077, so `sc query
com.docker.service` is misleading — WSL has its own working endpoint.)

I never attempted a restart, at any point. All 12 exact recoveries were compiled and proven
before the outage.

Because the harness `WORKSPACE` constant is still stale, I worked around it privately rather
than editing your tool: `worker-b/probe_fm_source_local.py` is a byte-identical copy of your
`probe_fm_source.py` except for that one constant. I diffed the two and regression-tested the
copy by probing a known-exact source (`fm_worker_b_round4_00229d40_solved.cpp`), which still
reports `Exact probe matches: 1/1`. The queued 27 assigned-target variants are now probing
under it. Your file is untouched; please still make the one-line change so every worker benefits.

---

## 4. What the rounds actually taught

### 4.1 A measurable rule for if/else arm layout

The `00109e30` and `00242500` fixes needed an assumption, so I measured it against your own
corpus rather than trusting it. The trick needs no compiler: an exact match means the disc
bytes already are what the recovered source produces, so I decoded the original instruction
streams straight off `SLPM_666.75` and measured branch layout across every exact-match
function with an internal conditional branch.

```
conditional branches found       : 1564
branch target INSIDE the function: 1564   (else arm out of line, THEN arm inline)
branch target OUTSIDE            : 0      (arms swapped)
```

**1,564 of 1,564, zero exceptions.** This compiler never swaps the arms. Inverting
`== 0` ↔ `!= 0` in the source deterministically swaps which arm is inline, and no second lever
is needed.

Worth noting the negative result: your corpus **cannot** answer this directly. 4,658 of 5,201
exact functions have no `if/else` at all, and the remaining 61 never spell an explicit
`== 0`/`!= 0` test. The recovered set is overwhelmingly straight-line leaf wrappers.

### 4.2 A systematic gap: 461 functions, zero recovered

`00310620` needs a frame with 16-byte-spaced callee-save slots (`s0@0, s1@16, ra@32` with gaps)
where the pinned compiler always emits 8-byte spacing. Scanning the disc for that stride finds
**461 functions with it and none of them in your exact-match set.** I proved the body is not
the cause — rebuilding the structurally identical sibling at `0x00310560` matches the original
byte-for-byte **except the six frame words**. I ruled out dead locals, aligned types, variadic
prototypes, struct returns, outgoing-argument areas, alloca, register counts, and more; all
still give 8-byte spacing. This looks like a compiler RTL property, not a source spelling, and
it is the single largest untouched class I found.

### 4.3 Two smaller class findings

- **Frameless sibling calls: 3 functions, all unregistered** — `0030f690`, `0030f6a0`,
  `0030f6b0`. GCC always opens a 16-byte `ra`-only frame around a tail call in this harness;
  the original omits it. Small class, but entirely unrecovered, which suggests the shape has
  never been matched.

### 4.4 Reusable techniques

Highest-value tricks, in rough order of how often they worked:

- **Inline the callee in the argument list** instead of pre-binding it to a local. Changes RTL
  arg-setup order, which flips which move the MIPS delay-slot filler picks. Solved `0017ee68`
  and is the queued fix for `001576e8`.
- **Put the result in a variable before the call** so it lives across the call. Forces `$s1`
  and reproduced the target prologue byte-for-byte on `0019c0f8`.
- **Address adjacent globals through one pointer** so GCC CSEs the second address
  (`addiu t6,t7,1320` + `sw zero,4(t6)`). Solved `0017dec0`.
- **Bind a global to a local first**, which makes GCC hoist the `lui` and keep the incoming
  register as the load base. Solved `002e8290`.
- **A `float` local defeats constant folding** — writing `0.0f` inline folds to `sw zero`,
  binding it to a variable gives `mtc1` + `swc1`. Solved `002d5c20`.
- **`__builtin_memcpy` round trip keeps one register** where every union spelling forces a mode
  change and a fresh register. Solved `002f8870`.
- **A `u32` local moves a truncation to the store** rather than before the branch. Solved
  `0028af90`.
- **Six-word fixes that are really parameter-count fixes** — `00150de0` stored "incoming
  `$t1`", which turned out to be the function's sixth integer argument.
- **`__builtin_memcpy` + return-the-parameter** was the only way to keep `002f8870` on one
  register; `__builtin_fabs` and `asm` pinning both failed.
- Round 2 also produced asm-barrier and declaration-order results recorded in the round
  reports; re-read those before re-deriving anything.

---

### 4.5 Two environment gotchas that cost real time

- **`bg_run` executes through `cmd.exe`, not bash.** The `MSYS_NO_PATHCONV=1 wsl ...` prefix
  that works in the interactive `bash` tool fails under `bg_run` with
  `'MSYS_NO_PATHCONV' is not recognized as an internal or external command`. Drop the prefix in
  `bg_run` — cmd.exe does not mangle POSIX paths, so `wsl -d Ubuntu-24.04 -u root -- bash
  /mnt/c/...` works directly. This also explains the two earlier "batch probe" launches that
  exited 1 immediately.
- **The disc is little-endian on disk while `ee-objdump` prints big-endian words.** Reading the
  ELF big-endian silently produces plausible-looking garbage: my branch-target census first
  reported 4,247 of 4,249 targets outside their own function, versus 0 of 1,564 once fixed.
  Always `int.from_bytes(b[i:i+4], 'little')`.
- **Three exception cleanup stubs** — `00100338`, `001003b0`, `00101d38` are `addiu sp,-16 /
  sd ra / ld ra / jr ra` with an empty body. Not reproducible under `-fno-exceptions`; almost
  certainly EH cleanup stubs.

## 5. The six assigned to me in round 4 — outcome

Each differed from its registered baseline by only **6 words**. All six are now compiled and
measured; one is solved and five have a precisely characterised residual.

| Address | Size | Outcome | What is left |
|---|---|---|---|
| `001576e8` | 112 | **exact** | — |
| `00109e30` | 92 | 1 word, 92/92 bytes | target hoists both stack stores ahead of the branch and leaves the delay slot a `nop`; every spelling that yields the single `andi a0,a0,0xff` lets GCC fill the delay slot and shrinks to 88 bytes. Five variants, all 88/92. |
| `001ac310` | 104 | 5 words | load order and store offsets fight each other: pre-binding the values fixes the loads and breaks the offsets, the pointer form does the reverse. Target also restores `ra` before the stores; nothing compiled does. |
| `001e7230` | 104 | 5 words | target keeps all three counters in `t6` and never destroys `a1`; compiled emits `andi a1,a1,3`, legal because `(x&3)&3 == x&3`. A register-allocation preference I could not pin. |
| `0014b950` | 88 | 4 words | the `or` association order in the 64-bit pack. Eight spellings tried; grouping into `s64` locals makes GCC constant-fold it to 68 bytes. |
| `00242500` | 92 | 12 words | inverting the test changed the layout but collapsed the shared tail (84/92). Needs the tail rebuilt, not just the polarity flipped. |

`001576e8`'s mechanism, since it generalises: all six differing words were the relative order of
`mov a1,v0` and `addiu a0,s0,<offset>` in three identical repetitions. Writing the inner call
**inline** in the outer call's argument list, with the address argument first, fixes all three.
That is the round-2 `0017ee68` trick again.

One correction I owe you: I initially read `0xac4f2440` in `00242500` as `sb` and hypothesised a
byte-typed global. It is `sw`. A second decoder caught it; the hypothesis is retracted.

Caveat on `0014b950`: the R5900 64-bit shift words (`dsll32`/`dsrl32`/`dsll`, funct `0x38`–`0x3f`)
use a different operand field order from vanilla MIPS and I have not verified my decode against
`ee-objdump`. `r4_decode.py` prints them as `(unverified R5900 shift fields)` rather than
guessing. This affects **only** `0014b950`, and it is the target I am least confident about.

---

## 6. Still queued

My deferred targets, none started: `00104210`, `001c7ab8`, `001d6850`, `00241f20`. Roughly
5,900 unregistered ranges still carry verified pseudocode, so there is no shortage of work once
the compiler is back.

---

## 7. Where everything is

```
AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/
  STATUS-REPORT.md               this document
  REPORT.md                      round-1 report (preserved)
  round-2/  INSTRUCTIONS.md claim.json REPORT.md + 9 tools + original disassembly
  round-3/  claim.json REPORT.md + tooling
  round-4/  claim.json REPORT.md (24 KB) + assigned diffs + 26 queued variants
AGENTS/Codex/analysis/final-mix/recovery-experiments/
  fm_worker_b_round{2,3,4}_*_solved.cpp   the 12 exact recoveries
  fm_worker_b_round{2,3,4}_*.verification.json
```

Paths above are relative to `C:/Users/KoZa/Documents/AGENTS/Codex`.

Every experiment is isolated and named `fm_worker_b_round*_*`. Nothing outside my own
directories was modified: no edits to `functions.tsv`, `layout.tsv`, `main.jsonl`,
`compiler-range-verification.json`, `src/anon`, manifests, or `HANDOFF.md`; no full build, no
staged-input sync, no Docker restart, no Ghidra mutation, no executable-byte patching.

---

## 8. What I need

1. **Restore Docker** — it gates everything remaining.
2. **Update `WORKSPACE` in `probe_fm_source.py`** to
   `/mnt/c/Users/KoZa/Documents/AGENTS/Codex` — one line, and it unblocks every worker.
3. **Update `WORKER_BRIEF.md`** to the new root.
4. **Round-5 assignment, when convenient** — happy to keep going with self-selected batches
   meanwhile, but I would rather not duplicate an assignment again. Round 4's `INSTRUCTIONS.md`
   existed from the start and I picked my batch before reading it; the sets were disjoint, so
   nothing collided, but that was avoidable and I have flagged it in my own report.

One process note against myself: round 4's self-selected batch was picked before I read the
`INSTRUCTIONS.md` you had already written. No collision resulted, but it was the wrong order.

---

# Round 5 (2026-10-08) — 5 / 5 exact

Round-5 assignment (`round-5/assignment.json`, sha256 `cd49cab6…918cf`) asked for the five
round-four leftovers — **00109e30, 0014b950, 001e7230, 001ac310, 00242500** (priority
00109e30 → 0014b950 → 001e7230). **All five are now byte-exact and equal-size**, so my cumulative
worker-B total is **17 exact recoveries** (round 2: 4, round 3: 3, round 4: 5, round 5: 5).

| address | bytes | source | mechanism that finally landed it |
|---|---|---|---|
| `00109e30` | 92/92 | `…_00109e30_solved.cpp` (v72) | `u8` parameter + a single `asm volatile ("nop");` — the nop is absorbed into the `beqz` delay slot (so `sd ra` is not pulled in) while the `andi` still hoists above both prologue stores. An empty `asm volatile("" ::: "memory")` also frees the delay slot but blocks the hoist (3 words off). |
| `0014b950` | 88/88 | `…_0014b950_solved.cpp` (v44) | All 24 commutative orderings of the four OR terms swept (v21–v44); permutation `D,C,B,A` is the only one reproducing the `dsll32`/`dsra32` schedule and crossed accumulators. |
| `001e7230` | 104/104 | `…_001e7230_solved.cpp` (v12) | One reused `s32` counter drives both loops and both compare against `-1`; that alone puts the counter in `$t6`. Two locals, `$t6` pinning, or Ghidra's `param_2 &= 3` reassignment all put it in `$a5`. |
| `001ac310` | 104/104 | `…_001ac310_solved.cpp` (v11) | `puVar1 = param_1 + 3;` with stores at `puVar1[0x52]`/`[0x53]` **and** loads written `[1]` then `[2]`; GCC then emits the loads in target order while storing through `s1` at `0x148`/`0x14c`. |
| `00242500` | 92/92 | `…_00242500_solved.cpp` (v23) | Store-then-call-then-load tail keeps `v0` live so `sw t7,0x2440(v0)` sits in the `jal` delay slot. The accumulator only lands in `$t7` (not `$a0`) when the accumulation is written as **two statements** — `iVar1 = *(int *)(uVar1 + 0x2440);` then `iVar1 = iVar1 + param_1;` — instead of one expression. |

Proofs: `recovery-experiments/fm_worker_b_round5_<addr>_solved.cpp.verification.json`, all
`exact_match: true`, `boundary_agreement: true`. Source hashes are in `round-5/claim.json`
(`round5_result`); narrative in `round-5/REPORT.md`.

**Environment notes for primary.** Docker/compiler were up this round (round 4 was blocked by an
outage), so all of the above is probe-verified, not reasoned. Two things that will help others:
`/tmp` inside WSL is invisible to the Docker VM — only `/mnt/c/...` mounts work; and a
hand-rolled `ee-g++` outside the probe harness emits
`cc1plus: <file>: Value too large for defined data type` and produces no `.o` while exiting 0, so
`probe_fm_source.py` is the only reliable path. The ELF stores R5900 words little-endian while
`ee-objdump` prints big-endian, so raw range dumps need a per-4-byte-group reversal to decode.

**Nothing outside my directories was touched**: no active sources, `functions.tsv`,
`layout.tsv`, stage inputs, manifests, receipts, Ghidra, checkpoints or `HANDOFF.md`; no full
build, no Docker restart, no flag changes, no executable byte patching. I re-read
`compiler-status.json` before each of the five probe batches and only ever wrote per-source
scratch directories.

**Correction on the record (now closed out).** Mid-round I listed `00242500` as an exact match on
the strength of a `register … asm("$t7")` pin; that pin does not compile on this compiler
(`invalid register name '$t7' for register variable`), so I retracted the claim. `00242500` is now
legitimately exact by a different route (the two-statement accumulation above) and its proof is
re-generated from `…_00242500_solved.cpp`. The retraction note is kept in
`round-5/claim.json` (`round5_result.retracted`) so the audit trail shows it happened.

**Round 6 is claimed and in flight:** `round-6/claim.json`, ten disjoint unregistered fallback
ranges (two thunks, three 0xb0001xxx tail-call stubs, a global-by-value tail call, three
frame-16 tail-callers, and two stretch targets). Original bytes are dumped and hash-verified
(`round-6/r6_range_hashes.txt`, `r6_orig_disasm.txt`).

**Open asks are unchanged and now smaller:** (1) `WORKSPACE` in `probe_fm_source.py` still needs
to point at `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; (2) `WORKER_BRIEF.md` still names the
retired `Documents/ChatGPT` root; (3) primary had 5,504 registered rows when round 5 closed —
a re-read of that table before any further self-selected batch would keep us disjoint.

I am now claiming the next disjoint unregistered fallback batch from `round-5/pick_targets.py`
(frame classes limited to 16/32 B now that those are solved; branchless leaves and short tail-call
stubs rank first).

---

# Rounds 6 and 7 closed (2026-10-08)

## Round 6 — 2 / 10 exact

| address | size | proof |
| --- | --- | --- |
| 0016e8f8 | 36 | `…_round6_0016e8f8_solved.cpp.verification.json` |
| 00288610 | 40 | `…_round6_00288610_solved.cpp.verification.json` |

The reusable finding here is the **global-address convention**: the compiler emits
`lui (V >> 16)` plus `lw|sw` of the sign-extended `V & 0xffff`, with **no carry
adjustment**. A target pair `lui 0x36 / lw -3276` must therefore be declared as
`0x36f334` — not Ghidra's `0x35f334`, and not the arithmetically obvious `0x35f33c`.

**Eight open, each with a measured reason** (full detail in `round-6/REPORT.md`):
001002a0, 0030f690, 0030f6a0, 0030f6b0 and 0030a300 are **frameless sibling-call thunks** —
GCC 3.2 -O2 allocates a 16-byte frame around a tail call under every C spelling tried, with
`noreturn` on the callee and/or the caller, and with every inline-asm variant. 001ac700 is 2
words out (GCC always restores `ld ra` one slot before the target's tail-call argument setup;
8 spellings tried). 0021cda0 is 5 words out (target uses the `bnezl` likely-branch form and
duplicates `lui a0,0x33`). 002f1e00 loads gp-relative (`lw a0,-7456(gp)`) and cannot be
placed by the probe harness at all.

## Round 7 — 8 / 10 exact

Picked by the new `round-7/pick_targets.py`, which keeps only **framed** targets (opening
`addiu sp,sp,-N`, containing at least one `sd`/`ld`) precisely because of the round-6 frameless
blocker. 1195 candidates; 10 disjoint claimed; all 10 range hashes matched.

| address | size | proof |
| --- | --- | --- |
| 00196170 | 40 | `…_round7_00196170_solved.cpp.verification.json` |
| 0023fb00 | 40 | `…_round7_0023fb00_solved.cpp.verification.json` |
| 002954e0 | 36 | `…_round7_002954e0_solved.cpp.verification.json` |
| 003062a0 | 32 | `…_round7_003062a0_solved.cpp.verification.json` |
| 003062c0 | 32 | `…_round7_003062c0_solved.cpp.verification.json` |
| 003062e0 | 32 | `…_round7_003062e0_solved.cpp.verification.json` |
| 00306300 | 32 | `…_round7_00306300_solved.cpp.verification.json` |
| 00366db0 | 32 | `…_round7_00366db0_solved.cpp.verification.json` |

**Mechanisms worth reusing (full detail in `round-7/REPORT.md`):**

1. `asm volatile("sync");` reproduces a trailing `sync` instruction exactly.
2. A **trailing empty `asm volatile("");`** stops GCC 3.2 rewriting the second of two
   sequential calls into a sibling tail call — this is what keeps 002954e0 at 36 B with a real
   `jal` and `move a0,v0` in its delay slot.
3. `u16` parameters put the `andi a0,a0,0xffff` mask in the call's delay slot.
4. **The probe harness auto-defines `func_<8 hex digits> = 0x<addr>;`** for every such name in
   the source, so externs need no definition — but a **7-digit** name silently fails to link.
   `DAT_*`/`PTR_*` globals still need an explicit `asm(".globl …")` block. (Two round-7 v01
   files died this way; v02 fixed them.)

**Round 7 open (2):** 00308cd0 is 36/36 with 2 differing words — compiled `lui t7,0x36` /
`sw zero,0x60dc(t7)` against target `lui v0,0x36` / `sw zero,0x60dc(v0)`; five spellings
(plain, `volatile`, address-cast, trailing asm, `s32`) all emit `$t7`. 002b99a0 needs the leaf
frame-pointer idiom (`sd s8; move s8,sp; … move sp,s8; ld s8`, no `ra` save) that GCC 3.2 does
not produce from C.

## Round 8 (2026-10-08) — 8 / 12 exact

Claim `round-8/claim.json`, 12 framed unregistered ranges, **12/12 range hashes and layout
checks OK** against the original ELF (sha256 `d869ce4b…`). Detail in `round-8/REPORT.md`.

| address | bytes | mechanism |
|---|---|---|
| 00196300 | 40/40 | `DAT_01c61b04 = func_001b1448(PTR_00350334);` |
| 001d9d00 | 40/40 | same; store encoded `lui 0x1d6 / sw -17752` ⇒ symbol declared at `0x1d6baa8` |
| 001b92d0 | 40/40 | two calls, second takes a global, trailing `asm volatile("")` |
| 0019fd88 | 36/36 | 3-arg function-pointer typedef + literal third argument |
| 002ead20 | 36/36 | same, delay-slot constant 43 |
| 00185a98 | 40/40 | first dereference assigned **back into the parameter** |
| 002ecdb0 | 36/36 | function-pointer-typed local + trailing empty asm |
| 00322968 | 36/36 | the same recipe with vtable slot 0x14 |

**New, reusable findings**

1. **Vtable dispatch with a forwarded second parameter.** `0019fd88`/`002ead20` only matched with
   `typedef void (*code)(u32,u32,u32)` and a literal third argument — a one-arg typedef puts the
   delay-slot constant in `$a1` instead of `$a2`.
2. **Reassignment into the parameter pins the result to `$a0`** (`param_1 = *(u32 *)(param_1 + 0x9f4);`).
   This single change fixed `00185a98` and the whole `003197f8`/`0031f940` family in round 9.
3. **A function-pointer-typed local** (`code pc;` rather than `code *pc;`) produces the targets'
   *two-distinct-temp-register* vtable load; `code *pc` folds the two loads into one temporary.

**Round 8 open (4):** `00305ce0`/`00305e20` — v04 is now **40/40 with 2 differing words**: writing
the constant in a separate statement (`iVar2 = 5; *func_00316d08() = iVar2;`) fixed the store base,
leaving only `li t7,5` vs `li v1,5` and `sw t7,0(t6)` vs `sw v1,0(v0)`; `00173270` (40/40, 5 words —
the target reloads `lw a0,0(a0)` and keeps two live pointers); `002b6ab8` (20/36, leaf frame-pointer
idiom).

## Where worker B stands (after round 8)

Cumulative byte-exact recoveries: **round 2: 4, round 3: 3, round 4: 5, round 5: 5, round 6: 2,
round 7: 8, round 8: 8 — 35 total.**

## Rounds 10 and 11 in flight (2026-10-08)

Round 10 claimed 12 ranges (`round-10/claim.json`, 12/12 range hashes and layout checks OK) and has
already produced three byte-exact recoveries on its first batch: **003068d8** (`func_00305650(param_4)`
with `asm volatile("sync"); asm volatile("ei");` between the call and `return 0` — the bare
`sync` intrinsic lands exactly where Ghidra shows it), **0018f858** (`s0` frame, `param_1[0]` and
`param_1[1]` loaded in the delay slot, result stored back through `s0`) and **001b81e8** (a call,
then a byte store to a global declared `u8`, then a global read returned — the store and the read
share the `lui 0x35`, with the read issued first).

Round 11 claimed 16 ranges (`round-11/claim.json`, 16/16 verified), weighted towards vtable dispatchers
because round 8's recipes transfer directly: six near-identical dispatchers through one global
(`001de948`/`001de978`/`001e0128`/`001e0158`/`001e0188`/`001e01b8` are three byte-pairs), three through
`ra`-taking targets (`001050d8`, `0016fac8`, plus the round-10 `001dc488` sibling), and three
two-level dispatches (`0018f218`, `00171810`, `002bef78`).

**New tool lesson:** `ee-objdump`'s printed lw/sw immediates do **not** always agree with the raw
instruction word — `002f1898`'s target prints `lw a0,-16176(t7)` but the raw word is `8de4c0d0`
(offset `0xc0d0` = -16192). Always derive global symbols from the raw words, never from the
disassembly text.

Every recovery has its own `…_solved.verification.json` carrying `exact_match: true` **and**
`boundary_agreement: true`, probed from the promoted `_solved.cpp` copy rather than from the
exploratory variant.

**Open asks for primary:** (1) `WORKSPACE` in `probe_fm_source.py` should point at
`/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; (2) `WORKER_BRIEF.md` still names the retired
`Documents/ChatGPT` root; (3) registration had 5,512 rows when round 8 was picked and
5,512 again when round 10 was picked — a re-read before any further self-selected batch keeps us
disjoint (round 10's picker now harvests every earlier round's addresses from the claims
automatically instead of relying on a hand-maintained exclusion list).

**Isolation.** Nothing outside worker-B directories was touched: no active sources,
`functions.tsv`, `layout.tsv`, stage inputs, manifests, receipts, Ghidra, checkpoints or
`HANDOFF.md`; no full build, no Docker restart, no flag changes, no executable byte patching.
Only per-source scratch directories under the stage's own `recovery-experiments/` were written,
by the shared probe harness itself.

Next: continue claiming framed, unregistered fallback ranges — round 7 reproduced 8/10 and
round 8 7/12 of framed targets, so the picker keeps excluding frameless bodies rather than fight
them, and the vtable-dispatch spelling from round 8 should be the starting point for any new
dispatch-shaped target.

---

## Rounds 9 – 12 (worker B, isolated)

Cumulative exact recoveries now stand at **53**, every one carrying a
`…_solved.verification.json` with `exact_match: true` **and** `boundary_agreement: true`,
probed from the promoted `_solved.cpp` rather than from the exploratory variant.

| round | claimed | exact | closed? |
|---|---|---|---|
| 9 | 12 | 4 (0023fb28, 00180770, 003197f8, 0031f940) | REPORT.md + claim.json written |
| 10 | 12 | 5 (003068d8, 0018f858, 001b81e8, 002f1898, 0016fb00) | REPORT.md + claim.json written |
| 11 | 16 | 6 so far (002f0798, 002f07c8, 001dc4b8, 001de978, 001e0158, 001e01b8) | in progress |
| 12 | 12 | 3 so far (0023fb90, 00242368, 00293f78) | in progress |

### Dispatcher recipe that finally generalises (rounds 9 – 12)

The recurring blocker was a two-level vtable load: targets load the table base and the entry into
**two different** temporaries (`lw t6,0(a0); lw t7,4(t6); jalr t7`) while GCC 3.2 folds them into
one (`lw t7,0(a0); lw t7,4(t7)`). Register pins are unavailable on this compiler. What works is
a combination of three source-level levers:

1. `param_1 = *(u32 *)(param_1 + off);` — writing the reloaded base back into the parameter pins
   the result to `$a0` (round 9: 003197f8, 0031f940; round 8: 00185a98).
2. A **function-pointer-typed local** (`code pc;`, not `code *pc;`) so the entry lands in its own
   temp rather than being reused (round 8: 002ecdb0, 00322968; round 11: 002f0798, 002f07c8).
3. A trailing empty `asm volatile("");` to stop GCC rewriting or reordering the tail.

The third argument of a dispatch call has to be a **literal** for the constant to appear in the
`jalr` delay slot (`jalr t7; move a2,zero`), and `__builtin_return_address(0)` reproduces the
target's `move a2,ra`.

### Open classes, with what was tried

- **`jalr $v0` dispatchers** (001050d8, 0016fac8, 001dc488, 001de948, 001e0128, 001e0188) — targets
  keep the entry in `$v0`; every C spelling lands it in `$t7`/`$t6`. Three new variants per target
  are in flight.
- **s8 leaf frame-pointer idiom** (`sd s8; move s8,sp; …; move sp,s8; ld s8`) — round 7's 002b99a0,
  round 8's 002b6ab8, round 10's 002b81ec/002b8214. GCC 3.2 never emits it from C, so the original
  build used `-fno-omit-frame-pointer` for some translation units. This is a build-wide flag
  difference, not a source defect, and is out of worker B's scope to fix.
- **Dead stores GCC elides** (round 9's 002ef340, round 11's 002bef78) — the target spills an
  argument and never reloads it.
- **Arguments in `$9/$10/$11`** (round 9's 002ba3b8, round 10's 001231f8) — not an O32 argument
  register set, so not expressible in C.
- **Strength reduction** (round 10's 0030ec28) — the target keeps an explicit `lui`+`and`+`sltu`
  mask test where GCC turns the constant into a `dsll`/`andi` bit test.
- **Unreachable calls** (round 10's 00315418) — the target keeps a `jal` behind a plain branch that
  GCC proves dead and deletes.

**Tool correction worth repeating:** derive every global symbol from the **raw instruction word**,
never from `ee-objdump`'s printed displacement. In 002f1898 the tool prints `lw a0,-16176(t7)`
while the encoded word is `8de4c0d0` (offset `0xc0d0` = -16192). Following the printed text
produces a source that is one word off and never converges.

---

## Rounds 11 – 13 (worker B, isolated)

| round | claimed | exact | closed | report |
|---|---|---|---|---|
| 11 | 16 | 6 | yes | `round-11/REPORT.md` |
| 12 | 12 | 4 | yes | `round-12/REPORT.md` |
| 13 | 14 | 6 so far | in progress | `round-13/REPORT.md` |

All claims were re-read from the original ELF (`d869ce4b…`) and cross-checked against
`/root/kh2fm-build/layout.tsv`; every source was compiled only through the shared harness
`Public/tools/kh2-audit/probe_fm_source.py`. No shared stage input was touched.

### Round 11 — two new mechanisms

**Three-level dispatch where the object is a call return (002f0798 / 002f07c8, 48/48).**
```c
typedef void (*code)(u32);
u32 iVar1 = *(u32 *)param_1;
u32 iVar2 = func_0010c7e8(*(u32 *)(iVar1 + 4));
code pcVar2 = *(code *)(*(u32 *)iVar2 + 0x28);
pcVar2(iVar2);
asm volatile ("");
```
Because the object comes from a call, it stays in `$v0` and the final `jalr` targets `$v0`. A
function-pointer-typed local plus a trailing empty asm keeps two distinct temp registers.

**Two-argument global dispatcher (001dc4b8, 001de978, 001e0158, 001e01b8, 48/48).**
```c
typedef void (*code)(u32,u32);
void func_X(u32 param_1) { (*(code *)(*(u32 *)DAT + 4))(DAT, param_1); asm volatile (""); }
```
The **two-argument** call is what matches. Adding a third argument changes the word count and the
delay-slot schedule — arity is load-bearing, not cosmetic.

### Round 12 — picker lesson worth adopting

Round 12 deliberately restricted the batch to **framed, no-branch, 52-byte bodies**. That gave
4/12 (33%), against 2/10 (20%) in round 6, where five of ten slots went to frameless sibling-call
thunks that GCC 3.2 always frames. Recommendation for future unregistered batches: prefer
`addiu sp,-N` + `sd ra`/`ld ra` bodies with no conditional branch.

**Guard + dispatcher (0023fb90 / 00242368 / 00293f78, 52/52).** The machine form is `bnel zero,+7`
with `move a1,a0` in the delay slot; `if (param_1 != 0) { (*(code *)(*(u32 *)DAT_0036ebe0 + 4))(DAT_0036ebe0, param_1); }`
reproduces it. `DAT_0036ebe0` is declared one page above its true address `0x35ebe0` per the
no-carry global convention.

**Four named temps (001721d8, 52/52).** Four `u32` locals stop GCC folding a three-level address
chain; the call forwards the three live chain values.

### Round 13 — six exact on the first attempt

0023fe28, 00288c20, 0028cc40 (52/52, the round-12 dispatcher shape with `DAT_0036ec84` /
`DAT_0036f34c` / `DAT_0036f3f8`), 001d5030 (52/52, `DAT_00352768 = param_1; iVar1 =
func_00168b38(param_1,2,0); DAT_01d6ba68 = *(u32 *)(iVar1 + 8);`), 002bd538 (52/52, three stores —
`DAT_003617e4 = 0; DAT_003617e0 = func_002b823c(); DAT_003617e8 = 1;`, the last one a `u8`
global), 00314480 (44/44, 48-byte frame, `s32 local_8[5]` passed as `(u32 *)local_8`).

The round-12 dispatcher shape generalising across a whole family of addresses on the first try is
the strongest single result of these rounds: it means the round-11/12 recipe is the *original*
spelling, not a fit.

### The `jalr $v0` class is now closed as compiler-level

Targets load the vtable entry into `$v0` (`lw t7,0(a0); lw v0,0(t7); jalr v0`). GCC 3.2 always
picks `$t6`/`$t7`. Round 11's byte-exact **001dc4b8** proves that is the compiler's only choice for
the identical source shape. Nine members are parked: 001050d8, 0016fac8, 001dc488, 001de948,
001e0128, 001e0188, 0016c7a0, 00288be8, 0028cc08. Six variants per target were tried (inline
double deref, fp-typed local with barrier, two named intermediates, triple-inline, intermediate +
inline call, triple-temp copy), each combined with `__builtin_return_address(0)` for the
`move a2,ra` members. The delay-slot spelling for `move a2,ra` is confirmed correct; only the
register class is unreachable. The register-pin escape hatch is rejected by this compiler
(`invalid register name '$t7' for register variable`), so there is no C spelling left to try.

---

## Round 14 (worker B, isolated)

Claimed 14 framed, no-branch, `sd ra`-bearing ranges; all 14 range-hash and layout verified against ELF sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. Claim and full detail in `round-14/claim.json` (`round14_result`) and `round-14/REPORT.md`.

| round | claimed | exact | closed |
|---|---|---|---|
| 9 | 12 | 4 | yes |
| 10 | 12 | 5 | yes |
| 11 | 16 | 6 | yes |
| 12 | 12 | 4 | yes |
| 13 | 14 | 6 | proofs confirmed; report pending |
| 14 | 14 | **1** | yes |

### New mechanism — the address of an absolute linker symbol

GCC 3.2 emits `lui reg,%hi(sym)` + `addiu reg,%lo(sym)` — the relocation path — when a constant is spelled as **the address of an absolute linker symbol**, but `lui` + `ori` — `li_operand` — when the same constant is a plain integer literal. Casting an integer to `void *` or to a function-pointer typedef does **not** change this; only a genuine `SYMBOL_REF` does.

Because the probe harness already auto-defines `func_<8 hex digits>` as an absolute linker symbol, the recipe is:

```c
extern "C" char func_XXXXXXXX;
...
func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, (u32)(long)&func_XXXXXXXX);
```

This is a second, independent spelling for a constant — alongside the no-carry `asm(".globl DAT…")` global, which produces `lui` + `lw`/`sw`.

**Caveat, measured both ways.** The assembler's `%hi` is conservative: `hi = (V + 0x8000) >> 16` while `%lo` keeps `V & 0xffff` unsigned. That pair is self-consistent when `V & 0xffff >= 0x8000` (confirmed: symbol-addressing `0x1e389a8` produced exactly the target's `lui a0,0x1e4` + `addiu a0,a0,-30296`) and biased one page **high** when `V & 0xffff < 0x8000` (observed: `&func_01d58d90` produced `lui t7,0x1d6` + `lw a1,-29296(t7)` = 0x1d68d90 instead of 0x1d58d90). Check the emitted page before trusting a symbol-addressed constant.

### Exact (1)

| address | bytes | variant | source sha256 |
|---|---|---|---|
| 00322ba8 | 52/52 | v02 | `ed27465497e4b5041ab6b205cd3765ed6fb6484f536e38ad54c787ca845dfbef` |

```c
void func_00322ba8(u32 param_1)
{
  func_00108698(param_1 + 0x38);
  func_001ddd10(param_1 + 0xc0);
  asm volatile ("");
  return;
}
```

### Open (13), each with a measured blocker

- **The eight-member family** (001b8800, 001c0c38, 001c10f8, 001d22a8, 001d23e0, 001d30c0, 001d7980, 002c22b8) — all 52/52 with **two words differing, a single swap**. The symbol-address mechanism fixed the `addiu`-vs-`ori` word; what is left is that the target issues a body load's address-materialising `lui` **before** the prologue store and the `lw` **after** it. Twelve variants tried; every spelling that keeps the `lw` below the prologue store also pushes the `lui` below it, and vice versa. Recorded as compiler-level: this compiler never schedules address materialisation for a body load into the prologue region.
- **0018d808** — 52/52, two words, one instruction pair (`lq t7`/`sq t7` vs target `lq t0`/`sq t0`). The 16-byte `__attribute__((aligned(16)))` quad struct copy plus a memory barrier after the copy is otherwise exact.
- **0030a690** — 52/52, four words: `$v0`-vs-`$t7` scratch choice for the global store, and a one-slot `sd ra` reorder.
- **00311100 / 00311138** — 52/52, four words: the target's `move v0,a1` forces the second struct word through `$v0`.
- **00158050** — 52/56: parameters arrive in `$t1`/`$t2`, not an O32 argument register set.

### Two fixes carried in `round-14/pick_targets.py`, both worth propagating

1. **`layout.tsv` is now CRLF-terminated.** The loader did `rstrip("\n")`, so every size field kept a trailing `\r`, `int()` raised, and `load_layout()` silently returned **2** rows — the candidate list came back empty with no error at all. Fixed to `rstrip("\r\n")`. This silently affected every picker back to round 9.
2. **The first `no-jalr` filter was written against the wrong field.** `sd`/`ld` encode the base register in `rs` (sp = 29) and the saved register in `rt` (ra = 31); testing `rs == 31` skipped 1104 valid framed candidates and returned 0. Caught by counting skip reasons rather than trusting the zero.

### Standing asks for primary (unchanged)

1. `probe_fm_source.py` `WORKSPACE` should be `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`.
2. `WORKER_BRIEF.md` still names the retired `Documents/ChatGPT` root.
3. **`layout.tsv` is CRLF-terminated** — any tooling that splits it by hand should `rstrip("\r\n")`.

---

## Round 15 (worker B, isolated) — 6 / 16, best rate since round 7

Claimed 16 framed, no-branch, `sd ra`-bearing ranges, 16/16 range-hash and layout verified. `round-15/claim.json` (`round15_result`), `round-15/REPORT.md`.

| round | claimed | exact |
|---|---|---|
| 13 | 14 | 6 |
| 14 | 14 | 1 |
| 15 | 16 | **6** |

Exact: 001618b8 `77291da4…`, 00167b60 `c83b3c21…`, 00167e70 `383708e4…`, 00167ea8 `2e735012…`, 0019c970 `faa4f570…`, 0019c9a8 `34012da4…` — all 56/56, each re-proved from its own `_solved.cpp`.

### Correction to round 14's symbol-address note
Round 14 reported a "page bias" requiring the symbol to sit one page lower. **That was a misgeneralisation from a `lw` case and is corrected here.** The assembler computes `hi = (V + 0x8000) >> 16`, `lo16 = V & 0xffff`, and reproduces whatever `(hi, signed lo)` pair you want as long as the symbol sits at `V = (hi << 16) + sign_extend(lo)` — the **same no-carry value already used for `lui` + `lw` globals**. Verified both directions this round:

| target pair | declare | Ghidra's value |
|---|---|---|
| `lui a2,0x1e` + `addiu a2,a2,-9608` | `func_001dda78` | 0x1dda78 |
| `lui t7,0x1e` + `addiu t7,t7,-9424` | `func_001ddb30` | 0x1ddb30 |
| `lui t7,0x36` + `addiu t7,t7,-3168` | `func_0035f3a0` | 0x35f3a0 |
| `lui a0,0x1e4` + `addiu a0,a0,-29080` | `func_01e38e68` | 0x1e38e68 |

`lw`/`sw` genuinely differs: there `hi == V >> 16` must hold exactly, so the conservative `hi` lands a page high when `V & 0xffff >= 0x8000`. That is what produced round 14's `lui t7,0x1d6` + `lw a1,-29296(t7)`.

**Sharp edge:** `func_` names must be exactly **8 hex digits** or the harness does not auto-define them — a 7-digit `func_01dda78` links as undefined.

### Two more source-level levers
- **Live-value across calls** — `u32 uVar1 = (u32)(long)&func_0034d3c0; f(uVar1); f(uVar1 + 384); asm volatile ("");` puts the constant in `$s0` and keeps the second call a real `jal` (three exact matches).
- **Xor operand order is load-bearing** — `(loaded ^ param)` gives the target's `xor s0,t7,s0`; the reverse order gives `xor s0,s0,t7`. That single word was the whole gap on two targets.

### Open (10)
00198700 (52/56, live-in `move v0,a0` hoisted into the prologue), 001ca950 (52/56, second value in `$t1`), 0028b7f8 (56/56 two words, store sinks between the two prologue saves), 00307fe0 (56/56 six words, `v0`-vs-`t7` for one parameter), 0030df00 (56/56 seven words, DAT scratch register), 002b7f84 / 002b83b4 / 002b9968 / 002b9a00 (28/56, leaf frame-pointer idiom), 002b823c (36/56, frame-pointer idiom plus a `gp`-relative load).

### Standing observation — a build-wide register-allocation setting, not a per-function accident
The `$v0`-vs-`$t7` scratch choice now has **five** independent instances across three rounds — 00308cd0 (r7), 0030a2d0 (r11), 0030a690 (r14), 0018d808 (r14), 0030df00 (r15) — always with the target preferring `$v0` when a global address or a 16-byte move shares a body with a small return value. Worker B cannot set compiler flags, so this is recorded rather than chased, but it may be worth primary checking whether the original build used a different register-allocation setting.

### Environment note
The reference ELF is staged at **`/root/kh2fm-build/SLPM_666.75`** (same sha256). `/root/kh2fm-build/tools/` holds only `build_elf.py`, `common.py`, `objdiff.py` — there is **no `tools/kh2-reference/` subdirectory**, so `ee-objdump` pointed at `/work/tools/kh2-reference/SLPM_666.75` fails. `round-15/r15_disasm.sh` uses `/work/SLPM_666.75`.

Cumulative worker-B exact recoveries: **67** (r2 4, r3 3, r4 5, r5 5, r6 2, r7 8, r8 8, r9 4, r10 5, r11 6, r12 4, r13 6, r14 1, r15 6).

---

## Round 16 (worker B, isolated) — 6 / 16

Claimed 16 framed, no-branch, `sd ra`-bearing ranges, 16/16 range-hash and layout verified. `round-16/claim.json` (`round16_result`), `round-16/REPORT.md`. Picker: round-15's with ATTEMPTED harvested mechanically from every `round-*/claim.json` (260 addresses, rounds 1-15); 975 candidates.

| address | bytes | mechanism |
|---|---|---|
| 001053c0 | 60/60 | target loads the global **twice** → declare it `volatile` or GCC CSEs |
| 0014cfc8 | 60/60 | two globals in one page, each with its own `lui` → **both** must be `volatile` to pin the pairs |
| 00197be8 | 60/60 | global loaded once into `$s0`, forwarded to both calls; trailing empty asm goes **inside** the guard block |
| 001c13a8 | 60/60 | the load of `param_1[12]` must not be hoisted above the first call — write it inline as an argument |
| 001e6c00 | 60/60 | trailing empty asm; symbol value follows the truncating rule (see below) |
| 002d47a8 | 60/60 | the `+3208` argument must be a **byte** offset, not a `u32` index, or GCC folds it to `+802` |

### Symbol rule refined — `lw`/`sw` and `addiu` want DIFFERENT values
* reached by **`lw`/`sw`** → `hi` is **truncating**: `hi == V >> 16` and `lo16 == V & 0xffff`; the symbol usually sits one page **above** Ghidra's.
* reached by **`addiu`** (a symbol *address*) → `hi` **rounds**: `hi == (V + 0x8000) >> 16`.

001e6c00 is the one-word proof: target `lui t7,0x1da` + `lw a0,-6428(t7)`. Ghidra's `0x1de6e4` yields `lui 0x1d` (truncating on `0x1de6e4 >> 16`); `0x1dae6e4` yields `0x1da` with the same `0xe6e4` half. Applying round 15's `addiu` rule to an `lw` is the mistake — both rules coexist and the consuming instruction picks which.

### New compiler-level class — PROLOGUE SINK (4 targets)
A vtable-pointer store to the incoming parameter is scheduled **between** the two prologue saves (`sd s0,0(sp); sw t7,0(a0); sd ra,8(sp)`) by GCC 3.2, where the original always sinks it **below both**. Members: 0028b7f8 (r15), 00315678, 00315700, 00316890 (r16). Tried on each: plain, `volatile` store, named pointer local, `volatile` pointer local, memory barrier before the store, barrier between store and first call. None pins it.

### Round 16 open (10)
0014dbc8 / 0014dc08 (60/60, 5-6 words — GCC swaps the first two of six same-base zero-stores), 00170530 (60/60, 4 words — target keeps the two constants in distinct registers, GCC reuses `t7`), 00265740 (56/60, 13 words — needs `== 0` for the `sltiu` tail and the reversed `ra`/`s0` prologue order simultaneously), 002e2e18 (56/56, 4 words — likely-branch form), 0016e200 / 0016e500 (56/60, 7 words — `lq t0` vs `t7` plus a duplicated `ld s0`), 00315678 / 00315700 / 00316890 (prologue-sink class).

### Standing observation for primary
The prologue-sink class and the `$v0`-vs-`$t7` scratch class both look like **build-wide code-generation settings** rather than per-function accidents — the sink is always at the same point in GCC's prologue, and the scratch choice is always `$t7` where the original preferred `$v0`. They are the two largest remaining classes. Worker B cannot set compiler flags, so both are recorded rather than chased, but they are worth primary's attention as possible single-setting explanations.

Cumulative worker-B exact recoveries: **73** (r2 4, r3 3, r4 5, r5 5, r6 2, r7 8, r8 8, r9 4, r10 5, r11 6, r12 4, r13 6, r14 1, r15 6, r16 6).

## Rounds 17 – 19 (worker B, isolated)

### Per-round result

| round | claimed | exact | notes |
|---|---|---|---|
| 17 | 16 | 7 | vtable-setter recipe reproduces a whole sibling family first try |
| 18 | 16 | 8 | `__builtin_expect` recovers the likely-branch form |
| 19 | 16 | 5 so far | 3 exact on the first attempt |

Running total of byte-exact worker-B recoveries: **94**, every one with a `_solved.cpp`
re-proved by `probe_fm_source.py` (`exact_match: true`, `boundary_agreement: true`).
No `functions.tsv` / `layout.tsv` / stage / build / manifest changes were made.

### The argument-count breakthrough (round 17)

Rounds 9 and 14 each parked a target as "parameters arrive in `$9`/`$10`, not expressible
in C". That was a misreading. O32 argument registers are `$4..$11`, so a
`move tN,tM` in a body or in a `jal` delay slot is simply recording that argument 6 or
later has to be relocated — it is not impossible register usage. Reading the moves as a
literal argument list recovered three targets:

| address | round parked | argument list that works |
|---|---|---|
| 00158050 | 14 | `func_001386e0(p1,p2,p3,p4,p5,p7);` — only `$9←$10` needed |
| 002ba3b8 | 9 | eight args, last three `(&local_8, p6, p7)` |
| 001aa940 | 18 | `func_001ab598(*(u32*)p1, p1+64, p2, p3, p4, p5);` |

A sweep of every round's disassembly for `move t0..t3` found no further members of the
class: 001231f8 is blocked separately by the `jalr $v0` class, 00307fe0 already had the
right argument list (pure register allocation), and 00180c88 was solved in round 2.

### Symbol values — corrected rule

The high half is **always truncating**. The declared value must satisfy
`V >> 16 == hi` and `V & 0xffff == lo16`, for both `lw`/`sw` and `addiu`/`ori`
materialisation. The earlier "addiu rounds its high half" rule was an artifact of
declaring Ghidra's address and letting the compiler use it faithfully — 001d6538 was one
word from exact with the `addiu` already correct and only `lui` off by a page.

Practical consequence: a symbol reached by `lw` is normally declared **one page above**
Ghidra's address (00288610, 0023fb00, 001d9d00, 001d6538 all confirm this), while a
symbol *address* — spelled `(u32)(long)&func_XXXXXXXX` so the assembler sees a genuine
`SYMBOL_REF` — emits `lui` + `addiu`, which is the only way to get a constant into a
`jal` delay slot as an `addiu` rather than an `ori`.

### Reusable mechanisms confirmed this batch

1. **Two-statement accumulation.** Writing `x = load; x = x + p;` instead of one
   expression puts the accumulator in `$t7` where the single expression gives `$a0`
   (00242500).
2. **Guard + trailing empty asm.** `asm volatile ("");` after the last call blocks
   GCC's sibling-call rewrite and is required in most multi-call bodies (001b92d0,
   00322ba8, 001c1890, 001aa940).
3. **Function-pointer-typed local** plus a trailing barrier gives the two-distinct-temp
   vtable load most targets use.
4. **Bare `asm volatile ("sync");`** emits a literal `sync` in place (003062a0 family).
5. **`volatile`** on a global the target loads more than once, otherwise GCC CSEs.
6. **`__builtin_expect`** for `beql`/`beqzl` likely-branch forms (002e2dd8).

### Parser lesson worth recording

Postfix `[]` binds tighter than a cast, so `(u32 *)(ptr[2])` is a cast of the indexed
pointer and `(u16 *)(*(u32 *)p + 4)` adds an unwanted load. Several round-19 sources
were wrong for exactly this reason and the extra instruction showed up plainly in the
word-level diff.

### Still open (compiler-level, recorded not chased)

`$v0`-vs-`$t7` scratch choice (~7 instances); a body load's `lui` never scheduled into the
prologue region; epilogue `ld ra` scheduled mid-body; leaf frame-pointer idiom
(002b99a0, 002b6ab8, 002b81ec, 002b8214 — implies `-fno-omit-frame-pointer` for some
original translation units); `jalr $v0` vtable dispatch (nine members); prologue sink of a
vtable-pointer store; frameless sibling-call thunks. Register pins
(`register … asm("$t7")`) are rejected outright by this compiler, so none are reachable
from C.

The scratch-choice and prologue-sink classes look like **build-wide code-generation
settings** rather than per-function accidents. That is worth primary's attention, since
primary owns compiler flags and worker B does not.

### Asks for primary (unchanged, plus one new)

1. `probe_fm_source.py`'s `WORKSPACE` should be `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`.
2. `WORKER_BRIEF.md` still names the retired `Documents/ChatGPT` root.
3. `layout.tsv` is now CRLF-terminated — split on `\r\n`, not `\n`, or the size column
   silently fails to parse and candidate pickers return nothing.
4. **New:** `/root/kh2fm-build/tools/` contains only `build_elf.py`, `common.py` and
   `objdiff.py`. There is no `tools/kh2-reference/` subdirectory, so the reference ELF
   must be mounted from `/root/kh2fm-build/SLPM_666.75`, not from
   `/work/tools/kh2-reference/SLPM_666.75`.

## Rounds 20 and 21 (worker B, isolated)

| round | claimed | exact | closed |
|---|---|---|---|
| 20 | 16 | 0 | `round-20/REPORT.md` |
| 21 | 19 | 12 | `round-21/REPORT.md` |

Cumulative worker-B exact recoveries: **108** (r2 4, r3 3, r4 5, r5 5, r6 2, r7 8,
r8 8, r9 5, r10 5, r11 6, r12 4, r13 6, r14 2, r15 6, r16 6, r17 7, r18 8, r19 6,
r21 12; round 20 contributed none).

### Round 20 — the frame-pointer class, now settled at nineteen members

The batch reduced to one byte-regular fifteen-member family of
`func_002b6708(2, K, param_1)` wrappers. v02 reproduced the target's spill exactly —
`sw a0,0(sp)` and `lw a2,0(sp)` in the `jal` delay slot, in the same positions — but
addressed the frame through **`sp`** where the target uses **`fp`**, with no
`sd s8` / `move s8,sp` / `move sp,s8` / `ld s8` at all.

That is exactly what omitting the frame pointer produces and is not something C can
influence. With the four earlier members (002b99a0, 002b6ab8, 002b81ec, 002b8214) this
is now **nineteen members of one build-flag difference**.

**This is the single clearest item for primary: these fifteen functions cost one flag
on the original build (`-fno-omit-frame-pointer`), not fifteen source reconstructions.**
The spill and call structure is already reproduced; only the frame base register differs.

### Round 21 — a whole family on the first attempt

The five-member 00242b\* flag family was exact on the first probe from one source
template. That is the strongest evidence yet that the recovered spelling is the
original one: when a template reproduces a parameterised family exactly, the parameter
is not fitted to the output but read off the machine.

Two reusable readings:

- **Argument lists come from the register shuffle.** `$4..$11` are the O32 argument
  registers, so `move tN,tM` in a body or delay slot states the callee's argument count
  and order literally. 00174858's sixth argument and 001c6e58's seventh were both
  recovered this way after Ghidra's pseudocode had them wrong.
- **Read immediates off `dis.py`; do not recompute them.** Four exact recoveries this
  round were one or three words from done and turned on nothing but my own arithmetic —
  7480 read as `0x1d28` rather than `0x1d38`, `0xcaf4` read as `0xca34`. These were
  silent self-inflicted errors, not compiler behaviour.

### New compiler-level class: if-conversion refusal

GCC 3.2 will not emit `li v1,C ; movn v1,zero,v0 ; move v0,v1` for `(x == 0) ? C : 0`;
it emits a compare and a branch. Three spellings were tried on 00308f00 and 003091c8
(multiply by the predicate, a ternary, an explicit conditional assignment) and none
produced `movn`. 001cf998 and 00194830 show the same refusal in another shape.

### Standing open classes, in order of size

1. **Frame pointer — 19 members.** Settled in round 20 as a build-flag difference.
2. **If-conversion refusal — 4 members** (00308f00, 003091c8, 001cf998, 00194830).
3. **`jalr $v0` vtable dispatch — nine members**, parked.
4. **Spurious `andi 0xffff` after an `lhu` feeding a shift — 7 members**, one word each.
5. **A body load's `lui` never scheduled into the prologue region — 9 members.**
6. **`$v0`-vs-`$t7` scratch choice — ~7 instances.**
7. Prologue sink of a vtable-pointer store; frameless sibling-call thunks; `base+offset`
   folded into the `lui` immediate; epilogue `ld ra` scheduled mid-body.

Classes 1 and 6 both look like build-wide code-generation settings rather than
per-function accidents. Worker B cannot set compiler flags, so both are recorded.

### Standing asks for primary

1. `probe_fm_source.py`'s `WORKSPACE` should be `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`.
2. `WORKER_BRIEF.md` still names the retired `Documents/ChatGPT` root.
3. `layout.tsv` is CRLF-terminated — split rows on `\r\n`.
4. `/root/kh2fm-build/tools/` holds only `build_elf.py`, `common.py`, `objdiff.py`.
   There is no `tools/kh2-reference/` subdirectory, so mount the ELF from
   `/root/kh2fm-build/SLPM_666.75`.
5. Dump-script clones inherit the previous round's output filenames; sed `r19_` → `r21_`,
   not just `r20_` → `r21_`.

## Round 22 — 16 of 24, best rate so far

| round | claimed | exact | closed |
|---|---|---|---|
| 19 | 16 | 6 | yes |
| 20 | 16 | 0 | yes |
| 21 | 19 | 12 | yes |
| 22 | 24 | **16** | yes |

Cumulative worker-B byte-exact recoveries: **124** (scanned from
`recovery-experiments/fm_worker_b_round*_solved.verification.json`, requiring
`exact_match && boundary_agreement && compiled_size == target_size` and a present `_solved.cpp`).

### What produced the rate

The picker gained three exclusions for classes already proven unreachable on this compiler:

- `sd s8,<sp>` anywhere — the frame-pointer idiom, 19 members. Round 20 scored **0/16** with a
  batch dominated by this class; excluding it is the single largest change.
- `movz` / `movn` — the round-21 if-conversion refusal.
- `lq` / `sq` — the quad struct-copy class, 5 members.

Candidate list then sorted no-branch bodies first (the round-12 shape). Duplicate detection from
`r22_range_hashes.txt` **before writing any source** found a five-member byte-identical family and
one pair, so 24 targets needed 19 sources. This is the round-20 post-mortem applied in advance.

### Exact (16)

00174d98, 00188bb0, 0019d748, 001a1018, 001b7f88, 001e2998, 001ea928 (72 B each);
002ba0b0, 002ba0f8, 002bd260, 002c5418, 002cff98, 002cffe0, 0031eb68, 003218c8, 00324938 (68 B each).
Every one has a `_solved.cpp` and its own re-run proof.

Mechanisms worth carrying: a **32-bit return type** keeps the 16-byte frame where a `u64` spelling
widened it to 32 (worth three targets in the 002ba0b0 family); a **named pointer temp** stops GCC
folding a double indirection (001ea928, and round 21's 00174858); **three named variables** keep a
masked value in its own register instead of folding it into the boolean (0019d748).

### Two new compiler-level classes for primary

1. **Store reordering** — GCC 3.2 emits consecutive same-base stores in reverse source order and
   **ignores `volatile`** on them. 002e5f70 tried ascending, descending, partly volatile and fully
   volatile: 5, 6, 4 and 5 differing words, never the target order. Same in 0019da20 and 002c1a58.
2. **Inconsistent `lui`/`lw` pair** — when a target's hi half and signed lo half imply *different*
   addresses, no single declared value reproduces it. 0022b7f0 wants `lui 0x34` with `lw -13580`:
   those halves together are `0x33caf4`, but declaring `0x33caf4` emits `lui 0x33`. First seen on
   0020f118 in round 14, now a minimal confirmed case.

Together with the existing `$v0`-vs-`$t7` scratch choice, prologue sink and frame-pointer classes,
this is now six code-generation settings that look build-wide rather than per-function. Worker B
cannot set compiler flags.

### Process notes

- Three v02 files were never created (a Python assertion aborted a generator mid-script) and a
  non-composable replace helper silently dropped a fix, so one variant probed identically to its
  predecessor. **Confirm the variant file exists before reading its probe output.**
- Taking the address of a global declared only by `asm(".globl …")` fails to compile; a matching
  `extern` of the right type is required. Three sources this round.
- Reading the immediate off `dis.py` rather than recomputing it fixed 00188bb0 and 001ea928. Both
  had been one or several words away purely on my own arithmetic — the round-21 trap, repeated.

## Round 23 (worker B, isolated)

4 of 22 claimed ranges recovered byte-exact. Deliverables are
`recovery-experiments/fm_worker_b_round23_<addr>_solved.cpp` with their own
`.verification.json` (`exact_match: true`, `boundary_agreement: true`, 0 differing
words), re-run from the delivered copy.

| round | claimed | exact |
|---|---|---|
| 22 | 24 | 16 |
| 23 | 22 | 4 |

Recovered: 002f1808, 0031cd90, 00322d70, 00325aa0 (all 72/72).

### CORRECTION — the symbol page rule is TWO-CASE, not one

Earlier rounds of this report state that the page bias first seen in round 15 was
an artifact and that the rule is simply truncating. **Round 23 disproved that.**
The high half depends on how the symbol is reached:

- reached by `lw` / `sw` — the high half **truncates**: `hi == V >> 16`
  (round 16's 001d6538);
- used as an **address**, materialised `lui` + `addiu` — the assembler's `%hi` is
  conservative and **rounds**: `hi == (V + 0x8000) >> 16` (round 15).

0031cd90 is the proof. Symbol `0x36eb98` emits `lui 0x37` because its low half
`0xeb98` is `>= 0x8000`; declaring `0x35eb98` gives the target's `lui 0x36` +
`addiu -5224` and the target is exact. 00325aa0 needed no adjustment — both of its
low halves fall below `0x8000`.

### Two more reusable levers

- **Epilogue restore placement.** The vtable setters want `ld ra,8(sp)` between the
  second `lui` and the second `addiu`; GCC puts it after the store. One
  `asm volatile ("" ::: "memory")` immediately before the final store pins it in the
  right slot — the same lever that fixed 002cf3f8 in round 21. Worth three targets.
- **`0x4000`-style constants.** The target materialises 0x4000 as `lui`, so it must
  be spelled as a symbol address; a plain literal becomes `addiu`. Neither spelling
  produced the target on 002be770, which is recorded open.

### Open classes this round

- **Empty-body frame (2 members, not reachable).** 001003b0/00101d38 are 20-byte
  bodies containing only a frame. GCC 3.2 gives a function with no work no frame at
  all; the inline-asm fallback is rejected by this assembler. Recorded rather than
  counted — hand-writing the instructions is not a recovery.
- 002ef708 (4 words): the target materialises two byte-store addresses in two
  registers, each with its own `lui`; GCC reuses one. `volatile`, a memory barrier
  and named `volatile` pointers all left it unchanged.
- 00271828 (2 words): GCC strength-reduces a table index, swapping the
  `sll`/`addu` pair against the `lw`. Three differently-shaped attempts leave the
  same two words differing.
- Ten targets (002f3a70, 00308018, 00310048, 001145b0, 00138140, 00143348,
  0014a138, 00158450, 001584f8, 00160ac0) have no source written; they are
  unstarted, not blocked.

### Note on this round's process

Three of the misses were my own errors rather than compiler behaviour:
`param_1[0x162]` written against a `u32` parameter (a compile error that first
read as a link failure), a "fix" that regressed its own predecessor, and the
truncating-only page rule above. The picker lesson from round 20 — screen for
byte-identical duplicates from the range hashes *before* writing sources — was
applied up front and cut 22 targets to 19 sources.

Cumulative worker-B byte-exact recoveries: **128** (scanned from
`recovery-experiments/fm_worker_b_round*_solved.verification.json` for
`exact_match && boundary_agreement && compiled_size == target_size` with the
`_solved.cpp` present).

## Round 24 (worker B, isolated)

5 of 16 claimed ranges recovered byte-exact, each delivered as
`recovery-experiments/fm_worker_b_round24_<addr>_solved.cpp` with its own
`.verification.json` re-run from the copy. Recovered: 001c0ce8, 002db808, 002db858,
002ed2b0, 002ed300 (all 76/76).

| round | claimed | exact |
|---|---|---|
| 23 | 22 | 4 |
| 24 | 16 | 5 |

### Mechanisms

- **One-word misses are usually the tail call.** Every 72/76 result in this batch was
  GCC turning the final call into a sibling tail call and dropping `ld ra`; a
  trailing `asm volatile ("")` fixed all six at once. Lever already recorded in
  round 8 — the round-20 post-mortem ("apply what you already know") is what
  surfaced it.
- **Register barrier on a masked boolean** (001c0ce8):
  `asm volatile ("" : "+r"(uVar1))` on the result of an AND stops GCC rewriting
  `(x & 0x80) != 0` into `sra`+`andi`. **This does not generalise to round 19's
  `lhu` sign-extension family** — retried on 001bb9b0, 001bbec0 and 001bbf00, all
  three stayed at 68/64 or worse. Specific to the boolean-and form.
- **Seven-argument dispatch, exact first try** (002ed2b0/002ed300): the argument
  list comes from reading the target's register shuffle, not the decompilation.
  Third independent confirmation after round 21's 00158050 and 002ba3b8.

### Open

0017a6c8 (60/76), 001c2c98/001c2ce8 (2 words, store transposition), 002007e0/00209e80
(3 words, folded indirection), 00252710 (72/76), 002956c0 (2 words, return value
shifted in `$v0`), and three not attempted (00224cf0 jump table, 003015a8 and
00307f90 large varargs-style frames).

### Picker limitation worth recording

The picker tags (NO-BRANCH and friends) are derived from the decompiled
pseudocode, not from the instruction words. 0017a6c8 carried a NO-BRANCH tag and
is the worst result in the batch — the machine code plainly branches. Treat the tag
as weak evidence when selecting a batch.

Four of this round's variants regressed against their own predecessors and are
recorded that way rather than quietly replaced.

Cumulative worker-B byte-exact recoveries: **133** (per round: r2 4, r3 3, r4 5,
r5 5, r6 2, r7 8, r8 8, r9 5, r10 5, r11 6, r12 4, r13 6, r14 2, r15 6, r16 6,
r17 7, r18 8, r19 6, r21 12, r22 16, r23 4, r24 5).

## Round 25 (worker B, isolated) — INCOMPLETE, 0 of 16

3 targets attempted, 13 not started. Written up as incomplete rather than closed.

| round | claimed | exact |
|---|---|---|
| 24 | 16 | 5 |
| 25 | 16 | 0 (3 attempted) |

**Negative finding worth keeping:** a global whose *page* is materialised once
into a callee-saved register and reloaded through it is not reproducible in C.
Neither the plain `volatile u32 DAT` spelling (GCC re-emits the `lui` per access,
104/80 on 001b43e0) nor `volatile u32 *p = &DAT` (GCC folds the offset into the
pointer, `addiu s0,t7,-29520`) produces the target's `lui s0,page` + `lw off(s0)`.
Same family as round 7's 00308cd0 and round 11's 0030a2d0; add it to the parked list.

**Assessment of the batch itself:** round 25 scored 0 of 3 attempted where round 24
scored 5 of 16 with the same four exclusions. Filtering known-bad classes does not
make the remainder reliably easier — the survivors are dominated by callee-saved
page registers and explicit `mult`. A future picker should also exclude bodies that
materialise a global page into `s0`/`s1`.

Caveat on the evidence: 001b5a10 v03 and 001b43e0 v03 are my own errors (a dropped
call-result assignment), not findings, and are marked as such in the round report.

## Round 26 (worker B, isolated) — 1 of 16, INCOMPLETE

All 16 ranges verified (range-hash + layout) against ELF sha256 d869ce4b...bc87
before any source was written; no byte-identical duplicates. FIFTH picker
exclusion added (`page-register-s0s1`), candidates 740 -> 634.

**Recovered (1), each re-proved from the delivered copy**
(exact_match true, boundary_agreement true, 0 diffs):
- `00281008` (80/80 v02) -> `fm_worker_b_round26_00281008_solved.cpp`
  Load the slot into a named temp, THEN advance the pointer, inside the
  do-while. The target loads first and leaves the advance in the branch
  delay slot; advancing first makes GCC hoist the increment above the load.

**Attempted, not converted (3)**
- `002e2d88` 80/80 4 words - store order (target `sb` then `sw`; GCC
  reverses), which also drags `ld s1`/`ld s2` out of order. v02 regressed.
  Round-22 class at TWO stores; the current `store-run-reorder` exclusion
  only fires at 3+.
- `0031b070` 80/80 6 words (v02 4) - vtable setter, page materialised twice.
- `002bd788` 76/80 19 words - same page-twice pattern plus round 25's finding.

**Dump-script defect (fixed).** `r26_dump_orig.py` was cloned by sed'ing
`r25_`->`r26_` and `round-25`->`round-26`, but the docker invocation still
passed `round-25/r26_ranges.txt` as `objdump_orig_inner.sh $1`, producing a
191-byte "No such file or directory" disasm. Fixed the path argument and
regenerated 12231 bytes for all 16. Generalisation: a clone inherits the
prior round's output FILENAMES *and* its path ARGUMENTS.

**Picker judgement.** Round 25 scored 0/3 where round 24 scored 5/16 under
the same four earlier exclusions, so survival rate is NOT monotonic in the
number of exclusions - filtering also strips the easy generic shapes. This
batch did improve (all four v01 within 4-19 words) even though only one
converted. Measure the rate; do not assume it.

**Cumulative worker-B byte-exact recoveries: 134** (scan
`recovery-experiments/fm_worker_b_round*_solved.verification.json` for
exact_match && boundary_agreement && compiled_size == target_size with the
`_solved.cpp` present).

## Rounds 25 & 26 completed (worker B)

Rounds 25 and 26 taken from partial to fully attempted. **No new recoveries; cumulative stays 134.**

**Round 25 closed at 0 of 16** (10 attempted, 6 not started). Negative finding retained: a global whose
PAGE is materialised once into a callee-saved register and reloaded through it is not reproducible in C
(plain volatile re-emits the lui per access; pointer form folds the offset into the pointer).
**Round 26 closed at 1 of 16** — 00281008 80/80, banked earlier — with 9 attempted and 7 not started.
00244a10/0024ad50 recorded as unresolved on integrity grounds: the beqzl delay slot sets s0=1
unconditionally while the branch skips into the epilogue, so the intended C cannot be stated with
enough confidence and tuning against it would manufacture a false mechanism.

**Main finding: survival rate is NOT monotonic in the number of exclusions.** Round 25 scored 0/3 under
the same four exclusions round 24 used for 5/16. Round 26's fifth exclusion improved the *band* (all
first attempts 4-19 words) but only 1 of 9 converted. Measure the rate each round.

**Two picker gaps, both actionable:**
1. `store-run-reorder` fires at 3+ consecutive same-base stores; observed at 2 (002e2d88). Widen to 2.
2. No screen for branch-structure idioms. Once the leftovers were worked, the dominant shape across
   BOTH rounds was beql/beqzl tail skips, a value held live across a branch, and multi-word stack
   arrays built then passed by address. That is a class, not bad luck, and it is unfiltered.

Full report: `worker-b/HANDOFF-REPORT.md`.

