# Review of nm06
Reviewer: orchestrator (no submissions, so no reviewer agent was needed). Reviewed 2026-10-13 (UTC). Mechanical check: review-auto-1.json (0 submitted, 4 blocked reports).
Overall: nothing to merge

| Address | Result | Recount (differing words per version) | Note |
| --- | --- | --- | --- |
| 001b6d88 | blocked (store-order) | 13, 8, 2, 2, 8, 2 | Best v3 at 2, tying rec87 v3; within R7. |
| 001b0498 | blocked (branch-layout) | 16, 6, 9, 6, 3, 3, 9, 3 | Best v5 at 3, tying rec82 v4; 8-version budget. |
| 001ad158 | blocked (register-allocation) | 2, 2, 11, 23 | Best v1 at 2, tying nm05 v3; within R7. |
| 001ac2a8 | blocked (register-allocation) | 2, 2, 2, 10 | Best v1 at 2, tying the earlier best; within R7. |

The queue shows all four as ready in their specialty queues with no owner. The last block command's exit code 255 did not stop the block from being recorded.
These four have now had two or three retries each and stay at 2 to 3 words. They are candidates for an opus specialist, not for another sonnet retry.
