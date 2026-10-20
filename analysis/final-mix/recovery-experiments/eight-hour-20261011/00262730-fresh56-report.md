# Fresh wrapper investigation: 00262730

The original 56-byte wrapper calls a global object getter, a membership helper, then a tail dispatch with its constant identifier. The getter returns a native word, not a 64-bit arithmetic value. A typed empty pre-call definition of the saved register reproduces every instruction except the order of the two prologue saves (return address and s0). An untyped register clobber instead triggers 128-bit spills and a larger frame; fixed-register markers after the call do not resolve the residual. Next investigate typed prologue save ordering with a genuine live input or ABI-supported frame representation. Do not repeat untyped clobbers or widen the arithmetic just to force a spill.

`00262730-fresh56-evidence.json` binds 10 complete proposals and original-range comparisons. No unsuccessful source is registered. No compiler-impossibility claim is made.
