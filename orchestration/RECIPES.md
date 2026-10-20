# Orchestrator recipes O1-O12

Exact procedures referenced by `ORCHESTRATION.md`. Worker recipes R0-R12 live in `briefs/_shared.md`. Run every command from `C:\Users\KoZa\Documents\AGENTS` with the PowerShell tool unless a step says otherwise. `PHASE` and `PREVIOUS` always come from `orch.py next-phase`; never type them from memory.

Short names used below:

| Name | Path |
| --- | --- |
| `ORCH` | `Codex\orchestration` |
| `TOOLS` | `Codex\orchestration\tools` |
| `QUEUE` | `python Public\tools\kh2-audit\recovery_queue.py` |
| `EX` | `Codex\analysis\final-mix\recovery-experiments` |
| `WPROOT` | `Codex\analysis\final-mix\recovery-experiments\orch-shift1` |

## O1. Start a wave (spawn workers)

1. `get_usage`. Apply rule 4 (60%: one worker only; 90%: wrap up; weekly 80%: final stop).
2. `python -I TOOLS\orch.py leases`: no leases, nothing submitted. If something is submitted, finish its review and O3 first.
3. For each WP of the wave:
   1. Create the WP directory `WPROOT\<wp>\` (`New-Item -ItemType Directory -Force <path>`).
   2. Note the UTC start time: `(Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')`.
   3. Call the Agent tool with `subagent_type: "general-purpose"`, `model` from the brief header (never `fable`), `run_in_background: true`, `description: "KH2FM <wp> worker"`, and this prompt (fill the angle brackets):

```
You are worker <wp> of the KH2FM recovery project, model <model>, worker id orch1-<wp>.
Read these two files completely, in this order, before running any command, then follow them exactly:
1. C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\_shared.md
2. C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\<wp>.md
Your WP directory: <Windows path of WPROOT\<wp>>
Your WP directory as a WSL path: /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/<wp>
WP start (UTC): <start time>
Do not ask questions; the manual answers them. Your final reply is the WP report from R11.
```

   4. PROGRESS line: `<UTC> | spawn | <wp> model <model> agent <agent id> start <start time>`.
4. Do not wait idle: while workers run, do docs-only work, reviews of finished WPs, or bookkeeping.

## O2. Review a WP report

When a worker's report arrives:

1. PROGRESS line: `<UTC> | report | <wp> <status> submitted <s> blocked <b> released <r>`.
2. Mechanical check: `python -I TOOLS\review_wp.py WPROOT\<wp> <WP start UTC>`. It writes `review-auto-<n>.json` in the WP directory and prints PASS/FAIL/FLAG lines.
3. Compare the report with the queue: every "submitted" line in the report must appear as a PASS or FAIL line; anything the report claims that the checker does not show is a false claim (record it under Problems in PROGRESS and treat that address as DO NOT MERGE).
4. Reviewer agent (recovery WPs only; tooling WPs skip to step 5): Agent tool, `model: "sonnet"`, `subagent_type: "general-purpose"`, `run_in_background: true`, prompt:

```
You are the reviewer for KH2FM work package <wp>. Read C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\_reviewer.md completely and follow it exactly.
WP directory: <Windows path>. WP start (UTC): <start time>. Worker report: <WP directory>\WP-REPORT.md.
Your final reply is the REVIEW.md text described in the brief.
```

5. Spot-check (you, LOOKED at): pick one MERGE address, open its submitted `.cpp`, and run `python -I TOOLS\kh2w.py diff <its .verification.json>`. It must print `Differing words: 0`. PROGRESS line: `<UTC> | review | <wp> verdict <overall> merge <list> reject <list> spot <address> ok`.
6. Apply the verdicts: DO NOT MERGE addresses go through O4 now. MERGE addresses wait for O3.
7. Tooling WP: run each script it delivered once, read the output, check that it wrote only the files its brief names; PROGRESS line with the result.

## O3. Integrate (the acceptance transaction)

Only when no worker runs, `orch.py leases` shows no leases, and every submitted address has a MERGE verdict (others went through O4).

1. `python -I TOOLS\orch.py leases`: `leases` is empty, and `submitted_awaiting_integration` equals the MERGE list. If not, stop and fix that first (O4 or wait).
2. `QUEUE pause`. Then `QUEUE status`: `"paused": true`, no `leased` rows.
3. `python -I TOOLS\orch.py next-phase` gives `PREVIOUS` and `PHASE`. PROGRESS line: `<UTC> | integrate-start | PHASE after PREVIOUS addresses <list>`.
4. `python -I TOOLS\orch.py mark-integrating PHASE`.
5. Curate: `python Public\tools\kh2-audit\prepare_fm_queue_batch.py curate PHASE`
   Expect one `Curated 1 exact definitions; new source remains isolated.` line per submission and the final line `Curated <n> proposals; independent probes required.` On any error: O5a.
6. Independent probes (WSL; can take a few minutes, use `run_in_background` if more than 10 proposals):
   `wsl -d Ubuntu-24.04 -u root -- python3 /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/probe_PHASE.py`
   Expect one `fm_primary_PHASE_recovered_<address>.cpp: complete independent exact proof; diagnostics saved` line per proposal and exit code 0. On any error: O5a.
7. Register: `python Public\tools\kh2-audit\prepare_fm_queue_batch.py register PHASE PREVIOUS`
   Expect `Prepared PHASE: <n> functions, prior <count> exact matches.`, one `Registered 1 FM candidate functions from src/anon/...` line per proposal, and `Registered <n> proposals; exclusive full acceptance required.` From this step on, any error is O5b.
8. Full build and cumulative checks (WSL, long: run with `run_in_background: true` and wait for the completion notice):
   `wsl -d Ubuntu-24.04 -u root -- python3 /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/accept_PHASE.py`
   Expect the last line `Native checks, saved artifacts, <B> recovery bundles, and 3 switch receipts passed.` Write down `B`. Also check that `Codex\analysis\final-mix\native-build\primary-PHASE-make-verify.log` ends with `MATCHED!`. Any error or a different ending: O5b.
9. Publish: `python Public\tools\kh2-audit\publish_fm_queue_batch.py PHASE PREVIOUS`
   Expect `Primary PHASE checkpoint PASS: ...` (twice, from the two gate runs) and finally `Published PHASE: +<n> ranges, <total> exact total.` This also resolves the queue entries as accepted, sets the compiler status to idle and resumes the queue. Any error: O5b.
10. `powershell -NoProfile -ExecutionPolicy Bypass -File TOOLS\preflight.ps1` prints `PREFLIGHT: PASS phase=PHASE ...` with the new totals.
11. LOOK: open one `EX\fm_primary_PHASE_recovered_<address>.cpp` and run `python -I TOOLS\kh2w.py diff EX\fm_primary_PHASE_recovered_<address>.verification.json`: `Differing words: 0`.
12. PROGRESS line: `<UTC> | integrate-pass | PHASE +<n> exact <total> fallback <f> bundles <B>`. Then O6.

## O4. Return a submission to the queue (not accepted)

```
QUEUE resolve --address <A> --evidence <path to REVIEW.md, review-auto-<n>.json or the failing log> --queue general
```

No `--accepted` flag. The address becomes `ready` again with the attempt recorded. PROGRESS line: `<UTC> | resolve-reject | <A> <one-line reason> evidence <path>`. If the reason is a technique violation, also add a DEVIATIONS row (P1).

## O5. Integration failure

**O5a (before registration: curate or independent probe failed).** Nothing shared has changed yet.
1. Keep every file. The name `PHASE` is now burned (it has files); `orch.py next-phase` will skip it automatically.
2. Find the failing address: for curate, the last `Curated` line before the traceback names the source; for the probe runner, the last printed source, or the newest `EX\fm_primary_PHASE_recovered_*.independent-probe*.log`.
3. O4 for that address with the log as evidence.
4. `QUEUE resume` is NOT needed; restart O3 at step 3 (the queue is still paused, the remaining submissions are still submitted).
5. PROGRESS line: `<UTC> | integrate-fail-a | PHASE <step> <address> <reason>`.

**O5b (registration, full build or publish failed).** Shared files may have changed. Do not repair anything.
1. Run no further compiler, registration, sync or publish command. Do not resume the queue. Leave `compiler-status.json` as it is.
2. Record under "Needs the user" in `ORCH\HANDOFF.md`: PHASE, PREVIOUS, the step number, the exact command, the last 40 lines of its output, the log paths (`native-build\primary-PHASE-make-verify.log` if it exists), and the snapshot `Codex\analysis\final-mix\accepted-snapshots\2026-10-09-before-PHASE\`.
3. PROGRESS line: `<UTC> | integrate-fail-b | PHASE step <n>`.
4. Continue only docs-only WPs and reviews; then final stop (section 9) and U2 with this failure first.

## O6. Bookkeeping after a publish

1. `python -I TOOLS\orch.py state`.
2. Edit `Codex\STATUS.md`: in "Accepted state" replace the six values (exact matches, C++ ranges, fallback ranges, staged inputs, recovery bundles = `B` from O3 step 8, switch batches = 3); replace the "Latest checkpoint" and "Gate" lines with the `checkpoint` and `gate` values; set "Last reconciled" to today and "from the PHASE checkpoint".
3. Append to `ORCH\CHANGELOG.md` under the shift heading: `- PHASE: +<n> functions (<addresses>), <bytes> instruction bytes; exact <total>, fallback <f>.` (bytes: sum of `target_size` in the curated `.verification.json` files, or the publish line in `primary-status.md`).
4. Update `ORCH\HANDOFF.md` section "State" with the same numbers and mark the WPs as integrated in `ORCHESTRATION.md` section 5 (`integrated PHASE`).
5. PROGRESS line: `<UTC> | bookkeeping | PHASE`.

## O7. Stop workers

0. Outside agents (Codex, opencode) cannot be messaged by you: tell the user in chat, in one line, "Please stop <ids> (paste: STOP (orchestrator): finish the probe that is running, then follow R12 and send your WP report now.)", and continue with step 2 when they confirm or when `orch.py leases` shows no leases for them.
1. SendMessage to every running Claude worker: `STOP (orchestrator): finish the probe that is running, then follow R12 in _shared.md and send your WP report now.`
2. Wait for each report (they arrive as notifications). Review them (O2).
3. `python -I TOOLS\orch.py leases` until no leases remain; a dead worker's lease expires within 15 minutes.
4. PROGRESS line: `<UTC> | stop | <reason>`.

## O8. Actions that wait for the user's explicit yes

Ask in chat (one message, numbered, with the default "no"), then continue other work. Only an explicit yes in chat for that specific action allows it: deleting or compressing anything under `Codex` or `Public`, editing hash-bound files or checkpoints by hand, changing compiler, flags, toolchain or build helpers, restarting Docker Desktop or WSL, unparking Codex worker `recovery-a`, sending anything off this machine.

## O9. Follow-up brief for a partial tooling WP

Copy `briefs\<id>.md` to `briefs\<id>b.md`. Keep the header (same model; depends on `<id>`). Under "Steps", paste the steps the report lists as not done, verbatim, then the worker's "exact next step" line. Add the row to `ORCHESTRATION.md` section 5 and put it at the front of the next wave. Recovery WPs need no follow-up brief: the queue holds their remaining work, and the next REC/SPEC WP picks it up.

## O10. Close a WP

1. `python -I TOOLS\orch.py leases`: no lease owned by `orch1-<wp>`.
2. Nothing is deleted: the WP directory is evidence.
3. PROGRESS line: `<UTC> | close | <wp> <integrated PHASE | nothing to integrate | not done: reason>`.

## O11. Usage

Load once per session: ToolSearch `select:mcp__ccd_session_mgmt__get_usage`. Call it before every spawn, after every integration, and at every wave start. Record each reading in PROGRESS: `<UTC> | usage | 5h <p>% weekly <q>%`. Thresholds: rule 4 of `ORCHESTRATION.md`.

## O12. Write new recovery briefs when the waves run out

1. Next general WP: copy `briefs\REC-template.md` to `briefs\rec<NN>.md` (next unused number), replace `<NN>`. Model sonnet.
2. Next specialist WP: copy `briefs\SPEC-template.md` to `briefs\<family><NN>.md`, fill the queue list from the family table in that template. Model opus.
3. Add the rows to `ORCHESTRATION.md` section 5 and a new wave line (one SPEC + one REC per wave, or two REC when the specialist queues are empty: check with `QUEUE status`).
4. PROGRESS line: `<UTC> | briefs | <names>`.
