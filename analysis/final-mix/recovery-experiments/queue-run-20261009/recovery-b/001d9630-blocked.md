# 001d9630: branch-entry lifetime blocker

Original live range is 88 bytes. Archived output differs only in entry scheduling: saved counter copy occurs before the positive-count check rather than after its pointer-copy delay slot. Four new 88-byte probes scoped the counter after an explicit early return, then varied fixed register-16, nonvolatile read/write marker, volatile marker and memory-clobbered marker. None match. Sources/proofs and original-byte hashes are bound in 001d9630-blocked-evidence.json.

Next hypothesis: retain the compiler-native counter copy while tying it to a post-branch pointer-state dependency, rather than scoping the variable or adding a blanket memory barrier. The branch must still test the original incoming register5, with pointer move in the delay slot. Read complete diffs before experiments; no compiler impossibility is established.
