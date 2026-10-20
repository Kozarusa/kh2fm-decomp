# Round 25 — worker B (isolated) — INCOMPLETE

**0 of 16 recovered.** 3 targets attempted, 13 not started. This report is written
as an incomplete round, not a closed one.

All 16 ranges were verified before any source was written (ELF sha256
`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`, per-range
sha256, start/end/size agreement with `/root/kh2fm-build/layout.tsv`).

## Attempted

| address | best | measured | reason |
|---|---|---|---|
| 001b43e0 | v02 | 104/80 | target materialises the global page once into `s0`; GCC re-emits the `lui` per access |
| 001b5a10 | v02 | 80/80 | 13 words; GCC folds the page offset into the pointer |
| 001bd8c8 | v02 | 80/80 | 16 words; the target uses an explicit `mult` for the index scale |

Not started: 00310130, 003102e0, 003103f8, 00310560, 00316d18, 00103500, 0014db78,
00192818, 00192940, 00194980, 001bdcd0, 0023d260, 002421e8.

## Negative finding

A global whose **page** is materialised once into a callee-saved register and
reloaded through it is not reproduced by either spelling available in C:

- plain `volatile u32 DAT` — GCC re-emits the `lui` for each access (104/80);
- `volatile u32 *p = (volatile u32 *)&DAT` — GCC folds the offset into the
  pointer (`addiu s0,t7,-29520`) where the target keeps `lui s0,page` + `lw off(s0)`.

This is the same family as round 7's 00308cd0 and round 11's 0030a2d0 and belongs
on the parked-class list.

One caveat on my own evidence: v03 of 001b43e0 and 001b5a10 are **not** findings —
I dropped the assignment of the call result in 001b5a10 v03 and produced a
semantically different function. Only v02 is worth reading.

## Assessment of the batch

Round 25 scored 0 of 3 attempted where round 24 scored 5 of 16 with the same four
exclusions. Filtering the known-bad classes does not make the remainder reliably
easier; the survivors are dominated by callee-saved page registers and explicit
`mult`. A future picker should also exclude bodies that materialise a global page
into `s0`/`s1`.

## Standing materialised constants

1. The probe harness should stage the reference ELF at
   `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; `WORKSPACE` currently points at the
   retired `Documents/ChatGPT` root.
2. `layout.tsv` is CRLF-terminated — split on `\r\n`.
3. Dump-script clones inherit the previous round's output filenames.
