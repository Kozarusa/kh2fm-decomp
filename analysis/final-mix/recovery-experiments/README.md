# Isolated FM recovery experiments

These files are outside the active source tree. Do not register an unmatched
definition or treat an isolated probe as a full-build checkpoint.

The resumed work promoted 369 equal-size, unmodified compiler matches:

| Active source | Accepted functions |
| --- | ---: |
| `src/anon/fm_fallback_small.cpp` | 46 |
| `src/anon/fm_fallback_helpers.cpp` | 31 |
| `src/anon/fm_fallback_vector.cpp` | 23 |
| `src/anon/fm_callback_split.cpp` | 3 |
| `src/anon/fm_copy_helpers.cpp` | 18 |
| `src/anon/fm_switch_helpers.cpp` | 2 |
| `src/anon/fm_switch_byte.cpp` | 1 |
| `src/anon/fm_compact_recovered.cpp` | 14 |
| `src/anon/fm_deferred_recovered.cpp` | 1 |
| `src/anon/fm_more_recovered.cpp` | 27 |
| `src/anon/fm_scalar_recovered_00..08.cpp` | 168 |
| `src/anon/fm_scalar_extra_recovered_00..12.cpp` | 35 |

The authoritative proofs are the corresponding `*-batch-verification.json`
files and `compiler-range-verification.json` in `../native-build/`. Those
proofs include the final registry aliases, forward declaration and callback
address encoding. The standalone source hashes identify earlier probe inputs;
do not substitute them for the registered source versions.

`fm_fallback_small.cpp` retains three unmatched proposals: `00152598`,
`0016c750` and `0016f7b0`. `fm_fallback_helpers.cpp` retains 13 unmatched
proposals. Its `00315458` proposal is superseded by the verified callback split;
the current ledger contains three separate functions and four padding bytes.
`fm_fallback_vector.cpp` has 23 exact standalone probes. These are EE VU
macro-mode and packed instructions, not a rebuild of extracted VU microcode.

`variants.cpp` and `verification.json` contain 72 initializer variants for
`00161410`, `001ba060` and `001c8e00`. None matches. The nine older deferred
definitions remain separately archived in `../recovery-drafts/`.

Run `tools/kh2-audit/probe_fm_source.py` inside WSL with `/root/kh2fm-build` as
the working directory and the absolute Windows-mounted source path as its
argument. Compiler outputs are isolated in the stage's `recovery-experiments/`
directory. The probe stops on compiler/linker failure and records the source
SHA-256. It compares complete ledger ranges when Ghidra reports a smaller body.
`fm_switch_helpers.cpp` contains two additional isolated exact probes at
`001e34e0` and `001e3538`. Both complete 88-byte ledger ranges and their
five-entry generated dispatch tables match original bytes. Their saved
`.probe.elf`, `.probe.o`, `.verification.json` and `.table-verification.json`
are checked by `tools/kh2-audit/verify_fm_switch_probe.py`. The linker sections
also contain four trailing zero padding bytes beyond each 20-byte table.
These helpers are now registered and included in the active match count.
Ghidra bodies remain 52 bytes; explicit range proof established the 88-byte
ledger ranges for registration. Full-link and provenance gates passed after
separating external original-address table references from generated label
tables. The initial defined D_ symbols caused a six-byte link mismatch; that
draft is superseded. `fm_switch_byte.cpp` adds an exact 108-byte signed-byte
switch and a third verified table. Original data is retained in the rebuilt
ELF; data integration and runtime table immutability remain unverified.

The scalar/variant sweep completed 1,396 proposals: 203 unique functions were
accepted, and 1,193 proposals remain unmatched. Types/callee prototypes are
provisional, including variadic declarations. Every accepted curated source
was re-probed and then passed registration and full-build gates. Both native
bundle receipts bind final compiler records and registered source hashes.
Input hashes, byte proofs, curation receipts and failed-initial logs identify
all proposal versions. New manual draft files retain 18 unmatched proposals;
only curated exact definitions are active. Old `0016c750` and `00315458`
proposals are superseded by proven source.

An optional second argument supplies explicitly proposed ranges; each must
match an original-range SHA-256. `callback-split-ranges.json` is the proven
example. Registration, nonoverlap checks, deliberate stage synchronization,
full ELF verification, compiler-size checks and input provenance are still
required before saving a checkpoint.

The callback project repair and incremental export are in
`../native-pseudocode/callback-boundary-export/`. Its merge receipt preserves
the replaced row, prior summary and before/after hashes. Ghidra's corrected
24-byte `00315458` body still yields pseudocode omitting the following
nonreturning call. Use the original instructions and compiler proof.

The autonomous follow-up completed result-signature and ABI-width sweeps. Exact rows were deduplicated against registered functions and earlier selections using hash-bound exclusion lists. `autonomous-curated-bundle.json` contains35 independently re-probed curated sources; all112 functions are now registered and full-build exact. Return-signature v1 compilation failures and all unmatched variants remain isolated. `generate_fm_return_variants.py` and `generate_fm_width_variants.py` refuse overwrites. Five remaining small-helper drafts (001060b8,001060e0,0010a7d8,00134278,0014c940) still mismatch original bytes; scheduling trials must not be copied into active sources. No active batch is failing.

The next follow-up recovered44 functions in14 curated sources. All five prior small drafts now match; their old mismatched files remain isolated. Fixed-signature probes produced two unique additions. Scalar-global v3 compiled176 proposals under two width profiles after pointer-declaration repairs;20 unique functions were accepted after byte comparisons/deduplication. Six float initializers,seven manual globals andfour float-memory helpers also passed full-range probes and independent curation. Float-role sweeps accepted no additional unique functions because their sole match was already registered. Earlier wrong address offsets and branch conditions remain visible in failed proofs and were corrected before registration. The current complete set is `followup-complete-bundle.json`; all44 definitions are registered and full-build exact. No unmatched source is active.

The usage-floor continuation registered four independently re-probed functions from `fm_last_window_recovered.cpp`; all four are full-build exact. Its three preceding retry files preserve allocation/scheduling mismatches. `fm_last_window_flags.cpp` contains one exact isolated proposal, 0020ea70, and three unmatched proposals. None of that flags file is active; 0020ea70 still needs curation, reprobe, deliberate registration and full-build gates. Recovery stopped at 3% weekly remaining, as requested.

October7 recovered001671e8 and0020ea70 from the flags retry after constraining the first two instruction order. Re-probed larger scalar candidates accepted00156880 and0019bdc8; one unresolved stack placeholder was excluded with prior failed sources/logs retained. All four curated definitions in oct7-complete-curated-bundle.json are registered and full-build exact. The two clamp functions still fail exact-byte checks; no clamp or other unmatched proposal was registered. The latest checkpoint gate is verify_fm_oct7_checkpoint.py 10 2.

October 7 clamp continuation: both remaining clamps, 00161a58 and 00161a80, are independently re-probed, registered and full-build exact. Twelve probe variants preserve allocation, branch-layout and delay-slot mismatches; v12 matches both complete 40-byte ranges. The branch-likely primitive uses explicit noreorder to preserve its conditional delay slot. Active source: fm_oct7_clamp_recovered.cpp. No unmatched variant was registered.

The cooperating-worker continuation integrated four exact initializers from
`fm_worker_b_initializers_recovered.cpp`, followed by ten exact fallback routines
from `fm_primary_resume_recovered_00.cpp` and `_01.cpp`. All fourteen passed
independent curated probes and full native gates. The callback omission is also
repaired through a reproducible flow-metadata correction and independently
reopened export; earlier descriptions of the omission are historical.
See the current status at the top of `../README.md`. Unmatched sources remain
isolated. The new width probes are experiments until separately curated,
re-probed, registered and verified through the complete native build.
