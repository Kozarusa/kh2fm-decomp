# KH2FM handoff — 2026-10-08

## Resume immediately
Full KH2FM JP PS2 decompilation (`SLPM_666.75`), prioritizing instruction-exact coverage over renaming. Reading this handoff authorizes autonomous continuation. Continue after batches/reports; routine work needs no user response. Use ultracave in chat, readable prose in saved files. No whole-game completion percentage. Preserve failed experiments and historical proofs; do not update handoffs unless requested.

## Locations and authority
- Project/docs/analysis: `C:/Users/KoZa/Documents/AGENTS/Codex`.
- Shared tools/assets: `C:/Users/KoZa/Documents/AGENTS/Public`; compiler reference: `Public/tools/kh2-reference`.
- Audit tools: `Public/tools/kh2-audit`. Historical `analysis/...` paths resolve under Codex; `tools/...` under Public. Old ChatGPT folder is retired; never recreate it as the working root.
- Linux compiler stage: `/root/kh2fm-build`, WSL `Ubuntu-24.04`, user root. Build there, not `/mnt/c`.
- Authority: `analysis/final-mix/README.md`, hash-bound receipts, `WORKER_BRIEF.md`, worker claims/reports. Protected old ClaudeShit material remains read/copy only.

## Accepted baseline
5,481 equal-size exact matches; 5,485 C++ ranges; 5,898 fallback ranges; 1,988 staged inputs; four unchanged padding cases (`0018f9f8`, `0014f148`, `00168370`, `00315440`). Full ELF/provenance/objdiff, 41 recovery bundles, both switch receipts, finalization and warning audit passed before relocation.

Latest manifest: `analysis/final-mix/primary-floatarguments-checkpoint-2026-10-07.json`. Gate: `Public/tools/kh2-audit/verify_fm_primary_floatarguments_checkpoint.py` (path resolution still needs migration before rerunning). Relocation audit verified all 3,985 manifest files, 1,988 build inputs and seven saved artifacts: no missing files or hash differences.

Original ELF SHA256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. ISO SHA256: `9486a553ba4355337d62b937a3206eb0360c23f2e6bf4151f1b134e44b7b47b1`. Compiler image: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`; retain existing flags. Whole-ELF equality retains fallback bytes; it is not a complete source rebuild. Types, boundaries and runtime behavior remain provisional.

## First actions
1. Finish live-tool path migration. Shared `probe_fm_source.py` now uses `/mnt/c/Users/KoZa/Documents/AGENTS/Codex`; end-to-end probe succeeded. `WORKER_BRIEF.md` has the split layout. Other helpers still contain old hardcoded roots or infer Public as the project root. Adapt live resolution; do not bulk-rewrite hash-bound manifests/proofs. Docker works in WSL; no restart needed. This session's sandbox still names the retired root, so new-root writes required approved escalation.
2. Integrate five Worker B round-four exact submissions after independent curation/re-probing: `00150de0` (28 B), `001576e8` (112 B), `0017dec0` (36 B), `00229d40` (40 B), `002e8290` (40 B). Files: `analysis/final-mix/recovery-experiments/fm_worker_b_round4_<address>_solved.cpp` and corresponding `.verification.json`; source hashes and exact flags verified. All five remain unregistered. Eleven earlier Worker B recoveries are already integrated.
3. Continue primary pending work: `fm_primary_sixword_v3_00171480.cpp` now has a complete 48-byte exact proof at the new path; `fm_primary_sixword_v3_00171930.cpp` is prepared but unprobed. `primary-sevenword-probes-v1-bundle.results.json` records exact `00171690` and `00172078` (44 B each); neither is curated/registered yet.
4. Resume further disjoint recovery after acceptance. Read `worker-coordination/primary-claim.json` and Worker B claims before choosing targets. Latest worker report: `worker-coordination/worker-b/STATUS-REPORT.md`; round-four claims contain older statuses, so prioritize current proofs/report. Compiler-impossibility and branch-layout claims remain hypotheses.

## Acceptance and coordination
Fresh isolated source/proof/log; curate complete exact ranges; independently re-probe; register without overlap while preserving aliases; hash-check named stage synchronization; `make verify MAKE_JOBS=8`; cumulative provenance/objdiff/artifacts/bundle/switch checks; finalization and warning audit; new cumulative checkpoint; refresh worker status. Stop dependent actions on any failed command. Keep previous checkpoints.

Primary owns shared registration/stage/full builds/manifests/Ghidra; Worker B owns isolated proposals. Coordinate through filesystem claims and `compiler-status.json`, not unsolicited messages. Do not spawn agents without authorization. Callback repair is saved and independently reopened; older MCP snapshot does not reflect it. Pointer-return parsing was fixed in curator, registration and reference `tools/common.py`; all accepted bundles passed afterward.
