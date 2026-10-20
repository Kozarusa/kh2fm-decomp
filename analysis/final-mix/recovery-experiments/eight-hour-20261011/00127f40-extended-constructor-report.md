# Extended constructor investigation: 00127f40

The native 120-byte constructor forwards its resource argument, reloads the header end after storing the buffer origin, and uses separate count stride and successive buffer pointers. The complete observed ABI is retained in the new proposals. Fixed-register stride and pointer lifetimes prevent one strength reduction, but neither tested profile reproduces the complete range. Next investigate the header alias after the origin store and the joint lifetime of start/end/count registers. Do not repeat the already tested opaque stride and end reload alone.

`00127f40-extended-constructor-evidence.json` binds 3 complete source/proof pairs. Types and higher-level identities remain provisional. No compiler-impossibility claim is made.
