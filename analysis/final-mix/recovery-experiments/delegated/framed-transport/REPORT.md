# Framed transport recovery pass

No exact proposal. Four scoped, evidence-derived probes completed; all remain unregistered. No shared stage inputs, compiler flags, registrations, gates or status files changed.

The isolated probe used `Public/tools/kh2-audit/probe_fm_source.py` under Ubuntu-24.04/root and its unchanged pinned `kh2-local/ps2-compiler:3.2-ee-040921-objdiff` compiler flags. The probe asserts original executable SHA-256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. Complete target bytes came from the original ranges in the existing proofs and were revalidated by the new probes; no decompiler boundary substitution occurred. Initial ordinary WSL access returned E_ACCESSDENIED; authorized escalated probes succeeded. Compiler is idle.

## 0013e610 allocator: 100 bytes

Original range SHA-256: `230e94fc3a63cd661eeac0864a508f1f11e31c3587b3e0335a9cc9ae6ee7f417`.

Best new source: `sa_transport_0013e610_lookup.cpp`, SHA-256 `f17136f31a795be5cd909837c9aae7ce2eafaf4749aca3e9069de2ebc0a41629`. Its adjacent `.verification.json` proves 100/100 bytes, not exact. Narrow four-instruction scaled-index/counter-store/lookup assembly fixes the prior store-before-shift and reversed `addu` operand differences. The first 48 bytes and final 36 bytes now match exactly. Original semantics remain decrement counter at base+0x1fa4, index table at base+index*4+0x1f80, result base+entry*0x380, helper(result,input,D_003486a0+0x20), return result.

All remaining differing words (little-endian bytes):

| Offset | Compiled | Original |
|---|---|---|
| 0x30 | 80030e24 | 35000e3c |
| 0x34 | 35000f3c | a086c68d |
| 0x38 | 1868ae01 | 80030f24 |
| 0x3c | a086e68d | 1868af01 |

The original cluster is `lui $14,0x35; lw $6,-0x7960($14); li $15,0x380; mult $13,$13,$15`. The proposal materializes stride in $14 before the global high address in $15 and reverses load/multiply timing.

Refinement `sa_transport_0013e610_address.cpp`, SHA-256 `4344501b4c5f7a463144c6f618d4162e57b19d8dd6ecccbfa4a95f74ae78173c`, also 100/100, not exact. Symbolic paired global-load relocations restore global register $14 and destination $6, but independent stride setup is hoisted ahead of that block. Multiplication/result transport moves to $15. Differences: 0x30 `80030f24/35000e3c`, 0x34 `35000e3c/a086c68d`, 0x38 `a086c68d/80030f24`, 0x3c `1878af01/1868af01`, 0x44 `21800f02/21800d02` (compiled/original).

Next hypothesis: include stride setup after the symbolic global load in the same narrow transport block, then constrain the C++ product to $13 before adding base. This was not probed; the root requested completion after four probes. The evidence establishes a concrete register/scheduling residual, not compiler impossibility.

## 00143470 seven-input wrapper: 92 bytes

Original range SHA-256: `a94765fa59ea67f8c6975261832e0b3924ed755e22cb85829d1b9e80c95b26e6`.

Best source remains historical `../../fm_primary_nexttransport_v1_00143470_1.cpp`, SHA-256 `b4208e0e5b13b1998a6b8058bef5125293740c521ee5f5f6435dd0cf248b7d45`, 92/92, not exact. The complete target/proof comparison shows the prologue and epilogue already exact; only six argument-transport words differ. Earlier broad descriptions of save-order differences do not apply to this particular best proof.

| Offset | Compiled | Original |
|---|---|---|
| 0x30 | 2d28c001 | 2d500002 |
| 0x34 | 2d30a001 | 2d28c001 |
| 0x38 | 2d388001 | 2d30a001 |
| 0x3c | 2d406000 | 2d388001 |
| 0x40 | 2d484000 | 2d406000 |
| 0x48 | 2d500002 | 2d484000 |

Original moves sixth input from $16 to outgoing $10 before outgoing $5,$6,$7,$8 moves, and moves outgoing $9 from $2 in the call delay slot. Historical source delays $10 until the call delay slot instead. Helper is `func_001652c8(D_00348804,p1,p2,p3,p4,p5,p6,p7)`.

`sa_transport_00143470_argument.cpp`, SHA-256 `c8f542a5cf4d56b66821e8ca3fb79dd580154548fb7428266f34ea45c425f1fc`, compiled 76/92, not exact. The seventh-input $10 marker removes the saved-register lifetime and changes the frame. This was an unsuccessful transport hypothesis, not a viable proposal.

`sa_transport_00143470_sixth.cpp`, SHA-256 `cc43306089d60cdb76d4d518cc5caa58aed94b8d725f863fd48fde5064a95ac0`, compiled 96/92, not exact. Correcting to sixth input and preserving $16 after the helper retains a saved register but adds transport and substantially reorders the prologue. The fixed marker before the call is too early for the original schedule.

Next hypothesis: preserve the best historical frame and constrain only the local $16-to-$10 move after the $10-to-$11 copy, without introducing a separate live pre-call value or an extra saved-register use. A narrow local transport constraint must preserve the compiler's original first-48-byte sequence and final restores.

## Preserved evidence

All four source files and all four adjacent complete-range `.verification.json` proofs remain in this directory. The historical source/proofs and `primary-fourhour-blockers.md` were read only. No whole-function assembly, blind variant sweep, registration, synchronization or full build occurred.
