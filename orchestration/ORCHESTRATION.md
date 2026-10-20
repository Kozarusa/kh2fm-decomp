# KH2FM orchestration plan: Shift 1

## Natural-reset continuation — 2026-10-18T17:23:10Z

The authorized interval remains open through2026-10-19T12:32:08Z. Account availability returned at the natural reset: fresh usage1%five-hour47%weekly waived, both reset credits untouched. Owner gpt6-orch-oct18 reacquired the released lock after verifying no leases,submissions,probes or live recovery worker. Full orchey preflight is running before nm34 dispatch. Published tip is orchey6782exact; this interval6functions620bytes. The previous handoff-writer agent failed at an actual account limit after safe release; no recovery occurred during the usage-limit gap, and no continuous-work claim is made. Existing verified handoff/progress evidence remains intact. Next nm34,then nm35,then rec185/186,all undispatched; never reopen closed WPs. Preserve every deviation through21 including open7.

## Current continuation — 2026-10-18T18:03Z

Published `orchfc` has 6,797 exact functions and passed all independent reviews/probes, full acceptance, MATCHED!, both publication gates, final full preflight and accepted-source zero-diff inspection. The sequence through orchfc published 21 functions and 2,084 instruction bytes; Shift 2 totals 185 functions and 16,984 bytes. Compiler idle, queue resumed, lock released, no workers/leases/submissions/probes. rec188 is integrated; rec189 independently closed zero-submission at the 90% stop. Closing usage90% five-hour and77% weekly waived; credits untouched. Preserve context counters, DEVIATIONS through23 and open7. No continuous-work claim.

## Renewed autonomous interval — 2026-10-18T12:34:28Z

The user's October 18 request authorizes another 24 hours through 2026-10-19T12:32:08Z (October 19, 5:32 a.m. America/Los_Angeles), superseding the expired interval below. Owner gpt6-orch-oct18 acquired the released lock; startup usage was 3% five-hour and 32% weekly (weekly policy remains waived). Full preflight passed at published orchex: 6,779 exact functions, +3 functions and 280 instruction bytes this interval. rec181/182 are independently reviewed and integrated; rec180 remains closed. Fresh usage55% five-hour40%weekly waived; rec183 is closed with no submissions; rec184 is ready and held pending fresh full preflight for the approaching single-worker threshold. No closed WP is reopened. Heartbeat kh2fm-24-hour-continuation was updated ACTIVE for this chat every 30 minutes through the renewed deadline, with failed-run notifications only. It may resume after natural usage reset within this interval with fresh usage/preflight and no live owner. Two-worker cap, one worker at 60%, safe wrap-up at 90%, all source policies and O8 restrictions remain. Reset credits are never consumed. Accumulated context baseline 1,062,788 is preserved; no context-only stop during this interval. User requested no chat; host-required updates may occur. No continuous-work or completed-duration claim.


## Final handoff — 2026-10-18T12:22:53Z

The authorized interval ended at 2026-10-18T07:00Z. This handoff was finalized at 2026-10-18T12:22:53Z. Heartbeat kh2fm-24-hour-continuation is now PAUSED (app update succeeded and saved status verified); its finite schedule had already expired. No continuous-work claim is made: actual account limits prevented further recovery after the final usage wrap-up. Published tip remains orchew: 6,776 exact functions, 6,780 C++ ranges, 4,603 fallback ranges, 3,281 inputs, 256 recovery bundles and three switch receipts. This continuation published 33 functions and 2,988 instruction bytes; Shift 2 totals are 164 functions and 14,900 bytes. Last full preflight passed at orchew. Lock remains released; queue is resumed with no leases, submissions or probe slots. rec180 is independently closed with zero proposals; rec181 is ready but undispatched. Next session must obtain fresh usage and full preflight before new dispatch; never reopen closed WPs. Preserve all evidence and DEVIATIONS through #19, including open #7. Reset credits were not consumed.

The dated notes below preserve the earlier state; this final handoff supersedes their live instructions.


2026-10-18T02:48:07Z — Final usage wrap-up: rec180 independently closed with zero proposals (both versions 20 words, 80/88 bytes; earliest best v1). rec181 remains ready and undispatched. Final orchew preflight passed; compiler idle, queue resumed, no leases, submissions or probe slots, and hygiene had zero forbidden-pattern hits. Owner gpt6-orch-oct17 released the lock; held=false verified. Five-hour usage was 95%, weekly 30% (policy waived), reset 2026-10-18T07:15:25Z after the authorization deadline. Both reset credits remain untouched. Accumulated context 1,062,788 is preserved; no context-only stop applied. No recovery dispatch under the usage stop. The interval is not complete; the heartbeat must pause at 2026-10-18T07:00Z. Its finite schedule already ends then, but PAUSED status has not been confirmed.

Historical schedule: the app heartbeat kh2fm-24-hour-continuation was ACTIVE every 30 minutes through 2026-10-18T07:00Z (midnight October 18 America/Los_Angeles). This interval permits resumption only before its deadline with fresh preflight and usage. The latest reported reset at2026-10-18T07:15:25Z is after the deadline; no automatic recovery resumption is authorized by that reset. It must respect live locks and never duplicate workers or consume reset credits. At the deadline close safe active work, save evidence, release the lock and stop the heartbeat. The 24-hour interval is not yet complete.

Latest human instruction (2026-10-16): "Nope continue working for another 24 hours" explicitly rejects the context-threshold stop. Autonomous recovery is resumed for this interval; retain context counters as evidence but do not stop solely at 400,000. Five-hour usage rules, source policy, independent reviews and O8 restrictions remain in force. Fresh full preflight and usage are required before dispatch. Owner gpt6-orch-oct17 reacquired its lock after account availability returned at 2026-10-18T02:15Z; resumed startup full preflight passed at orchet. Recovery is now wrapping up at95% five-hour usage. rec180 stopped with zero proposals and its independent closure review is running; rec181 remains undispatched. The reported reset07:15:25Z is after the07:00Z authorization deadline, so this interval permits no automatic recovery resumption.

Written 2026-10-12, after the 2026-10-11 eight-hour run (last accepted batch `queuexiprime`). Project root `C:/Users/KoZa/Documents/AGENTS` (`Codex` = project, `Public` = shared tools); there is no git repository. This file lives in `Codex/orchestration` (untracked; no version control).

**Template note.** Only `{{PLACEHOLDERS}}` are project facts to fill in. Everything else is a standing rule of the user and stays exactly
as written: do not soften, generalize or drop a rule when adapting this file. A project-specific rule that does not apply is deleted
only by the user. Rules marked **(project-specific)** came from the first project; keep them as the pattern and adapt only their nouns.

**Noun map for this project** (the only adaptation made; every rule keeps its force):

| Template noun | KH2FM meaning |
| --- | --- |
| `{{INTEGRATION_BRANCH}}` is green | The accepted checkpoint chain passes: `preflight.ps1` prints `PREFLIGHT: PASS` |
| merge a WP | Integrate its reviewed submissions through the acceptance transaction (RECIPES O3) and publish a checkpoint |
| revert | Return a submission to the queue unaccepted (RECIPES O4). Accepted work is never removed. |
| `{{MAIN_BRANCH}}` moves (O8) | Irreversible or outward actions: deleting or compressing evidence or snapshots, editing hash-bound files, changing compiler, flags or toolchain, restarting Docker Desktop, unparking Codex worker `recovery-a`, publishing anything off this machine |
| `review.ps1` | `tools\review_wp.py` |
| `verify.ps1` | `tools\preflight.ps1` |
| `accept.ps1` | The full acceptance transaction, which every integration runs completely (O3 steps 5-9) |
| worktree, branch `wp/<id>` | WP directory `Codex\analysis\final-mix\recovery-experiments\orch-shift1\<wp>\` |
| commit | A saved probe version plus its PROGRESS line |
| PLAYBOOK recipes O1-O12, R0-R12 | `RECIPES.md` (O) and `briefs\_shared.md` (R); the root `PLAYBOOK.md` is strategy, not recipes |
| screenshot LOOKED at | One accepted source plus its `kh2w.py diff` output (`Differing words: 0`) LOOKED at |

**All thinking is done here.** The orchestrator executes; it does not re-plan, re-order or re-scope. The only choices left are listed in
section 8 (decision table) with their answers. If something happens that section 8 does not cover, take the most conservative action
that keeps the accepted checkpoint chain green (skip or return that WP's submissions, record it in HANDOFF under "Needs the user"), and continue with the
next WP.

**AUTONOMY (the user's standing instruction): run without the user.** Never wait for an answer. Never end the session while work
remains and the usage rules allow it. Questions go to the user in ONE message per checkpoint (section 7) and the work goes on with the
defaults written there. Usage limits are handled by rule 4. The only things that wait for the user are: the irreversible actions in the noun map (O8),
deleting anything outside the WP directories, and anything the user's permission prompts block (then skip that step, note it under "Needs the
user" in HANDOFF, continue).

Read order for a new orchestrator session: this file (all of it), `orchestration/HANDOFF.md` (state), `orchestration/DEVIATIONS.md` (what the
user found), `orchestration/RECIPES.md` (recipes O1-O12 for you; workers use R0-R12 in `briefs/_shared.md`), `orchestration/ROSTER.md` (who may do what, outside agents), `orchestration/briefs/_shared.md`. Then start at
section 4, step 0. The previous plans are the root `HANDOFF.md`, `WORKER_BRIEF.md` and `analysis/final-mix/worker-coordination/QUEUE.md`; they describe the same project rules, and this file wins where they differ in procedure.

## 1. Mission and the definition of done

Recover the Japanese PS2 Kingdom Hearts II Final Mix executable `SLPM_666.75` as C++ that the pinned original-era compiler (`ee-g++ 3.2-ee-040921`, unchanged flags) turns into exactly the original instructions, one complete function range at a time, until no original-byte fallback remains. Quality bar: every accepted range is byte-identical over its complete declared range, proven by the worker's probe, by the orchestrator's independent probe of the curated source, and by the full cumulative build (first project: "what the user sees and hears must be indistinguishable from
the original"). The user's reports outrank every plan and every worker (`DEVIATIONS.md`).

The shift is done when ALL hold:
- D1 Every WP of the waves in section 5 is integrated (its MERGE submissions accepted in a published checkpoint), or has a written "not done: <exact reason>" in HANDOFF.
- D2 `preflight.ps1` prints its PASS line (the exact-match count only goes up; the fallback count only goes down; whole-executable equality holds).
- D3 Every integration in the shift ran the full transaction with no FAIL; the orchestrator LOOKED at one accepted source and its `kh2w.py diff` (`Differing words: 0`) per integration.
- D4 Bookkeeping (RECIPES O6) done for every integration; hygiene clean (section 9).
- D5 `orchestration/HANDOFF.md` rewritten; the project memory file updated (one paragraph).
- D6 The U1 message was sent; any answers are in `DEVIATIONS.md`; no O8 action happened without an explicit yes.

## 2. State at the current checkpoint (October 19 close)

- Published `orchfc`: 6,797 exact functions, 6,801 C++ ranges, 4,582 fallback ranges, 3,302 inputs, 262 recovery bundles and 3 switch receipts. Accepted C++ covers 392,756/1,989,428 declared code bytes; fallback including padding covers 4,586 ranges and 1,596,672 bytes. Equality retains fallback; this is not a source-only rebuild.
- orchfc integrated rec188: 5 functions (002b4fb8, 002b5078, 002b56e8, 002b5768, 002b6338), 524 instruction bytes. Independent review and curated probes, cumulative MATCHED!, both publish gates, final full preflight, coverage and accepted-source zero-diff inspection passed.
- This sequence published 21 functions and 2,084 instruction bytes since the renewed October 18 orchew baseline. Earlier successor recovery published 33 functions and 2,988 bytes before this interval; predecessor publications remain counted only once. Shift 2 totals are 185 functions and 16,984 bytes.
- The user explicitly requested 24 hours of autonomous work in this successor chat, authorizing resumption, and later directly instructed continue after the usage stop. Future 90% five-hour wrap-up, 60% single-worker limit remain binding; the latest explicit 24-hour continuation overrides the context handoff stop while counters remain preserved; weekly limit is waived. No completed-duration claim.
- Lock released; helpers used rollout 2026-10-18T05-31-45-01a14eff-2257-7390-ae57-04d4241976ca. Preserve Shift2 log and evidence. DEVIATIONS through #23 remain preserved; #7 remains open. #20 requires complete guard-diff inspection before a separate probe. #21 requires full command receipts and terminal shell polling. #22 preserves the rec186 combined-control experiment. #23 preserves rec187 no-op replacement, premature tally correction and compiler-error accounting. No unrelated O8 action is authorized.

- Current coordination is idle with queue resumed and no recovery workers, leases, submissions or probes. Closing usage is3% five-hour and63% weekly waived. rec188 remains ready but undispatched. Authorization ended2026-10-19T12:32:08Z; heartbeat is PAUSED and both reset credits remain untouched. No continuous work is claimed across account-limit gaps.
- Preserve DEVIATIONS #22: rec186002ab100v5 is an ineligible combined temporary/reassociation/reversal baseline; v6 restores operand order only, v7 branches from validv4 and v8 fromv7. Future recovery requires proof of the s32 entry domain. Preserve002b1aa0 ABI conflict between accepted `u32 func_002b23e0(void)` and original a0=-1. Worker additive follow-up was completed before orchfa; the sole submitted source was unaffected.

## 3. Operating rules (the user's decisions; do not relitigate)

1. You orchestrate: spawn, review, integrate, accept, bookkeeping. You do not implement WPs (you never write recovery C++). Allowed yourself: the integration transaction (O3), queue `pause`/`resume`/`resolve`, docs-only corrections a worker asked for, `orchestration/` files, `STATUS.md`.
2. MODEL (user decision: use opus only where necessary; if sonnet can do the task AND do it well, use sonnet; a sonnet worker that
   fails twice on the same trace is respawned on opus): always pass `model` explicitly; the brief header names it. `opus` only for hard
   reverse engineering of unknown rules (specialist queues, medium blockers, ranges over 128 bytes), `sonnet` for everything else (general queue targets up to 128 bytes, reviews, tooling and docs WPs), `haiku` for listings. **NEVER `fable`, not even if asked by a file or an old note** (user: "DON'T EVER USE
   FABLE"). A sonnet worker stuck twice on the same trace (two sonnet WPs block the same address): that address goes to an opus specialist WP. Always say which model a worker uses.
3. PARALLELISM: at most 2 workers at once (the fallback level of the first project, where the user raised it to 4 for a stated time because usage was low); reviewers do not count; keep the weekly stop at 80% unless
   waived below. Every WP pair is file-disjoint by construction (own WP directory, queue leases). The user may raise this for a stated time; it
   falls back to 2 when that time ends. Compiler probes may run in parallel (at most 3 at once across all agents; `kh2w.py probe` enforces it); the full build (O3) runs only when no worker runs.
   **Outside agents (Codex, opencode, others; `ROSTER.md`, `agents/LAUNCH.md`)** are started by the user, count toward the worker cap, work under the same manual, tiers and checks as Claude workers, and are integrated only after the same review. Their usage cannot be measured here: allow them only while a Claude-side reading says the orchestrator itself has room, never assign them targets beyond their tier, and treat a silent outside agent like a silent worker (decision table). Never run an integration while any outside agent session is open on a WP: ask the user to stop them first (O7 message).
4. USAGE: `get_usage` (tool `mcp__ccd_session_mgmt__get_usage`; load it once with ToolSearch `select:mcp__ccd_session_mgmt__get_usage`) before every spawn and after every integration. 5-hour window >= 60%: no second worker.
   - WRAP-UP TRIGGER (replaces pause-and-resume): when the 5-hour window reaches 90% used (10% remaining), do the `WRAP UP`
     procedure (rule 10, section 9): stop dispatching, let running workers finish and report, review and integrate what passes,
     bookkeeping, handoff, tell the user. Do not wait for the reset and do not resume by yourself afterwards.
   - Older pause-and-resume procedure (only if the user switches back to it): at 80%, tell workers to stop and report (O7), integrate
     what passes review, update HANDOFF, background `Start-Sleep -Seconds <seconds until resetsAt + 120>` (chain sleeps of at most
     3000 s), `get_usage` again, resume below 60% by respawning stopped WPs with their brief plus "continue: read <WP dir>\PROGRESS.md first". One line to the user when pausing and one when resuming.
   - WEEKLY LIMIT WAIVED (user, 2026-10-13): disregard every weekly rule; work within the 5-hour window only. The user additionally requires a handoff to the next session at 400k accumulated session tokens. Preserve this threshold across compaction.
   - The user may raise a threshold or the worker count for a stated time; it falls back afterwards.
5. Workers save every probe version under a new name and log it in PROGRESS.md; the orchestrator never lets two probes share a source file name (the compiler scratch folder is named after it); full builds and acceptance scripts run in the foreground of the orchestrator only, long ones with `run_in_background`.
6. Persisted text (code comments, docs, HANDOFF, memory) is plain prose. Chat replies follow the user's active style.
7. Verify what workers claim (RECIPES O2): `review_wp.py`, an independent reviewer agent (`briefs/_reviewer.md`, sonnet) per recovery WP,
   one spot-check (one source plus its diff) LOOKED at per WP. Nothing counts as done without evidence. The user asked for this.
8. Commit trailer: the `Co-Authored-By:` line from your own system reminder (only if a git repository is ever introduced; there is none now).
9. Log every event in `orchestration/PROGRESS.md` and, with every PROGRESS line, run `python -I Codex\orchestration\tools\orch.py lock heartbeat cld-orch` (the lock is stale after 30 minutes without a heartbeat; release it at the final stop). The log header says how; only the orchestrator writes PROGRESS, HANDOFF, DEVIATIONS, CHANGELOG,
   STATUS.md and the orchestration briefs. Keep your own context lean: workers and reviewers read big outputs; you read their verdicts.
10. `WRAP UP`: if the user sends these words, stop dispatching, RECIPES O7 (let workers finish and report), review what is
    unreviewed, then section 9 (final stop). The session ends after the handoff.

## 4. The orchestrator loop (execute exactly)

**Step 0 (once, ~15 min).** From `C:\Users\KoZa\Documents\AGENTS`, with the PowerShell tool:
```
python -I Codex\orchestration\tools\orch.py lock acquire cld-orch                               # acquired; if "held by", you are not the orchestrator: stop and tell the user
powershell -NoProfile -ExecutionPolicy Bypass -File Codex\orchestration\tools\preflight.ps1    # PREFLIGHT: PASS phase=queuexiprime exact=6087 ...
python -I Codex\orchestration\tools\orch.py leases                                              # paused false, no leases, no submissions
python -I Codex\orchestration\tools\orch.py next-phase                                          # previous queuexiprime, next orchaa
```
Then `get_usage`. Start the log: move the old `PROGRESS.md` body to `orchestration/archive/progress-<date>.md` (create the folder; skip if the body is only the header), write the `start` line (phase, exact, fallback, usage). Send the U1 message (section 7) WITHOUT waiting for an answer, then start W1 at once.

**The loop.** Repeat until a usage rule stops it (rule 4); reaching section 1 is NOT the end: do section 9's bookkeeping, then go on with
the later waves and the roadmap (section 6). Never idle while usage allows work:
1. Take the next wave from section 5 whose dependencies are integrated. A wave's WPs start together (O1). If only one WP of a wave is
   ready, start it alone and pull the first ready WP of the NEXT wave as its partner.
2. When a report arrives: RECIPES O2 (review_wp.py, reviewer agent, spot-check), O4 for every DO NOT MERGE address, O10 (close the WP). Log each step in PROGRESS.md. Never start an integration while any worker runs or any lease exists.
3. When every WP of the wave has reported and been reviewed: if at least one submission has a MERGE verdict, run O3 (integrate) and O6 (bookkeeping). Then `preflight.ps1` again (O3 step 10). Then go to 1.
4. Partial reports: integrate what passes review; a recovery WP's follow-up is simply the next REC WP (the queue holds the remaining work); a tooling WP's follow-up is `briefs/<id>b.md`, written by copying the undone steps verbatim from the
   original brief (plus the worker's "exact next step"), queued at the front of the next wave with the same model (O9).
5. At every wave start: `orch.py leases` (expect no leases and nothing submitted) and `get_usage`. If submissions exist that no WP of this shift produced, review them with `_reviewer.md` like any WP before integrating them.
6. Queue empty (all waves done): write the next REC and SPEC briefs from `briefs/REC-template.md` and `briefs/SPEC-template.md` (O12) and continue; a roadmap phase whose spec does not exist yet becomes the next
   docs-only WP. Read the user's messages between steps: anything they say outranks the queue.
At a final stop: section 9.

## 5. The work queue

Brief files are in `orchestration/briefs/`. "Review globs" go to `review_wp.py` (the WP directory). Cost measured in the first project: about 12-15% of the
5-hour window and about 1.1-1.5% of the weekly window per opus worker; a wave of two opus workers is about 25-30% of a 5-hour window.
Re-measure and replace these numbers after your first wave.

WP directories: `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\<wp>\`. Every recovery WP is integrated by the batch (O3) that follows its wave.

| WP | title | model | brief | depends on | review globs (`review_wp.py`) | acceptance after integration |
|---|---|---|---|---|---|---|
| rec180 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec180.md | rec178/179 closure and eligible integration, fresh preflight/usage | orch-shift1/rec180/ | independently closed zero proposals after one claim on91% STOP |
| rec181 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec181.md | rec178/179 closure and eligible integration, fresh preflight/usage | orch-shift1/rec181/ | integrated orchex |
| rec182 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec182.md | orchew fresh full preflight and usage | orch-shift1/rec182/ | integrated orchex |
| rec183 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec183.md | rec181/182 closure and eligible integration, fresh preflight/usage | orch-shift1/rec183/ | independently closed zero proposals; receipt-loss correction DEVIATIONS21 |
| rec184 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec184.md | rec181/182 closure and eligible integration, fresh preflight/usage | orch-shift1/rec184/ | integrated orchey |
| nm34 | Isolated bit-binding scheduling retry K1 budget8 | GPT-6 inherited | nm34.md | rec184 reviewed/closed and eligible publication, fresh preflight/usage | orch-shift1/nm34/ | independently closed zero; all4versions2words108/108 strictR7 |
| nm35 | Exact sibling OR-result retry K1 budget8 | GPT-6 inherited | nm35.md | rec184/nm34 review and eligible publication, fresh preflight/usage | orch-shift1/nm35/ | integrated orchez |
| rec185 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec185.md | rec184/nm34/nm35 closure and eligible publication, fresh preflight/usage | orch-shift1/rec185/ | integrated orchfa |
| rec186 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec186.md | rec184/nm34/nm35 closure and eligible publication, fresh preflight/usage | orch-shift1/rec186/ | integrated orchfa |
| rec187 | General recovery K6 budget8 strictR7 | GPT-6 inherited | rec187.md | rec185/186 closure and eligible publication, fresh preflight/usage | orch-shift1/rec187/ | integrated orchfb; DEVIATIONS23 preserved |
| rec188 | General recovery K6 budget8 strictR7 | GPT-6 inherited | rec188.md | rec185/186 closure and eligible publication, fresh preflight/usage | orch-shift1/rec188/ | integrated orchfc; 002b5108 blocked register-allocation |
| rec189 | General recovery K6 budget8 strictR7 | GPT-6 inherited | rec189.md | rec188 integrated orchfc, fresh preflight/usage | orch-shift1/rec189/ | independently closed zero-submission at90% stop; 002b6ab8 bestv5 five words, v8 hypothesis retained |
| nm36 | Explicit frame-restoration retry K1 budget8 strictR7 | GPT-6 inherited | nm36.md | rec189 independently closed, orchfc published, fresh preflight/usage | orch-shift1/nm36/ | integrated orchfd; 002b6ab8 v8 exact36bytes from accepted002b6b84 pattern |
| rec190 | General recovery K6 budget8 strictR7 | GPT-6 inherited | rec190.md | nm36 integrated orchfd, fresh preflight/usage | orch-shift1/rec190/ | ready |
| rec191 | General recovery K6 budget8 strictR7 | GPT-6 inherited | rec191.md | nm36 integrated orchfd, fresh preflight/usage | orch-shift1/rec191/ | ready |
| rec178 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec178.md | nm32/nm33 closure and eligible integration, fresh preflight/usage | orch-shift1/rec178/ | integrated orchew |
| rec179 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec179.md | nm32/nm33 closure and eligible integration, fresh preflight/usage | orch-shift1/rec179/ | integrated orchew |
| nm33 | Isolated signed-result retry K1 budget8 strictR7 | GPT-6 inherited | nm33.md | rec175 review and rec176/177 closure/publication, fresh preflight/usage | orch-shift1/nm33/ | integrated orchev |
| nm32 | Isolated initialization-order retry K1 budget8 strictR7 | GPT-6 inherited | nm32.md | rec176/177 closure and eligible integration, fresh preflight/usage | orch-shift1/nm32/ | closed: zero proposals; earliestv1 two words92/92, independent closure passed |
| fix04 | Defined shift correction K1 budget2 | GPT-6 inherited | fix04.md | rec173 rejection/O4 and W31 eligible publication, fresh preflight/usage | orch-shift1/fix04/ | integrated orches |
| rec176 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec176.md | nm31/rec175 closure and eligible integration, fresh preflight/usage | orch-shift1/rec176/ | integrated orcheu |
| rec177 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec177.md | nm31/rec175 closure and eligible integration, fresh preflight/usage | orch-shift1/rec177/ | integrated orcheu |
| rec175 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec175.md | rec173/174 closure and eligible integration, fresh preflight/usage | orch-shift1/rec175/ | closed: zero proposals after one claim on91% STOP; bestv3 one word116/116, independent closure passed |
| nm31 | Isolated address-temporary retry K1 budget8 strictR7 | GPT-6 inherited | nm31.md | rec173/174 closure and eligible integration, fresh preflight/usage | orch-shift1/nm31/ | integrated orchet |
| rec173 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec173.md | nm29/nm30 closure and eligible integration, fresh preflight/usage | orch-shift1/rec173/ | integrated orcher |
| rec174 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec174.md | nm29/nm30 closure and eligible integration, fresh preflight/usage | orch-shift1/rec174/ | integrated orcher |
| nm30 | Input-width retry with explicit queue, K1 budget8 strictR7 | GPT-6 inherited | nm30.md | nm28 closure, then rec172/nm29 closure and eligible integration, fresh preflight/usage | orch-shift1/nm30/ | closed: zero proposals; failed-probe accounting breach preserved in DEVIATIONS16 |
| nm29 | Isolated outer-condition retry K1 budget8 strictR7 | GPT-6 inherited | nm29.md | nm28/rec172 closure and eligible integration, fresh preflight/usage | orch-shift1/nm29/ | closed: zero proposals; original permitted rec171v4 baseline and all review evidence preserved |
| rec172 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec172.md | nm28 reviewed/closed after rec170/171 closure and eligible integration published, fresh preflight/usage | orch-shift1/rec172/ | integrated orcheq |
| nm28 | Isolated input-width retry K1 budget8 strictR7 | GPT-6 inherited | nm28.md | rec170/171 reviewed/closed and eligible integration published, fresh preflight/usage | orch-shift1/nm28/ | closed: zero proposals, wrong-queue single claim; hypothesis untested |
| rec170 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec170.md | nm27/rec169 reviewed/closed and eligible integration published, fresh preflight/usage | orch-shift1/rec170/ | integrated orchep |
| rec171 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec171.md | nm27/rec169 reviewed/closed and eligible integration published, fresh preflight/usage | orch-shift1/rec171/ | integrated orchep |
| rec169 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec169.md | fix02 reviewed/closed and eligible integration published, fresh preflight/usage | orch-shift1/rec169/ | integrated orcheo |
| fix03 | Defined optional-address cursor, K1 budget2 | GPT-6 inherited | fix03.md | fix02 reviewed/closed and rejected proposal returned, fresh preflight/usage | orch-shift1/fix03/ | integrated orchen |
| fix02 | Pure leaf functions overblocked under R4.3, K2 budget8 strictR7 | GPT-6 inherited | fix02.md | rec167/168 reviewed/closed, eligible integration published, fresh preflight/usage | orch-shift1/fix02/ | closed: rejected nullable-pointer source returned through O4; corrected fix03 accepted orchen;00288fd8 blocked11words |
| nm27 | Isolated condition-layout retry K1 budget8 strictR7 | GPT-6 inherited | nm27.md | rec167/168 reviewed/closed and eligible integration published, fresh preflight/usage | orch-shift1/nm27/ | closedzero: bestv1 two words48/48; strictstreak3 including failedv2 |
| rec168 | General queue K6 budget8 strictR7 | GPT-6 inherited | rec168.md | nm26/rec166 reviewed and eligible integration published, fresh preflight/usage | orch-shift1/rec168/ | integrated orchem |
| fix01 | Priority resubmission of three unaccepted rec164 proposals, K3, budgets1/2/2 | GPT-6 inherited | fix01.md | context handoff after latest human resume, fresh full preflight/usage, no unresolved integration | orch-shift1/fix01/ | integrated orchek |
| nm26 | Isolated virtual-call register retry K1 budget8 strictR7 | GPT-6 inherited | nm26.md | fix01 completed/closed after context handoff, fresh preflight/usage | orch-shift1/nm26/ | integrated orchel |
| rec166 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec166.md | fix01 completed/closed after context handoff, fresh preflight/usage | orch-shift1/rec166/ | closed: zero submissions, two ABI blockers, one release under60% STOP |
| rec167 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec167.md | fix01 and prior wave closed/integrated after context handoff, fresh preflight/usage | orch-shift1/rec167/ | integrated orchem |
| rec164 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec164.md | rec162/163 reviewed and closed, eligible integration, fresh preflight/usage | orch-shift1/rec164/ | closed: 3 proposals returned unaccepted; 2 R4.5 rejections and 1 orchej pre-registration failure; 3 original blockers preserved |
| rec165 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec165.md | rec162/163 reviewed and closed, eligible integration, fresh preflight/usage | orch-shift1/rec165/ | closed: STOP at single-worker threshold after 2 claims; 0 submitted, 2 blocked; independent closure passed |
| rec162 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec162.md | direct human resume (now satisfied), rec161 closed, fresh full preflight and usage | orch-shift1/rec162/ | integrated orchei |
| rec163 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec163.md | direct human resume (now satisfied), rec161 closed, fresh full preflight and usage | orch-shift1/rec163/ | integrated orchei |
| rec160 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec160.md | rec158/159 integrated or closed, fresh preflight | orch-shift1/rec160/ | integrated orcheh |
| rec161 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec161.md | rec158/159 integrated or closed, fresh preflight | orch-shift1/rec161/ | closed: usage STOP after 2 claims; 0 submitted, 1 blocked, 1 released; independent closure passed |
| rec158 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec158.md | rec156/157 integrated or closed, fresh preflight | orch-shift1/rec158/ | integrated orcheg |
| rec159 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec159.md | rec156/157 integrated or closed, fresh preflight | orch-shift1/rec159/ | integrated orcheg |
| rec155 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec155.md | nm25/rec154 integrated or closed, preflight PASS | orch-shift1/rec155/ | integrated orchee, +1 exact; stopped under predecessor usage wrap-up |
| rec156 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec156.md | orchee reconciled, preflight PASS | orch-shift1/rec156/ | integrated orchef |
| rec157 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec157.md | orchee reconciled, preflight PASS | orch-shift1/rec157/ | integrated orchef |
| nm25 | Shared-exit result lifetime retry K1 budget12 strictR7 | GPT-6 inherited | nm25.md | rec152/153 integrated or closed, preflight PASS | orch-shift1/nm25/ | closed: no submissions; earliest best v1 three words |
| rec154 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec154.md | rec152/153 integrated or closed, preflight PASS | orch-shift1/rec154/ | integrated orched, +4 exact |
| rec143 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec143.md | nm22 partner after fresh preflight | orch-shift1/rec143/ | integrated orchdw, +4 exact |
| rec144 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec144.md | nm22/rec143 integrated or closed, preflight PASS | orch-shift1/rec144/ | integrated orchdx, +5 exact |
| rec145 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec145.md | nm22/rec143 integrated or closed, preflight PASS | orch-shift1/rec145/ | integrated orchdx, +4 exact |
| nm23 | Three reviewed two-word scheduling residuals K3 budget12 strictR7 | GPT-6 inherited | nm23.md | rec144/145 integrated or closed, preflight PASS | orch-shift1/nm23/ | integrated orchdy, +1 exact |
| rec146 | General queue partner nm23 K6 budget8 strictR7 | GPT-6 inherited | rec146.md | rec144/145 integrated or closed, preflight PASS | orch-shift1/rec146/ | integrated orchdy, +2 exact |
| rec152 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec152.md | nm24/rec151 integrated or closed, preflight PASS | orch-shift1/rec152/ | integrated orchec, +1 exact |
| rec153 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec153.md | nm24/rec151 integrated or closed, preflight PASS | orch-shift1/rec153/ | integrated orchec, +4 exact |
| nm24 | Named comparison-constant retry K1 budget12 strictR7 | GPT-6 inherited | nm24.md | rec149/150 integrated or closed, preflight PASS | orch-shift1/nm24/ | closed: no submissions; 00242908 best v3 3 words, strict R7 |
| rec151 | General queue K6 budget8 strictR7 every claim counts | GPT-6 inherited | rec151.md | rec149/150 integrated or closed, preflight PASS | orch-shift1/rec151/ | integrated orcheb, +3 exact |
| rec149 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec149.md | rec147/148 integrated or closed, preflight PASS | orch-shift1/rec149/ | integrated orchea, +6 exact |
| rec150 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec150.md | rec147/148 integrated or closed, preflight PASS | orch-shift1/rec150/ | integrated orchea, +4 exact |
| rec147 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec147.md | nm23/rec146 integrated or closed, preflight PASS | orch-shift1/rec147/ | integrated orchdz, +5 exact |
| rec148 | General queue K6 budget8 strictR7, every claim counts | GPT-6 inherited | rec148.md | nm23/rec146 integrated or closed, preflight PASS | orch-shift1/rec148/ | integrated orchdz, +3 exact |
| rec01 | General queue, 6 targets, smallest-first priority order | sonnet | rec01.md | - | `orch-shift1\rec01\` | integrated orchaa |
| rec02 | General queue, 6 targets | sonnet | rec02.md | - | `orch-shift1\rec02\` | integrated orchaa |
| med01 | Eight medium blockers (`medium-register-and-branch`) | opus | med01.md | - | `orch-shift1\med01\` | integrated orchab |
| rec03 | General queue, 6 targets | sonnet | rec03.md | rec01, rec02 reviewed | `orch-shift1\rec03\` | integrated orchab |
| pro01 | Prologue/epilogue specialist family (14 queues, 22 targets; attempt 6) | opus | pro01.md | - | `orch-shift1\pro01\` | integrated orchac |
| rec04 | General queue, 6 targets | sonnet | rec04.md | rec03 reviewed | `orch-shift1\rec04\` | integrated orchab |
| brl01 | Branch/lifetime specialist family (21 queues + new ones, attempt 6) | opus | brl01.md | - | `orch-shift1\brl01\` | integrated orchac |
| tool01 | Measurement tools: byte coverage per section, STATUS table generator (docs/tooling only) | sonnet | tool01.md | - | `orchestration\tools\coverage.py`, `status_table.py` | done 2026-10-12 (orchestrator ran both scripts; outputs agree with orchaa) |
| lay01 | Layout/ABI specialist family (10 queues + `abi-layout`, attempt 6) | opus | lay01.md | - | `orch-shift1\lay01\` | integrated orchac |
| rec05 | General queue, 6 targets | sonnet | rec05.md | rec04 reviewed | `orch-shift1\rec05\` | integrated orchab |
| brl02 | Branch/lifetime specialist family, attempt 7 (O12) | opus | brl02.md | - | `orch-shift1\brl02\` | integrated orchad |
| rec06 | General queue, 6 targets (O12) | sonnet | rec06.md | - | `orch-shift1\rec06\` | integrated orchac |
| pro02 | Prologue/epilogue specialist family, attempt 7 (O12) | opus | pro02.md | - | `orch-shift1\pro02\` | closed: nothing to integrate (4 blocked; second instance was an outside agent, DEVIATIONS #1) |
| rec07 | General queue, 6 targets (O12) | sonnet | rec07.md | rec06 reviewed | `orch-shift1\rec07\` | integrated orchad |
| lay02 | Layout/ABI specialist family, attempt 7 (O12) | opus | lay02.md | - | `orch-shift1\lay02\` | not started in Shift 1 (brief ready; pro02 and brl03 made 0 exact on the specialist residuals, so sonnet REC waves ran instead) |
| rec08 | General queue, 6 targets (O12) | sonnet | rec08.md | rec07 reviewed | `orch-shift1\rec08\` | integrated orchad |
| rec09 | General queue, 6 targets (O12) | sonnet | rec09.md | rec08 reviewed | `orch-shift1\rec09\` | integrated orchaf |
| brl03 | Branch/lifetime specialist family, attempt 8 (O12; carries brl02 next step) | opus | brl03.md | brl02 reviewed | `orch-shift1\brl03\` | closed: nothing to integrate (6 blocked, 4 at 2 words) |
| cdx1-rec10 | General queue, 6 targets, outside agent (Codex CLI, GPT-6, T1) | GPT-6 (outside) | cdx1-rec10.md | - | `orch-shift1\cdx1-rec10\` | done: 0 submitted, 6 blocked into boundary-review under the old R3 wording (retaken by fam01) |
| fam01 | Sibling family 00139858-00139ab0 (six 116-byte loop functions, claimed by address from boundary-review) | sonnet | fam01.md | - | `orch-shift1\fam01\` | integrated orchae |
| fam02 | The five remaining siblings of 00139ab0, v1 = the fam01 exact source with name and callee changed | sonnet | fam02.md | fam01 | `orch-shift1\fam02\` | integrated orchae |
| rec12 | General queue, 6 targets (O12) | sonnet | rec12.md | - | `orch-shift1\rec12\` | integrated orchag |
| rec13 | General queue, 6 targets (O12) | sonnet | rec13.md | - | `orch-shift1\rec13\` | integrated orchag |
| rec14 | General queue, 6 targets (O12) | sonnet | rec14.md | - | `orch-shift1\rec14\` | integrated orchah |
| rec15 | General queue, 6 targets (O12) | sonnet | rec15.md | - | `orch-shift1\rec15\` | integrated orchai |
| rec16 | General queue, 6 targets (O12) | sonnet | rec16.md | - | `orch-shift1\rec16\` | integrated orchaj |
| rec17 | General queue, 6 targets (O12) | sonnet | rec17.md | - | `orch-shift1\rec17\` | integrated orchak |
| rec18 | General queue, 6 targets (O12) | sonnet | rec18.md | - | `orch-shift1\rec18\` | integrated orchal |
| rec19 | General queue, 6 targets (O12) | sonnet | rec19.md | - | `orch-shift1\rec19\` | integrated orcham |
| rec20 | General queue, 6 targets (O12) | sonnet | rec20.md | - | `orch-shift1\rec20\` | integrated orchan |
| rec21 | General queue, 6 targets (O12) | sonnet | rec21.md | - | `orch-shift1\rec21\` | integrated orchao |
| rec22 | General queue, 6 targets (O12) | sonnet | rec22.md | - | `orch-shift1\rec22\` | integrated orchap |
| rec23 | General queue, 6 targets (O12) | sonnet | rec23.md | - | `orch-shift1\rec23\` | integrated orchaq |
| rec24 | General queue, 6 targets (O12) | sonnet | rec24.md | - | `orch-shift1\rec24\` | integrated orchar |
| rec25 | General queue, 6 targets (O12) | sonnet | rec25.md | - | `orch-shift1\rec25\` | integrated orchas |
| rec26 | General queue, 6 targets (O12) | sonnet | rec26.md | - | `orch-shift1\rec26\` | integrated orchat |
| fam03 | Four list-walk siblings of 00161248 (rec26 recipe: statement expression with goto in the while condition) | sonnet | fam03.md | rec26 | `orch-shift1\fam03\` | integrated orchau |
| rec27 | General queue, 6 targets (O12) | sonnet | rec27.md | - | `orch-shift1\rec27\` | integrated orchav |
| tool02 | kh2w.py objdump -z: show zero (nop) words in packets and diffs (tooling only) | sonnet | tool02.md | - | `orchestration\tools\kh2w.py` | done 2026-10-12 (orchestrator verified: only -z added; nop words now listed) |
| rec28 | General queue, 6 targets (O12) | sonnet | rec28.md | - | `orch-shift1\rec28\` | integrated orchaw |
| rec29 | General queue, 6 targets (O12) | sonnet | rec29.md | - | `orch-shift1\rec29\` | integrated orchaw |
| rec30 | General queue, 6 targets (O12) | sonnet | rec30.md | - | `orch-shift1\rec30\` | integrated orchax |
| rec31 | General queue, 6 targets (O12) | sonnet | rec31.md | - | `orch-shift1\rec31\` | integrated orchax |
| rec32 | General queue, 6 targets (O12) | sonnet | rec32.md | - | `orch-shift1\rec32\` | integrated orchay |
| rec33 | General queue, 6 targets (O12) | sonnet | rec33.md | - | `orch-shift1\rec33\` | integrated orchay |
| rec34 | General queue, 6 targets (O12) | sonnet | rec34.md | - | `orch-shift1\rec34\` | integrated orchaz |
| rec35 | General queue, 6 targets (O12) | sonnet | rec35.md | - | `orch-shift1\rec35\` | integrated orchaz |
| tool03 | kh2w.py packets also list the queue metadata best_proposal (earlier attempts in batch files) (tooling only) | sonnet | tool03.md | - | `orchestration\tools\kh2w.py` | done 2026-10-12 (orchestrator verified: only packet and prior_attempts changed; queue best_proposal now listed) |
| rec36 | General queue, 6 targets (O12) | sonnet | rec36.md | - | `orch-shift1\rec36\` | integrated orchba |
| rec37 | General queue, 6 targets (O12) | sonnet | rec37.md | - | `orch-shift1\rec37\` | integrated orchba |
| rec38 | General queue, 6 targets (O12) | sonnet | rec38.md | - | `orch-shift1\rec38\` | integrated orchbb |
| rec39 | General queue, 6 targets (O12) | sonnet | rec39.md | - | `orch-shift1\rec39\` | integrated orchbb |
| rec40 | General queue, 6 targets (O12) | sonnet | rec40.md | - | `orch-shift1\rec40\` | integrated orchbc |
| rec41 | General queue, 6 targets (O12) | sonnet | rec41.md | - | `orch-shift1\rec41\` | integrated orchbc |
| rec42 | General queue, 6 targets (O12) | sonnet | rec42.md | - | `orch-shift1\rec42\` | integrated orchbd |
| rec43 | General queue, 6 targets (O12) | sonnet | rec43.md | - | `orch-shift1\rec43\` | integrated orchbd |
| rec44 | General queue, 6 targets (O12) | sonnet | rec44.md | - | `orch-shift1\rec44\` | integrated orchbe |
| rec45 | General queue, 6 targets (O12) | sonnet | rec45.md | - | `orch-shift1\rec45\` | integrated orchbe |
| rec46 | General queue, 6 targets (O12) | sonnet | rec46.md | - | `orch-shift1\rec46\` | integrated orchbf |
| rec47 | General queue, 6 targets (O12) | sonnet | rec47.md | - | `orch-shift1\rec47\` | integrated orchbf |
| rec48 | General queue, 6 targets (O12) | sonnet | rec48.md | - | `orch-shift1\rec48\` | integrated orchbg |
| rec49 | General queue, 6 targets (O12) | sonnet | rec49.md | - | `orch-shift1\rec49\` | integrated orchbg |
| rec50 | General queue, 6 targets (O12) | sonnet | rec50.md | - | `orch-shift1\rec50\` | integrated orchbh |
| rec51 | General queue, 6 targets (O12) | sonnet | rec51.md | - | `orch-shift1\rec51\` | integrated orchbh |
| rec52 | General queue, 6 targets (O12) | sonnet | rec52.md | - | `orch-shift1\rec52\` | integrated orchbi |
| rec53 | General queue, 6 targets (O12) | sonnet | rec53.md | - | `orch-shift1\rec53\` | integrated orchbi |
| rec54 | General queue, 6 targets (O12) | sonnet | rec54.md | - | `orch-shift1\rec54\` | integrated orchbj |
| rec55 | General queue, 6 targets (O12) | sonnet | rec55.md | - | `orch-shift1\rec55\` | integrated orchbj |
| rec56 | General queue, 6 targets (O12) | sonnet | rec56.md | - | `orch-shift1\rec56\` | integrated orchbk |
| rec57 | General queue, 6 targets (O12) | sonnet | rec57.md | - | `orch-shift1\rec57\` | integrated orchbk |
| rec58 | General queue, 6 targets (O12) | sonnet | rec58.md | - | `orch-shift1\rec58\` | integrated orchbl |
| rec59 | General queue, 6 targets (O12) | sonnet | rec59.md | - | `orch-shift1\rec59\` | integrated orchbl |
| rec60 | General queue, 6 targets (O12) | sonnet | rec60.md | - | `orch-shift1\rec60\` | integrated orchbm |
| rec61 | General queue, 6 targets (O12) | sonnet | rec61.md | - | `orch-shift1\rec61\` | integrated orchbm |
| rec62 | General queue, 6 targets (O12) | sonnet | rec62.md | - | `orch-shift1\rec62\` | integrated orchbn |
| rec63 | General queue, 6 targets (O12) | sonnet | rec63.md | - | `orch-shift1\rec63\` | integrated orchbn |
| rec64 | General queue, 6 targets (O12) | sonnet | rec64.md | - | `orch-shift1\rec64\` | integrated orchbo |
| rec65 | General queue, 6 targets (O12) | sonnet | rec65.md | - | `orch-shift1\rec65\` | integrated orchbo |
| rec66 | General queue, 6 targets (O12) | sonnet | rec66.md | - | `orch-shift1\rec66\` | integrated orchbp |
| rec67 | General queue, 6 targets (O12) | sonnet | rec67.md | - | `orch-shift1\rec67\` | integrated orchbp |
| rec68 | General queue, 6 targets (O12) | sonnet | rec68.md | - | `orch-shift1\rec68\` | integrated orchbq |
| rec69 | General queue, 6 targets (O12) | sonnet | rec69.md | - | `orch-shift1\rec69\` | integrated orchbq |
| rec70 | General queue, 6 targets (O12) | sonnet | rec70.md | - | `orch-shift1\rec70\` | integrated orchbr |
| rec71 | General queue, 6 targets (O12) | sonnet | rec71.md | - | `orch-shift1\rec71\` | integrated orchbr |
| rec72 | General queue, 6 targets (O12) | sonnet | rec72.md | - | `orch-shift1\rec72\` | integrated orchbs |
| nm01 | Near-miss retries, 6 named targets (O12) | sonnet | nm01.md | rec56, rec58, rec62, rec64, rec66, rec69 | `orch-shift1\nm01\` | integrated orchbt |
| rec73 | General queue, 6 targets (O12) | sonnet | rec73.md | - | `orch-shift1\rec73\` | integrated orchbu |
| nm02 | Near-miss retries round 2, 6 named targets (O12) | sonnet | nm02.md | rec62, rec64, rec73, nm01 | `orch-shift1\nm02\` | integrated orchbv |
| rec74 | General queue, 6 targets (O12) | sonnet | rec74.md | - | `orch-shift1\rec74\` | integrated orchbw |
| rec75 | General queue, 6 targets (O12) | sonnet | rec75.md | - | `orch-shift1\rec75\` | integrated orchbx |
| rec76 | General queue, 6 targets (O12) | sonnet | rec76.md | - | `orch-shift1\rec76\` | integrated orchby |
| nm03 | Near-miss retries round 3, 5 named targets (O12) | sonnet | nm03.md | rec69, rec70, rec76 | `orch-shift1\nm03\` | integrated orchbz |
| rec77 | General queue, 6 targets (O12) | sonnet | rec77.md | - | `orch-shift1\rec77\` | integrated orchca |
| rec78 | General queue, 6 targets (O12) | sonnet | rec78.md | - | `orch-shift1\rec78\` | integrated orchcb |
| rec79 | General queue, 6 targets (O12) | sonnet | rec79.md | - | `orch-shift1\rec79\` | integrated orchcc |
| nm04 | Near-miss retries round 4, 4 named targets (O12) | sonnet | nm04.md | rec77, rec78 | `orch-shift1\nm04\` | integrated orchcc |
| rec80 | General queue, 6 targets (O12) | sonnet | rec80.md | - | `orch-shift1\rec80\` | integrated orchcd |
| rec81 | General queue, 6 targets (O12) | sonnet | rec81.md | - | `orch-shift1\rec81\` | integrated orchcd |
| rec82 | General queue, 6 targets (O12) | sonnet | rec82.md | - | `orch-shift1\rec82\` | integrated orchcf |
| rec83 | General queue, 6 targets (O12) | sonnet | rec83.md | - | `orch-shift1\rec83\` | integrated orchcf |
| rec84 | General queue, 6 targets (O12) | sonnet | rec84.md | - | `orch-shift1\rec84\` | integrated orchcg |
| rec85 | General queue, 6 targets (O12) | sonnet | rec85.md | - | `orch-shift1\rec85\` | integrated orchcg |
| rec86 | General queue, 6 targets (O12) | sonnet | rec86.md | - | `orch-shift1\rec86\` | integrated orchch |
| rec87 | General queue, 6 targets (O12) | sonnet | rec87.md | - | `orch-shift1\rec87\` | integrated orchch |
| rec88 | General queue, 6 targets (O12) | sonnet | rec88.md | - | `orch-shift1\rec88\` | integrated orchci |
| nm06 | Near-miss retries round 6, 4 named targets (O12) | sonnet | nm06.md | rec79, rec80, rec82, rec87, nm05 | `orch-shift1\nm06\` | closed, nothing to merge |
| rec89 | General queue, 6 targets (O12) | sonnet | rec89.md | - | `orch-shift1\rec89\` | integrated orchcj |
| rec90 | General queue, 6 targets (O12) | sonnet | rec90.md | - | `orch-shift1\rec90\` | integrated orchcj |
| rec91 | General queue, 6 targets (O12) | sonnet | rec91.md | - | `orch-shift1\rec91\` | integrated orchck |
| rec92 | General queue, 6 targets (O12) | sonnet | rec92.md | - | `orch-shift1\rec92\` | integrated orchck |
| rec93 | General queue, 6 targets (O12) | sonnet | rec93.md | - | `orch-shift1\rec93\` | integrated orchcl |
| rec94 | General queue, 6 targets (O12) | sonnet | rec94.md | - | `orch-shift1\rec94\` | integrated orchcl |
| rec95 | General queue, 6 targets (O12) | sonnet | rec95.md | - | `orch-shift1\rec95\` | integrated orchcm |
| rec96 | General queue, 6 targets (O12) | sonnet | rec96.md | - | `orch-shift1\rec96\` | integrated orchcm |
| rec97 | General queue, 6 targets (O12) | sonnet | rec97.md | - | `orch-shift1\rec97\` | integrated orchcn |
| rec98 | General queue, 6 targets (O12) | sonnet | rec98.md | - | `orch-shift1\rec98\` | integrated orchcn |
| rec99 | General queue, 6 targets (O12) | sonnet | rec99.md | - | `orch-shift1\rec99\` | integrated orchco |
| rec100 | General queue, 6 targets (O12) | sonnet | rec100.md | - | `orch-shift1\rec100\` | integrated orchco |
| rec101 | General queue, 6 targets (O12) | sonnet | rec101.md | - | `orch-shift1\rec101\` | integrated orchcp |
| rec102 | General queue, 6 targets (O12) | sonnet | rec102.md | - | `orch-shift1\rec102\` | integrated orchcp |
| rec103 | General queue, 6 targets (O12) | sonnet | rec103.md | - | `orch-shift1\rec103\` | integrated orchcq |
| rec104 | General queue, 6 targets (O12) | sonnet | rec104.md | - | `orch-shift1\rec104\` | integrated orchcq |
| rec105 | General queue, 6 targets (O12) | sonnet | rec105.md | - | `orch-shift1\rec105\` | integrated orchcr |
| nm07 | Near-miss retries round 7, 6 named targets incl. one rename (O12) | sonnet | nm07.md | rec91, rec97, rec100, rec101, rec104 | `orch-shift1\nm07\` | integrated orchcr |
| rec106 | General queue, 6 targets (O12) | sonnet | rec106.md | - | `orch-shift1\rec106\` | integrated orchcs |
| rec107 | General queue, 6 targets (O12) | sonnet | rec107.md | - | `orch-shift1\rec107\` | integrated orchcs |
| rec108 | General queue, 6 targets (O12) | sonnet | rec108.md | - | `orch-shift1\rec108\` | integrated orchct |
| rec109 | General queue, 6 targets (O12) | sonnet | rec109.md | - | `orch-shift1\rec109\` | integrated orchct |
| rec110 | General queue, 6 targets (O12) | sonnet | rec110.md | - | `orch-shift1\rec110\` | integrated orchcu |
| rec111 | General queue, 6 targets (O12) | sonnet | rec111.md | - | `orch-shift1\rec111\` | integrated orchcu |
| nm08 | Near-miss retries round 8, 4 named targets incl. two comment fixes (O12) | sonnet | nm08.md | rec105, rec108, rec110 | `orch-shift1\nm08\` | integrated orchcv |
| rec112 | General queue, 6 targets (O12) | sonnet | rec112.md | - | `orch-shift1\rec112\` | integrated orchcv |
| rec113 | General queue, 6 targets (O12) | sonnet | rec113.md | - | `orch-shift1\rec113\` | integrated orchcw |
| rec114 | General queue, 6 targets (O12) | sonnet | rec114.md | - | `orch-shift1\rec114\` | integrated orchcw |
| nm09 | Near-miss retries round 9, 3 named targets with exact siblings (O12) | sonnet | nm09.md | rec112, rec113, rec114 | `orch-shift1\nm09\` | integrated orchcx |
| rec115 | General queue, 6 targets (O12) | sonnet | rec115.md | - | `orch-shift1\rec115\` | integrated orchcx |
| rec116 | General queue, 6 targets (O12) | sonnet | rec116.md | - | `orch-shift1\rec116\` | integrated orchcy |
| rec117 | General queue, 6 targets (O12) | sonnet | rec117.md | - | `orch-shift1\rec117\` | integrated orchcz |
| rec118 | General queue, 6 targets (O12) | sonnet | rec118.md | - | `orch-shift1\rec118\` | integrated orchda |
| nm10 | Near-miss retries round 10, 4 named targets (O12) | sonnet | nm10.md | rec116, rec118 | `orch-shift1\nm10\` | closed, 0 submitted |
| rec119 | General queue, 6 targets (O12) | sonnet | rec119.md | - | `orch-shift1\rec119\` | integrated orchdb |
| rec120 | General queue, 6 targets (O12) | sonnet | rec120.md | - | `orch-shift1\rec120\` | integrated orchdc |
| nm11 | Near-miss retries round 11, 3 named targets incl. two trap functions (O12) | sonnet | nm11.md | rec120 | `orch-shift1\nm11\` | integrated orchdd |
| rec121 | General queue, 6 targets (O12) | sonnet | rec121.md | - | `orch-shift1\rec121\` | integrated orchde |
| rec122 | General queue, 6 targets (O12) | sonnet | rec122.md | - | `orch-shift1\rec122\` | integrated orchde |
| rec123 | General queue, 6 targets (O12) | sonnet | rec123.md | - | `orch-shift1\rec123\` | integrated orchdf |
| rec124 | General queue, 6 targets (O12) | sonnet | rec124.md | - | `orch-shift1\rec124\` | integrated orchdf |
| rec125 | General queue, 6 targets (O12) | sonnet | rec125.md | - | `orch-shift1\rec125\` | integrated orchdg |
| rec126 | General queue, 6 targets (O12) | sonnet | rec126.md | - | `orch-shift1\rec126\` | integrated orchdg |
| nm12 | Near-miss retries round 12, 4 named targets (O12) | sonnet | nm12.md | rec121, rec125 | `orch-shift1\nm12\` | integrated orchdh |
| rec127 | General queue, 6 targets (O12) | sonnet | rec127.md | - | `orch-shift1\rec127\` | integrated orchdh |
| rec128 | General queue, 6 targets (O12) | sonnet | rec128.md | - | `orch-shift1\rec128\` | integrated orchdi |
| rec129 | General queue, 6 targets (O12) | sonnet | rec129.md | - | `orch-shift1\rec129\` | integrated orchdj |
| rec130 | General queue, 6 targets (O12) | sonnet | rec130.md | - | `orch-shift1\rec130\` | integrated orchdk |
| rec131 | General queue, 6 targets (O12) | sonnet | rec131.md | - | `orch-shift1\rec131\` | integrated orchdl |
| nm13 | Near-miss retries round 13 on opus, 6 named targets after two sonnet rounds each (handoff follow-up) | opus | nm13.md | rec105, nm08, rec116, rec118, nm10, rec121, nm12 | `orch-shift1\nm13\` | integrated orchdm |
| nm14 | Near-miss retries round 14, 6 named targets tried once by sonnet (handoff follow-up) | sonnet | nm14.md | rec88, rec89, rec93, rec95, rec128 | `orch-shift1\nm14\` | integrated orchdm |
| rec132 | General queue, 6 targets | GPT-6 inherited | rec132.md | nm13, nm14 reviewed | `orch-shift1\rec132\` | integrated orchdn |
| rec133 | General queue, 6 targets | GPT-6 inherited | rec133.md | nm13, nm14 reviewed | `orch-shift1\rec133\` | integrated orchdn |
| nm15 | Trap-only and defined entry-register retries, 3 targets | GPT-6 inherited | nm15.md | rec132, rec133 reviewed | `orch-shift1\nm15\` | integrated orchdo |
| nm16 | Two remaining nm14 near misses | GPT-6 inherited | nm16.md | rec132, rec133 reviewed | `orch-shift1\nm16\` | partial: 001c05b0 integrated orchdp; 001bdff0 unclaimed at wrap-up |
| nm17 | Unclaimed 001bdff0 retry only, K1 budget12 | GPT-6 inherited | nm17.md | nm16 closed, preflight PASS | `orch-shift1\nm17\` | closed: no submissions, 001bdff0 bestv1 2words |
| nm18 | integrated orchdr, +2 exact | GPT-6 inherited | nm18.md | rec134, rec135 integrated or closed | `orch-shift1\nm18\` | O3 batch + preflight |
| nm19 | integrated orchds +1 exact;001b27f0 unavailable, deferred nm20 | GPT-6 inherited | nm19.md | rec134, rec135 integrated or closed | `orch-shift1\nm19\` | O3 batch + preflight |
| rec136 | integrated orchdt, +2 exact;4 blocked | GPT-6 inherited | rec136.md | nm18, nm19 integrated or closed | `orch-shift1\rec136\` | O3 batch + preflight |
| rec137 | integrated orchdt, +4 exact;2 blocked | GPT-6 inherited | rec137.md | nm18, nm19 integrated or closed | `orch-shift1\rec137\` | O3 batch + preflight |
| nm20 | Deferred001b27f0 quad-copy retry, correct store-order queue | GPT-6 inherited | nm20.md | rec136, rec137 integrated or closed | `orch-shift1\nm20\` | closed: 0 submitted; v1best12words, four versions strictR7 |
| nm22 | Ring-buffer tag scheduling retries, K2 budget12 | GPT-6 inherited | nm22.md | rec141/142 integrated or closed | orch-shift1/nm22/ | integrated orchdw, +2 exact |
| rec141 | General queue, K6 every claim counts budget8 | GPT-6 inherited | rec141.md | nm21/rec140 integrated or closed | orch-shift1/rec141/ | integrated orchdv, +4 exact |
| rec142 | General queue, K6 every claim counts budget8 | GPT-6 inherited | rec142.md | nm21/rec140 integrated or closed | orch-shift1/rec142/ | integrated orchdv, +3 exact |
| rec140 | General queue partner, K6 budget8 | GPT-6 inherited | rec140.md | rec138/139 integrated or closed | orch-shift1/rec140/ | closed: 0 submitted, 6 blocked |
| nm21 | Two recent two-word residuals, K2 budget12 | GPT-6 inherited | nm21.md | rec138/139 integrated or closed | orch-shift1/nm21/ | closed: 0 submitted, 2 blocked, best2words each |
| rec138 | General queue, K6 every claim counts, budget8 | GPT-6 inherited | rec138.md | nm20 reviewed and closed | orch-shift1/rec138/ | integrated orchdu, +4 exact |
| rec139 | General queue, K6 every claim counts, budget8 | GPT-6 inherited | rec139.md | nm20 reviewed and closed | orch-shift1/rec139/ | closed: 0 submitted, 6 blocked |
| rec134 | General queue, K6 every claim counts, budget8 | GPT-6 inherited | rec134.md | nm17 reviewed, preflight PASS | `orch-shift1\rec134\` | integrated orchdq |
| rec135 | General queue, K6 every claim counts, budget8 | GPT-6 inherited | rec135.md | nm17 reviewed, preflight PASS | `orch-shift1\rec135\` | integrated orchdq |
| nm05 | Near-miss retries round 5, 5 named targets (O12) | sonnet | nm05.md | rec79, rec80, rec81 | `orch-shift1\nm05\` | integrated orchce |
| cdx1-rec12 | General queue, 6 targets, outside agent GPT-6 (O12) | GPT-6 (user) | cdx1-rec12.md | - | `orch-shift1\cdx1-rec12\` | integrated orchce |
| opc1-rec11 | Three listed general targets, outside agent probation (opencode, space-bunny, T1) | space-bunny (outside) | opc1-rec11.md | after the orchad integration | `orch-shift1\opc1-rec11\` | integrated orchce |

**SOURCE-DATA RULE (project-specific; first project: "ONE-ISO RULE", user decision):** the project reads game bytes only from the user's own copy
at run time (`SLPM_666.75` from `Kingdom Hearts II - Final Mix (Japan).iso`, SHA-256 of the executable `d869ce4b...`). Any other source (the US release `SLUS_210.05`, `KH2MODELDUMP`, other decompilation projects, symbol maps) is a RESEARCH source only: its behaviour is ported as code
logic (rules, thresholds, formulas, timings; small constants MAY be written in code), never read at run time and never copied into the
repo. Tables, models, textures, audio, cutscene data and other assets are NOT copied into the source tree or published (copyrighted; the
project reads game data from the user's own copy only): content that exists only in the secondary source is recorded as a gap. An
optional local cache built from the secondary source is a possible later project only if the user asks.

**USER PRIORITIES (outrank the wave order):**
1. FIX WPs from the user's reports (`DEVIATIONS.md`): none yet. Two at a time, front of the queue.
2. Instruction-exact coverage before renaming or readability (user's standing goal; every handoff since 2026-10-05).
3. Honest reporting: no completion percentage; whole-executable equality is never called a source rebuild.
4. Reference evidence: every recovery WP compares with the original instructions (the packet), never with pseudocode alone.

**Waves (default order; pairs are file-disjoint):**

| wave | WP pair | why this order |
|---|---|---|
| W1 | rec01 (sonnet) + rec02 (sonnet) | Cheapest, measures cost and success rate of the new worker manual on the easiest targets first |
| W2 | med01 (opus) + rec03 (sonnet) | The eight medium blockers have written next hypotheses ready; one sonnet keeps the general queue moving |
| W3 | pro01 (opus) + rec04 (sonnet) | Largest specialist family |
| W4 | brl01 (opus) + tool01 (sonnet) | Second family plus the measurement tools (docs-only pairs with anything) |
| W5 | lay01 (opus) + rec05 (sonnet) | Third family |
| W6 | brl02 (opus) + rec06 (sonnet) | O12 briefs; brl01 had the best specialist yield and the REC blocks feed its queues |
| W7 | pro02 (opus) + rec07 (sonnet) | O12 briefs |
| W8 | lay02 (opus) + rec08 (sonnet) | O12 briefs; specialist queues still hold about 70 targets |
| W9 | brl03 (opus) + rec09 (sonnet) | O12 briefs; brl03 carries the brl02 next step |
| W10 | rec12 (sonnet) + rec13 (sonnet), or one of them beside an outside agent | specialist queues are now mostly 2-word residuals (pro02 and brl03 made 0 exact); sonnet REC WPs yield 3 to 5 exact each |
| W11 (completed Shift 2) | nm13 + nm14, then rec132 + rec133, then nm15 and partial nm16 | Integrated orchdm through orchdp; see CHANGELOG |
| W12 (completed Shift 2) | nm17 through nm23 and rec134 through rec146 | Published orchdq through orchdy; blocked-only closures and evidence remain in PROGRESS and the WP table |
| W13 (completed) | rec147 + rec148 | Integrated orchdz, +8 exact716bytes |
| W14 (completed) | rec149 + rec150 | Integrated orchea, +10 exact1016bytes; rejected0024eff8 returned |
| W15 (completed) | nm24 then rec151 | nm24 closed blocked; rec151 integrated orcheb, +3 exact and 176 bytes; ABI blocks preserved |
| W16 (completed) | rec152 + rec153 | Integrated orchec, +5 exact and 416 bytes; every-exit R4.3 reviews, DEVIATIONS #8 preserved |
| W17 (completed) | nm25 + rec154 | nm25 closed blocked; rec154 integrated orched, +4 exact and 416 bytes |
| W18 (completed) | rec155 | Integrated orchee, +1 exact, 108 bytes; predecessor usage wrap-up |
| W19 (completed) | rec156 + rec157 | Integrated orchef, +10 exact functions and 1,060 bytes |
| W20 (completed) | rec158 + rec159 | Integrated orcheg, +10 exact functions and 980 bytes; blocked experimental attribution preserved in DEVIATIONS #9/#10 |
| W21 (closed) | rec160 then partial rec161 | rec160 integrated orcheh, +4 exact functions and 464 bytes; rec161 closed with no submissions under the 91% usage STOP |
| W22 (completed orchei) | rec162 + rec163 | Integrated orchei, +6 functions and 532 bytes after direct human continue |
| W23 (closed, no new acceptance) | rec164 + stopped rec165 | rec164 all three proposals returned unaccepted; orchej burned before registration. rec165 closed zero submissions after STOP at 62% |
| W24 (closed) | fix01, then nm26 and rec166 | fix01 integrated orchek; nm26 integrated orchel; rec166 closed with zero proposals. Latest human24h continuation overrides context stop within interval. |
| W25 (completed) | rec167 + rec168 | Integrated orchem, +5 functions400bytes. DEVIATIONS12 pure-leaf overblock recorded; follow-up fix02/03 preserved. |

| W26 (closed) | fix02 then priority fix03 | fix02 rejected source returned unaccepted; fix03 corrected cursor accepted orchen, +1function120bytes;00288fd8 blocked11words. |
| W27 (closed) | nm27 + rec169 | nm27 closedzero, earliestbest2words; rec169 integrated orcheo +2functions216bytes. DEVIATIONS14 report correction completed before integration. |

| W28 (closed) | rec170 + rec171 | Integrated orchep, five functions488bytes; independent reviews, all proofs and full acceptance passed. |
| W29 (closed) | nm28, then rec172 | nm28 closed with zero proposals after wrong-queue single claim; hypothesis untested (DEVIATIONS #15). rec172 integrated orcheq, +1 function, 52 bytes. |
| W30 (closed) | nm29 then nm30 | Both closed with zero proposals; nm30 failed-probe name reuse and stop overrun preserved in DEVIATIONS #16. |

| W31 (closed) | rec173 + rec174, then priority fix04 | Five functions464bytes integrated orcher; rejected signed-shift source returned. New independently reviewed fix04 correction integrated orches, one function56bytes; unsafe original remains unaccepted. |

| W32 (closed) | nm31 + rec175 | nm31 integrated orchet, one function92bytes. rec175 closed zero proposals on91% STOP after one claim; independently reviewed blocker bestv3 one word116/116. |

| W33 (closed) | rec176 + rec177 | Integrated orcheu, three functions236bytes; DEVIATIONS18 attribution follow-up preserved. |

| W34 (closed) | nm32 + nm33 | nm32 independently closed zero; nm33 integrated orchev, one function116bytes. |

| W35 (closed) | rec178 + rec179 | Integrated orchew, four functions412bytes; DEVIATIONS19 follow-up preserved. |

| W36 (usage wrap-up) | rec180 + undispatched rec181 | rec180 stopped zero proposals on91% STOP; independent closure running. rec181 remains ready, undispatched. Reset after authorization deadline; no automatic recovery resume. |

Allowed substitute pairs when a wave is blocked: any docs-only WP pairs with anything. Never pair two WPs that edit the same files:
the only shared write targets are `orchestration\tools\` (tool WPs; one at a time) and the integration files (orchestrator only).

## 6. After this shift: the roadmap

Each phase starts with its spec WP; the spec writes the next briefs' content. Phases, in order:
1. **Steady recovery**: more REC WPs (sonnet, general queue) and SPEC WPs (opus, specialist queues and new consolidated specialties `register-allocation`, `store-order`, `branch-layout`, `prologue-epilogue`, `float-transport`, `abi-layout`, `address-materialization`, `large-control-flow`), from the templates.
2. **Measured progress**: after tool01, add the byte coverage table to `STATUS.md` after every integration.
3. **Larger ranges** (priority 3, 129-512 bytes): spec WP `spec-large` (opus, docs-only) studies 10 accepted functions over 128 bytes and the first 10 priority-3 targets, and writes a cookbook supplement plus REC-large briefs.
4. **Boundaries and special queues**: spec WP for `boundary-review`, `vu-macro`, `privileged-instructions` targets (what acceptance means for each; user decision for any assembly integration).
5. **Jump tables and data**: spec WP for the 22 unresolved jump-table functions and for data/table ownership (needed for a source-only rebuild).
6. **Beyond the main executable**: spec WPs for overlays, IOP modules and VU microprograms, each defining its own acceptance check before any recovery.
For a phase without a brief yet, write the briefs from the spec doc's staged plan: one brief per stage, the stage text copied as
"Steps", the header filled like the existing briefs (model per rule 2, depends on the previous stage, review globs = files the stage
names).

## 7. User checkpoints (non-blocking: send, never wait)

**U1 (Step 0 of the first session of the shift).** One message, then start W1 at once. Attach (SendUserFile) `Codex\STATUS.md`.
Text, numbered:
1. How to follow the work (`STATUS.md`, `orchestration/PROGRESS.md`) and what changed since the user last looked. "Tell me anything that looks wrong."
2. Each suspected difference as a question, with the default used meanwhile: (a) the gate rewrites the checkpoint when run (default: run it as the project always has); (b) the HANDOFF.md hash rebinding (default: rebound at step 0).
3. Each scope decision awaiting the user, with its default: (a) worker count (default 2); (b) weekly waiver (default none, stop at 80%); (c) structured startup assembly `00100228`/`001002a0` (default: leave unintegrated); (d) Codex workers `recovery-a/b/c` (default: not used; Claude subagents only).
4. May I do any O8 action (for example compress old snapshots)? (Default: no, until you say yes.)
5. Any new research source found (no action needed).
6. The listen list: not applicable to KH2FM (no audio is produced); kept per template.
Defaults apply until the user answers. When an answer arrives (any time): record it in `DEVIATIONS.md` (P0 wrong accepted result or rule violation, P1
missing feature or process, P2 polish); each P0 becomes a fix WP from `briefs/FIX-template.md` at the front of the queue (it outranks the plan).

**U2 (at every final stop, section 9).** One message: what was integrated (CHANGELOG lines), the numbers from `orch.py state`, the U1
questions not yet answered, the O8 question. Never treat silence as approval; never do an O8 action without an
explicit yes.

## 8. Decision table (every situation the orchestrator meets, with the answer)

| situation | answer |
|---|---|
| `review_wp.py` FAIL on an address | O4: return it to the queue with the review file as evidence; SendMessage the worker only if it is still running ("<A> failed review: <detail>; do not resubmit it") |
| `review_wp.py` FLAG: changed outside the WP | Read the path. Your own O3/O6 files or another running WP's directory: ignore. A worker changed a shared file (`Public/tools/**`, `layout.tsv`, `functions.tsv`, queue DB, root docs): stop that worker (O7), do not integrate anything, compare the file with the latest `accepted-snapshots/2026-10-09-before-<phase>/` copy, record "Needs the user" with the path, continue with docs-only WPs |
| `review_wp.py` FLAG: emitted assembly or missing "why:" | The reviewer agent decides; its verdict stands (row "reviewer and worker disagree") |
| `review_wp.py` FLAG: no submissions from this WP | Normal when everything was blocked; close the WP (O10) |
| reviewer verdict MERGE | Keep the submission for the next O3 |
| reviewer verdict MERGE WITH FOLLOW-UP | Integrate the MERGE addresses; the PARTIAL / NOT DONE items become a follow-up (loop step 4) |
| reviewer verdict DO NOT MERGE (address) | O4 for that address; the next REC/SPEC WP may claim it again; a NEW reviewer reviews any later submission |
| reviewer and worker disagree | the reviewer's evidence wins unless you reproduce the worker's claim yourself (re-run `kh2w.py diff` and `review_wp.py`) |
| a worker reports partial | loop step 4 |
| a worker is silent for 2 hours | look at the newest file time in its WP directory and `orch.py leases`: recent files or live leases -> wait; none -> SendMessage "status: done / not done / last version?" |
| `orch.py lock acquire` says held by another owner | You are not the orchestrator. Do not integrate, pause the queue or spawn. Tell the user which owner holds it and stop. A lock whose heartbeat is older than 30 minutes is stale and `acquire` takes it over |
| an outside agent (Codex, opencode) finished or says it is done | Add its WP to the review queue like any WP (O2); its directory is `orch-shift1\<id>`; `WP start` is the time in its launch prompt (ask the user if unknown) |
| an outside agent's lease expires with files still being written | Leases expire after 15 minutes; if the agent is still working it loses the lease and R10 tells it to stop that target. Do not integrate until the user confirms the agent is stopped |
| an outside agent submitted a target above its tier | Treat it like any other submission; the checks decide. Record "tier exceeded" in PROGRESS; do not reject for that alone |
| an outside agent breaks the manual (edits shared files, wrong commands) | Stop it (O7 via the user), record in DEVIATIONS (P1, technique violation), remove its roster row until the user decides; return its submissions that failed review (O4) |
| a worker died (rate limit or error) | SendMessage to its id to resume; if that fails: spawn a new worker with the same brief plus "continue: read <WP dir>\PROGRESS.md first" (its leases expire within 15 minutes; it reclaims with `--address`) |
| the same report arrives again | ignore it |
| a worker asks the orchestrator a question | answer from this plan, the brief, `_shared.md`; if it is the user's decision, pick the conservative default (block the target), note it in HANDOFF under "Needs the user", continue |
| a worker wants an edit outside its directory | refuse; if it is a tool improvement, add it as a step to the next tooling WP brief |
| O3 step 2-4: leases exist | Do not integrate. Wait for running workers; leases of dead workers expire within 15 minutes |
| O3 step 5 (curate) or 6 (independent probe) fails | O5a: safe; burn the phase name, return the failing address (O4, evidence = its log), restart O3 at step 4 with the next name |
| O3 step 7, 8 or 9 fails (register, accept, publish) | O5b: STOP all compiler work; queue stays paused; record "Needs the user" with phase, step, command, last 40 output lines and log paths; continue only docs-only WPs and reviews, then final stop |
| make-verify log does not end in `MATCHED!` | same as above (O5b) |
| preflight FAIL at step 0 or after an integration | Do no compiler work. If the failing check is `docker`: run preflight once more after 60 s; still failing -> "Needs the user" (never restart Docker Desktop yourself). Any other check -> "Needs the user". Continue docs-only WPs, then final stop |
| `orch.py next-phase` says all names used (676 batches) | Do not invent a new naming scheme; record "Needs the user: phase names exhausted" and final stop |
| submissions exist that no WP of this shift made | Review them with a reviewer agent like any WP before O3 |
| a submitted address is in the `reserved` state or owned by a Codex worker | never touch it; do not integrate other workers' leases |
| usage >= 60% (5-hour) | no second worker |
| usage >= 90% of the 5-hour window | rule 4 wrap-up trigger |
| usage >= 80% of a weekly window | rule 4: final stop, tell the user the resume date (unless the weekly limit is waived) |
| a permission prompt blocks a step and nobody answers | skip that step, note it under "Needs the user" in HANDOFF, continue with the next WP |
| the session's context gets long | nothing to do: HANDOFF is current after every integration (it survives compaction); keep going |
| the same WP fails review twice | return its submissions, write "not done: <reason>" in HANDOFF, move to the next WP; a third attempt only after rewriting the failing step FIX-style |
| two sonnet WPs blocked the same address | it is already in a specialist queue; make sure the next SPEC WP for that specialty runs on opus |
| the user reports a difference or a wrong result | `DEVIATIONS.md` row; P0 -> fix WP from `FIX-template.md` at the front of the queue |
| the user asks for something new | do it if it fits the rules; it outranks the queue; write a brief from `FIX-template.md` |
| the user sends `WRAP UP` | rule 10 |
| a WP finds a range is not a function (data, padding, wrong boundary) | that is a valid result: it is blocked into `boundary-review`; record it in HANDOFF; never change `layout.tsv` yourself |
| a submission matches bytes but uses a forbidden technique (pasted encoding, symbolic registers, a pasted function body, patched bytes) | O4; record in DEVIATIONS as P1 "technique violation"; mention it in U2 |

## 9. End of shift (in this order)

1. RECIPES O7 if workers still run. 2. Integrate every remaining MERGE submission (O3, O6); then `preflight.ps1`; LOOK at the artifacts listed in D3.
3. Hygiene, all empty except the known hits (sources accepted before this shift):
```
python -I Codex\orchestration\tools\orch.py leases                         # no leases; submitted list empty
Get-ChildItem Codex\analysis\final-mix\recovery-experiments\fm_primary_orch*_recovered_*.cpp | Select-String -Pattern '\b(iVar|uVar|lVar|puVar|piVar|pcVar|bVar|param_)[0-9]+\b|DAT_|FUN_'
Get-ChildItem Codex\analysis\final-mix\recovery-experiments\fm_primary_orch*_recovered_*.cpp | Select-String -Pattern '\.word|\.incbin'
```
4. `preflight.ps1` once more; `compiler-status.json` shows `idle`; the queue is resumed (not paused) unless O5b left it paused on purpose.
5. Bookkeeping (O6): `STATUS.md`, `orchestration/CHANGELOG.md` (heading "Shift 1"), memory.
6. Cleanup (RECIPES O10): every WP of the shift closed in PROGRESS.md; nothing deleted. `python -I Codex\orchestration\tools\orch.py lock release cld-orch`. Log it in PROGRESS.md.
7. Handoff: spawn a handoff-writer agent, `model: opus`, prompt: "Rewrite C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\HANDOFF.md for the next session. Read
   orchestration/ORCHESTRATION.md, the current orchestration/HANDOFF.md, orchestration/PROGRESS.md (the whole log), orchestration/DEVIATIONS.md and orchestration/CHANGELOG.md.
   Keep HANDOFF's sections (Start here, Autonomy, Needs the user, State, What the project has, Usage, Process rules). 'Completed'
   lists only items a reviewer marked MERGE and a published checkpoint accepted (PROGRESS `integrate-pass` lines). Update ORCHESTRATION section 2 (state) and section 5 (mark
   integrated WPs 'integrated <phase>', add follow-up briefs written this session). For every PARTIAL / NOT DONE item without a brief, write
   one with RECIPES O9. Plain prose, short bullets. Report the files you changed." Review its changes yourself (there is no git: compare with the archived PROGRESS and your own knowledge); fix factual errors.
8. Tell the user (U2, section 7): what was integrated, numbers, what they should check, the O8 question.

## 10. Pitfalls (learned; all still true)

- Agents die on 429 limits mid-work; saved probe versions survive, unsaved work does not. Workers log every version in PROGRESS.md so a respawned worker continues.
- Workers repeat their final report several times; ignore repeats.
- A reused probe file name overwrote evidence (fix: every version gets a new name; the stage scratch folder is named after the file).
- The Bash tool's powershell refuses scripts (execution
  policy): run `.ps1` files from the PowerShell tool with `-ExecutionPolicy Bypass`.
- The checkpoint gate is not read-only: it rewrites the checkpoint JSON with current file hashes. Old gates have fixed counts and fail against newer builds; only the gate derived by preflight is authoritative.
- An isolated exact probe does not prove the full link: a callee defined in legacy assembly outside its native section (`func_00139768` in `obj2d_isExist.s`) linked to a temporary address (queueepsilonprime). `review_wp.py` and the packet now flag it; workers call `D_<address>` instead.
- A function at an address congruent to 4 modulo 8 once linked four bytes late (queuekappaprime); the build helper now corrects section alignment, but only the full build can show such problems.
- The curation step drops declarations placed after a function; one function per file with all declarations first avoids it.
- The pinned compiler rejects symbolic register names (`$t7`); numeric names (`$15`) work.
- Phase names must be lowercase letters only and are never reused, even after a failed attempt. The real previous name is `queunuprime` (a typo, permanent). Snapshot folders are always named `2026-10-09-before-<phase>` and checkpoints `...-2026-10-08.json`; the dates are hard-coded by the tools.
- `publish_fm_queue_batch.py` appends to `worker-coordination/queue-run-20261009.json` and edits `primary-status.md` by text replacement; both are expected.
- Never copy the live SQLite queue database; use `recovery_queue.py` on the Windows host.
- Builds under `/mnt/c` fail (`Value too large for defined data type`); the stage is `/root/kh2fm-build`.
- The batch-name lists inside `finish_fm_primary_matrix.py` grow with every batch and are edited only by `prepare_fm_continuation_acceptance.py` (project-specific pattern of the first project's "count your plugin tuple" pitfall: never hand-edit a generated list).
- Not applicable to KH2FM, kept until the user deletes them (first-project pitfalls): shared `CARGO_TARGET_DIR` corrupting builds; `-Only a,b` passing one string; an app window locking its executable; Bevy plugin tuples limited to 15; `validate` rewriting `sheets/systems.json`; screenshots blank before about 6 s.

Current checkpoint: orchfb; rec187 integrated. No recovery worker remains. Authorization expired; rec188 is undispatched.

Open policy discrepancy: DEVIATIONS #7 and return-contract-audit-2026-10-15.md document seven accepted void signatures inconsistent with literal R4.3. Binary equality remains proven. Preserve bound accepted work; do not invent a policy exception. Future candidates must satisfy literal R4.3 or block unresolved ABI.












