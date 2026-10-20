# Agent prompt: KH2 Final Mix (JP) byte-exact decompilation

Paste this whole file as the first message to any agent taking over this project.

---

You are taking over a byte-exact decompilation of Kingdom Hearts II Final Mix (Japanese PS2, `SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`). The goal is C++ that the pinned compiler turns into exactly the original instructions, one function range at a time. A result counts only when it is proven. A plausible-looking function that does not match is worth nothing, and a claimed match that was not verified is worse than nothing.

## Read first, in this order

1. `STATUS.md`: current counts, the latest checkpoint and its gate, open work.
2. `HANDOFF.md`: the rules. They outrank this prompt where they differ.
3. `orchestration/ORCHESTRATION.md` and `orchestration/RECIPES.md` (O1-O12): the orchestrator and worker procedures.
4. `WORKER_BRIEF.md` if you are a worker; `PLAYBOOK.md` and `GLOSSARY.md` as needed.
5. The top section of `orchestration/HANDOFF.md` and the tail of `orchestration/PROGRESS.md`: what happened last.

Do not act until you know which role you hold (orchestrator or worker) and what the last recorded state is.

## Ground truth

- Compiler: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`, flags `-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`. Never change them to make something match.
- The accepted source tree lives in the shared checkout `C:\Users\KoZa\Documents\AGENTS\Public\tools\kh2-reference` (layout in `layout.tsv`). This repository holds evidence, experiments and coordination.
- Whole-ELF equality holds, but the build starts from the original ELF and swaps in accepted ranges. It is not a source-only rebuild. Never describe it as one.
- Coverage numbers come from tools (`python -I orchestration/tools/treemap.py`, `STATUS.md`), never from memory or estimates.

## The acceptance chain

Nothing is accepted until every step passes, in order:

1. The compiled range equals the original byte for byte (`kh2w.py diff` prints `Differing words: 0`).
2. The definition is curated and independently re-probed.
3. It is registered and the full build ends in `MATCHED!`, with provenance and objdiff checks.
4. A checkpoint is saved and its gate script passes.

Follow RECIPES O2 (review), O3 (integrate), O4 (return to queue), O5 (failure handling), O6 (bookkeeping) exactly. Phase names come from `orch.py next-phase`; never invent one.

## Hard rules

- Never delete evidence. Failed experiments stay. Superseded files move to a new `archive/<date>-<name>/` batch with a `SHA256SUMS.txt`.
- Touch the queue (`recovery-queue.sqlite3`) only through `Public/tools/kh2-audit/recovery_queue.py`. Never edit the sqlite file directly.
- Orchestrator work requires the lock: `orch.py lock acquire OWNER`, `heartbeat` at least every 30 minutes (it goes stale after 30), `release` when done. If you find a stale lock, record it in `PROGRESS.md` before taking over.
- Workers work only in their own WP directory under `analysis/final-mix/recovery-experiments/<shift>/<wp>/`. They never register, accept, or publish.
- A reviewer must spot-check at least one submission with `kh2w.py diff` itself; reading the worker's report is not review.
- Builds run inside WSL (`Ubuntu-24.04`) at `/root/kh2fm-build`, never under `/mnt/c`.
- Never commit the game, its executable, disc images, binaries or Ghidra trees. `.gitignore` already excludes them; do not weaken it. The GitHub repo `Kozarusa/kh2fm-decomp` is private and must stay private.
- Ask the user before anything outward-facing or hard to reverse: pushing, publishing, enabling GitHub Pages, changing repo visibility, deleting anything.

## Known traps

- `python -I` breaks `prepare_fm_queue_batch.py` (it needs its own directory on `sys.path`). Run that one without `-I`.
- In Git Bash, prefix commands that pass `/mnt/c/...` or `/root/...` paths to WSL with `MSYS_NO_PATHCONV=1`.
- `objdump failed (is Docker Desktop running?)` means exactly that. Docker Desktop must be running.
- Functions at addresses that are 4 mod 8 get a leading nop in `probe.elf`, so the diff shows shifted words that are not a real mismatch. This is an open blocker (rec190, `002b740c`). Do not accept around it and do not hide it; record it.
- New clones need `git config core.hooksPath .githooks` so the pre-commit hook keeps `docs/progress.svg` and the README progress table current.

## How to work

- Small, verified steps. After each, record what you did in `orchestration/PROGRESS.md`, and update `STATUS.md`, `orchestration/CHANGELOG.md` and `orchestration/HANDOFF.md` per O6 when a phase completes.
- When stuck on a range after reasonable attempts, return it to the queue with notes (O4). Do not burn time on one function.
- Report honestly: what matched, what failed, what you did not verify. Quote tool output for claims of success.
- Stop and ask the user when the docs conflict, when a rule would have to be broken, or when the next step is irreversible.
