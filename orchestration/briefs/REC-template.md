# rec<NN>: general queue recovery

| Field | Value |
| --- | --- |
| WP | rec<NN> |
| Model | sonnet |
| Worker id | orch1-rec<NN> |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec<NN>` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/rec<NN>` |
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
- K is a hard limit: every claim attempt, including unavailable, released and reclaims, counts toward K. Stop at K6. Only a lower differing-word count improves the best; ties and errors increment the strict R7 streak. Stop at streak3.
- Before creating each new version, name the exact baseline file and compare the proposed source change against it. Change exactly one intended compiler-significant control, preserving condition shape, volatility, guards and bindings otherwise. Log the baseline and single change.
- Audit every original return path under literal R4.3 before drafting or submitting. Earlier accepted void signatures do not waive that rule (DEVIATIONS #7). Do not discard outgoing callee results or invent zero for untouched entry-v0 paths. Use conservative R12 ABI blocking when the manual cannot represent the contract without an exception.

- R4.3 distinction: a pure leaf range that never sets v0/f0 and has no outgoing callee result may use void exactly as the manual states. Untouched entry registers alone are not a block. Mixed untouched-entry and outgoing-callee-result paths remain unresolved ABI cases. DEVIATIONS #12 records the overblocking correction; do not repeat it.

- Mechanical review belongs to the orchestrator and independent reviewer. Recovery workers must not run review_wp.py or delegate a reviewer; finish the manual source audit and WP report only.

- Every probe invocation consumes its unique version identifier, including a missing-source or compiler failure. Count such failures as strict R7 non-improvements; do not recreate/reprobe the same numbered version after a failed probe. Preserve the error and advance to the next unused name, subject to budget/streak limits. Only the explicit R5 environment retry is exempt. A source-write failure before any probe does not authorize overwriting an existing file or evidence.

- When expressing an original bit shift, preserve defined word-bit transport. A signed left shift with possible negative or overflowing input is not justified by exact bytes; use fitting unsigned transport while preserving the original argument/result extension, or block with evidence. Do not combine this semantic correction with scheduling controls.

- Introducing a temporary, adding a register binding and adding an empty guard are separate controls and require separate saved/probed versions. Do not bundle a supporting temporary with a guard, even when the guard needs an lvalue. Preserve the prior version and count every intermediate non-improvement; DEVIATIONS18 preserves the combined-control violation.

- For a guard insertion, select a unique full source context and confirm exactly one replacement and one added guard site in the complete source diff before probing. Never use a broad replacement that matches several return or assignment sites. DEVIATIONS19 preserves an accidental two-site insertion.

- Guard diff inspection must finish in a separate completed tool call before the probe call. Do not batch diff output and probing in one shell command; buffered output cannot satisfy inspection-before-probe. DEVIATIONS20 preserves the process deviation.

- Emit the entire exec_command result, retaining exit_code and session_id. A completed functions cell can contain a still-running shell session. Poll every session_id until its process finishes before reading generated files, judging empty output, or retrying. DEVIATIONS21 preserves a receipt-loss error; no environment failure may be inferred from output alone.

- Extracting an address temporary must preserve both addition association and operand order. Test reassociation or reversal separately; DEVIATIONS22 preserves a combined-control violation.

- Verify source replacement success and inspect completed proof/diff counts before logging or making the next decision. Failed/no-op attempts still consume versions and non-improvement streaks. DEVIATIONS23 preserves a corrected premature tally.
