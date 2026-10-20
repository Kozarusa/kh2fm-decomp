# Isolated recovery investigation: 002713a0

Condition width, fixed pointer register and forward/reversed/ternary/label forms preserve the one-word bnel-versus-bne residual or worsen layout. Investigate a new branch-delay dependency representation that permits speculative high-word materialization; tested pointer-register and condition-width alternatives are exhausted.

This session preserved 32 completed compiler proofs. The adjacent `002713a0-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
