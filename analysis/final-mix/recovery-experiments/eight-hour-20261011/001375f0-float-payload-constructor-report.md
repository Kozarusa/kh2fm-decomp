# Float payload constructor investigation: 001375f0

The native 64-byte constructor forwards a float from 0036ac9c in f12 and the object, identifier 79, and two payloads in a0-a3, then clears object offset 1304. The full ABI and float type reproduce every instruction except the ordering of the global address low-add and return-address save. Input dependencies, narrower helper word types, and a word-carried object do not solve that residual; the latter adds unwanted width conversions. A direct address primitive also perturbs earlier instructions. Next investigate joint global-address/prologue scheduling with the correctly typed pointer and full argument set. Do not repeat the recorded width-only or address-input dependency tests.

`001375f0-float-payload-constructor-evidence.json` binds 14 complete proposals. No unsuccessful source is registered and no compiler-impossibility claim is made.
