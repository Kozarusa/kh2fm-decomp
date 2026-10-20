# Kingdom Hearts II US: historical decompilation baseline

**Target changed to Japanese PS2 Final Mix.** The user will supply its ISO in the
next session. This document and its associated artifacts describe the earlier US
audit only. See `../HANDOFF.md` for the current objective and next-session context.

The priority is coverage of the entire original game. Readability improvements
come after coverage and correctness. This historical audit used the US PS2 ISO,
`SLUS_210.05`, SHA-256
`9301c1551364c58a8be074d644faad0b27a8454806588ed97450fed6d2c90545`.

## Current baseline

| Item | Observed state |
| --- | --- |
| Current C export | 17,690 distinct module/address entries, all unverified pseudocode |
| Recovered reference pseudocode | 1,161 additional entries in `recovered-pseudocode/` |
| Combined function inventory | 18,851 entries; this is not the denominator of original functions |
| Native inputs | Main executable, four overlays, eight standalone IRX modules, sixteen ROMDIR modules extracted |
| Vector-unit programs | 14 ELF DVP sections extracted, 22,008 bytes; not decompiled |
| Archive inventory | 26,469 entries including nested indexes; five unresolved filenames |
| Script scan | 2,954 selected archive containers examined without parse errors |
| AI scripts | 1,293 references to 629 distinct payload hashes |
| Area scripts | 707 references to 677 distinct payload hashes |
| Event scripts | 1,385 references to 870 distinct payload hashes |
| Current export defects | Three functions contain bad-instruction/truncated pseudocode; 447 functions have warnings |
| Verified reconstruction coverage | Unknown; no native rebuild or assembly equivalence has been demonstrated |

Script payloads are raw extracted inputs. These counts include duplicate and
zero-length entries. The scan covers MDLX, ARD, MAG, BAR, BIN, BDX and the five
unnamed archive entries. It does not certify all executable formats or microcode
embedded inside other assets. Executable ELF flags alone do not identify pure
code: the main section includes data, and an executable NOBITS overlay placeholder
contains no original file-backed instructions.

**Existing object dump mismatch:** only 125 of the 435 distinct AI payloads in
`KH2MODELDUMP` match the scripts extracted from the US ISO; 310 do not. Its
provenance/version is unconfirmed. Use `coverage/disc-scripts/` as the authoritative
US script input and keep the old dump as reference material. There are 628
nonempty distinct disc AI payloads; the 629th payload hash represents empty data.

## Working order

1. Reconcile function boundaries and processor/language settings against original
   bytes. Remove data or empty overlay placeholders mistakenly identified as code.
   Repair truncated output and record actual decompiler failures.
2. Establish native coverage by bytes and address ranges, including uncovered
   regions, executable overlays, SDK/IOP modules, and vector-unit programs. Keep
   uncertain regions explicitly unresolved rather than declaring them covered.
3. Decode the original US AI, area, and event scripts. Validate each supported
   format through round-trip reconstruction or an equivalent format-specific
   check. Keep undecoded data and failures visible in the coverage ledger.
4. Recover native code with the correct compiler/ABI, comparing generated
   instructions with original instructions. Prioritize missing or invalid code
   before cosmetic names and formatting. Cross-version symbols are hints only.
5. Verify full reconstruction and representative original game behavior. Count
   only demonstrated coverage toward completion; generated exports, stubs,
   substitute gameplay implementations, and from-scratch rewrites are not proof
   of a complete decompilation.

No completion percentage is claimed until executable boundaries and verification
criteria provide a defensible denominator. Matching code is the strongest check
for native functions; explicit exceptions require a documented equivalent check.

## Artifacts and provenance

- `coverage/summary.json`: ISO audit and present export status.
- `coverage/reconciliation.json`: current/reference function inventory comparison.
- `coverage/reference-only-functions.json`: recovered functions and source records.
- `coverage/repair-queue.json`: immediate bad-instruction/section-membership issues.
- `coverage/native-inputs.json`, `vector-programs.json`: native binary metadata.
- `coverage/archive-entries.json`: named and unnamed archive entries.
- `coverage/disc-script-summary.json`, `disc-scripts.json`: extracted script ledger.
- `../reference/claude-snapshot/provenance.json`: 98 hash-verified reference copies.

The original `C:\Users\KoZa\Documents\ClaudeShit` tree is read-only. The copied
main executable and all four overlay payloads were verified against the current
ISO. The copied Ghidra repository was not opened or mutated; per-file copy/hash
verification does not prove a transactional snapshot of an active project.
The copied `Spreadsheet.json` is explanatory text, not the actual function ledger;
the useful ledgers reside in the copied `kh2_ps2/sheet` and `raw` directories.

Reproduce the baseline from the workspace root:

```powershell
python tools/kh2-audit/audit.py
python tools/kh2-audit/reconcile.py
python tools/kh2-audit/scan_scripts.py
```

These commands write only workspace artifacts. Reconciliation writes recovered
reference pseudocode separately and preserves the existing `decompiled` exports.
`copy_reference.py` is a one-time snapshot command and refuses to overwrite an
existing destination.
