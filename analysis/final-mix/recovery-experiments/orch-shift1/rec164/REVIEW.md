# Review of rec164
Reviewer: GPT-6 inherited. Reviewed 2026-10-16T20:46:24Z. Mechanical check: review-auto-2.json (3 PASS, 0 FAIL, 9 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 00285d18 | MERGE | 60 bytes exact; sentinel scan returns explicit 0/1; ordinary C++ without assembly. |
| 002865d0 | DO NOT MERGE | 84 bytes exact and return flow preserved, but u32 func_002859a0(void) does not copy the packet siblings' s32 return declaration as R4.5 requires. |
| 00287430 | DO NOT MERGE | 124 bytes exact and return flow preserved, but the same callee declaration mismatch violates R4.5. |

Spot check: 00287430 diff shows Differing words: 0 (yes); mechanically PASS but rejected for declaration reuse.
Blocked reports: 3 checked, 0 incomplete.
Follow-up: Root will return both rejected addresses unaccepted through O4 and integrate only eligible 00285d18 (60 bytes). No correction or additional version is authorized in closed rec164 during the usage wrap-up. A distinct future FIX WP must first copy/probe the preserved best source, then isolate the callee declaration correction to s32 func_002859a0(void) in v2 and obtain independent review. Preserve all existing sources/proofs; this reviewer performed no correction or new probe.

Declaration evidence: all five packet-named siblings declare func_002859a0 returning s32. fm_primary_dependencyfamily_recovered_00272a00.cpp:11, its 00272a70 sibling:11, fm_primary_oneword_recovered_002908f0.cpp:14 and fm_primary_threeword_recovered_0028e710.cpp:11 use (void); fm_primary_threeword_recovered_0026dcb8.cpp:11 uses (...). Neither submitted u32 declaration copies one exactly. R4.5 says to copy the declaration exactly when an accepted caller is listed. Same-width ABI and exact bytes do not waive this explicit requirement; no binary malfunction is claimed.

Return-contract audit: 00285d18 writes v0=0 in the first branch delay slot, returns 1 in the match-return delay slot and retains zero on sentinel exhaustion. Source expresses all exits. 002865d0 calls 002859a0, adds 204 to v0 and never changes it afterward; conditional bit store and epilogue preserve that adjusted result, which source returns. 00287430 similarly adds 164 to v0 and preserves it through its conditional bit store and all exits. Its source v0 binding is initialized by the call and adjusted afterward; no uninitialized read. No submitted original writes f0 or consumes a float return. No outgoing result is discarded or unspecified entry-v0 value invented; the two rejections concern declaration reuse, not these return-flow checks.

Blocked contracts: 00283e48 returns either 002835a8 or 00283900 tail-call result. 002853b8's final callee is 0023fa90, not 0028fa90: packet instructions at 00285400 and fm_primary_width_recovered_02.cpp show that address and an accepted void definition. Its outgoing result is not overwritten by the wrapper; zero-version ABI blocking is conservative. 00287b30 tail-calls 00287c78; packet-named fm_primary_queueomega_recovered_00287bd0.cpp and fm_primary_queuetheta_recovered_00287b98.cpp declare it void, with different parameter forms. The worker blocked before drafting rather than inventing an accepted-void exception. No accepted source was changed.

All submitted filenames/sizes agree with WP-REPORT.md, total 268 bytes before these source-policy rejections. Each has one ordinary C++ function, allowed include, declarations before the function and descriptive names. 002865d0 uses an initialized numeric $14 word binding and one explained empty combined/word dependency guard. 00287430 uses an initialized numeric $2 result binding and one explained empty dependency guard. Every binding/guard has its own why comment. No emitted instructions, pasted body, byte arrays or prohibited trickery.

Proof audit: independently verified all 20 source SHA-256 hashes, target/compiled sizes, exactness flags and differing-word counts against original ELF slices; original ELF SHA-256 agrees. Counts: 00283e48 v1-v7 18,14,18,13,18,17,16, all 112/112; 00285d18 v1-v5 19,19,19,10,0 at 80/60,80/60,80/60,56/60,60/60; 002865d0 v1-v4 4,3,4,0, all 84/84; 00287430 v1-v4 23,18,11,0 at 128/124,128/124,124/124,124/124.

R6 audit: every successor checked against its named baseline. 00283e48 v2 adds one row guard; v3 binds row relative to v2; v4 adds nextValue temporary relative to v2 without reversing comparison operands; v5 binds index relative to v4; v6 adds only next-index guard relative to v4; v7 reorders next/current declarations relative to v4. 00285d18 v2 adds read volatility relative to v1; v3 independently widens argument relative to v1; v4 independently changes cursor representation to index relative to v1; v5 changes early return to shared result/break. 002865d0 v2 adds one combined-result guard, v3 binds word, v4 adds word dependency to that existing guard. 00287430 v2 splits decrement, v3 adds only result binding, v4 adds one guard. No temporary/binding bundle, operand reversal or multiple-site guard insertion found.

Six claims satisfy K6; version counts 7,0,5,4,4,0 remain within budget8. 00283e48 earliest best is v4, 13 words at 112/112; v5-v7 worsen and reach strict R7 streak3. All R9 reports contain six prescribed lines and non-empty next hypotheses. WP report completed before the parent's fresh92% wrap-up; no later claim/version is present. Closed-WP extra work requires explicit authorization.

Outside-WP attribution: all nine flagged paths below are root orchestration work or the separately authorized handoff-writing role, confirmed by the assignment. No rec164 worker-attributed shared-file mutation found.

Mechanical output:
PASS 002865d0 84 bytes exact; source orch1_rec164_002865d0_v4.cpp
PASS 00285d18 60 bytes exact; source orch1_rec164_00285d18_v5.cpp
PASS 00287430 124 bytes exact; source orch1_rec164_00287430_v4.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/GPT6-MEMORY.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm26.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec166.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec167.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/tools/record_checkpoint_docs.py
Blocked reports: 3. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec164\review-auto-2.json
