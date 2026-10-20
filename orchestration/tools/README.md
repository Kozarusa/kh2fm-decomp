# Orchestration tools

All run on the Windows host from `C:\Users\KoZa\Documents\AGENTS`. Python scripts use only the standard library; run them with `python -I`. None of them changes the queue, registries, sources, stage or checkpoints, except where noted.

| Tool | Used by | What it does |
| --- | --- | --- |
| `preflight.ps1` | orchestrator (step 0, after every integration) | Docker in WSL, stage executable hash, compiler idle, queue view, build record, then the current checkpoint gate (which rewrites the checkpoint JSON, as the project always has). Ends with `PREFLIGHT: PASS ...`. `-SkipGate` is for testing only. |
| `orch.py next-phase` | orchestrator (O3) | Previous accepted phase and the next unused `orchXX` name. |
| `orch.py state` | orchestrator (O6) | Accepted counts, checkpoint and gate path from the saved build records. |
| `orch.py leases` | orchestrator | Pause flag, live leases, submissions awaiting integration (read-only database view). |
| `orch.py mark-integrating PHASE` | orchestrator (O3 step 4) | The one write: marks `compiler-status.json` as integrating (UTF-8 without BOM). |
| `kh2w.py packet ADDRESS OUTDIR` | workers (R2) | Writes `ADDRESS-packet.md`: range, original disassembly with decoded `D_` addresses, callees with registry names, legacy-assembly flags and accepted callers, Ghidra pseudocode, earlier attempts. Uses WSL Docker objdump on the stage, read-only. |
| `kh2w.py probe SOURCE` | workers (R5) | Runs the project's isolated probe through at most 3 shared slots (`orchestration/locks/probe-slot-*.lock`, stale after 10 minutes). Refuses a version name whose `.verification.json` exists. |
| `orch.py lock acquire/heartbeat/release/status OWNER` | orchestrator | The single-orchestrator lock `orchestration/locks/ORCHESTRATOR.lock` (stale after 30 minutes without heartbeat). |
| `kh2w.py diff PROOF [OUTFILE]` | workers (R6), reviewers, orchestrator spot-checks | Side-by-side original and compiled disassembly of one probe, with differing lines marked `!!`. |
| `review_wp.py WP_DIR START_UTC` | orchestrator (O2), reviewer | Mechanical review of a WP's submissions and of changes outside the WP; writes `review-auto-<n>.json` in the WP directory. |

Tested on 2026-10-12: preflight with `-SkipGate`, both `orch.py` read commands, `kh2w.py packet` on `00106a18` and `00105de0`, `kh2w.py diff` on a saved 4-word mismatch, and `review_wp.py`'s source checks against 362 accepted sources (calibrated so accepted practice passes, except the known `func_00139768` collision and older raw Ghidra names).

October 16 successor helpers (orchestrator only):

- `gpt6_log.py EVENT DETAIL` appends one event to the preserved Shift 2 log and heartbeats the current owner's lock. Rebind its owner before a successor uses it.
- `gpt6_context.py` reads this chat's native context counter, including growth across compaction. Rebind its rollout path for a successor; it prints only context counters and never conversation text.
- `check_saved_proofs.py WP [WP ...]` reads every saved proof in the named work packages and checks source SHA-256, sizes, word counts, exactness and original ELF slices. It neither probes nor builds.
- `record_checkpoint_docs.py PHASE BUNDLES WP [WP ...]` updates STATUS, CHANGELOG, HANDOFF, ORCHESTRATION and GPT6-MEMORY from an already published checkpoint. Run only after full O3, preflight, coverage and the accepted-source spot check pass, with no recovery workers remaining. Supply the bundle count printed by acceptance. Inspect the resulting current-state text before dispatching another wave.
- `reconcile_oct16_resume.py` and `update_resume_handoff.py` are one-time evidence of this successor's initial reconciliation. Do not rerun them against a later checkpoint.

