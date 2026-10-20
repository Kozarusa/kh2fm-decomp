# Object recovery investigation: 001c2c98

The closest original proposal swaps only the final vtable and mode stores. Making either store individually volatile keeps that residual; making both volatile or inserting a full memory barrier alters the preceding flag-load and register schedule. The next experiment should describe canonical object-field aliasing or carry independent flag dependencies into the final stores while preserving the already correct early return-address restore. Do not repeat the four recorded volatile/barrier cases.

`001c2c98-object-evidence.json` binds 4 complete new source/proof pairs. No unsuccessful proposal is registered and no compiler-impossibility claim is made.
