# Round 22 — worker B, isolated proposals

**16 of 24 byte-exact.** Best rate of any round so far.

## What made this round work

The picker carried over from round 21 and gained three exclusions for classes already proven
unreachable on this compiler:

| exclusion | class it removes | why |
|---|---|---|
| `sd s8,<sp>` anywhere in the body | frame-pointer idiom (19 members) | round 20 scored 0/16, fifteen of them this class |
| `movz` / `movn` | if-conversion refusal (4 members) | round 21; GCC 3.2 will not build a predicate into `movn` |
| `lq` / `sq` | quad struct copy (5 members) | keeps landing in a different temp |

With those gone the top of the candidate list was no-branch framed bodies, which is the round-12
shape that scored 4/12 where round 6 scored 2/10. The batch sorted no-branch first and took 24.

**Duplicate screening before writing sources.** The `r22_dump_orig.py` range hashes showed
`002c1a58`/`002c1aa0` identical and five bodies (`002cff98`, `002cffe0`, `0031eb68`, `003218c8`,
`00324938`) all identical. So 24 targets needed **19 sources**. This is the round-20 post-mortem
applied in advance instead of after.

## Exact (16)

All have `recovery-experiments/fm_worker_b_round22_<addr>_solved.cpp` plus their own
`…_solved.verification.json`, each re-run from the copy: `exact_match: true`,
`boundary_agreement: true`, zero differing words.

| address | bytes | variant | mechanism |
|---|---|---|---|
| 00174d98 | 72/72 | v01 | symbol address materialised `lui`+`addiu`, held in `$s0` across both calls |
| 00188bb0 | 72/72 | v05 | byte load + `sltiu` guard; DAT declared `0x33f210` |
| 0019d748 | 72/72 | v03 | three named variables so the masked value keeps `$t7` |
| 001a1018 | 72/72 | v01 | call result live across two calls stays in `$s0` |
| 001b7f88 | 72/72 | v03 | byte flag as `volatile u8`; DAT declared `0x1d58cb8` |
| 001e2998 | 72/72 | v01 | global read into a local before the guarded pair of calls |
| 001ea928 | 72/72 | v03 | named pointer temp at `param_1+0xa0` indexed `[3]` |
| 002ba0b0 | 68/68 | v02 | symbol addresses; 32-bit return keeps the 16-byte frame |
| 002ba0f8 | 68/68 | v02 | same template |
| 002bd260 | 68/68 | v02 | same template |
| 002c5418 | 68/68 | v01 | four-argument call, one literal plus one symbol address |
| 002cff98 | 68/68 | v02 | vtable setter + trailing empty `asm` |
| 002cffe0 | 68/68 | v02 | same source (byte-identical body) |
| 0031eb68 | 68/68 | v02 | same source (byte-identical body) |
| 003218c8 | 68/68 | v02 | same source (byte-identical body) |
| 00324938 | 68/68 | v02 | same source (byte-identical body) |

One template reproducing a five-member family exactly on the second attempt is the strongest
evidence available that the recovered spelling is the original and not something fitted to bytes.

## Two new compiler-level classes

**Store reordering** — GCC 3.2 emits consecutive same-base stores in reverse source order and does
not respect `volatile` on them. `002e5f70` was tried ascending, descending, partly volatile and
fully volatile (5, 6, 4 and 5 differing words); none produced the target order. `0019da20` is the
same shape. `002c1a58` is a byte store that will not stay below the word stores (four variants,
best 2 words).

**Inconsistent `lui`/`lw` pair** — a target pair whose hi half and signed lo half imply *different*
addresses cannot be produced from any single declared value. `0022b7f0` wants `lui 0x34` together
with `lw -13580(t7)`: those halves together are `0x33caf4`, but declaring `0x33caf4` emits
`lui 0x33`. First seen on `0020f118` in round 14; now confirmed with a minimal case.

Also joined the existing **prologue-sink** class: `002a9ce8`.

## Process notes

- Three v02 files were never created — a Python assertion aborted the generator mid-script — and a
  non-composable replace helper silently dropped a fix from `00188bb0`, so v02 probed identically
  to v01. Confirm a variant file exists before reading its probe output.
- Taking the address of a global declared only by `asm(".globl …")` fails to compile; a matching
  `extern` of the right type is required. Three separate sources this round.
- Reading the immediate off `dis.py` instead of recomputing it fixed `00188bb0` and `001ea928`.
  Both were one or several words away purely on my own arithmetic — the same trap as round 21.

## Unresolved (8)

`002a9ce8` (15 words, prologue sink), `002c1a58` (8, store reordering), `002c1aa0` (byte-identical
to `002c1a58`, no separate source), `002e5f70` (5, store reordering), `002eee68` (16, dead spills),
`0019da20` (5, store reordering), `001d7ec8` (16, one saved register versus two),
`0022b7f0` (1 word, inconsistent `lui`/`lw` pair).

Full detail with every attempted variant is in `claim.json` under `round22_result`.