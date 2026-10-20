# nm35 progress
start 2026-10-18T17:29:47Z
claim 1 of 1: 002aa450 token 4061b6313ebd47d59078ff04203a6606 attempts 2
Read packet and required rec184 evidence. Review MERGE. R4.3: single exit returns callee result +316 on both store/no-store paths; no f0 output. R4.5 exact accepted s32 func_002a9d68(void). v1 unchanged earliest-best baseline; unsigned arithmetic and operand order retained.
002aa450 v1: 4 words; best v1 4 words; streak 0. First diff instruction10 lw t6 versus t5. C11(c) next: bind only existing OR result to numeric13 following accepted sibling v2.
002aa450 v2: 4 words; best v1 4 words; streak 1. First diff instruction10 unchanged. C11(d) next: one empty read-write result guard only, preserving result binding and all operands.
v3 full source diff emitted and inspected in finished exit_code0 call: one guard insertion plus trailing blank line; no other compiler-significant changes.
002aa450 v3: 0 words; best v3 0 words; streak 0. Manual R8 audit: one function, nothing after closing brace except whitespace, exact accepted callee declaration, no Ghidra names or emitted instruction asm, numeric13 binding and empty result guard each why commented. Single epilogue returns callee result+316 on both paths; no f0 output. Unsigned shifts masked31, unsigned integer address arithmetic; operand order preserved.
submitted 002aa450 v3; K1 exhausted. R11 report completed 2026-10-18T17:31:57Z. All exec_command results retained exit_code0; no running session_id returned. Missing sibling v3 diff reconstructed from named proof into own WP; zero words confirmed.
