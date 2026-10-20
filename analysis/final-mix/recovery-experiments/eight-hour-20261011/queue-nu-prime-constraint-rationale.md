# Source rationale for the fresh 68/72-byte recovery batch

All eighteen selected sources were independently curated, compiled, and accepted through `queunuprime`. Original names and higher-level types remain provisional. Full instruction equality is the acceptance condition; it does not establish portable C++ behavior or complete original signatures.

The `001142e0` and `00114328` exports incorrectly suggested word returns. Their native loads return floats in F0. Positive outer condition blocks preserve the original branch layout and byte argument masks with ordinary C++.

The `00133938` and `001339d0` header writers need their word, halfword, and byte accesses to share a union alias type. Separate pointer casts let the compiler remove required cursor reloads. The selected `001339d0` proposal uses word-sized input and return types; its exact register transport does not prove the exported 64-bit signature.

`001585a0` uses an explicit word-valued predicate, a 64-bit bit mask, and a word helper result. This retains the native conditional moves without the extra boolean XOR operations seen in rejected proposals.

The `00136ab8` zeroing routine uses volatile views for the original store order. One page-address LUI transport preserves the otherwise swapped load/store pair. Empty register dependencies retain the native pointer lifetimes; the final return-address clobber declaration places restoration after the stores. This unit contains one emitted assembly instruction, not a pasted function body.

`0013fec0` preserves the caller's pointer in its existing saved register and then advances that same variable. Its `mode(TI)` type describes a 16-byte copy, with register 8 constrained for the copied value. Empty pointer constraints retain the original self-assignment check. The actual load, store, branch, calls, and frame instructions come from the compiler.

The four `0016df28`, `0016df70`, `0016e000`, and `0016e048` wrappers load their coefficient into F1 before loading the input into F0. Each has one CVT.W.S primitive and a union representation transfer to the word passed to the final helper. This preserves the observed native conversion instruction rather than assuming an ordinary C++ cast is interchangeable.

The `00171268` and `001712b0` guards forward three separate floating-point registers plus a word pointer. Their opaque global pointers preserve the required address setup before the tail call. `00172ae0` uses a word-returning virtual callback with two word arguments and a normalized boolean argument.

`00188fe0` needs a positive result block to retain the native failure and epilogue layout. `00194830` likewise needs a positive callback-result block. Its selected source explicitly uses the SLLV primitive so every shift count follows the native instruction's wrapping behavior. An earlier matching unmasked C++ shift proposal was superseded before curation; its source, proof, and supersession receipt remain preserved.

The remaining four attempted routines were not registered. Their exact-size mismatches, source/proof hashes, and next hypotheses are recorded in the four `fresh68-blocker.md` reports.
