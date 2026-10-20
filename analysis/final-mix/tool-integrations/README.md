# KH2FM reverse-engineering integrations

## Working: Ghidra MCP
Upstream: https://github.com/bethington/ghidra-mcp
Built v7.0.0 against the existing Ghidra 12.1.4 and JDK 25. The workspace-local Gradle init script selects the existing JDK rather than installing JDK 21. The extension is installed in the workspace's Ghidra distribution; the Python bridge has an isolated environment at `tools/ghidra-mcp/.venv`.

The backend runs at `http://127.0.0.1:8089`, using an isolated copy of `kh2fm` under `analysis/final-mix/ghidra-mcp-projects/`. This copy is an analysis snapshot, not the authoritative project. Refresh it deliberately when the authoritative project changes, after stopping the backend and preserving any useful results.

From the workspace:
- Start/check the hidden backend: `powershell -File tools/kh2-audit/start_fm_ghidra_mcp.ps1`.
- Verify actual MCP negotiation and a read-only callback query: `tools/ghidra-mcp/.venv/Scripts/python.exe tools/kh2-audit/verify_fm_ghidra_mcp.py`. Windows named-pipe creation may need sandbox escalation.
- Query saved evidence through the restricted HTTP helper: `python tools/kh2-audit/query_fm_ghidra_mcp.py /get_functions analysis/final-mix/tool-integrations/query.json function=0x00315458 fields=decompiled_code,callees`.

The SDK smoke test advertised 224 tools; the backend exposes 190 endpoints. This does not mean those tools have been added to the desktop chat's built-in tool registry. They are usable immediately through the installed MCP bridge and the local query helper. No global Codex settings were changed.

Saved queries cover the callback, both unresolved main jump-table functions, complete callback/predicate disassembly and high P-code. The callback query independently reproduces the discrepancy: `00315468` calls `00315440`, the call graph includes it, but decompiled text omits it. The dataflow attempt at `0025f1d0` could not resolve an s4 varnode; its error is retained. P-code and call graphs remain advisory; original instructions, compiler equality and the existing registration gates remain authoritative. No new recovery or runtime proof was established.

## Evaluated alternatives
- **REA**: https://github.com/morluto/rea . The checked source `src/ghidra/GhidraProvider.ts` limits architectures to x86/x86_64/arm/arm64; its Windows provider accepts x86-64 PE. The PS2 MIPS/R5900 ELF is unsupported. Repository retained at `tools/rea`; no unsupported import attempted. It may help inspect host-side PCSX2 software, but that is distinct from guest-game semantics.
- **IDA MCP**: https://github.com/HexRaysSA/ida-mcp . Requires IDA 9.4+ with idalib and Python 3.11+. No qualifying IDA installation was found in the inspected installation directories or running processes. Repository retained at `tools/ida-mcp`; not connected. Cross-checking PS2 analysis additionally depends on available processor/decompiler support and licensing.
- **Cheat Engine MCP Bridge**: https://github.com/miscusi-peek/cheatengine-mcp-bridge . Repository retained at `tools/cheatengine-mcp-bridge`. PCSX2 is installed; Cheat Engine and a loaded Lua bridge were not found. The bridge can support future host-process memory reads once those prerequisites and a running game are present. Guest EE RAM must be mapped explicitly; host x86 breakpoints/disassembly do not establish PS2 guest instruction behavior. No runtime memory was read or modified, and no DBVM setup was performed.

Pinned repository commits, build hashes and query hashes are recorded in `integration-receipt.json`. The main saved compiler checkpoint remains 5,303 exact matches.

Later October 7 work supersedes the setup-time callback discrepancy and compiler
count above. The authoritative Ghidra project now clears the inferred indirect
`CALL_RETURN` override at `00315460`; its saved and independently reopened export
includes the following `00315440` call. The original setup receipt and MCP
snapshot are historical and remain unchanged. The snapshot needs a deliberate
refresh before queries reflect the repair. Read the current status at the top of
`../README.md` and `../native-pseudocode/callback-flow-merge-v2.json` for current
evidence. No executable bytes or callback boundaries changed.
