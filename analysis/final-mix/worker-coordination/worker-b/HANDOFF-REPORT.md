# Worker B — Session Report (rounds 25 & 26 completed)

**Scope of this report:** rounds 25 and 26 taken from partial to fully attempted.
**Cumulative byte-exact recoveries: 134** (scan `recovery-experiments/fm_worker_b_round*_solved.verification.json`
for `exact_match && boundary_agreement && compiled_size == target_size` with `_solved.cpp` present).

| round | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
|---|---|---|---|---|---|---|---|
| recovered | 0 | 12 | **16** | 4 | 5 | **0** | 1 |

Round 22 (16/24) remains the best rate. **Nothing new was recovered in this stretch** — one round-26
deliverable (00281008) was already banked; the work here was finishing the two incomplete rounds.
Both are now **closed as attempted, with every unstarted target either worked or explained.**

---

## Round 25 — 0 of 16, closed

Ten targets attempted (was 3), six never started. Every range hash and layout verified OK.

**Negative finding (the round's real result):** a global whose *page* is materialised once into a
callee-saved register and reloaded through it is not reproducible in C.
- `volatile u32 DAT;` → GCC re-emits the `lui` per access.
- `volatile u32 *p = &DAT;` → GCC folds the offset into the pointer (`addiu s0,t7,-29520`)
  where the target keeps `lui s0,page` + `lw off(s0)`.

Targets: 001b43e0, 001b5a10, 001bd8c8 (attempted); 00308cd0 (r7), 0030a2d0 (r11) from earlier rounds.
Belongs on the parked-class list.

| target | best | notes |
|---|---|---|
| 00310130 / 003102e0 | 68/76 (v01) | 4-member family, see below |
| 003103f8 / 00310560 | not probed | identical body, differing only in the middle callee |
| 001bdcd0 | 72/80, 9 words | closest of the round; nested `beqz` on two predicates |
| 0023d260 | 84/80, 12 words | body grew past target: 3 void calls + byte/word stores |
| 002421e8 | 64/80, 14 words | `andi 1` then `andi 0xff` no-op pair not reproduced |
| 00103500 | 68/80, 15 words | set-if-absent loop, two globals |

**The four-member family (00310130/003102e0/003103f8/00310560)** is the instructive failure. All four
are the same body with a different middle callee, so one pattern covers four targets — good leverage,
and it still failed twice. v01 wrote the natural C and GCC merged the value the target keeps **live
in `s1` across the branch**, giving a 16-byte frame against the target's 48. v02 split the return into
two exits to force the value to stay live; the body grew to 84 bytes instead. Recorded as
branch-lifetime, not as a compiler quirk.

---

## Round 26 — 1 of 16, closed

**Delivered: 00281008, 80/80 byte-exact**, re-proved from the delivered copy.

```c
do { uVar1 = *puVar1; puVar1 = (u32 *)((u8 *)uVar1 + 20);
     if (uVar1 != 0) func_001a17c8(uVar1); iVar1--; } while (iVar1 >= 0);
```

Mechanism: **load the slot into a named temp, THEN advance the pointer.** The target loads first and
leaves the advance in the branch delay slot; advancing first makes GCC hoist the increment above the
load so the advance becomes the delay-slot body. Worth one word swapped, four offsets differ.

Nine attempted, seven not started.

| target | best | notes |
|---|---|---|
| 002bd788 | 76/80, 19 | same page materialised twice — round-25 page class |
| 0031b070 | 80/80, **4** | 4 consecutive same-base stores + memory barrier |
| 002e2d88 | 80/80, **4** | 2 stores, opposite order; also drags `ld s1`/`ld s2` out of order |
| 002ef660 | 76/80, 13 | 4 byte stores in shift order — store-run-reorder family |
| 0024e008 | 84/80, 16 | table-select-by-global; body grew |
| 00294480 | 64/80, 18 | branch-likely tail with a duplicated load in the delay slot |
| 00244a10 / 0024ad50 | 72/80, 9 | **semantics ambiguous — see below** |

**00244a10 / 0024ad50 are recorded as unresolved on integrity grounds, not difficulty.** The `beqzl`
delay slot sets `s0 = 1` unconditionally while the branch itself skips past the epilogue's tail into
`ld ra`, so on the taken path the return value is whatever the callee left in `v0`. I could not state
the intended C with enough confidence to call the mismatch evidence, so I did not tune against it.
Guessing here would have manufactured a false "mechanism".

---

## The finding that matters most

**Survival rate is NOT monotonic in the number of exclusions.**

Round 25 scored **0 of 3 attempted** under exactly the four exclusions round 24 used for **5 of 16**.
Round 26's fifth exclusion (`page-register-s0s1`) did improve the *band* — all first attempts landed
within 4–19 words — but only 1 of 9 converted. Each filter removes a bad class and also removes the
easy generic shapes, so what survives skews toward harder register-allocation idioms.

**Measure the rate every round. Do not assume each added exclusion is a net win.**

### Two concrete picker gaps, both from this stretch

1. **`store-run-reorder` fires at 3+ consecutive same-base stores; observed at 2** (002e2d88).
   Widen to 2 — one-line change.
2. **No screen for branch-structure idioms.** Once the leftovers were worked, the dominant shape across
   *both* rounds was: `beql`/`beqzl` tail skips, a value held live across a branch, and multi-word
   stack arrays built then passed by address (00192818/00192940 do six `lw` + six `sw`). That is a
   class, not bad luck, and it is unfiltered.

### Standing picker caveats

- **Tags are weak evidence.** NO-BRANCH etc. come from decompiled pseudocode, not instruction words.
  0017a6c8 carried a NO-BRANCH tag and was round 24's worst result.
- **Always screen `rN_range_hashes.txt` for byte-identical duplicates before writing any source.**
  Recent rounds needed 16 targets from 13 sources, 24 from 19, 22 from 19.

---

## Mechanisms worth carrying forward

1. **32-bit return types keep the 16-byte frame.** A `u64` spelling widened it to 32 (3 targets, 002ba0b0 family).
2. **Vtable-setter recipe**, exact on 5 byte-identical members:
   `*(u32*)param_1 = (u32)(long)&SYM; func_A(...); func_B(...); asm volatile("");`
   The trailing empty asm stops GCC tail-calling the last call.
3. **Symbol page rule is TWO-CASE, not one.** Reached by `lw`/`sw`, `hi` **truncates** (`V >> 16`).
   Used as an **address**, the assembler's `%hi` is conservative and **rounds** (`(V + 0x8000) >> 16`).
   Round 23 disproved the earlier "truncation only" reading — the biased-looking evidence was real.
4. **Epilogue restore placement:** one `asm volatile ("" ::: "memory")` immediately before the final
   store pins `ld ra` in the right slot (3 targets, round 23).
5. **Named variables block folding** — a masked value stays in `$t7` instead of collapsing into the
   boolean (0019d748); a named pointer temp stops a double indirection folding (001ea928).
6. **Trailing `asm volatile ("")`** defeats a tail call of the final call (6 one-word misses, round 24).
7. **Named temp before a pointer advance** pins load-then-advance ordering (00281008, round 26).
8. **Register barrier on a masked boolean:** `asm volatile ("" : "+r"(uVar1))` stops GCC rewriting
   `(x & 0x80) != 0` into `sra`+`andi`. **Does not generalise** — retried on round 19's `lhu` family,
   all three stayed at 68/64 or worse. Form-specific.

---

## Parked / unreachable classes

- global PAGE materialised into s0/s1 and reloaded through it (001b43e0, 001b5a10, 001bd8c8, 00308cd0, 0030a2d0)
- three or more consecutive same-base stores/loads — GCC reverses their order, ignores `volatile`
- inconsistent `lui`/`lw` halves that no single declared value produces (0022b7f0)
- value held live across a branch in a specific callee-saved register (00310xxx family)
- empty body containing only a frame — GCC gives a function with no work no frame, and the inline-asm
  fallback is rejected by this assembler (`Error: illegal operands 'sd $ra,0($sp)'`).
  Hand-writing instructions is **not** a recovery.
- prologue sink; dead spills; saved-register-count mismatches

---

## Process notes

- **A cloned dump script inherits the prior round's output filenames AND its path arguments** —
  sed on the `rN_` prefix fixes neither. `r26_orig_disasm.txt` was 191 bytes of an error because the
  clone still passed `round-25/r26_ranges.txt`. `objdump_orig_inner.sh` takes the list as `$1`, so the
  fault is in the **caller**. Cost one wasted run.
- Confirm a variant file exists before reading its probe output — an aborted generator once left a
  "fix" file missing while its probe line was still logged.
- Taking `&GLOBAL` when the global is declared only by `asm(".globl …")` fails to compile; a matching
  `extern` of the right type is required. Three times this session — the most common link failure.
- Read the immediate off `worker-coordination/worker-b/round-13/dis.py <verification.json>` rather
  than recomputing it; two "fixes" were purely my own arithmetic.
- `r5_cmp.py`'s "orig" column is byte-reversed and a size mismatch cascades into fake diffs.
- Symbol names must be `func_` + exactly 8 hex digits (pad `0x1e2a568` → `func_01e2a568`). 9-digit
  names fail to auto-define and the link dies with `undefined reference`.
- Deliverable = `_solved.cpp` **plus its own verification json re-run from the copy**. The flag
  fields live at `rows[0]`, not at the top level of the json.
- **Mark your own bad variants as not-evidence.** Two round-25 v03 files were my errors (dropped
  call-result assignments); they are flagged so they can't later be misread as compiler findings.

---

## For primary — outstanding

1. Probe harness `WORKSPACE` should be `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; it still points at the retired `Documents/ChatGPT` root.
2. `WORKER_BRIEF.md` still names the retired root.
3. `layout.tsv` is **CRLF-terminated** — split on `\r\n` or every read carries a stray `\r`.
4. Mount the ELF from `/root/kh2fm-build/SLPM_666.75`; there is no `tools/kh2-reference/` under the stage.
5. Dump-script clones need both the filename and the path argument fixed.
6. Picker: widen `store-run-reorder` from 3 to 2; add a screen for branch-structure idioms.

---

## Suggested next round (27)

Start from round 26's picker with (a) `store-run-reorder` at 2 and (b) a new
`branch-lifetime` exclusion, then take targets in a **single shape family** — the four-member
`00310xxx` attempt showed that one pattern covering four targets is the best leverage available,
even when it fails. Round 26's remaining seven: 002d28f8, 0030ec50, 00172fb0, 00187b90, 0018d738,
001b6ab8, 001bc6a8.