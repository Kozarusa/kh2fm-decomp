# cdx1-rec12: general queue recovery (outside agent)

| Field | Value |
| --- | --- |
| WP | cdx1-rec12 |
| Model | GPT-6 (Codex CLI, outside agent, user's choice) |
| Worker id | cdx1-rec12 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\cdx1-rec12` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/cdx1-rec12` |
| Queues, in order | `general` |
| K (targets to claim) | 6 |
| Version budget per target | 8, and stop after 3 versions without improvement (R7) |
| Size rule | Release targets over 128 bytes (R3) |
| Depends on | nothing |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Steps

1. R0.
2. Repeat R1 to R10 until you have claimed K targets and each one is submitted, blocked or released.
3. R11: write the WP report and reply with it.

## Notes for this WP

- The general queue serves the most promising targets first (priority 1: earlier equal-size proposals within three differing words; then ranges up to 128 bytes). Many have earlier attempts: R4 tells you to start from the best one.
- Released targets (over 128 bytes) do not count toward K.

- K is a hard limit on claims: count them in PROGRESS.md and write the WP report right after the K-th target is resolved. Never claim again an address you blocked in this WP. Write source files without a byte-order mark (use the Write tool or `-Encoding ascii`; PowerShell `Set-Content` adds one).
- Outside-agent note: your previous WP (cdx1-rec10) first lost time to sandbox limits on WSL, then blocked six functions under an old boundary rule that has since been fixed (R3 now says to attempt ranges whose `jr ra` is mid-range with loop blocks after it, and never-returning loops). Run the self-test probe in `agents/LAUNCH.md` step 4 before your first claim; if it cannot reach WSL, stop and report that instead of guessing.
- Reserved addresses: `002803e0`, `002811f8` and `002835d8` belong to another outside agent's WP (opc1-rec11). If a claim returns one of them, release it at once, do not count it, and claim again.
