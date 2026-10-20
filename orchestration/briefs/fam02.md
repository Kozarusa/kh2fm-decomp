# fam02: the five remaining siblings of 00139ab0 (apply the known exact source)

| Field | Value |
| --- | --- |
| WP | fam02 |
| Model | sonnet |
| Worker id | orch1-fam02 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\fam02` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/fam02` |
| Targets, in order (queue to claim from) | `00139858` (`branch-layout`), `001398d0` (`branch-layout`), `00139948` (`register-allocation`), `001399c0` (`register-allocation`), `00139a38` (`register-allocation`) |
| K (targets to claim) | 5 (exactly the five above, nothing else) |
| Version budget per target | 8, and stop after 3 versions without improvement (R7) |
| Size rule | none needed (each is 116 bytes) |
| Depends on | fam01 |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Why this WP exists

fam01 found the exact source for the last of six sibling functions, `00139ab0`, at its first version, after the five earlier siblings had already been blocked at 2 to 4 differing words. All six have the same 116-byte shape and read the same global `D_00347f80`; they differ in the function name and the callee. The exact source is `orch-shift1\fam01\orch1_fam01_00139ab0_v1.cpp` (read-only for you).

## Steps

1. R0.
2. For each address in the order above:
   1. Claim it, one only: `python Public\tools\kh2-audit\recovery_queue.py claim --worker orch1-fam02 --queue <queue from the table> --count 1 --address <A>`. If it returns no lease, write `not available <A>` in PROGRESS.md and go to the next address.
   2. R2 (packet). Read the packet's callee list and its `D_` annotation.
   3. Version 1 is a copy of the fam01 exact source with only three things changed: the file name, the function name `func_<A>`, and the callee (declaration and call) taken from this address's packet. Keep the struct, the global, the loop and the `// why:` comment exactly. fam01's report lists the expected callees in order: `00139580`, `00139570`, `001395a8`, `00139598`, `001396d0`; the packet wins if it differs.
   4. Probe (R5). Exact: submit (R8). Not exact: continue with R6 and the cookbook from that version.
3. R11.

## Notes for this WP

- K is a hard limit on claims: count them in PROGRESS.md and write the WP report right after the K-th target is resolved. Never claim again an address you blocked in this WP. Write source files without a byte-order mark (use the Write tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
- The queue can hand an address you just blocked straight back to you. If a claim returns an address you blocked in this WP, release it at once, do not count it, and continue.
