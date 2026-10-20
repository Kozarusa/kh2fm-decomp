# fam01: sibling family 00139858-00139ab0 (six 116-byte loop functions)

| Field | Value |
| --- | --- |
| WP | fam01 |
| Model | sonnet |
| Worker id | orch1-fam01 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\fam01` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/fam01` |
| Queue | `boundary-review`, claimed only by address (below) |
| Targets, in order | `00139858`, `001398d0`, `00139948`, `001399c0`, `00139a38`, `00139ab0` |
| K (targets to claim) | 6 (exactly the six above, nothing else) |
| Version budget per target | 8, and stop after 3 versions without improvement (R7) |
| Size rule | none needed (each is 116 bytes) |
| Depends on | nothing |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Why this WP exists

The outside agent cdx1-rec10 blocked these six into `boundary-review` under the old R3 wording, with zero versions. The orchestrator checked all six packets: each is a complete function (prologue, a `jr ra` in the middle, loop blocks after the epilogue that end in a `b` back into the range, no `.word`). R3 now says such ranges are attempted. They are siblings 0x78 bytes apart with the same shape, so the recipe that solves the first should carry over to the others with only the global and the callee changed.

## Steps

1. R0.
2. For each address in the order above, claim it with
   `python Public\tools\kh2-audit\recovery_queue.py claim --worker orch1-fam01 --queue boundary-review --count 1 --address <A>`
   and then follow R2 to R10. Do not apply the R3 boundary row to these six; the orchestrator has checked them. The packet names the earlier blocker report; it only says "R3 boundary", and nothing was tried.
3. After the first exact match, start each later sibling from that exact source (change only the name, the `D_` global and the callee to match its packet).
4. If a claim returns no lease, write `not available <A>` in PROGRESS.md and go to the next address.
5. R11.

## Notes for this WP

- K is a hard limit on claims: count them in PROGRESS.md and write the WP report right after the K-th target is resolved. Never claim again an address you blocked in this WP. Write source files without a byte-order mark (use the Write tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
