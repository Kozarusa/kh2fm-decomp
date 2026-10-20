# Review of rec135
Reviewer: GPT-6 inherited, independent reviewer. Reviewed 2026-10-14T01:24:05Z. Mechanical check: review-auto-2.json (5 PASS, 0 FAIL, 6 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 00227cd8 | MERGE | v1 independently matches all 14 own-target words (56 bytes); ordinary bounded search over 96 records with 40-byte stride. |
| 0022afa0 | MERGE | v4 independently matches all 17 own-target words (68 bytes); the initialized numeric $f0 float binding and initialized pointer guard each have a separate same-line why comment. |
| 0022b558 | MERGE | v3 independently matches all 26 own-target words (104 bytes); the initialized numeric $17 object binding preserves the object across both calls; the initialized global pointer guard has its own why comment. |
| 0022cea0 | MERGE | v3 independently matches all 30 own-target words (120 bytes); the initialized numeric $17 object binding has its own why comment; signed halfword and unsigned byte reads, early return, and both tail-call paths agree with the packet. |
| 0022d820 | MERGE | v1 independently matches all 23 own-target words (92 bytes); ordinary 32-entry callback loop advances by two pointer slots, calls table slot 8, and clears each non-null entry. |
| 0022e0a8 | DO NOT MERGE | Correctly blocked, not submitted. Earliest minimum is v4: three differing words at indices 21, 23, 24; 100/100 bytes. |

Source and evidence audit: I read all five submitted C++ files, their own packets, submission reports and verification JSONs, plus WP-REPORT.md and PROGRESS.md. Each submitted source hash matches its proof. I independently decoded the own packet's instruction words to little-endian bytes and compared them with target_hex for all 19 proofs; every target matches its own packet. I independently compared compiled_hex and target_hex in four-byte words, counting missing words as differences. All five submitted proofs have zero differences and exact full acceptance sizes, totaling 440 bytes. Each source contains one function; external declarations and type declarations precede it, and nothing follows it. There are no forbidden decompiler names, instruction-emitting asm, bytecode tricks, data-to-code casts, or unassigned reads. The indirect callback in 0022d820 is an ordinary typed table call. Every binding and every empty guard has its own same-line why comment. The stricter empty-asm rule is satisfied without an exception. The inferred callees are reported as provisional; the copied declaration patterns agree with the named accepted callers.

Spot check: 0022afa0 v4 diff shows Differing words: 0 (yes). I ran kh2w.py diff and LOOKED at the complete 17-row original/compiled listing, including mtc1 to $f0, cvt.s.w, mul.s, cvt.w.s, mfc1, and the tail jump and delay slot; every row matches.

Budget audit: K6 is satisfied by six numbered claims, with five submitted and one blocked; there is no seventh claim. All 19 version proofs have matching source hashes and own-target bytes. Independent differing-word counts are:

| Address | Counts in version order | Versions / budget | Final best |
| --- | --- | --- | --- |
| 00227cd8 | 0 | 1 / 8 | v1, 0 |
| 0022afa0 | 10, 6, 6, 0 | 4 / 8 | v4, 0 |
| 0022b558 | 11, 6, 0 | 3 / 8 | v3, 0 |
| 0022cea0 | 30, 30, 0 | 3 / 8 | v3, 0 |
| 0022d820 | 0 | 1 / 8 | v1, 0 |
| 0022e0a8 | 14, 14, 13, 3, 3, 3, 4 | 7 / 8 | v4, 3 |

Strict R7 is satisfied. In particular, 0022e0a8 v4 resets the streak to zero; v5 and v6 tie the best, and v7 regresses, producing streaks 1, 2, 3. The worker stops at v7, before the separate eight-version ceiling. The report names earliest best v4, not v7. The first differing word is 0022e0fc: original 11e2fff8 versus compiled 15e2fff2. The remaining differences are 0022e104: 1000fff1 versus 1000fff7, and 0022e108: 0200202d versus dfb00000. These support the branch-layout classification.

Blocked reports: 1 checked, 0 incomplete. 0022e0a8-BLOCKED.md contains all six R9 template lines (heading plus five fields), the correct range, versions, earliest best and sizes, first difference, changes and counts, strict stopping reason, and a non-empty untried C9 volatile-read hypothesis. The next hypothesis is a proposal, not proven evidence.

Outside-WP flags: all six paths below are parent-owned orchestration changes according to the explicit review assignment, not worker changes. No additional outside path was flagged, and there is no shared-file rejection.

Mechanical output:
```text
PASS 0022cea0 120 bytes exact; source orch1_rec135_0022cea0_v3.cpp
PASS 00227cd8 56 bytes exact; source orch1_rec135_00227cd8_v1.cpp
PASS 0022afa0 68 bytes exact; source orch1_rec135_0022afa0_v4.cpp
PASS 0022d820 92 bytes exact; source orch1_rec135_0022d820_v1.cpp
PASS 0022b558 104 bytes exact; source orch1_rec135_0022b558_v3.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm18.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/tools/gpt6_context.py
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec135\review-auto-2.json
```

Only the mechanical checker output and this REVIEW.md were written during review. No probe, build, queue mutation, integration, external transmission, deletion, or tool/compiler configuration change was performed.
