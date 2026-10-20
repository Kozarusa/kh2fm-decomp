# pro02: specialist recovery, prologue/epilogue family

| Field | Value |
| --- | --- |
| WP | pro02 |
| Model | opus |
| Worker id | orch1-pro02 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\pro02` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/pro02` |
| Queues, in order | `prologue-epilogue`, `address-prologue-scheduling`, `byte-prologue-scheduling`, `float-address-prologue`, `prologue-load-scheduling`, `prologue-save-order`, `prologue-scheduling`, `sdk-callback-prologue`, `sdk-prologue-operation-scheduling`, `wrapper-prologue-save-order`, `primary-store-epilogues`, `float-epilogues`, `float-boolean-epilogue`, `tail-call-frame-elision`, `loop-save-order` |
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
