# KH2FM project: instructions for AI agents

This folder is a reverse-engineering project (Kingdom Hearts II Final Mix, Japanese PS2). Do not explore it. What you do depends on how you were launched.

**If your launch prompt gives you a worker id and a WP id** (for example `cdx1-rec06`), you are a recovery worker. Read these two files completely, in this order, and then do exactly what they say. Do not read anything else first.

1. `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\_shared.md`
2. The brief named in your launch prompt, in `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\briefs\`

Rules that apply to every agent and every model:

- Write only inside your own WP directory. Never edit anything else.
- Use only the commands in the manual. Use the shell for them; do not substitute other tools.
- Never change compiler flags, never run full builds, never touch the queue database directly, never restart Docker or WSL, never publish or send anything off this machine.
- Do not ask questions. The manual covers every situation; when in doubt, block or release the target as it says and report.

**If your launch prompt says you are the orchestrator**, read `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\ORCHESTRATION.md` and follow it. Only one orchestrator may run at a time (the lock in step 0 enforces it).

**If you were launched without any of this**, you are not a worker. Read `C:\Users\KoZa\Documents\AGENTS\Codex\STATUS.md` and wait for the user's instruction.
