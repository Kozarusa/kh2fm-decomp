# Isolated recovery investigation: 00308cd0

The C++ global store matches every original word except the load-ra/store order. Volatile and precise-assembly descriptions did not fix this; address-form assembly introduced extra instructions. Review the scheduler treatment of epilogue loads with a statically known global store.

This session preserved 8 completed compiler proofs. The adjacent `00308cd0-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
