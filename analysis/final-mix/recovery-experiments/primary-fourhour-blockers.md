# Four-hour recovery session blockers

## 00242a28: return-address restore scheduling

Eight new precise-memory and split-expression variants were probed with unchanged flags. No complete exact match. Best size remains 64 bytes; return-address restoration appears after the load/mask rather than before the final calculation. Existing and new proof/log files remain preserved. Move to another target; do not register these proposals.

## 002006b0: saved-register store order

Seven new call-pair variants were tested. Existing 76-byte proposal differs in the initial return-address and saved-register store order. Removing the trailing barriers shrinks to 72 bytes; new input barriers did not recover the target. Preserve all proofs and move to another target.

## 002c1950: split address and argument scheduling

Nine new address/float/object dependency variants compiled to 64 bytes but none matched the original instruction order. The return-address store must follow both address instructions while the object-plus-offset calculation must follow the float load. Source constraints tested do not satisfy both. All proofs/logs preserved; move to the pending-proposal inventory.

## 0017c0a0: packet-call and final-store scheduling

Seven new complete 104-byte variants remain nonmatching. Prologue stack-argument order and final constants/stores differ. All preserved; move to a disjoint medium-size batch.

## 00102c90 / 00103080: initializer argument and store allocation

Twelve new struct/global variants and earlier array spellings remain nonmatching. Contiguous globals reduce compiled size from 124 to 96 bytes, but target is 92 bytes. The target stores the incoming first argument at offset 0x14 instead of materializing one. Tested argument constraints do not reproduce all register allocations and store order. Both targets remain a paired blocker; no registration.

## 001033d8 / 00103428: signed table traversal

Width and pointer traversal experiments remain nonmatching. 001033d8 best new size is 84 versus target 80 bytes. 00103428 live boundary is 88 bytes, differing from the 84-byte pseudocode body; the probe uses the live boundary, not the stale body size. Target uses signed halfword loads and distinct count/offset variables; natural spellings change normalization and loop scheduling. Preserve these as paired table-search work.

## 00308cd0 / 00305ce0: short fixed-register scheduling

Focused variants reproduce size but not the final restore/register sequence. Explicit unpaired high relocation and a global memory-output variant fail linking; these are invalid experiments, not evidence of compiler impossibility. Their logs are preserved. The independently solved sibling targets proceed to integration; these two remain unregistered.

## 001668f8 / 00166930: ordered initialization epilogue

Seven complete variants reproduce 52 bytes but not the required constant placement, store order and return-address/saved-register restore order together. Volatile stores fix memory ordering but change epilogue scheduling. No source accepted; move to another family.

## 001e6250 / 001b8800: split-address residuals

Nine new variants retain correct size but differ in constant/restore or initial high-address/load scheduling. Correct signed address decoding was established for 001b8800; it does not itself solve register ordering. All variants and logs remain isolated. Move to another family.

## 0028ac98 / 00195c58: short compare/call schedules

Ten paired source/register experiments across three short families solved 001ac700. Remaining scaled-index and conditional-call targets still differ in register allocation or prologue order. The original shared-return shape restores 0028ac98 size to 32 bytes, but is not exact. Preserve both unresolved targets for new hypotheses.

## Resolution: callback-load family

001b8800 and seven related callbacks are now fully accepted. The solved pattern preserves signed address decoding, high-half/prologue order and the third-argument load before advancing register 5. Historical failed variants remain unchanged. 001e6250 remains unresolved.

## 00315678 / 00315700 / 00316890 / 0028b7f8: destructor prologue/store family

Eight volatility/barrier variants and three representative table-value constraints retain 56 bytes but fail to put the return-address store between the saved-register store and vtable write while retaining the original call delay slots. Paired pointer-offset helpers were solved separately. Preserve the four unresolved destructor targets; move on.

## 0014dbc8 / 0014dc08: six-store clear epilogue

Three final object-lifetime constraints preserve 60 bytes but do not restore the return address before saved register 16 as required. Existing complete store sequence matches; restore order remains unresolved. Preserve all variants and move on.

## 001abf00 / 00265740 / 00265c10: predicate setup and saved-register order

Ten variants across four predicates solved 002e9c58. The three remaining functions differ in zero/one initialization order or return-address/saved-register prologue order; removing barriers can shrink 60-byte predicates to 56 bytes. Preserve all source/proof files; move to the next family.

## 002c1a58: final object initializer restore order

Volatile fields reproduce the original store sequence, but restore timing differs. End memory barriers prevent early return-address restoration but restore register 16 before register 31. Two final object-lifetime markers did not solve both constraints. Other members of this mixed batch were solved; preserve this residual and move on.

## 00271828 / 001c2c98 / 001c2ce8: argument and flag-store ordering

Return-register shifting solved 002956c0 and grouped constants/explicit zero solved 0014a188. The remaining call-result move order in 00271828 and paired table/flag store order are nonmatching. Volatile stores change earlier load/register allocation, so they are not a complete solution. Preserve failed variants and move to a different family.

## 00172928 / 0010f748: packet float ordering and conditional epilogue

Five packet float/ABI/pointer lifetime proposals and two final predicate barriers remain nonmatching. Equal-size packet variants change prologue or argument move order; stronger float constraints grow to 100 versus 92 bytes. Predicate barriers replace branch-likely behavior but do not reproduce the target shared zero-result slot. Preserve experiments; move on.

## 001d86a0 / 002920c0: return-base arithmetic and field-load ordering

Fixed return-base arithmetic changes size from 120 to 116 bytes and does not preserve the full predicate sequence. Early halfword and grouped byte-load variants retain 136 bytes but still differ in register/field order. Paired 108-byte loops and a 100-byte packed-argument helper were solved separately. Preserve these two residuals and move on.

## Follow-up: link-order transfer did not generalize

Seven new probes applied the proven wrapper constraint to two predicates, four destructors and one byte-update helper. None was exact. Byte argument/register transport improved, but restore/load interleaving still differs. These observations narrow the applicability of the successful wrapper pattern; they do not establish compiler impossibility.

## Fresh family: unresolved baseline and branch-layout work

The virtual iterator 0011ea40 is solved by restoring its floating-point ABI. Six other fresh targets remain unaccepted: 0010f6f8 (float result branching), 0010fea0 (guarded search), 00112d90 (guarded return), 0011bd70 (FPU determinant register/order), 00114438 and 00114490 (table lookup layout). New branch hints and register/table snapshots reach the target sizes for representative float/table routines but do not match full instructions. The table ranges are 88 bytes in live layout versus 84 in pseudocode; no boundary was silently shortened. Preserve all experiments and move to another batch.

## Epilogue family follow-up

Five register/lifetime marker variants each for 0014dc48, 0014dca8 and 002e5f70 failed exact comparison. The first two remain equal-size with saved-register restore order differences; a $17 clobber expands 002e5f70 to 76 bytes against 68. Preserved proposals and proof files use fm_primary_epiloguefamily_v1. Parked these three targets and moved to callbacks. Four callbacks from the same exploratory batch were subsequently resolved and fully accepted by callbackaddress; corrected global addresses and fixed original register transports were necessary.

## Acceptance runner correction

The first callbackreturn acceptance runner retained the previous callbackaddress batch name. Its 76-bundle success did not establish acceptance of the new five sources. Corrected the runner, synchronized all seven intended inputs, and reran full acceptance: 77 bundles and all five complete new ranges pass. The prior accepted native build was preserved before registration. Two PowerShell inline Python generator attempts failed quoting without modifying project state; file-based generators were used instead.

## Short globals follow-up

001c8a90, 00305e20 and 0030ec28 remain unresolved after sixteen new source variants (shortglobals_v1/v2). Correct globals and constrained values produce equal-size code, but instruction scheduling still differs: repeated high-address setup is delayed for 001c8a90; return-address restore is delayed behind the store or mask operation for the other two. Volatile/nonvolatile markers and call-result input dependencies did not resolve these differences. No failed proposal was registered. Parked these targets and moved on.

## Medium fresh family

0011eea8: baseline 72/76 bytes; three branch/register variants reach 76/76 but differ in original linked-list registers and branch/load scheduling. 00124c48: baseline 104/92; fixed return-pointer register reduces two variants to 92/92, but branch/loop instructions still differ. 00127d40: baseline 100/96; four narrower parameter/result variants shrink to 84 or 88 bytes, losing the original branch/return layout. 00132018: baseline and three branch-hint variants remain 84/80. 001317a8: direct globals produce 80/88; explicit address lifetimes reach 84/88; four floating-register variants reach 88/88 but differ in limit computation, constant loads and floating result allocation. Preserved mediumfresh_v1/v2/v3 and mediumcontrol_v1 evidence; parked these five targets. Two siblings are fully resolved and accepted: 00123d40 (76 bytes, mediumcall) and 00132f38 (96 bytes, tablelookup).

## Fresh helper residual

00136968 remains equal-size but differs in global base-address setup and store ordering. Three grouped-halfword/address variants (freshhelpers_v3) did not resolve it. Parked this target. Other selected helpers are now accepted: 001367e0 (96 bytes), 0013c7d0 (80), 00137458 (76), 0013b4b0 (84), 001337f0 (88), 00133980 (80). The packet machine census validates both positive controls and finds no other tracked instances matching the tested transport pattern. The first freshhelpers_v3 generator stopped on an assertion before probing because imported decompiler line endings yielded extra blank lines; whitespace normalization repaired the generator without altering accepted files.

## Next family residuals

0013c820: first argument is floating-point and original caller also materializes additional stack constants omitted by the decompiler. Baseline was 72/84 bytes. Six float/stack-width/padded-color proposals reach 80, 84, 88 or 104 bytes but do not match; provisional padded-color semantics were not accepted. 00141010: incoming argument and three downstream arguments are floating-point; grouped global state at 00348710 improves agreement. Typed signatures and pointer/register lifetimes reach 96/96. The closest floatcall_v4 proposal differs only in high-address load placement across the guard; volatile variants expand to 100. Parked after eleven refinements. 0013e610: four total equal-size allocator variants still differ in prologue/index/global-address scheduling. 00143470: preventing sibling tail calls restores 92-byte size, but three variants retain argument transport/save-order differences. Parked these four targets and moved on. The same selection fully resolves 0013e5a8 (100), 0013f828 (92) and 00140850 (80). One isolated quadfamily_v2 parameter-register syntax variant was rejected by the compiler; it was never registered.

## Flag and float family residuals

00148638: original comparisons are ordered strict threshold-less-than-value tests, with different unordered/NaN behavior from the decompiler's less-than-or-equal interpretation. Corrected comparison structure reaches 84/84 and differs only in one floating load/branch placement; branch hints and explicit load lifetimes do not resolve it. 00146ed8: original unsigned byte load, signed extraction and redundant low-byte mask are absent from the first 60/80 proposal; opaque byte variants reach 76/80 but still differ. 00148a68: retained table base improves 96/84 to 88/84; register and marker variants do not resolve loop/address scheduling. 00144570: aligned stack copy restores 92-byte size, but bounds arithmetic allocation/store ordering remains different. Six fixed-floating-register variants expand to 116 bytes, including coordinate reuse variants; these failed proposals remain isolated. Parked all four targets and moved on. The byte wrapper 0014e140 is fully resolved and accepted at 84 bytes by symbolic original-address relocation. Also deferred malformed 00146730 decompiler output containing a BADSPACEBASE/register stack-unwind artifact; this requires original instruction reconstruction before a meaningful C++ proposal.

## Global family residuals

0014ec40: original has repeated initializer guards and separate float source-address loads. First grouped proposal is 56/84; separate guarded proposals reach 80/84, and reconstructed nested-guard proposals reach 76/84. None match the original redundant branch/constant placement. 0014fba0: the first 84-byte proposal differs in row-stride/index scheduling; direct six-byte row arithmetic and opaque loop-index variants reach 76 or 80 bytes against 84. 00153610: replacing double zero with float zero reduces 132/100 to 96/100; explicit numerator address and three expression orderings produce 100 or 104 bytes but differ in original floating arithmetic/load order. No re-associated expression was accepted. 00155ee8 and 00155fc0: original dispatch uses bounded jump tables at 0036b2c4 and 0036b2ec; naive C switches become decision chains of 76/88 and 56/80 bytes. Deferred these two until explicit code-and-table reconstruction can be verified. Parked all five and moved on. Accepted siblings: 0014f578 (88), 00157160 (92), 00155658 (100).

## Resolved lookup-switch blockers

00155ee8 and 00155fc0 are now fully accepted at 88 and 80 bytes. GNU computed-goto sources with generated label tables reproduce the original bounded dispatch; all 40 table bytes match independently and in the full native link. The first source variants crossed initialized declarations with fallback jumps and were rejected by the compiler; moved index declarations before the jumps in new variants. The first full table-verifier attempt expected a legacy small-batch proof file not produced by the current curated-bundle workflow. Adapted only the new batch to current compiler records and direct linked-code comparisons; earlier two switch batches passed unchanged. All 89 bundles and three switch receipts now pass. The legacy inspect_fm_small_batch.py helper still contains a historical ChatGPT output path; it was read but not executed or edited. Use the current curated-bundle workflow instead. Original tables are retained in the rebuilt ELF, so full data integration remains outstanding.
