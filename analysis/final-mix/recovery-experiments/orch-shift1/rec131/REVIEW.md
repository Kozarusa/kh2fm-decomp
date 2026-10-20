# Review of rec131
Reviewer: sonnet. Reviewed 2026-10-13 (UTC). Mechanical check: review-auto-1.json (3 PASS, 0 FAIL, FLAG paths are orchestrator files).
Overall: RETURN (one target); the other two MERGE
(Saved by the orchestrator from the reviewer's reply; the reviewer did not write files.)

| Address | Verdict | Reason |
| --- | --- | --- |
| 0021f5d8 | MERGE | Exact 72 bytes; report agrees (v4); one empty "+r" guard with a same-line why comment (C11d). |
| 00220c88 | RETURN | Exact 104 bytes (v4), but it reads `register u8* entry asm("$2");` with no initialiser to pick up a value the caller leaves in v0. Reading a never-assigned register-asm local is undefined behaviour; C11c covers binding a computed value, and v0 is not an EABI argument register. No accepted precedent. Needs a user ruling before this idiom is allowed; until then it goes back to general. |
| 00224780 | MERGE | Exact 88 bytes; report agrees (v2); plain C++, no asm. |

Spot check: 00220c88 diff shows Differing words: 0 (orchestrator and reviewer); the match is real, the problem is only the idiom.
Blocked reports: 3 checked, 0 incomplete, within R7.
- 00222898: vu-macro (R3, not probed); the packet has lqc2, vmulax, vmaddaz, vdiv, qmtc2, cfc2, sqc2 and no accepted sibling.
- 002233f0: best v2 at 1 word, trap only (`break` against `teq`).
- 00223448: best v1 at 3 words (two argument move orders plus the trap).
