# rec186 progress
start 2026-10-18T17:39:49Z
claim attempt 1 of 6
claim 1 of 6: 002aae30 token 2520420c59fd4a74b3c05ccf8e6c610e attempts 1
002aae30 R4.3 audit: sole exit returns callee v0 plus 148; unsigned shifts/address arithmetic. v1 fresh baseline; accepted declaration copied.
002aae30 v1: 0 words; best v1 0 words; streak 0
submitted 002aae30 v1
claim attempt 2 of 6
claim 2 of 6: 002ab100 token 57f67438542242aab59804c1b85ae4ed attempts 1
002ab100 R4.3: both exits set bool v0. v1 fresh baseline, unsigned shifts/address arithmetic; signed 64-bit bgez input.
002ab100 v1: 29 words; best v1 29 words; streak 0
v1 first diff 1: parameter conversion; baseline orch1_rec186_002ab100_v1.cpp, single change s64 parameter to s32 removes unnecessary narrowing.
002ab100 v2: 31 words; best v1 29 words; streak 1
v2 C1 audit paths complete; baseline orch1_rec186_002ab100_v2.cpp single control bool transport to u32 (function and result), original sltu full word.
002ab100 v3: 31 words; best v1 29 words; streak 2
v3 C1 paths correct; baseline orch1_rec186_002ab100_v3.cpp single C11(b) control introduce loop mask temporary, operand order preserved.
002ab100 v4: 25 words; best v4 25 words; streak 0
v4 first diff 2 C11(b); baseline orch1_rec186_002ab100_v4.cpp single control introduce loop base temporary, existing operand order maintained.
002ab100 v5: 29 words; best v4 25 words; streak 1
Deviation: v5 temporary introduction also reversed addition operands; parent notified. v6 baseline orch1_rec186_002ab100_v5.cpp single control restore base-first addition.
002ab100 v6: 29 words; best v4 25 words; streak 2
v7 baseline orch1_rec186_002ab100_v4.cpp, single C11(c) bind existing counter to t4; no guard.
002ab100 v7: 22 words; best v7 22 words; streak 0
v8 baseline orch1_rec186_002ab100_v7.cpp, single C11(b) introduce nonnegative-path mask temporary, operand order preserved.
v4/v5 comparison: added u32 base = D_0035f610 + 0x88u before word; replaced D_0035f610 + word * 4u + 0x88u with word * 4u + base. v5 bundled controls; no isolated effect claimed; v5 ineligible future baseline pending source-policy review. v6 restoration consumed normal version and streak.
002ab100 v8: 13 words; best v8 13 words; streak 0
blocked 002ab100 -> register-allocation
claim attempt 3 of 6
claim 3 of 6: 002ad338 token 4fd12bdf5c754fabbe318c8657427356 attempts 1
002ad338 R4.3: both exits explicit v0 0/1. v1 fresh baseline, unsigned shift/address transport.
002ad338 v1: 18 words; best v1 18 words; streak 0
v2 baseline orch1_rec186_002ad338_v1.cpp, single C11(c) bind existing result to v0.
v3 baseline orch1_rec186_002ad338_v2.cpp, single C11(d) guard immediately after result initialization; unique context verified, full diff one guard.
002ad338 v2: 20 words; best v1 18 words; streak 1
002ad338 v3: 20 words; best v1 18 words; streak 2
v4 baseline orch1_rec186_002ad338_v1.cpp, single C11(c) bind existing index to t4.
002ad338 v4: 16 words; best v4 16 words; streak 0
v5 baseline orch1_rec186_002ad338_v4.cpp, single C7(c) early return to result assignment and loop break.
002ad338 v5: 20 words; best v4 16 words; streak 1
v6 baseline orch1_rec186_002ad338_v4.cpp, single C11(b) replace loop-carried word temporary with same-iteration index shift.
002ad338 v6: 18 words; best v4 16 words; streak 2
v7 baseline orch1_rec186_002ad338_v6.cpp, single C7(c) early return to result assignment and loop break.
002ad338 v7: 2 words; best v7 2 words; streak 0
v8 baseline orch1_rec186_002ad338_v7.cpp, single C11(a) reorder independent mask computation before index increment.
002ad338 v8: 2 words; best v7 2 words; streak 1
blocked 002ad338 -> register-allocation
claim attempt 4 of 6
claim 4 of 6: 002b1660 token de8d90b2c23e4bf4b3f31135fbf0d232 attempts 1
002b1660 R4.3: all exits return last callee v0; no mixed-entry path. v1 fresh baseline; func_00139d78 declaration copied from packet-named fm_oct7_extended_recovered_00.cpp.
002b1660 v1: 11 words; best v1 11 words; streak 0
v2 baseline orch1_rec186_002b1660_v1.cpp single C13 control assign final result to existing result variable before returning.
002b1660 v2: 11 words; best v1 11 words; streak 1
v3 baseline orch1_rec186_002b1660_v2.cpp, single empty result guard after final call, unique context and full one-site diff checked.
002b1660 v3: 13 words; best v1 11 words; streak 2
v4 baseline orch1_rec186_002b1660_v3.cpp single C11(c) bind existing result to v0; existing guard preserved.
002b1660 v4: 13 words; best v1 11 words; streak 3
blocked 002b1660 -> branch-layout
claim attempt 5 of 6
claim 5 of 6: 002b1aa0 token ad66828f99a14bd4b5736e8417010078 attempts 1
blocked 002b1aa0 -> abi-layout: zero versions, exact accepted void callee declaration conflicts original argument
claim attempt 6 of 6
claim 6 of 6: 002b23e0 token 397842b2becc46f3bd739dfd9e571978 attempts 1
002b23e0 R4.3: sole exit v0 global plus low-word product; original mult low word modeled unsigned. v1 fresh baseline.
002b23e0 v1: 8 words; best v1 8 words; streak 0
v2 baseline orch1_rec186_002b23e0_v1.cpp single C11(c) bind existing result to t5.
002b23e0 v2: 8 words; best v1 8 words; streak 1
v3 baseline orch1_rec186_002b23e0_v2.cpp single C11(d) result guard after assignment. Unique context verified, full diff exactly one added guard.
002b23e0 v3: 4 words; best v3 4 words; streak 0
v4 baseline orch1_rec186_002b23e0_v3.cpp single C11(b) introduce factor temporary; multiplication operand order preserved.
002b23e0 v4: 4 words; best v3 4 words; streak 1
v5 baseline orch1_rec186_002b23e0_v4.cpp single C11(c) bind existing factor to t6.
002b23e0 v5: 4 words; best v3 4 words; streak 2
v6 baseline orch1_rec186_002b23e0_v5.cpp single C11(d) factor guard. Unique context checked; complete diff one added guard.
CORRECTION preceding v5 tally was written before inspecting diff: 002b23e0 v5: 2 words; best v5 2 words; streak 0. No decision relies on erroneous tally.
002b23e0 v6: 2 words; best v5 2 words; streak 1
v7 baseline orch1_rec186_002b23e0_v6.cpp single C11(b) reuse existing bound result for unsigned product, addition operand order preserved.
002b23e0 v7: 2 words; best v5 2 words; streak 2
v8 baseline orch1_rec186_002b23e0_v7.cpp single C11(d) guard on product result; unique context/full one-site diff inspected in completed preceding call.
002b23e0 v8: 5 words; best v5 2 words; streak 3
blocked 002b23e0 -> register-allocation; K6 reached
R11 WP-REPORT written; manual source audit completed for submitted source, no assembly/bindings or forbidden names. All six queue receipts closed; mechanical review left to orchestrator.

Review follow-up (additive correction): DEVIATIONS22 remains. 002ab100 v5 is ineligible as a future baseline. v6 restores addition operand order but retains reassociation; v7 branches from valid v4. Any future 002ab100 submission must establish the s32 entry argument domain: original bgez tests the incoming register, while v2 onward narrowed the initial s64 parameter. No isolated temporary or operand-order effect is established for v5.
002b1aa0 retains the ABI conflict between packet-named accepted u32 func_002b23e0(void) and original a0=-1. No R4.5 exception is granted.
Static files verify guard sites, not historical tool-call timing or shell polling. No independent proof of timing or polling is claimed. Independent review approves only submitted 002aae30, with this follow-up.
