# KH2FM handoff — 2026-10-07

## Goal and authority
Full KH2FM JP PS2 decompilation (`SLPM_666.75`); prioritize coverage and correctness before renaming. Do not report a whole-game completion percentage.

Workspace: `C:\Users\KoZa\Documents\ChatGPT`. Authority: `analysis/final-mix/README.md` and hash-bound JSON evidence. All analysis paths below are relative to `analysis/final-mix/` unless stated otherwise.

`C:\Users\KoZa\Documents\ClaudeShit` is READ/COPY ONLY. Never edit its originals, tools or projects. The US ISO, `decompiled/` and `analysis/coverage/` are legacy; `reconcile.py` is US-only. Use `--target fm` for audits/scans. Never use stale binaries after a failed build.

Future handoff reads authorize autonomous resumption without asking. Continue working after successful recoveries and validation; completing a batch is not a stopping condition. Create or update handoff documents only when the user requests it. Use ultracave for replies and readable prose for persisted code/docs. Condensed command output is complete.

Choose targets, resolve routine implementation decisions, investigate failures,
and advance through available work autonomously. Do not require user input for
routine work or worker coordination. Coordinate through shared claims and
reports. When a task is blocked, record the evidence and continue another
unblocked task. Progress updates do not require a reply before work continues.

## Current verified checkpoint
- 5,304 equal-size, unmodified compiler matches; 5,308 C++ ranges; 6,071 original fallback ranges.
- 1,861 verified staged inputs; 628 local recovery additions.
- Four unchanged four-byte zero-padding cases: `0018f9f8`, `0014f148`, `00168370`, `00315440`. No truncation.
- Whole ELF, native scope/provenance, objdiff, finalization and warning audit pass. All eight recovery bundles and both switch receipts bind the current linked ELF. No failing active batch.
- Latest manifest: `primary-matrix-checkpoint-2026-10-07.json`.
- Gate from workspace: `python tools/kh2-audit/verify_fm_primary_matrix_checkpoint.py`.

Latest continuation recovered `0011d500`, all 220 bytes, in `tools/kh2-reference/src/anon/fm_primary_matrix_recovered.cpp`. The isolated v1 source and independently re-probed curated source are exact. The branch-likely self-copy guard preserves its conditional address-addition delay slot; vector copy and post-store base reload use explicit instructions, while floating-point sign changes remain C++. This is an additional boundary start, so the fallback range count is unchanged. Registration, synchronization, full-build and bundle evidence use the `primary-matrix` prefix. Prior fixed-count gates describe historical snapshots; use the latest gate above.

Cooperation: `WORKER_BRIEF.md` gives a new external worker the eight unmatched initializer targets, isolated naming and claim/report rules. Initializers are reserved for that worker; primary work covers matrix recovery and callback analysis. Check claims before choosing overlapping targets. The brief alone does not confirm the external worker has started.

Latest recovered functions: `001671e8`, `0020ea70`, `00156880` (344 bytes), `0019bdc8` (192 bytes), `00161a58` and `00161a80` (40 bytes each). Both clamps reside in `tools/kh2-reference/src/anon/fm_oct7_clamp_recovered.cpp`; twelve isolated variants/proofs are retained, with v12 and the independent curated reprobe exact. The upper clamp explicitly preserves the branch-likely conditional delay slot with `noreorder`. Earlier pending flag/clamp instructions are superseded.

The builder begins with the original ELF and replaces registered C++ ranges. Whole-ELF equality does not establish a complete source rebuild. Types, names, callee prototypes (including variadic declarations), global types, parameter roles and literal address splits remain provisional. Runtime equivalence and IOP/overlay/VU rebuilding remain unproved.

## Identity and non-native coverage
ISO: `Kingdom Hearts II - Final Mix (Japan).iso`.
ISO SHA256: `9486a553ba4355337d62b937a3206eb0360c23f2e6bf4151f1b134e44b7b47b1`.
ELF SHA256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
The ELF is upstream-identical and booted by SYSTEM.CNF; do not confuse the hashes.

15 ISO files; 33,745 archive entries; 30 native inputs. VU extraction: 14 sections, 22,008 bytes; microprograms unbuilt. Script scans: 3,243 containers, zero errors. All 2,503 scripts round-trip byte-exact: 733 AI (one empty), 727 area, 1,043 events. Local OpenKH fixes preserve encoding aliases/unknown words, empty AI, Unk1d arguments, event fields and padding. The failure queue is empty; RawEvent `0x00`, `0x0F`, `0x08` remain in the semantic queue. Reconstruction is not runtime proof; unvisited AI bytes remain data.

## Build and checkpoint workflow
Reference: `tools/kh2-reference`, commit `8b5bc4790ac3fe951ffaf15b6933d186ebab7a43`, with intentional local corrections.
Compiler archive SHA256: `12519affc1fe38130b44fc6bcea98557a95e799a46c66337bb436652a8f0b80c`.
WSL: Ubuntu-24.04; Docker image: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`; compiler: `ee-g++3.2-ee-040921`. Docker integration was restored by a hidden Docker Desktop restart.

Build ONLY in `/root/kh2fm-build`; `/mnt/c` builds fail with `Value too large for defined data type`. Use LF shell files. WSL requires escalation. Synchronize named files only after prior-stage SHA checks; preserve staged edits and original registry aliases.

Inside `wsl -d Ubuntu-24.04 -u root`, after `cd /root/kh2fm-build`:
1. `make verify MAKE_JOBS=8`
2. `python3 /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-audit/check_native_build.py /root/kh2fm-build /mnt/c/Users/KoZa/Documents/ChatGPT/tools/kh2-reference`
3. `python3 tools/objdiff.py report --elf kh2.elf`
4. Only after passing, run `save_fm_native_checkpoint.py` from the audit directory; refresh all recovery bundles and both switch receipts.
5. On Windows, run `finalize_native_fm.py`, `audit_native_findings.py`, then the current checkpoint gate.

Acceptance requires complete equal-size original instructions, independent curated reprobe, deliberate nonoverlapping registration, full ELF verification and source provenance. Retain source/input/proof hashes, curation and synchronization receipts, full byte proofs, and successful/failed logs. Never register unmatched experiments. Saved ELF/objects/provenance/objdiff/manifests reside in `native-build/`; experiments and archived drafts remain isolated in `recovery-experiments/` and `recovery-drafts/`.

Helpers in `tools/kh2-audit/`: `probe_fm_source.py`, `curate_fm_probe.py`, `register_fm_batch.py`, `sync_fm_boundary_checkpoint.py`, `inspect_fm_small_batch.py`, `verify_fm_scalar_native_bundle.py`, `verify_fm_native_switch_tables.py`, `save_fm_native_checkpoint.py`. Probe complete declared ranges; explicit overrides require original-range SHA checks. Generators refuse overwrites; refinements need new names/versions. Boundary cleanup is complete: do not rerun `finish_boundary_checkpoint` or `complete_boundary_cleanup`. Detailed recovery history and superseded proposals remain in the README and evidence.

## Boundaries and native analysis
- `0035ebb8`: six-slot dispatch table; phantom function removed.
- `001391e8` and `001391f8`: exact eight-byte returns; the latter calls `00152000`/`001523d8`.
- `002e7340`: exact 100-byte caller, four padding bytes, separate exact 48-byte helper at `002e73a8`.
- `00100350`: exact 92 bytes; t7=0 forces `00100390` to `001003a4`; zero jump at `00100398` is infeasible. Warning retained.
- Callback split: `00315458` 24 bytes; `00315470` 20; padding at `00315484` four; `00315488` 16. Three functions exact. Ghidra still omits the nonreturning `00315440` call from `00315458`; compiler/original instructions and `fm_callback_split.cpp` are authoritative. Merge receipt: `native-pseudocode/callback-boundary-export/merge-receipt.json`.
- Boundary ledger: 11,378 shared starts and 20 candidates; agreeing starts do not prove ends.

Ghidra 12.1.4 EE extension/JDK25: `tools/ghidra-install/ghidra_12.1.4_PUBLIC`; project: `ghidra-projects/kh2fm`. Language IDs: `r5900:LE:32:default`, `MIPS:LE:32:default`. Before headless runs, set absolute XDG_CONFIG_HOME/XDG_CACHE_HOME under workspace `tools/ghidra-state/config/cache`.

18,283 unverified candidates: EE 11,398; IOP 1,995; overlays 4,890. There are 429 warning functions and 22 unresolved priority jump-table functions (main two, overlays 20). Forty static diagnoses comprise 31 switch overrides, the zero jump, startup `0010001c`, and seven shared delay-slot loop entries. Diagnoses and overrides are not runtime proof. IRX relocations are applied; runtime addresses are unverified. Overlay base `0x01f18000` is supported by ELF/header trampolines; lifecycle and boundaries remain unresolved.

## Switch evidence
`audit_fm_jump_tables.py` verifies 33 of 34 main dispatch sites using original words and conservative unsigned bounds. Overrides cover 31 functions; 32 partial rows were merged into `main.jsonl` without changing bodies or executable bytes. Evidence and merge receipts reside under `native-pseudocode/`; successful application log: `ghidra-jump-table-application-final.log`.

Withheld `00275438`: nested dispatch `002757c8`/table `00373c50` lies beyond body/ledger end `002756f4`; outer table `00373bac` has 41 entries, nested table 39. Unresolved `0025eee8`: s4 bound predicate crosses calls/early returns; preservation is unproved.

Exact registered switches: `001e34e0`/`001e3538`, 88 bytes each despite 52-byte Ghidra bodies; `00272c20`, 108 bytes with signed byte loads/fallback return. `--range-proof` requires source hashes, original bytes, equal sizes and ledger agreement. Original-address table symbols are extern; generated label tables match original words in auxiliary linked data. Defined D_ symbols previously caused a six-byte link mismatch because PROVIDE did not override definitions. Original tables remain in the rebuilt ELF; generated-data integration, runtime writes/immutability, target semantics and cross-ledger case boundaries are unproved.

## Next work
Recover remaining fallback ranges and refine isolated unmatched proposals against original instructions. Review 22 unresolved jump tables, repair the callback export omission, confirm overlay loading, build native/VU modules, decode the three RawEvents, and establish runtime behavior. Prioritize coverage and instruction proof over renaming.

## Additional analysis tools
Ghidra MCP v7.0.0 is built, installed and tested against an isolated copy of the FM project. Start/check it with `tools/kh2-audit/start_fm_ghidra_mcp.ps1`; query through `query_fm_ghidra_mcp.py`, or verify the installed MCP bridge with `verify_fm_ghidra_mcp.py` using its workspace virtual environment. Read `analysis/final-mix/tool-integrations/README.md` for paths, saved evidence and limitations. It exposes decompilation, disassembly, call graphs and P-code without replacing compiler gates. REA excludes PS2 MIPS; IDA and Cheat Engine bridges remain unconnected because required local applications were not found. Their inspected repositories are retained under `tools/`.

## Pi efficiency stack
The requested packages are installed in Pi: `npm:billion-context-pi`, `npm:pi-rtk-optimizer`, `npm:@pixs/cbm-tools`, and `git:github.com/DietrichGebert/ponytail`. Ponytail's user config sets `defaultMode` to `ultra`. Reload/restart an existing Pi session to load changes; these Pi extensions do not automatically run inside Codex.

Codebase memory is available directly through `codebase-memory-mcp cli`. The `kh2fm-reference` index covers `tools/kh2-reference` (19,736 nodes, 46,105 edges); 44 files have partial parsing and no file is unusable. Confirm freshness with `index_status`; retrieve focused graph results and snippets rather than rereading broad source dumps. Treat the graph as navigation, not compiler or boundary evidence; use direct files/original instructions for verification and `rg` when indexing misses a construct. Keep handoffs compact, reuse existing helpers, preserve condensed command output and avoid unnecessary implementation. Compiler acceptance gates remain unchanged.
