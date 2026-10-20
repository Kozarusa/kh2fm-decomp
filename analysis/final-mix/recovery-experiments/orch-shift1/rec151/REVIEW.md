# Review of rec151
Reviewer: GPT-6 inherited. Reviewed 2026-10-15T20:30:02Z. Mechanical check: review-auto-2.json (3 PASS, 0 FAIL, 7 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 002519d0 | MERGE | v1 exact 52 bytes; returns the first nonzero predicate result or the second callee result, preserving both outgoing-v0 paths. |
| 00251e90 | MERGE | v1 exact 52 bytes; returns the three-argument tail callee result and preserves stride-8 indexing. |
| 00252618 | MERGE | v2 exact 72 bytes; returns the tail callee result; stride-6 Entry preserves the signed halfword at offset 2; accepted declarations match packet siblings. |

Spot check: 00252618 diff shows Differing words: 0 (yes).
Blocked reports: 3 checked, 0 incomplete (00251ec8, 00252020, 00252710).

Evidence audit: all 9 saved source/proof pairs have matching SHA-256 hashes, one row naming the correct address, and target bytes matching the original packet. Independently recounted differing words, including size tails:

| Address | Version counts | Earliest best | R7 disposition |
| --- | --- | --- | --- |
| 002519d0 | 0 | v1: 0 | Exact immediately. |
| 00251e90 | 0 | v1: 0 | Exact immediately. |
| 00251ec8 | No versions | None | Conservative R12 ABI block. |
| 00252020 | No versions | None | Conservative R12 ABI block. |
| 00252618 | 2,0 | v2: 0 | Exact within budget. |
| 00252710 | 11,8,8,8,8 | v2: 8 | Stopped at streak 3 after v5. |

K6 is respected: six numbered claims, three submissions totaling 176 bytes and three blocked targets. All source versions inspected. Every named-baseline diff changes one control: 00252618 v2 introduces a coherent typed stride-6 lookup representation; 00252710 v2 adds only s0 binding, v3 adds only the result guard, v4 adds only a separate checked temporary, and v5 adds only its guard. Earlier bindings, guards, types and conditions remain intact. No instruction-emitting assembly occurs. The blocked target's initialized binding and empty guards each have an individual why comment. All candidates contain one ordinary C++ function, declarations before it, no forbidden names or executable-data substitutions.

Return contracts checked against every original exit, including blocked candidates. 002519d0 preserves func_00139d78's nonzero v0 and otherwise returns func_0028acc8's v0. 00251e90 directly returns func_0028dbf8's v0. Both 00252618 versions return func_0028dac8's v0. Every 00252710 version returns zero on the zero-byte path and the normalized callee predicate otherwise, matching original s0 initialization and sltu conversion. No candidate discards a result with void or invents a zero for an untouched entry-v0 path.

Callee declarations match packet siblings where available: func_00139d78 matches fm_oct7_extended_recovered_00.cpp; func_002891e8 matches fm_primary_capacity_recovered_00303c48.cpp; func_0028dac8 matches fm_primary_dependencyfamily_recovered_00272a00.cpp; func_001a6d08 matches fm_primary_clearsequence_recovered_001d7940.cpp. For callees without a listed accepted declaration, parameters and integer results follow the target's call sites. func_00252110 receives a fresh a0 argument in 00252618, whereas 00252710 does not set a fresh argument; their locally inferred declarations remain provisional, not an established shared ABI.

All three R9 reports contain the six required lines and nonempty next hypotheses. 00252710 correctly names earliest best v2 at 8 words, 80/76 bytes, and its first branch-target difference. The two zero-version blockers accurately distinguish unavailable proof data from a measured result:

- 00251ec8: null global returns untouched entry v0; failed predicate returns its v0; success tail returns func_0023f5b8's result.
- 00252020: null global returns untouched entry v0; nonzero isCreated returns its v0; zero item count returns isCreated's zero; the successful tail returns func_00288e88's result.

Their conservative R12 ABI blocks avoid both result-discarding void signatures and fabricated null-path zeros. The proposed defined empty-output entry-register capture is documented as a future hypothesis, not approved here. No new version, probe, or exception to R4.8 is authorized. Previously accepted void-policy inconsistencies remain the separate root audit's open work; they supply no exception for this WP. No never-returning-loop target was present.

All seven outside-WP flags below are root documentation or the root-commissioned independent return-contract audit, as explicitly attributed in the review assignment. No worker outside-WP mutation identified. No probes, builds, queue mutations or new candidate versions performed.

Mechanical output:
```text
PASS 002519d0 52 bytes exact; source orch1_rec151_002519d0_v1.cpp
PASS 00251e90 52 bytes exact; source orch1_rec151_00251e90_v1.cpp
PASS 00252618 72 bytes exact; source orch1_rec151_00252618_v2.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/STATUS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/GPT6-MEMORY.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/return-contract-audit-2026-10-15.md
Blocked reports: 3. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec151\review-auto-2.json
```
