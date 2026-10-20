# brl03: specialist recovery, branch and lifetime family

| Field | Value |
| --- | --- |
| WP | brl03 |
| Model | opus |
| Worker id | orch1-brl03 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\brl03` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/brl03` |
| Queues, in order | `branch-layout`, `register-allocation`, `store-order`, `float-transport`, `address-materialization`, `branch-delay-address-lifetime`, `branch-delay-lifetime`, `float-branch-layout`, `float-condition-block-layout`, `sdk-list-branch-layout`, `sdk-range-guard-branch-layout`, `control-transfer`, `dispatch-result-lifetime`, `float-predicate-lifetimes`, `float-result-register-allocation`, `bitmap-index-register-lifetime`, `linked-list-memory-lifetime`, `allocator-pointer-lifetimes`, `argument-register-scheduling`, `callback-address-scheduling`, `conditional-argument-transport`, `digit-loop-scheduling`, `indexed-bit-scheduling`, `indexed-table-scheduling`, `header-mirror-scheduling`, `float-conversion-scheduling` |
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
- Pattern found by brl01 (branch-layout): the compiler folds 0/1 results into `slt`/`movz`, or merges zero stores, unless each false path has its own `= 0` or `return 0` arm. Use if / else-if / else with explicit 0 arms, `if (a && b) return 1; return 0;`, or direct global stores in both arms. A `while (ptr != 0) { ...; return ...; }` form places the guarded call block after the epilogue.
- Pattern found by lay01 (store-order): a non-volatile `asm("" : "+m"(field) ...)` whose output names a field that is stored again later is deleted as a dead store and has no effect. The `+m` output must name a field that is not rewritten afterwards (this fixed 00137c50; see `orch-shift1\lay01\`). `001c2c98` v4 is down to one swapped `ori`/`addiu` pair with every store exact; its twin `001c2ce8` should take the same recipe.
- The queue can hand an address you just blocked straight back to you (it happened to brl01 and brl02). If a claim returns an address you blocked in this WP, release it at once (`recovery_queue.py release --address <A> --token <TOKEN>`), do not count it toward K, and continue with the next queue in your list.
- Carried from brl02: `0011f270` (register-allocation, 128 bytes) is 2 words from exact; only the `addu` operand order differs. Read `orch-shift1rl021f270-BLOCKED.md` first if you are served it.
