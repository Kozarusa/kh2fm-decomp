# Isolated recovery investigation: 00319788

Original two-call routine uses daddiu with a 48-byte frame and saves ra at offset 40; the existing exact-size proposal uses addiu with a 16-byte frame and saves ra at offset zero. Calls and return flow already agree. Investigate SDK calling-frame ABI and structured assembly classification; do not assume changing C++ return types alone repairs the frame.

This session preserved 0 completed compiler proofs. The adjacent `00319788-recovery-results.json` binds source and proof hashes, size comparisons, and instruction differences. Compiler-failure diagnostics remain in the corresponding probe logs. No new accepted recovery or compiler-impossibility claim is made.
