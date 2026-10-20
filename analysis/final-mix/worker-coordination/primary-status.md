# Primary worker status — 2026-10-08

Accepted: 6,800 equal-size exact matches, 6,804 C++ ranges, 4,579 fallback ranges,
3,305 staged inputs, and four unchanged padding cases. Full ELF equality, provenance,
objdiff, all 264 recovery bundles, all three switch batches, finalization, warning audit and the
current checkpoint passed.

Gate from AGENTS: `python Public/tools/kh2-audit/verify_fm_primary_orchfe_checkpoint.py`.
Manifest: `analysis/final-mix/primary-orchfe-checkpoint-2026-10-08.json`.
Previous accepted build, registry, layout and original linker helper are preserved in
`accepted-snapshots/2026-10-08-before-workerbacklog/`. Historical manifests are unchanged.

This work accepted 118 independently curated and re-probed worker submissions, totaling
6,752 instruction bytes. All 134 delivered worker round-two-and-later solved proposals
present at preflight are now accepted; 16 were already accepted and 118 were pending.
`00242500` now has a complete independently verified proof and is accepted. A filename
or historical report alone still does not establish acceptance.

The full linker now supports the absolute object-address declarations already handled
by isolated probes. All 21 missing constants resolve; the focused regression preserves
21,814 previous source aliases. Compiler image and flags remain unchanged. Hash-checked
synchronization covered 121 named inputs, including the narrow helper correction.

Remaining primary claims: `00132850`, `00154558`, `001565c0`, `0017c0a0`, `002006b0`, `00242a28`, `002c1950`, `002eb778`.
Worker claims/reports have advanced through round 26; inspect their latest state before
claiming any target. The existing guidance file is the user's updated backlog-first
assignment. Primary has not issued another guidance file or changed that guidance.

Primary owns shared registration, synchronization, full builds, receipts, checkpoints
and Ghidra. Worker B owns isolated proposals and reports. Coordinate through filesystem
claims and compiler-status.json. No handoff document was modified. Whole-ELF equality
retains original fallback bytes; types, boundaries and runtime behavior remain provisional.

The subsequent argumentfinish recovery accepts the complete 100-byte `002ec9d0` range. Its independent proof, full build, all 53 bundles, both switches, finalization and warning audit passed. This session has accepted 119 ranges totaling 6,852 instruction bytes.

Round 27 adds three independently curated, re-probed and fully accepted 76-byte ranges: 001145b0, 00158450 and 001584f8. Rounds 23–26 were checked against all currently available proof variants: 4, 5, 0 and 1 unique exact recoveries respectively, all already accepted. See recovery-experiments/primary-roundstwenty-audit-v1.json. Failed proposals remain unregistered.

Conditionfinish accepts complete 40-byte 00307f68 after independent curation and all cumulative gates. A project status, prioritized work and newcomer report was requested for a follow-up after approximately three hours; the app heartbeat is scheduled.

The active four-hour work goal has accepted complete 84-byte 002eb9d8. New probe evidence and blockers are recorded under primary-fourhour-*; all existing exact proposals were inventoried and none remain unaccepted.

The four-hour session also accepts complete 76-byte 00106558. It has now added two exact ranges and 160 instruction bytes. Six fresh medium targets were claimed; failed prototypes and original-byte evidence remain preserved.

The four-hour session additionally accepts complete 84-byte 001024b0. Total session progress is three ranges and 244 instruction bytes. A machine-readable priority inventory covers all 5,706 currently tracked fallback ranges at project-prioritized-range-backlog.json; it does not claim undiscovered boundaries or data work are exhausted.

Addressalias accepts complete 60-byte 001d6538. The four-hour session has accepted four ranges and 304 instruction bytes. Two complete 52-byte addressalias-v2 proposals, 0020f118 and 0020f150, have fresh exact proofs and await curation/integration; do not count them as accepted.

Globalcall accepted both 52-byte helpers. Framealias then accepted 72-byte 0022b7f0 and the two complete 20-byte framed returns 00100338/00101d38. All are fully accepted; the preceding pending-proposal paragraph is historical. Session gain: nine ranges, 520 bytes.

Nearhelper accepts complete 104-byte 0013e4b8 after restoring the first-call argument and original register scheduling. Session progress is ten accepted ranges and 624 instruction bytes; all 62 bundles and both switches pass.

Virtualaddress accepts 003155c0 (40 bytes) and 00171348 (44 bytes). Session progress: twelve ranges, 708 instruction bytes. Three fresh 44-byte sibling proposals 00171378, 00171e58 and 0030a2d0 have isolated exact proofs and await integration.

Virtualsiblings fully accepts 00171378, 00171e58 and 0030a2d0, each 44 bytes. Session progress: fifteen ranges, 840 instruction bytes. Ordered initializer variants remain unregistered; see blocker log.

Memoryfamily fully accepts 0018f218 (48 bytes), 0018d808 (52 bytes) and 001d2210 (52 bytes). Session progress: eighteen ranges, 992 instruction bytes. project-report-draft.md contains the requested report structure and onboarding; final counts and evidence will be refreshed after the minimum four-hour work period.

Tailcallload accepts complete 40-byte 001ac700. Session progress: nineteen ranges, 1,032 instruction bytes; elapsed work is still below four hours. Two other short-family residuals are recorded in the blocker log.

Callbackfamily fully accepts eight 52-byte helper ranges after independent curation and full acceptance. Session progress: twenty-seven ranges, 1,448 instruction bytes. An original-byte census found no remaining unaccepted members of this exact 13-instruction family. Existing callback/split-address blocker entries are historical for these now-accepted targets.

Offsetpair accepts two complete 60-byte helpers, 001fab08 and 001fb870. Session progress: twenty-nine ranges, 1,568 instruction bytes. Destructor and clear-epilogue residuals remain isolated.

Conditionresult accepts complete 60-byte 002e9c58. Session progress: thirty ranges, 1,628 instruction bytes. Remaining predicate setup/prologue mismatches are preserved in the blocker log.

Mixedtransport accepts 002f10c0 (60 bytes), 0022dd40 (64 bytes) and 00181a90 (64 bytes). Session progress: thirty-three ranges, 1,816 instruction bytes. Complete source/proof hashes and cumulative acceptance are preserved.

Calltransport accepts 0014a188 (68 bytes) and 002956c0 (76 bytes). Session progress: thirty-five ranges, 1,960 instruction bytes. Fresh 68-byte loop proposal 002908a8 is isolated exact and awaits curation/integration.

Clearloop accepts complete 68-byte 002908a8. Session progress: thirty-six ranges, 2,028 instruction bytes. New packet/predicate experiments remain nonmatching and are recorded as blockers.

Dependencyfamily accepts two complete 108-byte loop functions and the 100-byte packed-argument function 0014b4b0. Session progress: thirty-nine ranges, 2,344 instruction bytes. Fresh wrapper proofs 002c6420 (108 bytes) and 0018c8f0 (112 bytes) are exact but not yet accepted.

Wrapperorder accepts 002c6420 (108 bytes) and 0018c8f0 (112 bytes). Session progress: forty-one ranges, 2,564 instruction bytes. Applying the new link-order pattern to parked families did not generalize; fresh failed proofs are preserved.

Floatiterator accepts complete 84-byte 0011ea40 with the corrected floating-point ABI. Session progress: forty-two ranges, 2,648 instruction bytes. A positive-control-validated census found only this unaccepted member before integration. The prior empty census had an incorrect branch mask and is explicitly retained as invalid evidence.

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

The five-hour queue run began 2026-10-09 15:25:02 UTC and requires at least 18,000 active work seconds, excluding usage-limit interruptions. Queuealpha accepts six complete functions (00153610, 0014db78, 0014dbc8, 0014dc08, 00160ac0, 0014dc48), totaling 472 instruction bytes. Independent curated probes, full build, 93 cumulative bundles, three switch checks, finalization and the current gate pass. Workers drain for exclusive integration and resume stealing small batches afterward.

queuebeta accepts 11 complete ranges (00143348, 0014a138, 0014dca8, 0015d730, 001668f8, 00166930, 0016a158, 0031b070, 0016f470, 00172928, 0019da20), totaling 944 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuegamma accepts 14 complete ranges (0014ae10, 001618f0, 0019ab30, 001abf00, 001b6ab8, 001c8a90, 001c9df8, 001d4ef0, 001d6ec8, 001e5fd8, 00222978, 002229d8, 00224c20, 00293350), totaling 1364 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuedelta accepts 12 complete ranges (00141010, 001b84b8, 001d86a0, 00209e80, 0020e548, 00222678, 00222868, 002229a0, 002920c0, 002f3cd8, 002f4000, 002f42e8), totaling 852 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueepsilon accepts 24 complete ranges (00152598, 00191f20, 0019ec20, 001b6070, 00203a40, 00207260, 00209fb8, 0020b410, 00222568, 002430b0, 0024e008, 00271828, 0028ac98, 00292148, 002921d0, 00292258, 002bd788, 002c1a58, 002e5f70, 002f47d8, 00305e20, 00307f40, 00308da0, 0030ec28), totaling 1684 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuezeta accepts 10 complete ranges (00162b68, 0016d888, 00178cf8, 001a2a18, 001b7958, 0020e138, 002eaba8, 002ece98, 002f3d08, 002f4888), totaling 608 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueeta accepts 22 complete ranges (001003b0, 00100468, 00100700, 00101ce0, 00102470, 00102750, 0013a178, 00162b18, 00163210, 00163268, 00167658, 0016adc8, 00183768, 001846a0, 001860b0, 0019fb70, 001b08e8, 001c6400, 00222790, 00222800, 002cbf08, 002f49c0), totaling 1844 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuetheta accepts 32 complete ranges (00102c48, 00102f38, 00103480, 00103500, 00103748, 001037b8, 001039f8, 00103b78, 001045b8, 00104cf0, 00104da0, 00104e18, 00146cb0, 00163828, 00178220, 0018a4d8, 001979d8, 001b2f10, 001cd520, 001d29a0, 001dc5f8, 00258a88, 00276f38, 002806a0, 00287b98, 002c18e0, 002d2070, 002d88a8, 002dce80, 002dd140, 002ffbe0, 00306900), totaling 2180 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueiota accepts 1 complete ranges (00174af8), totaling 48 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuekappa accepts 1 complete ranges (00158ac8), totaling 84 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuelambda accepts 1 complete ranges (0028b1c0), totaling 36 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuemu accepts 3 complete ranges (0016e718, 00182838, 002e7b88), totaling 116 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuenu accepts 3 complete ranges (001d97c8, 0023e738, 00288018), totaling 120 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuexi accepts 2 complete ranges (001a1db8, 001b1be0), totaling 84 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueomicron accepts 1 complete ranges (0023e788), totaling 40 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuepi accepts 2 complete ranges (001d97f0, 001d9820), totaling 96 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuerho accepts 1 complete ranges (001ad990), totaling 52 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuesigma accepts 1 complete ranges (0023e700), totaling 56 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuetau accepts 2 complete ranges (001bbcc0, 003160e0), totaling 100 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueupsilon accepts 3 complete ranges (00173270, 001bd3e0, 00241fd0), totaling 144 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuephi accepts 3 complete ranges (002e2e18, 00308650, 0030a690), totaling 160 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuechi accepts 6 complete ranges (0015cbb8, 001c0268, 001de910, 00241740, 00256b80, 0031e0b8), totaling 264 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuepsi accepts 8 complete ranges (0016f770, 00191bf0, 001b83f0, 001b9c28, 001c2d48, 001de7d8, 002289c0, 00228e28), totaling 384 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueomega accepts 10 complete ranges (001d3350, 0025a1d0, 00276df8, 00287bd0, 002bd730, 002dc248, 002dd218, 002f1ae0, 00308dc0, 0031e068), totaling 480 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuealphaprime accepts 57 complete ranges (00114850, 00114968, 00114b90, 00114cc8, 00114de0, 00114f38, 00115090, 00115290, 001153e8, 00115560, 001156b8, 001157d0, 00119d08, 0011a340, 0011a510, 0011f5a0, 001207c8, 00128008, 00131770, 00132590, 00133228, 001b01d8, 001d2070, 00236a18, 00239898, 0023c0c0, 0023f870, 00290870, 002d1840, 002d2a58, 002d6af0, 002dab30, 002dad40, 002db580, 002db730, 002ddb80, 002de810, 003157b8, 00315840, 003158c8, 0031e630, 0031f008, 0031f238, 0031f4b8, 0031fe88, 0031ff88, 00320050, 00320118, 003207c8, 00320c80, 00321648, 00324b78, 00325408, 00325550, 003255b8, 00325618, 00325678), totaling 2964 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuebetaprime accepts 12 complete ranges (001c7c68, 001ca718, 001cbbf8, 001cc0e8, 001cced8, 001d28f0, 001d74f8, 001da278, 002ceaa8, 0031c9a8, 0031ca20, 0031e110), totaling 768 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuegammaprime accepts 13 complete ranges (001358c0, 00135900, 0014a950, 0014ba20, 0014ba90, 001ad5a8, 001ad5f0, 001db8f8, 001db950, 0028b750, 0028b788, 002c1aa0, 002ee5d8), totaling 956 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuedeltaprime accepts 5 complete ranges (00185b00, 00185b70, 001ae9a0, 001aea00, 002d49c0), totaling 528 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueepsilonprime accepts 8 complete ranges (00105da8, 0010c7f0, 0011c4b0, 0011f238, 001394d8, 0015b4c0, 002cb7c8, 003206f0), totaling 448 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuezetaprime accepts 2 complete ranges (002d96d8, 002d9730), totaling 168 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueetaprime accepts 3 complete ranges (0014f030, 002cba50, 00304db0), totaling 168 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuethetaprime accepts 10 complete ranges (00123d90, 00124100, 00132270, 0013f608, 0014f688, 00153310, 0015a118, 0017c8f0, 001b6f48, 001d4dc0), totaling 616 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queueiotaprime accepts 7 complete ranges (0031ae18, 0031c0b8, 0031d770, 0031d7c0, 0031d978, 0031e008, 00322e18), totaling 444 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuekappaprime accepts 11 complete ranges (0015a6c8, 002314c0, 002424c0, 00242980, 002429c0, 00287720, 00287760, 0029e258, 0029e3a0, 002b6b84, 002b7f84), totaling 676 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuelambdaprime accepts 18 complete ranges (002b6bc4, 002b6c04, 002b7078, 002b7108, 002b78ec, 002b7e34, 002b7ebc, 002b7efc, 002b7fbc, 002b7ffc, 002b803c, 002b8374, 002b83b4, 002b9968, 002b99c8, 002b9a00, 002b9a38, 002b9a78), totaling 1120 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuemuprime accepts 21 complete ranges (002b6adc, 002b6b24, 002b6f28, 002b7010, 002b70b8, 002b726c, 002b72e4, 002b7334, 002b73ac, 002b788c, 002b792c, 002b797c, 002b7c34, 002b7ca4, 002b7cec, 002b7d5c, 002b7db4, 002b7e74, 002b7f3c, 002b823c, 002b83ec), totaling 1888 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queunuprime accepts 18 complete ranges (00106a18, 0010f918, 001142e0, 00114328, 00133938, 001339d0, 00136ab8, 0013fec0, 001585a0, 0016df28, 0016df70, 0016e000, 0016e048, 00171268, 001712b0, 00172ae0, 00188fe0, 00194830), totaling 1272 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

queuexiprime accepts 16 complete ranges (00106a60, 00138140, 00161598, 0016bd10, 0016c358, 0016d640, 0016d8d0, 0016e240, 00171518, 00171640, 00172890, 00173558, 00173dc0, 00175b68, 00176818, 0017a6c8), totaling 1248 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaa accepts 5 complete ranges (00105de0, 00105f00, 00105fc8, 00109360, 00109cc0), totaling 524 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchab accepts 17 complete ranges (0010ab08, 0010cce0, 0010f660, 0010f960, 0010f9f0, 00112388, 001129d8, 00112d28, 001168c0, 0011b038, 0011c828, 0011e350, 0011ecc8, 00160488, 0016ffc8, 00170ee8, 0018f0b0), totaling 1616 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchac accepts 17 complete ranges (0010ce78, 0010f6b8, 001124f8, 001144e8, 0011f078, 001231f8, 00123ba8, 00123c20, 00123c98, 00124748, 00137c50, 00161548, 001b1bb8, 0028b7f8, 00315678, 00315700, 00316890), totaling 1376 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchad accepts 11 complete ranges (00108930, 00109788, 00132068, 00132ec0, 001340e8, 00135c88, 00135cc8, 00135d00, 001373a0, 001385c0, 0018dbd8), totaling 872 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchae accepts 6 complete ranges (00139858, 001398d0, 00139948, 001399c0, 00139a38, 00139ab0), totaling 696 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaf accepts 4 complete ranges (00139b28, 00139ba0, 00139c18, 0013a958), totaling 464 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchag accepts 8 complete ranges (0013aca0, 0013b9e0, 0013d750, 0013e3b0, 0013efe8, 00140760, 001407d0, 001418e8), totaling 756 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchah accepts 4 complete ranges (00141988, 00142208, 00143a48, 00143ae0), totaling 468 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchai accepts 5 complete ranges (00143dd0, 00144060, 00145580, 00145c28, 00145c68), totaling 508 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaj accepts 5 complete ranges (00146730, 00147240, 00149c08, 00149c40, 0014a470), totaling 420 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchak accepts 4 complete ranges (0014a868, 0014ad20, 0014cc40, 0014cde0), totaling 344 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchal accepts 6 complete ranges (0014d008, 0014d478, 0014d8d0, 0014d910, 0014ed28, 0014eda8), totaling 568 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcham accepts 3 complete ranges (0014f5d0, 00153100, 001535b0), totaling 248 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchan accepts 2 complete ranges (00154288, 001542c8), totaling 164 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchao accepts 4 complete ranges (00157aa0, 001585e8, 00159130, 00159c20), totaling 336 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchap accepts 2 complete ranges (0015a768, 0015a810), totaling 160 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaq accepts 4 complete ranges (0015aaf8, 0015ac68, 0015c450, 0015cc18), totaling 364 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchar accepts 4 complete ranges (0015cff0, 0015de98, 0015eaf8, 0015edb8), totaling 396 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchas accepts 3 complete ranges (0015ee10, 00160430, 001608c0), totaling 332 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchat accepts 2 complete ranges (00161248, 001615e8), totaling 232 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchau accepts 4 complete ranges (00160e50, 00160f10, 00161030, 001611a8), totaling 416 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchav accepts 3 complete ranges (001616f0, 00165830, 001659b8), totaling 276 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaw accepts 6 complete ranges (00166968, 001675b0, 00167b08, 00167b98, 00167f38, 00168008), totaling 580 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchax accepts 9 complete ranges (00168958, 00168aa0, 00168b38, 0016ac80, 0016b070, 0016b7a0, 0016b800, 0016bb38, 0016c508), totaling 780 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchay accepts 7 complete ranges (0016c640, 0016d5d0, 0016dad8, 0016dd28, 0016e200, 0016e500, 0016f4b8), totaling 616 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchaz accepts 6 complete ranges (0016f8d0, 0016f970, 001703a8, 001708f8, 00170cd0, 00170dd0), totaling 528 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchba accepts 7 complete ranges (00171418, 00171810, 00171848, 00171c60, 00171fa8, 001727c8, 00172a10), totaling 508 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbb accepts 6 complete ranges (00172a80, 00173348, 00173918, 001739b8, 00173e38, 00173f08), totaling 552 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbc accepts 8 complete ranges (00175370, 00176258, 00176620, 00176c68, 00177540, 00178280, 00178570, 001786e0), totaling 764 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbd accepts 9 complete ranges (00179b68, 00179c80, 00179f80, 0017a418, 0017a538, 0017a600, 0017a718, 0017c030, 0017c108), totaling 856 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbe accepts 8 complete ranges (0017ce10, 0017ce80, 0017de70, 0017edf0, 0017f488, 00180408, 001805e8, 00180618), totaling 760 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbf accepts 11 complete ranges (00180ce0, 00180d40, 00180dc0, 00180ef0, 001817f0, 00182720, 00182ab0, 00182d80, 00182f38, 001835a0, 00184478), totaling 940 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbg accepts 6 complete ranges (00185a28, 00185a68, 00185c48, 00185da8, 00185de0, 00186078), totaling 384 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbh accepts 6 complete ranges (00187420, 001874a0, 001877a0, 00187ab8, 00188340, 001883f8), totaling 624 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbi accepts 7 complete ranges (00188670, 001886d0, 00188758, 001888c8, 00189228, 0018b200, 0018bbf8), totaling 708 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbj accepts 9 complete ranges (0018d790, 0018e108, 0018f248, 0018f940, 0018fde0, 0018fe80, 001900d0, 00190140, 00190388), totaling 696 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbk accepts 8 complete ranges (001906f0, 001907e0, 00190a28, 001918c8, 00191938, 00191a50, 001922c8, 00192320), totaling 732 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbl accepts 7 complete ranges (001940b8, 001942b8, 001943e8, 001947c0, 00194930, 00194980, 00195858), totaling 656 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbm accepts 8 complete ranges (00196198, 00196288, 001964d8, 001966b0, 00196710, 00196888, 00196a40, 00196b88), totaling 836 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbn accepts 5 complete ranges (00197c28, 00197e08, 00197fe0, 00198700, 00198970), totaling 404 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbo accepts 6 complete ranges (00198b88, 00198bd0, 00199030, 00199120, 00199cd0, 0019aa00), totaling 560 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbp accepts 7 complete ranges (0019ad00, 0019b260, 0019b380, 0019bad8, 0019bf00, 0019c590, 0019c838), totaling 544 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbq accepts 8 complete ranges (0019c8d0, 0019c920, 0019d380, 0019d438, 0019d588, 0019eb60, 0019ebc0, 0019f5d8), totaling 640 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbr accepts 8 complete ranges (0019f740, 0019f8f8, 0019f950, 001a07b0, 001a1658, 001a17c8, 001a1d50, 001a2578), totaling 716 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbs accepts 5 complete ranges (001a25c8, 001a2618, 001a2668, 001a3a88, 001a3b08), totaling 424 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbt accepts 3 complete ranges (001904a8, 00195468, 0019ac80), totaling 248 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbu accepts 3 complete ranges (001a4060, 001a49a0, 001a5a48), totaling 288 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbv accepts 3 complete ranges (00198aa8, 00199548, 00199810), totaling 292 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbw accepts 3 complete ranges (001a60c8, 001a6440, 001a6ae8), totaling 268 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbx accepts 5 complete ranges (001a6c90, 001a74f8, 001a78c0, 001a80c8, 001a8190), totaling 348 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchby accepts 3 complete ranges (001a8258, 001a8510, 001a8cd0), totaling 244 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchbz accepts 4 complete ranges (0019ee28, 0019f8c0, 001a81f0, 001a8c78), totaling 292 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchca accepts 2 complete ranges (001a8f10, 001a92d8), totaling 204 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcb accepts 3 complete ranges (001aadb0, 001aae28, 001aaf98), totaling 188 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcc accepts 5 complete ranges (001aa790, 001aa7f0, 001abdf0, 001abe80, 001ac660), totaling 464 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcd accepts 7 complete ranges (001ac858, 001ac8b0, 001acf38, 001ad1d0, 001ad228, 001ad3e0, 001ad430), totaling 672 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchce accepts 10 complete ranges (001ad098, 001ad0f8, 001ad4a8, 001ad9c8, 001adbc0, 001ae210, 001aeb80, 001aebf0, 002803e0, 002835d8), totaling 896 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcf accepts 10 complete ranges (001af778, 001afa50, 001afe30, 001b0210, 001b0728, 001b0858, 001b1360, 001b1928, 001b1e80, 001b1ff0), totaling 852 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcg accepts 7 complete ranges (001b24c8, 001b2520, 001b3018, 001b3098, 001b3a90, 001b43e0, 001b5400), totaling 720 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchch accepts 8 complete ranges (001b58b8, 001b5a10, 001b5af0, 001b5ef0, 001b6c60, 001b7998, 001b7f30, 001b8680), totaling 676 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchci accepts 5 complete ranges (001b87b0, 001b8ce0, 001b8d60, 001b8e00, 001b9bc8), totaling 480 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcj accepts 7 complete ranges (001bb4b0, 001bb7f8, 001bb890, 001bb9b0, 001bb9f0, 001bbac0, 001bbb50), totaling 532 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchck accepts 10 complete ranges (001bbc30, 001bbdb8, 001bbec0, 001bbf00, 001bbf40, 001bbfd0, 001bc010, 001bc050, 001bc0e0, 001bc130), totaling 760 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcl accepts 8 complete ranges (001bcf38, 001bd5b0, 001bd618, 001bdcd0, 001be890, 001befd8, 001bf6a8, 001bfc28), totaling 724 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcm accepts 6 complete ranges (001bffd8, 001c0648, 001c0a00, 001c1060, 001c1130, 001c11e0), totaling 580 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcn accepts 6 complete ranges (001c1708, 001c2338, 001c2ba8, 001c35a0, 001c3aa0, 001c5f38), totaling 572 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchco accepts 8 complete ranges (001c7950, 001c8948, 001c8b48, 001c9b38, 001c9b90, 001c9c00, 001c9db0, 001ca448), totaling 732 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcp accepts 8 complete ranges (001cbeb8, 001ccda0, 001ce378, 001ce3e8, 001ce488, 001ced10, 001ced68, 001cf560), totaling 776 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcq accepts 7 complete ranges (001cf998, 001cfac0, 001d14e0, 001d1540, 001d1f38, 001d2130, 001d2690), totaling 616 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcr accepts 4 complete ranges (001c3670, 001ca950, 001d3b68, 001d3f38), totaling 328 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcs accepts 8 complete ranges (001d5068, 001d5198, 001d5868, 001d59b0, 001d5cd0, 001d5d20, 001d69d0, 001d6d00), totaling 772 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchct accepts 6 complete ranges (001d6e08, 001d6e60, 001d7730, 001d7ec8, 001d8070, 001d8fa8), totaling 572 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcu accepts 6 complete ranges (001d9148, 001d9320, 001d9c68, 001d9ca0, 001d9dd0, 001d9e30), totaling 468 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcv accepts 6 complete ranges (001d7a08, 001d9d48, 001da420, 001db5a8, 001db808, 001db850), totaling 420 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcw accepts 8 complete ranges (001db8b8, 001db9a8, 001dba98, 001dbb38, 001dbcd0, 001dc018, 001dc418, 001dc4e8), totaling 700 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcx accepts 7 complete ranges (001db7d0, 001dba18, 001dbad0, 001dc738, 001dc790, 001dcc60, 001dcd88), totaling 588 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcy accepts 4 complete ranges (001dcfb0, 001dd2b8, 001ddc08, 001ddc48), totaling 288 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchcz accepts 6 complete ranges (001de168, 001de4b0, 001de508, 001de590, 001de610, 001de8a8), totaling 628 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchda accepts 3 complete ranges (001dffd8, 001e0058, 001e01e8), totaling 280 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdb accepts 2 complete ranges (001e0750, 001e0de8), totaling 200 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdc accepts 3 complete ranges (001e2788, 001e27c0, 001e29e0), totaling 216 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdd accepts 1 complete ranges (001e2660), totaling 84 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchde accepts 5 complete ranges (001e3468, 001e3898, 001e60b0, 001e65d0, 001e7798), totaling 504 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdf accepts 9 complete ranges (001e7810, 001e78e0, 001e7cc0, 001e9078, 001ea458, 001eb0c8, 001eb140, 001eb1b0, 001eb228), totaling 992 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdg accepts 2 complete ranges (001fab48, 001fbb20), totaling 244 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdh accepts 6 complete ranges (001f0430, 001fb928, 001fcb18, 00200638, 00205718, 00207050), totaling 660 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdi accepts 2 complete ranges (002072a8, 0020df70), totaling 224 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdj accepts 3 complete ranges (0020eac0, 0020eaf8, 0020ebd8), totaling 228 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdk accepts 1 complete ranges (0021cda0), totaling 44 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdl accepts 2 complete ranges (0021f5d8, 00224780), totaling 160 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdm accepts 9 complete ranges (001b8988, 001bba88, 001c0410, 001d4f40, 001dddd0, 001ded98, 001dee10, 001e0230, 0020cf60), totaling 840 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdn accepts 10 complete ranges (00224f38, 002252b0, 00225328, 00225640, 00225690, 002256c8, 00225aa8, 00226e60, 00227078, 002278e0), totaling 936 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdo accepts 2 complete ranges (00220c88, 002233f0), totaling 192 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdp accepts 1 complete ranges (001c05b0), totaling 100 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdq accepts 10 complete ranges (00227a28, 00227cd8, 0022afa0, 0022b028, 0022b558, 0022c4b8, 0022cea0, 0022d820, 0022e188, 0022e330), totaling 852 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdr accepts 2 complete ranges (001bc6a8, 00226050), totaling 148 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchds accepts 1 complete ranges (001b7df0), totaling 120 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdt accepts 6 complete ranges (0022e6b0, 0022efb8, 0022f4f0, 002322b8, 00232348, 00232498), totaling 576 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdu accepts 4 complete ranges (00232590, 00232e60, 00233ac0, 00233c98), totaling 312 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdv accepts 7 complete ranges (002349e8, 00236148, 002367c8, 00236d60, 002384f8, 00239558, 00239b50), totaling 568 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdw accepts 6 complete ranges (002341e8, 00234298, 00239f78, 0023d260, 0023e918, 0023edb0), totaling 456 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdx accepts 9 complete ranges (0023ef50, 0023fcd0, 002409b8, 00240a08, 00240b48, 00240e10, 00241320, 00241528, 00241568), totaling 672 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdy accepts 3 complete ranges (00239f18, 00241670, 002421e8), totaling 256 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchdz accepts 8 complete ranges (00242a90, 00242c00, 00242df0, 00243190, 002431d0, 00243230, 00244a10, 00244db8), totaling 716 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchea accepts 10 complete ranges (00247bb0, 00249358, 0024ad50, 0024b078, 0024b1a0, 0024c828, 0024eb50, 0024f240, 00250748, 00250928), totaling 1016 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheb accepts 3 complete ranges (002519d0, 00251e90, 00252618), totaling 176 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchec accepts 5 complete ranges (00253380, 002576d0, 00257970, 00257ff8, 00258a30), totaling 416 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orched accepts 4 complete ranges (00259350, 002594b8, 00259510, 0025d620), totaling 416 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchee accepts 1 complete ranges (00262290), totaling 108 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchef accepts 10 complete ranges (002636b0, 00263778, 002638e0, 00263c60, 00263cc0, 00263e18, 00264328, 002656c0, 002670a0, 002670f8), totaling 1060 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheg accepts 10 complete ranges (002671e8, 00267320, 00269ef8, 00269f58, 0026e5b8, 0026ff30, 00271e08, 00275c78, 00275e08, 00275e68), totaling 980 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheh accepts 4 complete ranges (00275f08, 00276a90, 00276b10, 0027a108), totaling 464 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchei accepts 6 complete ranges (0027ae78, 0027db58, 00280240, 00282c68, 002831e0, 00283618), totaling 532 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchek accepts 3 complete ranges (00285d18, 002865d0, 00287430), totaling 268 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchel accepts 1 complete ranges (00284ea8), totaling 68 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchem accepts 5 complete ranges (0028ae28, 0028ae98, 0028b040, 0028b120, 0028b218), totaling 400 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchen accepts 1 complete ranges (00288f60), totaling 120 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheo accepts 2 complete ranges (0028bdb8, 0028cdb8), totaling 216 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchep accepts 5 complete ranges (0028cf28, 0028d008, 0028dd90, 0028e5e0, 0028eb88), totaling 488 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheq accepts 1 complete ranges (0028f4a0), totaling 52 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcher accepts 5 complete ranges (00292630, 00292eb0, 00293668, 00293fc0, 00294208), totaling 464 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orches accepts 1 complete ranges (00292a58), totaling 56 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchet accepts 1 complete ranges (0028f690), totaling 92 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orcheu accepts 3 complete ranges (00294480, 00295228, 00298f90), totaling 236 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchev accepts 1 complete ranges (00294408), totaling 116 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchew accepts 4 complete ranges (0029c9d8, 0029dd00, 0029dda8, 0029e7b0), totaling 412 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchex accepts 3 complete ranges (002a0360, 002a4990, 002a6878), totaling 280 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchey accepts 3 complete ranges (002aa2f8, 002aaa38, 002aab90), totaling 340 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchez accepts 1 complete ranges (002aa450), totaling 84 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchfa accepts 5 complete ranges (002aacd8, 002aae30, 002ab258, 002abdc8, 002b16d8), totaling 436 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchfb accepts 4 complete ranges (002b2840, 002b2d48, 002b3ae8, 002b4f50), totaling 420 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchfc accepts 5 complete ranges (002b4fb8, 002b5078, 002b56e8, 002b5768, 002b6338), totaling 524 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchfd accepts 1 complete ranges (002b6ab8), totaling 36 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.

orchfe accepts 2 complete ranges (002b9b78, 002b9e80), totaling 164 instruction bytes. Independent curated probes, full build, cumulative bundles and switch receipts, finalization, warning audit and checkpoint pass. Five-hour queue run continues.
