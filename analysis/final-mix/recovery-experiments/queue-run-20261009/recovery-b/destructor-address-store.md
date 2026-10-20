# 00315678 / 00315700: vtable address and prologue scheduling

Each original range is 56 bytes. The archived volatile C++ store differs only in register31-save versus vtable-store order. These share the same pattern as the previously routed 0028b7f8, but have positive-low table addresses 00367860 and 00367848.

Sixteen new isolated proofs remain nonmatching and exactly 56 bytes. Explicit two-instruction address blocks, compiler-native high constants with input/read/write markers and low addiu assembly, native low addition, volatile precise-memory stores, an incoming register4 pointer pin, an extra pointer input, and a post-store pointer lifetime marker all alter initial scheduling without matching. Complete original/source/proof hashes and differing offsets are bound in destructor-address-store-evidence.json. Prior broad memory/link-register markers were read and not repeated.

Next hypothesis: reuse the documented tablestoreprecise result from 0028b7f8 as a control, and investigate a translation of the native address expression that retains the low addiu ahead of both saved-register stores while keeping the early store out of the first call delay slot. Separate prologue scheduling from table-address allocation. Do not repeat the explicit address-block or volatile precise-memory controls listed here. No compiler impossibility is established.
