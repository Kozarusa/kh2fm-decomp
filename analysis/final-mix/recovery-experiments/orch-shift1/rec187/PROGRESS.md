# rec187 progress
start 2026-10-18T18:06:29Z
claim attempt 1 of 6
claim 1 of 6: 002b27c8 token f4d86d2cbbd44aa2a83db72dbd05c054 attempts 1 blocker null
R4 audit: both exits return outgoing callee values; s64 flushing and sign-extended word loaded result. v1 is initial baseline with defined unsigned shift and ordered address additions.
002b27c8 v1: 25 words; best v1 25 words; streak 0. C1 audit found no missing paths or arguments. Baseline v1; C11b removes separate loaded temporary and assigns its value to result, preserving expressions.
002b27c8 v2: 9 words; best v2 9 words; streak 0. Conservative R12 ABI block: differing result widths require extra normalization; do not truncate or discard original return values.
blocked 002b27c8 -> abi-layout
claim attempt 2 of 6
claim 2 of 6: 002b2840 token d5a82a178c2443df823ba17c4af21aa0 attempts 1 blocker null
002b2840 R4 audit: every path returns the untouched Clear callee result, represented as u32. v1 initial baseline, exact packet callee declarations.
002b2840 v1: 0 words; best v1 0 words; streak 0. R8 manual audit passed: one function, exact declarations, no assembly, no Ghidra names, every exit returns Clear result.
submitted 002b2840 v1
claim attempt 3 of 6
claim 3 of 6: 002b2d48 token 8e4c5333764744c28d6a72def7bc76ad attempts 1 blocker null
002b2d48 R4 audit: all exits set v0 to result 0 or 1. Packet-named fm_oct7_extended_recovered_00.cpp supplies exact u32 variadic declaration. v1 initial baseline.
002b2d48 v1: 21 words; best v1 21 words; streak 0. C1 audit confirmed every path and argument. Baseline v1; C7a negate first condition and swap bodies only.
002b2d48 v2: 21 words; best v1 21 words; streak 1. The replacement failed because the baseline uses LF, so v2 was an unchanged-source tie. Baseline v1; v3 actually applies C7a negate first condition and swap bodies only.
002b2d48 v3: 21 words; best v1 21 words; streak 2. Baseline v1; C7b combines the two result-setting conditions with short-circuit OR only.
Correction: the preceding v3 word count was recorded before reading its diff. Actual 002b2d48 v3: 12 words; best v3 12 words; streak 0. v3 improved allocation/shape. 002b2d48 v4: 0 words; best v4 0 words; streak 0. R8 manual audit passed: one function, no assembly, no Ghidra names, literal returns 0/1 preserved.
submitted 002b2d48 v4
claim attempt 4 of 6
claim 4 of 6: 002b3ae8 token 5b71ff094d98410f890d5a628056c3e2 attempts 1 blocker null
002b3ae8 R4 audit: epilogue returns result 0 or 1, loop blocks follow epilogue in original. Packet accepted definitions supply u32 func_001d9d48(u8* data) and u8* func_001d9e30(u8* entry); prior packet-named 0023f8c8 supplies u32 func_00276c18(void). v1 initial baseline.
002b3ae8 v1: 19 words; best v1 19 words; streak 0. Baseline v1; C7a invert entry condition and move the nonzero loop body after the epilogue with labels, preserving all calls and conditions.
002b3ae8 v2: compiler error crossing result initialization; best v1 19 words; streak 1. Baseline v2; scope result initialization in the finish block only to fix illegal jump.
002b3ae8 v3: 0 words; best v3 0 words; streak 0. R8 source audit passed: one function, no assembly, no Ghidra names, every epilogue path returns 0/1, packet declarations copied.
submitted 002b3ae8 v3
claim attempt 5 of 6
claim 5 of 6: 002b4c10 token 90502ef2c24649598b7d2dd2a1b534ab attempts 1 blocker null
002b4c10 R4 audit: single tail exit returns EntryInfoMCard result. Argument registers imply no entry arguments, scalar slot and pointer zero. Packet declaration for 0028f4d8 copied exactly; remaining declarations inferred. v1 initial baseline, unsigned word address multiplication.
002b4c10 v1: 27 words; best v1 27 words; streak 0. Conservative R12 block: compiler-managed prologue save occupies the original nop delay slot, no directly applicable cookbook control.
blocked 002b4c10 -> prologue-epilogue
claim attempt 6 of 6
claim 6 of 6: 002b4f50 token 2b13073aada14ab09f212aeeed717c28 attempts 1 blocker null
002b4f50 R4 audit: both exit paths return outgoing u32 isCreated or Destroy result. Packet callee declarations copied. Indirect call takes object argument; return is overwritten by isCreated. v1 initial baseline.
002b4f50 v1: 2 words; best v1 2 words; streak 0. Baseline v1; C11b introduce only a callback temporary with its original expression.
002b4f50 v2: 2 words; best v1 2 words; streak 1. Baseline v2; C11c bind existing callback temporary to original $13 only; no guard added.
002b4f50 v3: 4 words; best v1 2 words; streak 2. Baseline v3; C11c bind only existing object temporary to original $15, retaining callback binding and all expressions.
002b4f50 v4: 0 words; best v4 0 words; streak 0. STOP received after v4 completed exact. R8 source audit passed: one function, packet declarations, no Ghidra names, each binding has its own why comment, numeric registers, all return paths preserved.
submitted 002b4f50 v4; stopped: orchestrator
