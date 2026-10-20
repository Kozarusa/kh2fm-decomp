# Round 26 (worker B, isolated) — 1 of 16, INCOMPLETE

Targets claimed: 16, all range-hash + layout verified against the ELF
sha256 d869ce4b...bc87 **before any source was written**. No byte-identical
duplicates in this batch.

## Recovered (1)

| addr | size | variant | mechanism |
|------|------|---------|-----------|
| 00281008 | 80/80 | v02 | load-then-advance in a do-while |

`fm_worker_b_round26_00281008_solved.cpp`, re-proved from the delivered copy:
exact_match true, boundary_agreement true, differing_words 0.

**Mechanism.** The loop is `do { slot = *p; p += 20; if (slot) f(slot); } while (--i >= 0)`.
The target emits the load *first* and leaves the pointer advance in the
branch delay slot. Written the natural way (advance, then dereference) GCC
hoists the increment above the load and the advance lands in the delay slot
instead — one word swapped, and the body then differs at four offsets.
Holding the slot in a **named temp** and only then advancing the pointer is
what pins the order.

## Attempted, not converted (3)

- **002e2d88** — 80/80, 4 words. STORE ORDER: target emits `sb(280)` then
  `sw(276)`; GCC emits `sw` then `sb`, and the same reordering drags
  `ld s1`/`ld s2` into the wrong order. v02 (volatile typed pointers) made
  it worse, 5 diffs. Round 22's class, now seen at two stores rather than
  three — the current `store-run-reorder` exclusion only fires at 3+.
- **0031b070** — 80/80, 6 words (v02 4). Vtable setter with the round-23
  memory barrier; page materialised twice.
- **002bd788** — 76/80, 19 words. Same page-twice pattern, plus the round-25
  negative finding.

## Dump-script defect (fixed, worth propagating)

`r26_dump_orig.py` was cloned by sed'ing `r25_`→`r26_` and
`round-25`→`round-26`, but the docker invocation still passed
`round-25/r26_ranges.txt` as `objdump_orig_inner.sh $1`.
`r26_orig_disasm.txt` came out as 191 bytes of
`No such file or directory`. Fixed the argument; regenerated 12231 bytes
covering all 16.

**Generalisation of the known clone lesson:** a clone inherits the prior
round's output *filenames* **and** its path *arguments*. Sed on the `rN_`
prefix alone fixes neither.

## Picker

FIFTH exclusion added: `page-register-s0s1` — a `lui` whose target register
is s0 (16) or s1 (17). Candidates 740 → 634.

Motivation: round 25 scored 0/3 where round 24 scored 5/16 under the *same*
four earlier exclusions. Survival rate is **not** monotonic in the number of
exclusions — filtering also strips the easy generic shapes.

The batch did improve: all four v01 sources landed within 4–19 words, far
better than round 25's, even though only one converted. Treat the rate as a
signal to measure, not an assumption.

## Standing asks to primary

1. probe harness `WORKSPACE` should be `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`
2. `WORKER_BRIEF.md` still names the retired `Documents/ChatGPT` root
3. `layout.tsv` is CRLF-terminated — split on `\r\n`
4. mount the ELF from `/root/kh2fm-build/SLPM_666.75`
5. dump-script clones inherit prior output filenames **and path arguments**
