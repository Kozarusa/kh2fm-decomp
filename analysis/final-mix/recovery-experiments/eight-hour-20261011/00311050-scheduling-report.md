# Unresolved function 00311050

The closest ordinary C++ proposal has all 48 bytes and differs only by swapping the operation literal load into a0 and the sd ra,16(sp). Array versus struct aggregates, signed/unsigned operation prototypes, empty register markers, and precise literal transport did not produce a complete match. Keep the original function on fallback; no compiler impossibility is established.

## Evidence

12 complete compiler probes are preserved in the adjacent evidence manifest. Every proposal retains its source hash and complete original/compiled range. None has been registered.

## Next hypothesis

Retain the validated 32-byte payload frame and signed-byte normalization. Investigate operation-register initialization scheduling relative to the return-address save; payload shape and argument width alone did not solve the two-word swap.
