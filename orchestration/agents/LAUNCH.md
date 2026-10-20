# Launching outside agents (Codex, opencode, others)

These agents are started by you, in a terminal, from the folder `C:\Users\KoZa\Documents\AGENTS\Codex` (so each tool finds `AGENTS.md` there and can write inside the project). The orchestrator cannot start them. The exact command-line flags below are **not verified**: both tools are installed here (`codex`, `opencode`), but check `codex --help` and `opencode --help` for the current names of the working-directory, approval and non-interactive options before relying on them.

## Before you start an agent

1. The orchestrator (a Claude session running `ORCHESTRATION.md`) must be running, or you must have finished its last integration. External agents may not run while an integration is in progress: `python -I Codex\orchestration\tools\orch.py leases` must show `"paused": "false"`. If it is paused, wait.
2. Add the agent to `orchestration/ROSTER.md` (prefix, tool, model, tier).
3. Make its brief: copy `briefs\REC-template.md` (T1) or `briefs\SPEC-template.md` (T2/T3) to `briefs\<id>.md` (for example `cdx1-rec06.md`), replace the WP and worker id fields, and create its WP directory `Codex\analysis\final-mix\recovery-experiments\orch-shift1\<id>`. The orchestrator does this for you if you ask it to prepare a brief.
4. Check the tool can run the one command everything depends on. In the tool's session run: `python -I Codex\orchestration\tools\kh2w.py probe Codex\orchestration\selftest\orch_selftest_00105de0_v3.cpp`. It must refuse with "already exists". If the tool is blocked by its sandbox, give it permission to run `wsl` and `python` for this folder, or do not use it.

## The launch prompt (paste as the agent's first message)

```
You are a KH2FM recovery worker.
Worker id: <prefix><n>-<brief>   (example cdx1-rec06)
WP id: <prefix><n>-<brief>       (same as the worker id)
Brief: C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\<id>.md
WP directory: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\<id>
WP directory as a WSL path: /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/<id>
WP start (UTC): <time from (Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')>
Follow the instructions in AGENTS.md in the current folder. Read the manual and your brief completely before running any command. Do not ask questions. Your final reply is the WP report from R11.
```

## When it finishes

Tell the orchestrator "<id> finished". It reviews the WP exactly like a Claude worker (`review_wp.py`, a reviewer agent, a spot check) and integrates the approved submissions at the next integration. Nothing an outside agent reports counts until then.

## Stopping an agent

Type "STOP (orchestrator): finish the probe that is running, then follow R12 and send your WP report now." into its session. If the agent has crashed, do nothing: its leases expire within 15 minutes and its targets return to the queue by themselves.

## Per-tool notes

| Tool | Notes |
| --- | --- |
| Codex CLI | Earlier Codex sessions needed approved escalation for WSL commands in this project. Use a mode where `wsl`, `python` and writes under `Codex\analysis` are allowed without a prompt per command, or approve them when asked. Do not give it access outside the project folder. |
| opencode | Same permissions. Set the model in its own configuration. For a model you have not used on this project, start at T1 with the cheapest brief (`REC-template.md`). |
| Any other agent | Needs: a shell it can run PowerShell commands in, read and write access to the project folder, and the ability to follow a long instruction file. If it cannot do all three, do not use it. |
