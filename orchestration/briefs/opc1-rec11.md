# opc1-rec11: three listed general targets (outside agent, probation run)

| Field | Value |
| --- | --- |
| WP | opc1-rec11 |
| Model | space-bunny (opencode, outside agent) |
| Worker id | opc1-rec11 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\opc1-rec11` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/opc1-rec11` |
| Queue | `general`, claimed only by address (below) |
| Targets, in order | `002803e0` (60 bytes), `002811f8` (60 bytes), `002835d8` (64 bytes) |
| K (targets to claim) | 3 (exactly the three above, nothing else) |
| Version budget per target | 8, and stop after 3 versions without improvement (R7) |
| Size rule | none needed (all three are under 128 bytes) |
| Depends on | nothing |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Why this WP is narrow

This agent's previous run (as a second `orch1-pro02`) held 11 leases at once, 10 of them unlogged, and its report had a wrong start date and "0 best words" on blocked targets. This run is a probation run: three listed targets, one lease at a time, and a report that must match the queue exactly. A clean run moves the agent to normal T1 briefs.

## Steps

1. R0. Your WP directory is new and empty. If any `PROGRESS.md` other than your own exists anywhere, it is not yours: never read or resume another worker's progress log.
2. For each address in the order above:
   1. Lease check (required before every claim): `python -I Codex\orchestration\tools\orch.py leases`. Count the entries whose `owner` is `opc1-rec11`. It must be 0. If it is not 0, do not claim: finish (submit, block or release) the target you hold first.
   2. Claim exactly that address, one only:
      `python Public\tools\kh2-audit\recovery_queue.py claim --worker opc1-rec11 --queue general --count 1 --address <A>`
      Never use a `--count` other than 1. Never claim without `--address`.
   3. Write the claim line in PROGRESS.md at once (R1 format), then follow R2 to R10 for that target.
   4. If the claim returns no lease, write `not available <A>` in PROGRESS.md and go to the next address.
3. After the third address is resolved: run the lease check once more (it must show no `opc1-rec11` lease), then R11.

## Report rules (the orchestrator checks every line against the queue and your files)

- Started: the `WP start (UTC)` from your launch prompt, not a guess.
- Best words: the differing-word count printed by `kh2w.py diff` for your best version. A blocked target never has 0 (0 means exact, and exact means submitted).
- Versions: the number of `_v<N>.cpp` files you probed for that target.
- Mention every claim you made, including any you released.

## Notes for this WP

- Write source files without a byte-order mark (use your file-writing tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
- Do not edit any file outside your WP directory, and do not change any queue entry except through claim, heartbeat, submit, block and release for your own leases.
