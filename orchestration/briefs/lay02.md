# lay02: specialist recovery, layout and ABI family

| Field | Value |
| --- | --- |
| WP | lay02 |
| Model | opus |
| Worker id | orch1-lay02 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\lay02` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/lay02` |
| Queues, in order | `abi-layout`, `aggregate-abi-layout`, `constructor-buffer-alias`, `constructor-final-store-alias`, `initialization-store-groups`, `table-initializer-layout`, `teardown-global-allocation`, `variadic-frame-layout`, `sdk-frame-abi`, `context-save-runtime`, `indexed-header-copy` |
| K (targets to claim) | 6 |
| Version budget per target | 12, and stop after 3 versions without improvement (R7) |
| Size rule | none (do not release for size) |
| Depends on | nothing |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Steps

1. R0.
2. Repeat R1 to R10 until you have claimed K targets and each one is submitted or blocked. Every target in these queues was blocked before: R2 requires you to read its blocker report. Your first change must be the report's "next hypothesis" unless the report shows it was already tried; then take the next cookbook change for the symptom.
3. When you block again, use the consolidated specialty from the R9 table (not the old queue name), so the next specialist sees one queue per symptom.
4. R11.

## Notes for this WP

- K is a hard limit on claims: count them in PROGRESS.md and write the WP report right after the K-th target is resolved. Never claim again an address you blocked in this WP. Write source files without a byte-order mark (use the Write tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
- Pattern found by lay01 (store-order): a non-volatile `asm("" : "+m"(field) ...)` whose output names a field that is stored again later is deleted as a dead store and has no effect; the `+m` output must name a field that is not rewritten afterwards (fixed 00137c50).
- The queue can hand an address you just blocked straight back to you (it happened to brl01 and brl02). If a claim returns an address you blocked in this WP, release it at once (`recovery_queue.py release --address <A> --token <TOKEN>`), do not count it toward K, and continue with the next queue in your list.
