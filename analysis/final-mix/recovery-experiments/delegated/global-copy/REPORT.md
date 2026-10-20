# Global copy recovery report

The pinned compiler is `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`; flags and live project state were unchanged. The isolated verifier checked original ELF SHA-256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. Both function boundaries are 84 bytes. `original-disassembly.txt` independently records original instructions from the ELF; `comparisons.json` records every new valid source hash and exact word difference.

## Exact proposal: 00158b20

`sa_copy_b20_float.cpp` and its verification proof match all 84 bytes. Source SHA-256: `d358fdcd07a7be42bac781e1229ee9c4cf2f3c93db55bb6818fe1e016bc8b016`.

The source retains C++ float loads/stores and pointer equality guards, with the established narrow LQ/SQ copy transports. Symbolic paired LUI/ADDIU address transports constrain register 15. Precise copy memory operands avoid extra global-address materialization. Updating `object` by 0x70 reproduces the final register-4 destination without an extra move. A memory input on first LUI preserves the preceding float store; a `$f0` clobber on first low-half materialization places the second float load afterward. This is a proposal only, with no registration or full-build claim.

## Blocker: 00158ac8

Prior `fm_primary_globalcopy_v3_00158ac8_1.cpp` is 84/84 and differs in five words: three LUI register-13 allocations and two ADDIU register-13 sources versus original register 15. Its branch-likely guards and delay slots are otherwise correct.

New paired symbolic address transports reproduce register 15 and retain 84 bytes, but first BEQL becomes BEQ with a NOP delay slot. The original first BEQL delay slot materializes the next global high half only on the taken branch; fallthrough rematerializes the same high half after the first SQ. Compiler scheduling of opaque symbolic address transports does not duplicate that materialization into the first likely-branch slot. The second BEQL and float delay-slot duplication remain correct.

Making low halves compiler-visible retains size but changes early instruction order and first guard. An unpaired high-half experiment for 00158b20 fails linking and is not valid evidence. Clobbering register 13 in the existing 00158ac8 copy transports merely reallocates high halves to register 12, leaving the same five-word residual. No 00158ac8 proposal is exact; no compiler impossibility is claimed.

## Operational notes

Initial WSL execution required sandbox escalation. An initial shell loop lost its loop variable in PowerShell expansion and produced `.probe.log`; it did not compile a source. Subsequent explicit isolated invocations produced the preserved proofs. Only this delegated directory and uniquely named WSL scratch directories were written.
