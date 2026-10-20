# Typed object-forwarding family

57 complete original 52-byte ranges share the same stack/register behavior. Each stores a distinct table address into the object, calls a first helper with that object in a0, then forwards the same object to a final helper after restoring saved registers. The saved Ghidra export omits the object argument from many first-helper calls.

Two representative sources established the typed C++ template before the remaining 55 candidates were generated. All 57 isolated full-range probes match every original instruction, including frame setup, call delay slots, table addresses, helper targets, and the final tail jump. This report precedes independent curated recompilation and full cumulative acceptance; isolated proofs alone are not accepted recovery credit.

Class names, exact C++ class layouts, and higher-level helper identities remain provisional. The sources deliberately retain address-based symbols. No compiler flags changed. No whole-function assembly was introduced.
