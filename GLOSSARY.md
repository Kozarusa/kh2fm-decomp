# Glossary

Terms used across this project's documents, in plain language.

| Term | Meaning |
| --- | --- |
| **FM / KH2FM** | Kingdom Hearts II Final Mix, the Japanese PS2 release. The active target. The earlier US audit lives in `analysis/coverage/` and is legacy. |
| **`SLPM_666.75`** | The main game executable on the FM disc. The US equivalent is `SLUS_210.05`. |
| **EE / R5900** | The PS2's main CPU (Emotion Engine), a MIPS-family core. Main executable code runs here. |
| **IOP / IRX** | The PS2's I/O processor and its loadable modules (24 here). Not covered by the main build proof. |
| **Overlay** | Separately loaded game code (five here), mapped at about `0x01f18000`. Boundaries and lifecycle are unresolved. |
| **VU / DVP** | Vector-unit microprograms (14 sections, 22,008 bytes). Extracted, not yet disassembled or rebuilt. |
| **Instruction-exact / equal-size match** | C++ whose compiled output equals the original range in size and every instruction. The project's acceptance criterion. |
| **Range** | A function's complete original byte extent as declared in the layout ledger. Ghidra body sizes can disagree and are advisory. |
| **Fallback range** | A range still supplied from original bytes because no accepted C++ exists. |
| **Padding case** | Four ranges (`0018f9f8`, `0014f148`, `00168370`, `00315440`) needing four zero bytes after the function. Counted separately. |
| **Probe** | An isolated compile of one candidate source against its original range using the pinned compiler. Not acceptance. |
| **Curated source** | The exact definition extracted from a successful probe (`curate_fm_probe.py`), which must be probed again independently. |
| **Registration** | Adding a proven range to `functions.tsv` and `layout.tsv` without overlap and with aliases preserved. Primary only. |
| **Stage** | The Linux build directory `/root/kh2fm-build`, where full builds run. |
| **Full build / `make verify`** | Builds the ELF from the original plus registered C++ ranges and checks whole-file equality. |
| **Provenance / objdiff** | Checks that staged inputs match the workspace sources, and an instruction-level comparison of the rebuilt ELF. |
| **Recovery bundle** | A hash-bound record of one accepted batch's functions and sources, re-verified against each new linked ELF. |
| **Switch receipt** | Verification of generated jump tables and the code that references them. |
| **Checkpoint** | A hash-bound manifest of accepted state, with a gate script that re-verifies it. |
| **Gate** | The script that validates a checkpoint. Only the current one is authoritative. |
| **Snapshot** | A pre-change copy of registry, layout and build evidence under `accepted-snapshots/`, kept for rollback and audit. |
| **Blocker** | A recorded reason a target did not match, with the first differing instructions and a next hypothesis. Not a claim of impossibility. |
| **Claim / lease** | A worker's reservation of an address. Queue leases last 15 minutes and are renewed by heartbeat. |
| **Primary / Worker** | The agent that owns shared integration, and agents that produce isolated proposals. |
| **Branch-likely, delay slot** | MIPS features that strongly affect instruction scheduling and often explain near-miss mismatches. |
| **`func_XXXXXXXX` / `D_XXXXXXXX`** | Provisional names for a function or global derived from its original address. They are not original developer names. |
| **Ghidra pseudocode** | Decompiler output. An analysis aid, never accepted source. |
| **OpenKH / BDX** | The community toolkit, and its AI-script format. Local fixes make all 2,503 scripts rebuild byte-exact. |
| **Ultracave** | The owner's chosen terse chat style (from the Pi/Ponytail setup). Applies to chat replies, not to saved files. |
