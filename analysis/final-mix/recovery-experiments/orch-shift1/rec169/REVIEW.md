# Review of rec169
Reviewer: GPT-6 inherited, independent reviewer. Reviewed 2026-10-17 UTC. Mechanical check: review-auto-3.json (2 PASS, 0 FAIL, 8 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 0028bdb8 | MERGE | v8, 92 bytes exact; all three exits preserve outgoing u32 results; accepted declarations match exactly; shared guarded exit preserves the v6 path effects. |
| 0028cdb8 | MERGE | v6, 124 bytes exact; zero path returns func_00139d78 result, nonzero path returns virtual callback result; declaration matches accepted source exactly; both numeric bindings have individual why comments. |

Spot check: 0028cdb8 diff shows Differing words: 0 (yes).
Blocked reports: 4 checked, 0 incomplete.

Return/declaration audit: 0028bdb8 returns func_0028be58 on its zero branch, func_0028e4c8 on the equal branch, and func_0028e560 through the tail path. The three declarations match packet-named fm_primary_dependencyfamily_recovered_00272a00.cpp literally. 0028cdb8 returns the first callee's v0 when zero; otherwise it replaces result with the indirect callback's v0 before the bit store and return. Its func_00139d78 declaration matches fm_oct7_extended_recovered_00.cpp. Neither submitted function fabricates a zero, discards an outgoing result, emits instruction assembly, reads an uninitialized register binding, or uses a nullable-pointer fallback with offset arithmetic. Both contain one function, declarations before it, no forbidden names or hidden byte-code reproduction. The indirect callback is an ordinary original vtable dispatch.

Successor audit: Compared every complete successor against its explicitly named baseline. 0028bdb8 v2 binds result, v3 adds the first-exit guard, v4 reverses the first condition with its bodies, v5 adds the second-exit guard, v6 reverses the second condition with its bodies, v7 removes only the first guard. v8 correctly branches from v6, not v7: two guarded returns become one shared guarded exit, with one guard still executed on each original non-tail return path. Numeric binding, branch conditions, arguments and operands otherwise remain intact. 0028c0a0 v2 reverses final stores from v1; v3 adds volatility from v1 without reordering; v4 adds one memory barrier from v1; v5 adds the color binding from v3 without changing volatile access or store order. 0028cdb8 v2 changes only the second address transport while retaining offset+base operand order; v3 introduces the table temporary; v4 binds table; v5 introduces callback temporary; v6 binds callback. Every binding/guard has its own why comment. No version adds guards at multiple sites.

Budget audit: Six claims, eight/five/six versions for the attempted targets. 0028bdb8 counts 20,21,19,19,11,3,3,0 and 0028cdb8 counts 4,3,3,2,2,0 remain within the strict streak rule. 0028c0a0 counts 5,4,4,7,4: earliest best is v2, and v3-v5 reach streak3, correctly stopping at v5. WP report and blocker select v2, not the later tie.

Blocked evidence: 0028b830 ends with j 00106420, so its outgoing callee result cannot be ignored merely because packet-named fm_primary_orchac_recovered_00123c98.cpp declares void func_00106420(u32*). 0028b940 and 0028b9b0 leave the final jal 0028dfe8 result register untouched through their jr ra exits; packet-named fm_fallback_helpers.cpp defines void func_0028dfe8(u32* object). These are outgoing-callee ABI conflicts under literal R4.3/R4.5, not pure no-call/no-v0/no-f0 leaf cases. Conservative zero-version ABI blocking is justified. All three retain the prescribed R9 fields with explicit not-applicable entries; 0028c0a0 records its best first difference, counts, stopping reason and a nonempty next hypothesis.

Follow-up:
- Correct or annotate WP-REPORT.md Problems: none to disclose the worker's out-of-scope review_wp.py invocation. This violated the manual's explicit command allowlist even though its observed output stayed within the WP. Root reports DEVIATIONS #14 already records the breach and a no-repeat warning. Keep that process record attached to integration; no source rejection is warranted without evidence of source/shared-file mutation. Worker review-auto-1.json is not independent review; this review and review-auto-3.json supply that gate.
- Attribute all eight outside-WP flags to the orchestrator, as explicitly confirmed by root: Codex/orchestration/DEVIATIONS.md, HANDOFF.md, ORCHESTRATION.md, PROGRESS.md, ROSTER.md, briefs/nm28.md, briefs/rec170.md, briefs/rec171.md. No worker-owned shared mutation was established.

Mechanical output:
```text
PASS 0028bdb8 92 bytes exact; source orch1_rec169_0028bdb8_v8.cpp
PASS 0028cdb8 124 bytes exact; source orch1_rec169_0028cdb8_v6.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm28.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec170.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec171.md
Blocked reports: 4. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec169\review-auto-3.json
```
