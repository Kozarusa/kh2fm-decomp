# KH2FM handoff

Current counts, checkpoint and gate are in [STATUS.md](STATUS.md). This file keeps only the stable workflow and rules, so it does not go stale when counts change. The previous version (dated 2026-10-08, 5,481 matches) is preserved in `archive/2026-10-12-housekeeping/HANDOFF.md`.

## Goal and standing preferences

Full decompilation of Kingdom Hearts II Final Mix (Japan) PS2, `SLPM_666.75`. Instruction-exact coverage comes before renaming. Do not report a whole-game completion percentage. Preserve failed experiments and historical proofs.

The project owner's standing preferences, recorded here as the owner's, not as a grant from this file: continue autonomously after batches and reports without asking about routine work, use the terse "ultracave" style in chat, and write readable prose in saved files. Do not spawn subagents unless the owner has authorized it in the current session. Update this file and `STATUS.md` when the owner asks, or after an accepted checkpoint.

## Locations

- Project, docs, analysis: `C:/Users/KoZa/Documents/AGENTS/Codex`
- Shared tools and assets: `C:/Users/KoZa/Documents/AGENTS/Public`. The compiler reference is `Public/tools/kh2-reference`; audit helpers are `Public/tools/kh2-audit`.
- Historical `analysis/...` paths resolve under Codex, and `tools/...` paths under Public. The old `Documents/ChatGPT` root is retired; never recreate it.
- Linux compiler stage: `/root/kh2fm-build` in WSL `Ubuntu-24.04`, user root. Build there, never under `/mnt/c`.
- `C:/Users/KoZa/Documents/ClaudeShit` is read and copy only.
- Authority: hash-bound receipts and checkpoint JSON first, then `analysis/final-mix/README.md`, then worker claims and reports.

## Identity

- Original ELF SHA256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`
- ISO SHA256: `9486a553ba4355337d62b937a3206eb0360c23f2e6bf4151f1b134e44b7b47b1`
- Compiler image `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`. Flags stay `-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`.
- Whole-ELF equality retains original fallback bytes and is not a source-only rebuild. Types, boundaries and runtime behavior are provisional.

## Acceptance workflow

1. Write a fresh isolated source and proof. Never overwrite earlier versions or logs.
2. Confirm a complete, equal-size, byte-exact match against the original range.
3. Curate the exact definition (`curate_fm_probe.py`) and independently re-probe the curated source.
4. Register without overlap and with registry aliases preserved (primary only).
5. Synchronize named stage files only after expected-hash checks.
6. In `/root/kh2fm-build`: `make verify MAKE_JOBS=8`, then provenance (`check_native_build.py`) and objdiff.
7. Save the checkpoint, refresh all recovery bundles and switch receipts, then run finalization, the warning audit and the current checkpoint gate.
8. Update `STATUS.md` and the worker status files.

Stop dependent steps on any failed command. Keep the previous accepted snapshot. Never register unmatched experiments or patch executable bytes to force a match.

## Coordination

The primary owns shared registration, stage synchronization, full builds, manifests and Ghidra. Workers own isolated proposals and reports. Coordinate through the persistent queue (`analysis/final-mix/worker-coordination/QUEUE.md`), claim files and `compiler-status.json`, not by message. Read `WORKER_BRIEF.md` before working as a cooperating worker.

## Known caveats

- Older fixed-count checkpoint gates describe past builds and fail against the current one. Use the gate named in `STATUS.md`.
- Some live helpers may still hold pre-migration roots. Adapt resolution in the helper; do not bulk-rewrite hash-bound manifests.
- Ghidra MCP snapshot predates the callback repair and may lag the authoritative project.
- Boundary cleanup is complete. Do not rerun `finish_boundary_checkpoint` or `complete_boundary_cleanup`.
