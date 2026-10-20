# Isolated recovery investigation: 00305ce0

Exact-size C++ and precisely described store variants all leave original ra restoration after the store rather than before it. An empty read of the return-address register did not fix scheduling. Review the original compiler ABI or return/store dependency before repeating store qualifiers.

This session preserved 8 completed compiler proofs. The adjacent `00305ce0-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
