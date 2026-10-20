# Scalar wrapper investigation: 002eff58

The scalar predicate adds floats at object offsets 272 and 276, multiplies by the global at 00376224, and compares with offset 28. An opaque address reproduces the full 56-byte range length. The best register proposal differs only in the order of the global float load and addition, and the multiply/comparison destination register. Later lifetime markers, arithmetic primitives, and expression evaluation variants perturb more words. Next investigate a native floating expression representation that keeps the factor live in f0 and the accumulated result in f1 without moving the first object load. No unsuccessful source is registered.

`002eff58-scalar-wrapper-evidence.json` binds 16 complete source/proof pairs. Types and high-level identities remain provisional; no compiler-impossibility claim is made.
