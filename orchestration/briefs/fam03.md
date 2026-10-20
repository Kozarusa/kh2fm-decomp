# fam03: four list-walk siblings of 00161248 (apply the known exact form)

| Field | Value |
| --- | --- |
| WP | fam03 |
| Model | sonnet |
| Worker id | orch1-fam03 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\fam03` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/fam03` |
| Targets, in order (queue to claim from) | `00160e50`, `00160f10`, `00161030`, `001611a8` (all `branch-layout`) |
| K (targets to claim) | 4 (exactly the four above, nothing else) |
| Version budget per target | 8, and stop after 3 versions without improvement (R7) |
| Size rule | none needed (all are 128 bytes or less) |
| Depends on | rec26 |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Why this WP exists

rec26 blocked these four at 3 to 4 differing words, then found on its fifth target, `00161248`, the form that reproduces their shared loop idiom (a list walk whose head is a branch-likely `bnezl`): a GNU statement expression with `goto` inside the `while` condition. The exact source is `orch-shift1\rec26\orch1_rec26_00161248_v5.cpp` (read-only for you). The best earlier attempt for each target is in `orch-shift1\rec26\` (its BLOCKED file names it).

## Steps

1. R0.
2. For each address in the order above:
   1. Claim it, one only: `python Public\tools\kh2-audit\recovery_queue.py claim --worker orch1-fam03 --queue branch-layout --count 1 --address <A>`. If it returns no lease, write `not available <A>` in PROGRESS.md and go to the next address.
   2. R2 (packet). Read rec26's best attempt for this address and its BLOCKED file.
   3. Version 1: take rec26's best attempt for this address and rewrite only its list-walk loop into the statement-expression form of `00161248` v5 (the `if (node != 0) goto advance; next = <head>; goto done; advance: next = <next field>; done: node = next; next != 0;` condition). Keep the rest of the body, the globals, the callee, the field offsets and the `// why:` comment.
   4. Probe (R5). Exact: submit (R8). Not exact: continue with R6 and the cookbook from that version.
3. R11.

## Notes for this WP

- K is a hard limit on claims: count them in PROGRESS.md and write the WP report right after the K-th target is resolved. Never claim again an address you blocked in this WP. Write source files without a byte-order mark (use the Write tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
- The queue can hand an address you just blocked straight back to you. If a claim returns an address you blocked in this WP, release it at once, do not count it, and continue.
