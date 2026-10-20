# Isolated recovery investigation: 00105af8

The complete original selects an indexed word after storing the mode, then reloads the selected global on the ordinary path. Raw low-word transport avoids unnecessary 64-bit narrowing, but index register allocation and branch layout remain different. Investigate original global-region aliasing and table types before adding more register barriers.

This session preserved 20 completed compiler proofs. The adjacent `00105af8-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
