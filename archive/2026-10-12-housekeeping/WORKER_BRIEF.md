# KH2FM cooperating worker brief

## Mission

Help recover the Japanese PS2 Kingdom Hearts II Final Mix executable, `SLPM_666.75`. Prioritize additional complete, instruction-exact C++ function recoveries and sound boundary evidence over renaming. Do not report a whole-game completion percentage.

Read `HANDOFF.md`, then the relevant sections of `analysis/final-mix/README.md`. The README and hash-bound JSON evidence are authoritative. Reading the handoff authorizes work to resume; begin useful work without asking whether to start. Use ultracave for chat replies, but readable prose for saved documents and code.

Continue working after successful recoveries and validation. Completing a batch
or writing a progress report is not a stopping condition. Create or update
handoff documents only when the user requests it. Retain required build evidence
without treating evidence collection as a reason to end the work.

Choose targets, resolve routine implementation decisions, investigate failures,
and continue useful work autonomously. Do not require user input for routine
work or coordination. Record blockers in shared reports and move to another
unblocked target. Progress updates do not require a reply before work continues.

Workspace: `C:\Users\KoZa\Documents\AGENTS\Codex`.

## Current filesystem layout

Project documents, analysis, experiments and worker coordination are under `C:/Users/KoZa/Documents/AGENTS/Codex`. Shared tools, the reference repository and original assets are under `C:/Users/KoZa/Documents/AGENTS/Public`; tool executables are in its `tools` directory. Resolve historical `analysis/...` paths against Codex and `tools/...` paths against Public. Preserve historical proof and manifest contents; do not rewrite hash-bound evidence to change paths. The old ChatGPT directory is retired. The Linux compiler stage remains `/root/kh2fm-build`.

## Orientation for a completely new agent

You have no assumed prior context. This is an existing reverse-engineering project, not a request to create a new game or start a repository from scratch. The user wants a full decompilation of the Japanese Final Mix release of Kingdom Hearts II for PlayStation 2. Much work remains. Your immediate contribution is a disjoint, reviewable piece of that effort.

The main executable runs on the PS2 Emotion Engine, an R5900 MIPS-family processor. Additional IOP modules, overlays, VU microprograms, and game scripts are separate parts of the game. Main-executable function recovery does not prove those other parts have been rebuilt. Addresses in this document are hexadecimal original executable virtual addresses, not host-process addresses or ISO file offsets.

In this project, a recovered function is C++ source that the pinned original-era compiler reproduces with exactly the original instructions and size. Names such as `func_00104210` and `D_003677a8` identify provisional functions and globals by original address. They do not establish original developer names or final types. Ghidra pseudocode is an analysis proposal, not accepted source. A fallback range is a portion still supplied from original executable bytes rather than accepted C++ output.

The executable is named `SLPM_666.75`; the ISO is `Kingdom Hearts II - Final Mix (Japan).iso`. Their hashes differ. The build deliberately preserves unrecovered original bytes. Therefore, a byte-identical built ELF means registered replacements were compatible with the original image, not that all game code now has source.

### Read and locate

All paths below are relative to the workspace unless written as absolute paths:

| Path | Purpose |
| --- | --- |
| `HANDOFF.md` | Compact current state, authority, workflow, and unresolved work |
| `analysis/final-mix/README.md` | Detailed authoritative project record; historical counts can be superseded |
| `tools/kh2-reference/SLPM_666.75` | Original target executable used for byte comparison |
| `tools/kh2-reference/src/anon/` | Existing address-named recovery source |
| `tools/kh2-reference/functions.tsv` | Shared function registry; preserve aliases |
| `tools/kh2-reference/layout.tsv` | Shared declared native range layout |
| `analysis/final-mix/native-pseudocode/main.jsonl` | Main executable Ghidra candidates, one JSON record per line |
| `analysis/final-mix/native-pseudocode/function-boundary-comparison.json` | Cross-ledger boundary comparison |
| `analysis/final-mix/native-build/compiler-range-verification.json` | Saved full-build compiler range evidence |
| `analysis/final-mix/recovery-drafts/` | Archived unmatched source; read its README before using it |
| `analysis/final-mix/recovery-experiments/` | Isolated proposals, compiler proofs, and historical failed attempts |
| `tools/kh2-audit/` | Existing audit, probe, curation, synchronization, and checkpoint helpers |
| `/root/kh2fm-build` inside WSL | Existing Linux compiler stage; shared resource |

Read relevant records rather than dumping every large file. Use `rg` to locate target addresses and direct file reads to inspect authoritative evidence. Read helper argument handling before invoking a helper; do not invent flags.

### First actions

1. Read the handoff, this entire brief, and relevant README sections. Resolve missing paths or access through available local resources and shared worker reports. If required evidence remains unavailable, record the limitation and continue work supported by accessible evidence; do not invent project evidence.
2. Run the baseline checkpoint gate. If it fails, retain its output and report the failure before assuming the saved build is valid. You may continue isolated read-only analysis.
3. Inspect existing worker claims, the active registry, and saved compiler range evidence for the six round-4 addresses in the assignment below. Claim only still-unrecovered, unclaimed targets.
4. Inspect round-4/targets.json, its referenced source versions, and complete compiler mismatch proofs. Inspect complete original instructions and range boundaries before changing source.
5. Write a worker-specific claim and begin a new isolated source version. Coordinate shared compiler access through shared files, then probe. While compiler access is unavailable, prepare sources and reproducible probe commands and continue independent analysis.
6. Deliver the return package described below. Do not wait for perfect recovery of the entire batch to save useful evidence.

No new compiler installation, repository clone, broad dependency upgrade, or global configuration change is needed for this assignment. Existing tools are already installed. A missing or unavailable runtime is a concrete blocker to investigate, not permission to replace the project's toolchain.

## Current baseline

The current accepted baseline is verified by the gate below:

- 5,707 equal-size, unmodified compiler matches across 5,711 C++ ranges.
- 5,706 original fallback ranges and 2,179 verified staged inputs.
- Four unchanged four-byte zero-padding cases: `0018f9f8`, `0014f148`, `00168370`, `00315440`.
- Latest manifest: `analysis/final-mix/primary-delegatedbatch-checkpoint-2026-10-08.json`.
- Gate: `python tools/kh2-audit/verify_fm_primary_delegatedbatch_checkpoint.py`.

The primary worker has completed matrix `0011d500`, all 220 bytes, with full-build
acceptance. Its source is `tools/kh2-reference/src/anon/fm_primary_matrix_recovered.cpp`.
Do not spend your new assignment on this now-recovered range.

Worker B's four delivered initializers are also integrated: `00161410`,
`001995f8`, `001ba060`, `001c8e00`. The primary worker has repaired the callback
export and accepted additional small, width-profile, and instruction-refinement ranges. Check the current status at
the top of `analysis/final-mix/README.md` and the shared primary status file
before relying on historical counts or fixed-count gates.

These counts are a baseline, not permission to overwrite later work. Check current evidence before choosing targets. Whole-ELF equality does not establish a complete source rebuild: the builder starts from the original ELF and replaces registered C++ ranges. Types and runtime equivalence remain provisional.

Original ELF SHA256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.

Original ISO SHA256: `9486a553ba4355337d62b937a3206eb0360c23f2e6bf4151f1b134e44b7b47b1`.

## Historical assignment: Worker B, round 4 (superseded)

Read `analysis/final-mix/worker-coordination/worker-b/round-4/INSTRUCTIONS.md` and its hash-bound `targets.json`.

| Address | Bytes | Closest archived differing words |
| --- | ---: | ---: |
| `0014b950` | 88 | 6 |
| `00109e30` | 92 | 6 |
| `00242500` | 92 | 6 |
| `001ac310` | 104 | 6 |
| `001e7230` | 104 | 6 |
| `001576e8` | 112 | 6 |

Eleven exact Worker B recoveries across rounds one through three are integrated. Preserve their evidence. All unresolved earlier targets remain yours but deferred; compiler-limit explanations remain hypotheses. Continue focused recovery with the pinned image and flags, then claim another disjoint unregistered fallback autonomously.

## Coordination and ownership

Use `analysis/final-mix/worker-coordination/worker-b/` for a claim, progress notes, and final report. Use filenames beginning `fm_worker_b_round4_` for new isolated C++ experiments in `analysis/final-mix/recovery-experiments/`. Create new version names rather than overwriting existing sources or proofs.

Before editing, write `round-4/claim.json` containing your worker ID, chosen addresses, baseline source/evidence hashes, and intended output paths. A claim is advisory, not an atomic lock; check other claims and communicate overlapping work before proceeding. Keep claims current when changing targets.

You own isolated proposals and reports. The primary worker owns shared integration: `tools/kh2-reference/functions.tsv`, `layout.tsv`, active source registration, staged synchronization, full builds, checkpoint manifests, recovery bundles, switch receipts, finalization, and `HANDOFF.md`. Do not modify those shared outputs independently.

The shared Linux compiler stage is `/root/kh2fm-build`. Read `analysis/final-mix/worker-coordination/compiler-status.json` and coordinate compiler access through shared claims and status files before running probes. This activity record is advisory, not an atomic lock. If access cannot be established, deliver prepared sources and exact probe commands through your report and continue independent analysis. Do not run a full build, synchronize shared stage inputs, restart Docker, or mutate a Ghidra project concurrently with another worker.

Use shared claim, status, and report files for worker coordination without routing routine decisions through the user. Use other communication channels only within their existing authorization.

## Evidence and acceptance

1. Verify the original ELF identity and target start/end against current ledgers. Ghidra body sizes are advisory and can be wrong.
2. Record complete original instruction ranges and their hashes. Never truncate a mismatch to claim success.
3. Save each candidate under a new isolated filename, with readable rationale for any inline assembly or register constraints.
4. Use the existing isolated compiler probe when compiler access is coordinated. Keep successful and failed logs, source hashes, and full byte proofs.
5. A candidate is exact only when its complete compiled size and bytes equal the complete original declared range. Keep padding distinct from function instructions.
6. Curate exact definitions with `curate_fm_probe.py`, then independently re-probe the curated source. Hash-bind both stages.
7. Hand the primary worker the complete package. Only deliberate nonoverlapping registration, preserved aliases, full native build, provenance, objdiff, finalization, and current checkpoint verification establish an integrated recovery.

Never register unmatched experiments. Do not present isolated probe success as full-build acceptance. Do not infer established types, parameter semantics, overlay lifecycle, or runtime behavior from byte equality alone.

## Lessons from the latest accepted recoveries

Diagnose the first differing instructions before generating variants. Check
argument width, signed-low external-address materialization, saved registers,
store scheduling, quadword copies, and floating-point argument transport where
the original instructions support them. These are observations, not final types.
Keep searches bounded; repeated unproductive variants are a reason to move to
another target, not to stop work.

Put shared structures, typedefs, and constants before the first function
definition. The curator can omit declarations placed between functions.
Independently re-probe the curated file; never reuse a successful raw probe as
proof that a different curated source compiles. Preserve failed versions.

Use the pinned EE disassembler and original words for instruction evidence.
Worker B's hand-written R5900 decoder is advisory and has known inaccuracies.
Old fixed-count gates describe historical builds; a newer count failing an old
gate does not by itself establish corruption. Use the current README gate.
The Ghidra MCP snapshot predates the saved callback repair and its backend may
be unavailable; direct saved exports and reproducible local tools remain usable.

## Existing tools

- `tools/kh2-audit/probe_fm_source.py`: isolated Linux compile/link and complete-range byte comparison. Runs under WSL and imports the shared stage's build helpers. Input source must be within the workspace.
- `tools/kh2-audit/curate_fm_probe.py`: extracts hash-bound exact definitions into a new source. Requires independent re-probing afterward.
- `tools/kh2-audit/register_fm_batch.py`: shared registration; primary worker only.
- `tools/kh2-audit/sync_fm_boundary_checkpoint.py`: shared synchronization helper; inspect its contract before use.
- `tools/kh2-audit/check_native_build.py`: staged source provenance.
- `tools/kh2-audit/save_fm_native_checkpoint.py`: shared checkpoint saving.

Example coordinated probe:

```powershell
wsl -d Ubuntu-24.04 -u root -- python3 /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-audit/probe_fm_source.py /mnt/c/Users/KoZa/Documents/ChatGPT/analysis/final-mix/recovery-experiments/fm_worker_b_round4_v1.cpp --summary
```

Build only in `/root/kh2fm-build`; builds under `/mnt/c` fail with `Value too large for defined data type`. WSL requires escalation in the current environment. Use LF shell files. Compiler image: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`. Never use stale binaries after a failed build.

Codebase memory is available through `codebase-memory-mcp cli`; inspect `index_status` and command help before use. The `kh2fm-reference` index is navigation only. Use original instructions and direct source for proof, and `rg` when indexing misses constructs.

Ghidra MCP is available through the workspace's restricted query helper. Read `analysis/final-mix/tool-integrations/README.md`. Its project is an isolated analysis snapshot; decompilation, disassembly, call graphs, and P-code are advisory and do not replace compiler gates.

## Hard boundaries

- `C:\Users\KoZa\Documents\ClaudeShit` is READ/COPY ONLY. Never edit its originals, tools, or projects.
- Target FM. US ISO artifacts, `decompiled/`, and `analysis/coverage/` are legacy. `reconcile.py` is US-only. Use `--target fm` where supported.
- Preserve original registry aliases, staged edits, and prior evidence. Synchronize named files only after expected prior-stage SHA checks.
- Do not rerun `finish_boundary_checkpoint` or `complete_boundary_cleanup`; boundary cleanup is complete.
- Do not hand-edit Ghidra output to masquerade as a corrected decompiler export. Record annotations separately or produce a reproducible analysis/export correction.
- Do not modify executable bytes to force a match.
- Condensed command output is the complete result. Use `rtk proxy` only for unusable output, as specified by the workspace instructions.

## Return package

Save `analysis/final-mix/worker-coordination/worker-b/round-4/REPORT.md` with:

- Claimed and completed addresses, complete range sizes, and current registration status.
- Exact paths and SHA256 hashes for each source, original-range evidence, probe proof, curated source, independent reprobe, and logs.
- Exact versus unmatched results; describe the first differing instructions for unmatched candidates.
- Boundary disagreements, provisional assumptions, and any remaining requirements.
- Commands the primary worker needs to reproduce your results.
- An explicit statement that shared registration and full-build integration remain pending unless the primary worker has completed them.

Share a concise progress message pointing to the report, then continue with the
next unclaimed target within your assignment. Preserve partial evidence if
blocked; identify the specific blocker and useful next action, then continue
another unblocked target without requiring a user reply.

## Next Worker B assignment (2026-10-08)

Read `analysis/final-mix/worker-coordination/worker-b/round-5/INSTRUCTIONS.md`. Its five unresolved ranges supersede the active round-four assignment; historical packets and reports remain evidence. All five round-four exact submissions are accepted.

## Current Worker B assignment: round six

All five round-five exact submissions are accepted, including the subsequently proved
`00242500`. The 118-proposal worker backlog has passed cumulative acceptance. Continue the
disjoint round-six claim after reading `analysis/final-mix/worker-coordination/worker-b/round-6/PRIMARY-INSTRUCTIONS.md`.
Use the current primary status for acceptance counts and compiler coordination. Numeric
register names such as `$15` and operand constraints are supported by the pinned compiler;
a rejected symbolic `$t7` spelling is not compiler-impossibility evidence.

Callbackaddress accepts four complete 48-byte ranges: 001dc488, 001de948, 001e0128 and 001e0188. Signed low offsets establish globals 01d5bb00 and 01d9e340; earlier proposals decoded these incorrectly. Curated independent probes, full build, all 76 cumulative bundles, both switches, finalization, warning audit and current gate passed. The four-hour session has accepted 46 ranges and 2,840 instruction bytes. The positive-control machine census finds exactly these four instances of this instruction family.

Callbackreturn accepts five complete 52-byte ranges: 001050d8, 0016c7a0, 0016fac8, 00288be8 and 0028cc08. Capturing the original return address before the object loads reproduces the original scheduling. Independent curated probes, full build, all 77 bundles, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 51 ranges and 3,100 instruction bytes. Positive-control census covers all eleven tracked instances; the other six were already accepted.

Mediumcall accepts 1 complete ranges (00123d40), totaling 76 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 52 ranges and 3,176 instruction bytes.

Tablelookup accepts 1 complete ranges (00132f38), totaling 96 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 53 ranges and 3,272 instruction bytes.

Freshhelpers accepts 2 complete ranges (001367e0, 0013c7d0), totaling 176 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 55 ranges and 3,448 instruction bytes.

Aliashelpers accepts 2 complete ranges (00137458, 0013b4b0), totaling 160 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 57 ranges and 3,608 instruction bytes.

Packetalias accepts 2 complete ranges (001337f0, 00133980), totaling 168 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 59 ranges and 3,776 instruction bytes.

Virtualguard accepts 1 complete ranges (0013e5a8), totaling 100 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 60 ranges and 3,876 instruction bytes.

Quadtransport accepts 2 complete ranges (0013f828, 00140850), totaling 172 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 62 ranges and 4,048 instruction bytes.

Bytewrapper accepts 1 complete ranges (0014e140), totaling 84 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 63 ranges and 4,132 instruction bytes.

Globalargument accepts 1 complete ranges (0014f578), totaling 88 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 64 ranges and 4,220 instruction bytes.

Flagguard accepts 1 complete ranges (00157160), totaling 92 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 65 ranges and 4,312 instruction bytes.

Floatresult accepts 1 complete ranges (00155658), totaling 100 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 66 ranges and 4,412 instruction bytes.

Lookupswitch accepts 2 complete ranges (00155ee8, 00155fc0), totaling 168 instruction bytes. Independent curated probes, full build, cumulative bundle checks, both switches, finalization, warning audit and the current gate pass. The four-hour session has accepted 68 ranges and 4,580 instruction bytes.

The lookup-switch batch recovers complete 88-byte 00155ee8 and 80-byte 00155fc0 plus independently proves their two 20-byte compiler-generated label tables. All three switch batches now cover five code ranges and five generated tables. The tables match in auxiliary linked data; function references resolve to original absolute table addresses, and the rebuilt ELF still retains original table bytes. This is not data integration or a source-only rebuild. The new native table checker consumes hash-bound current compiler records and directly compares linked code as well as data.

Indexedmask accepts 1 complete ranges (001584a0), totaling 88 instruction bytes. Independent curated probes, full build, cumulative bundle checks, all active switch batches, finalization, warning audit and the current gate pass. The four-hour session has accepted 69 ranges and 4,668 instruction bytes.

Maskpair accepts 2 complete ranges (00158548, 00159ce0), totaling 168 instruction bytes. Independent curated probes, full build, cumulative bundle checks, all active switch batches, finalization, warning audit and the current gate pass. The four-hour session has accepted 71 ranges and 4,836 instruction bytes.

Delegatedbatch accepts 5 complete ranges (00148638, 0014ec40, 00158b20, 00158fd8, 00159c58), totaling 440 instruction bytes. Independent curated probes, full build, cumulative bundle checks, all active switch batches, finalization, warning audit and the current gate pass. The four-hour session has accepted 76 ranges and 5,276 instruction bytes.
