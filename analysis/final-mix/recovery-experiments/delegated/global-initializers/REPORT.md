# Global initializer recovery report

All three isolated proposals compare exactly against the original executable using the unchanged pinned `kh2-local/ps2-compiler:3.2-ee-040921-objdiff` compiler and `Public/tools/kh2-audit/probe_fm_source.py`. No registration, synchronization, shared status, full build, gates, or compiler changes were performed.

Original executable SHA-256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.

| Address | Exact source | Verified bytes | Source SHA-256 | Original range SHA-256 |
|---|---|---:|---|---|
| 0014ec40 | sa_init_0014ec40_v8.cpp | 84 | `af9d818c91733cabb1e7731b918bdf136cf681a757bd2b1c55e321fbf90fb4f6` | `9b2caa412e5746fe88629f333644b223d77f2b148b9d6f1c476818d472785459` |
| 00158fd8 | sa_init_00158fd8_v2.cpp | 84 | `500ff2f6dcbcef4d6d3402a1455c14ebc8e4859102a9c2fab7aa01987782997d` | `b83c6d436c22a67b728b3dff53612dc84ca54b7b5844fb8ff2be1eeb6be68db3` |
| 00159c58 | sa_init_00159c58_v2.cpp | 104 | `305f9bfc1a84945f4fdd3e5990ffe0fd0e63b470e85947744129dc2d80500a72` | `511e6c2b68e640c1e2c4252d1b0ae50b73408f9964b863653be883de17206710` |

Each corresponding `.verification.json` preserves source hash, target bytes, linked candidate bytes, boundary agreement, and exact equality. The two float-pair routines are 84 bytes. The helper initializer is **104 bytes**, not the 100-byte Ghidra pseudocode extent: the original final `jr ra` at 00159cb8 has its stack-restoration delay slot at 00159cbc. The live boundary and the complete pinned probe agree at 104; no shortened range override was used.

## Reconstruction and successful mechanism

Original 0014ec40 first phase guard skips both copies; first mode guard skips the first copy and reaches the second phase guard. Its first mode-branch delay slot redundantly materializes `0xffff`. First copy loads a float through register 15 from 0036b200 and stores to 004f3580. Second copy independently loads 0036b204 and stores to 004f3584. 00158fd8 has the identical structure with sources 0036b31c/0036b320 and destinations 004f35a4/004f35a8.

00159c58 retains the same guard structure, with stack allocation, return-address save, a branch-likely first phase guard restoring the return address only on the skipped path, float source 0036b374, destination 004f3600, and repeated guards before tail-calling 00190128 with address 0034aa18. The original contains a padding NOP after the tail-call delay slot, followed by the shared final return and its delay slot. The successful proposal matches all of these bytes.

The successful sources retain C++ control flow, float loads/stores, and the typed helper call. Empty inline-assembly transport constraints make phase and mode constants opaque in original register 15. Explicit separate phase checks permit register 15 to serve successive phase, mode, and source-address roles. No whole-function assembly or instruction assembly is used. The ordinary nonvolatile float globals correctly describe the original 32-bit floating loads and stores.

## Focused probe evidence

0014ec40 v1-v3 preserved outer phase control flow but retained comparison constants in registers 14/13, producing 76/84 bytes. v4-v7 constrained the opaque phase constant and recovered 84 bytes, the redundant first mode delay-slot constant, and the outer skip target, but retained mode constant in register 14 and a NOP in the second phase delay slot. v8 additionally constrained the mode constant in register 15 and separated the second phase check: all bytes match. This mechanism transferred directly to 00158fd8 v2 and 00159c58 v2, both exact.

Fresh sibling v1 sources and their failed proofs remain for comparison. A first WSL invocation required sandbox escalation. One shell-loop invocation lost the loop-variable transport and therefore produced no candidate proof; corrected file-based selection successfully ran all intended probes.

Root integration remains outstanding. Exact isolated sources are proposals, not registered acceptance claims.
