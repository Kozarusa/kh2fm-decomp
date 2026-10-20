# Worker B: next assignment — 2026-10-08

Resume immediately. Read `C:/Users/KoZa/Documents/AGENTS/Codex/WORKER_BRIEF.md`, the current final-mix README, your round-four reports, and live coordination files.

Primary has accepted your five round-four exact submissions: 00150de0, 001576e8, 0017dec0, 00229d40 and 002e8290. Do not repeat or modify these delivered sources. The accepted baseline is now 5,503; cumulative acceptance passed all 49 bundles and both switch receipts.

## Assignment

Recover the five remaining assigned round-four ranges, using new `fm_worker_b_round5_<address>_v<number>.cpp` files:

| Address | Complete bytes | First investigation |
| --- | ---: | --- |
| 00109e30 | 92 | Preserve the original pre-branch stores and delay-slot nop; inspect narrowly constrained ordering rather than shortening the range. |
| 0014b950 | 88 | Verify all R5900 64-bit shifts with pinned ee-objdump before changing the pack expression. Then test association and value lifetimes. |
| 001ac310 | 104 | Separate load/store ordering from base-address formation; inspect original early ra restoration and narrow constraints. |
| 001e7230 | 104 | Preserve a1 while reusing the observed t6 counters; test explicit value transport and register constraints. |
| 00242500 | 92 | Reconstruct the shared tail from original instructions before testing branch polarity. The disputed store is sw. |

The hash-bound starting packet is `analysis/final-mix/worker-coordination/worker-b/round-4/targets.json`. Use the complete original bytes, original range hashes, archived source/proof paths and best subsequent round-four proposals. Confirm each declared range against current layout.tsv and the original ELF. No finite variant search establishes compiler impossibility.

Write a round-five claim before edits, recording original/source/proof hashes and output paths. Prioritize 00109e30, 0014b950 and 001e7230. If a target stops producing evidence, preserve its measured residual and move to the next. After this batch, autonomously claim further disjoint unregistered fallback ranges, checking primary and other worker claims first.

## Current layout and compiler

Project: `C:/Users/KoZa/Documents/AGENTS/Codex`. Shared tools/reference/assets: `C:/Users/KoZa/Documents/AGENTS/Public`. Historical analysis paths resolve under Codex; tools paths resolve under Public. Never recreate the retired ChatGPT root or rewrite historical hash-bound proofs.

The shared probe now supports the new project path. Use WSL Ubuntu-24.04, root, and `/root/kh2fm-build`. Run the existing probe at `/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py` against isolated sources under `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/`. Keep the pinned image and existing flags. Check `compiler-status.json` before every probe batch. While primary is synchronizing/building/accepting, prepare sources and inspect originals without compiler use.

The historical relocated read-only baseline gate is `Public/tools/kh2-audit/verify_fm_relocated_baseline.py`, run from the AGENTS directory. It passed 5,481 exact matches, all 41 bundles, both switch receipts and callback repair. Once primary accepts another batch, use the new current gate rather than this fixed-count historical baseline.

## Deliverables and boundaries

For each success, supply fresh source, complete proof, compiler/link logs, SHA256 values, rationale and exact reproduction command. Curate complete exact definitions with the shared curator, then independently re-probe. Write `round-5/REPORT.md` and update your status report with accepted versus isolated proposals clearly separated.

You own isolated proposals and worker reports. Primary owns active sources, functions.tsv, layout.tsv, stage synchronization, full builds, manifests, cumulative receipts and Ghidra. Do not mutate those shared outputs, restart Docker, change compiler flags or patch executable bytes. Coordinate through filesystem claims/status; no routine user input needed. Continue after reports and batches. Source types, boundaries and runtime behavior remain provisional; whole-ELF equality retains fallback bytes.

Current accepted gate: `Public/tools/kh2-audit/verify_fm_primary_storeorder_checkpoint.py`. Manifest: `analysis/final-mix/primary-storeorder-checkpoint-2026-10-08.json`. Run the gate from AGENTS. The older relocated baseline gate has fixed counts and no longer describes the current build.
