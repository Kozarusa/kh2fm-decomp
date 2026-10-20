# Unresolved function 00311460

The original checks unsigned value-13 < 35, branches to the valid helper call, and places the return-address save in that conditional branch delay slot. The invalid path branches to the common epilogue with -1 in its delay slot. Simple C++ collapses this into a shorter conditional tail call or a different shared epilogue. Preventing the tail call and marking the invalid result preserved behavior but did not match the original layout. Signed 32-bit versus 64-bit result variants did not resolve it. Keep the original on fallback; no compiler impossibility is established.

## Evidence

9 complete compiler probes are preserved in the adjacent evidence manifest. Every proposal retains its source hash and complete original/compiled range. None has been registered.

## Next hypothesis

Model the invalid-result path as a distinct branch while retaining the predicate in v0 and the single common epilogue. Avoid repeating basic signed-width changes, likelihood hints, and empty result markers already tested.
