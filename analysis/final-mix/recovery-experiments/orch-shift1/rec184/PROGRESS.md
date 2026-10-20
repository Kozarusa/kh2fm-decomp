# rec184 progress
start 2026-10-18T13:25:37Z
claim 1 of 6: 002a9ce8 token dde6395d95f447c7ac0a5cdb10626bc8 attempts 1 blocker null
002a9ce8 R4.3: single exit forwards final callee v0; u32 return. R4.5: exact accepted declaration func_00319a60(...). v1 fresh: correct allocator a1 and global address; earlier 15-word source not mandatory baseline.
002a9ce8 v1: 15 words; best v1 15 words; streak 0. First difference prologue save scheduled into first jal delay slot; C12 no s-register binding or volatile local to remove, result already separate. R12 conservative block: no covered applicable next control.
blocked 002a9ce8 -> prologue-epilogue
claim 2 of 6: 002aa2f8 token 5a78d168e1ff4e6dac50608963a16be4 attempts 1 blocker null
002aa2f8 R4.3: both exits set v0 with sltu boolean, no callees. Defined u32 shifts and integer address transport. v1 fresh instruction-order loop.
002aa2f8 v1: 12 words; best v1 12 words; streak 0. C11 v2 baseline orch1_rec184_002aa2f8_v1.cpp: reverse loop address-add operands only.
002aa2f8 v2: 11 words; best v2 11 words; streak 0. C11 v3 baseline orch1_rec184_002aa2f8_v2.cpp: introduce final mask temporary only, preserve expression operand order.
002aa2f8 v3: 2 words; best v3 2 words; streak 0. C11 v4 baseline orch1_rec184_002aa2f8_v3.cpp: introduce final address temporary only, preserve addition operands.
002aa2f8 v4: 0 words; best v4 0 words; streak 0. Manual audit: one function, declarations before it, no assembly/bindings/Ghidra names; both returns boolean, defined unsigned shifts/address transport.
submitted 002aa2f8 v4
claim 3 of 6: 002aa450 token 36ddf408f80a48a78f37b75fe43ed8f5 attempts 1 blocker null
002aa450 R4.3: single epilogue v0 = callee result +316 on every path; return address. R4.5 exact accepted s32 func_002a9d68(void). v1 fresh; earlier 13-word source not mandatory baseline. Defined unsigned shift and address transport.
002aa450 v1: 4 words; best v1 4 words; streak 0. C11 v2 baseline orch1_rec184_002aa450_v1.cpp: introduce flag temporary only, preserve operands and condition.
002aa450 v2: 4 words; best v1 4 words; streak 1. C11 v3 baseline orch1_rec184_002aa450_v2.cpp: bind existing word to original t6 only.
002aa450 v3: 4 words; best v1 4 words; streak 2. C11 v4 baseline orch1_rec184_002aa450_v3.cpp: add one empty result guard only; unique full assignment context matched once.
v4 complete guard diff inspected in finished prior call: exactly one added guard, no other compiler-significant change.
002aa450 v4: 4 words; best v1 4 words; streak 3. Stop R7.
blocked 002aa450 -> register-allocation
claim 4 of 6: 002aa8e0 token 47e10b30b307446da3f628d6028c29af attempts 1 blocker null
002aa8e0 R4.3: single exit v0 = last callee result &31; return index. R4.5 copied exact accepted s32 func_002a9d68(void) and s32 func_002aa5b8(s8,s32). v1 fresh. Defined unsigned shift/multiply/address transport.
002aa8e0 v1: 31 words; best v1 31 words; streak 0. C1 R4.3 audit: original passes full a0 without entry normalization. v2 baseline orch1_rec184_002aa8e0_v1.cpp: first parameter u32 only; accepted callee declaration unchanged.
002aa8e0 v2: 27 words; best v2 27 words; streak 0. R12 ABI block: exact R4.5 accepted callee s8 forces sll/sra argument narrowing absent from original. All five packet siblings declare same s8,s32. No permissible signature exception.
blocked 002aa8e0 -> abi-layout
claim 5 of 6: 002aaa38 token 9b9bfb8ac24f4e51b82fe025ebcf96ba attempts 1 blocker null
002aaa38 R4.3: both exits sltu boolean, no callee. v1 uses own exact sibling 002aa2f8 pattern with target name, offset132 and bound32 from packet. Defined unsigned shifts/address transport.
002aaa38 v1: 0 words; best v1 0 words; streak 0. Manual audit: one function, declaration before, no asm/bindings/Ghidra names, both exits boolean, all shifts/address operations unsigned.
submitted 002aaa38 v1
claim 6 of 6: 002aab90 token e01349ae65c14c94917418564a8782fa attempts 1 blocker null
002aab90 R4.3: single exit v0 = callee result +132; return address. R4.5 exact accepted s32 func_002a9d68(void). v1 plain sibling pattern; unsigned shift/address operations.
002aab90 v1: 4 words; best v1 4 words; streak 0. C11 v2 baseline orch1_rec184_002aab90_v1.cpp: bind existing result to t5 only. Flag temporary and word binding failed equivalent sibling 002aa450; preserve original scheduling statements.
002aab90 v2: 4 words; best v1 4 words; streak 1. C11 v3 baseline orch1_rec184_002aab90_v2.cpp: add one empty result guard only; unique assignment matched once.
v3 complete guard diff inspected after prior tool completed: exactly one guard insertion, no other compiler-significant change.
002aab90 v3: 0 words; best v3 0 words; streak 0. Manual audit: one function, exact accepted callee declaration, no Ghidra names; numeric t5 binding and empty guard separately introduced, each why commented; v0 callee result+132 on every exit; defined unsigned shifts/address transport.
submitted 002aab90 v3; K6 reached; no further claims
R11 WP-REPORT written 2026-10-18T13:39:22Z; all six claims closed; 3 submitted, 3 blocked, 0 released.
