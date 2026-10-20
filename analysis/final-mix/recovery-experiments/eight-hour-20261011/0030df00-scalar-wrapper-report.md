# Scalar wrapper investigation: 0030df00

The native SDK wrapper stores -1 at 00366180, calls 002fde18 with 01e38e68, zero, and four, then returns zero. Typed bindings reproduce the initial high-address and -1 constants in v0 and v1 and all call/return instructions. The best four-word residual places the callback high-address calculation too late around the return-address save and global store. A dependency on the callback value or an emitted address primitive hoists operations before the stack adjustment and does not resolve the range. Next investigate joint callback/prologue scheduling rather than repeat fixed constants, broad barriers, or value dependencies.

`0030df00-scalar-wrapper-evidence.json` binds 11 complete source/proof pairs. Types and high-level identities remain provisional; no compiler-impossibility claim is made.
