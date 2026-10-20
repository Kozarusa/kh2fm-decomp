# Context restoration at 001055b8

The complete declared 104-byte original range is a context-restoration routine.
Ghidra's current export says only `return 1`; that export omits the routine's
essential register, stack, and control-flow effects.

The original instructions load twelve 128-bit general-purpose registers from
the context pointer in a0: gp, sp, s8, ra, and s0 through s7 at successive
16-byte offsets from 0 through 176. They then load f20 through f31 from
successive four-byte offsets 192 through 236. The final instructions jump to
the restored ra and return 1 in v0 in the branch delay slot.

The range has no ordinary function prologue. It restores the stack pointer
and return address before transferring control. Treating its exported
`return 1` as a normal C++ function would erase the original behavior.

No claim of compiler impossibility is made. A defensible next experiment is
structured assembly with named context offsets, followed by complete original
byte verification and a separate review of the context ABI, saved-register
widths, restored stack behavior, and nonlocal return semantics. Assembly must
remain separately classified until the project supports and verifies its
integration. This report does not count a recovered C++ function or runtime
validation.

Read-only disassembly used the pinned project's ee-objdump against the
original `SLPM_666.75`, address interval [001055b8, 00105620). The original ELF
SHA-256 is d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87.
