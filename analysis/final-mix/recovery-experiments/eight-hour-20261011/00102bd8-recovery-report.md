# Isolated recovery investigation: 00102bd8

A live second-callback high-word carrier moves the missing LUI before the first store, but then the stack adjustment and final global LUI each swap with a store. Typed table and narrow memory dependencies did not recover the complete range. Seek a joint scheduling representation preserving high-word lifetime and prologue delay without repeating broad memory barriers.

This session preserved 40 completed compiler proofs. The adjacent `00102bd8-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
