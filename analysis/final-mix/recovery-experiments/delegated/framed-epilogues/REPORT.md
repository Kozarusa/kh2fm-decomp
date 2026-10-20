# Framed epilogue recovery: scoped blocker report

No exact proposal was found. No source was registered or synchronized. Only this delegated directory was written.

The original image identity was checked by each successful probe: SHA-256 d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87. Probes used unchanged flags through Public/tools/kh2-audit/probe_fm_source.py and kh2-local/ps2-compiler:3.2-ee-040921-objdiff. Every verification file binds the tested source hash and includes original instruction bytes. evidence.json additionally records source hashes, target-range hashes and differing instruction offsets.

## 0014dc48 and 0014dca8

Read fourwordfresh_v2 originals, all five epiloguefamily_v1 proofs, their source generator, and primary-fourhour-blockers.md. The original restores register 17 at offset 0x48, register 16 at 0x4c, register 18 at 0x50, and register 31 at 0x54. Existing equal-size output instead restores 16 then 17. Instructions before offset 0x48 agree exactly.

Hypothesis: replacing the blanket memory barrier and memory clobber with exact byte-store memory outputs might expose enough alias information to change restore scheduling without altering register allocation or frame size. A combined precise-memory store and three separate precise-memory stores were tested for 0014dc48. Both produce exactly the previous 96-byte output. The combined precise-memory proposal was also tested independently for 0014dca8, with the same result. Only offsets 0x48 and 0x4c differ.

This excludes the tested memory-constraint granularity change as a solution. It does not establish compiler impossibility. Repeating final empty register/lifetime markers is unsupported by the earlier five-marker evidence; their clobbers changed save widths/frame size or left the baseline untouched.

## 002e5f70

Read fiveword_v2 and all five epiloguefamily_v1 proofs. Original 68-byte code completes all five clearing stores, then restores register 31 at offset 0x34 and register 16 at 0x38. Baseline has the same body but restores 16 then 31.

Hypothesis 1: use exact memory outputs for the final four word stores and remove the blanket barriers. The 68-byte precise-memory proposal reproduces the baseline exactly, differing only at offsets 0x34 and 0x38.

Hypothesis 2: make all five stores volatile, including the first doubleword store, with no blanket memory barriers. This preserves 68 bytes and restores register 31 earlier, at offset 0x24, immediately after the doubleword store. Register 16 remains after the final word store. This establishes that store visibility affects return-address scheduling, but fails the required position after all stores.

The remaining issue is the placement of the return-address restore after the final word store and before the saved base register restore. The precise-memory spelling did not alter the compiler-generated epilogue order. The all-volatile spelling moved the restore too early. Earlier register-17 clobber output was 76 bytes and was not repeated.

## Artifacts

Five sa_frame_*.cpp sources, matching .probe.log and .verification.json files, prepare.py, probe.py, and evidence.json are preserved here. All five probes are nonmatching and unsuitable for acceptance. The initial unprivileged WSL attempt failed with E_ACCESSDENIED; successful probes used the authorized escalation path. Compiler use is now paused for root integration.
