# Evidence-backed findings from the eight-hour recovery run

This is a working investigation record. Only published checkpoints count as accepted progress. Source types and higher-level identities remain provisional. The original executable and pinned compiler remain unchanged.

## Exported types and return values need independent checking

The native `00304db0` range is 56 bytes. The initial integer-bit formula came close but used different registers. Fixed-register and lifetime markers made the match worse. A `double` argument unpacked through a union reproduced the entire range with ordinary C++, under the pinned compiler. The corresponding `v4_native_word_extraction_4` and `_5` proofs both match; the unsigned-word version avoids introducing signed-overflow arithmetic. Its bit formula is consistent with a double NaN predicate, but the anonymous symbol is retained.

The exported void signatures for `00123d90` and `00124100` do not adequately describe their native value flow. Returning the indirect callback result reproduces `00123d90`; a void callback and wrapper reproduce `00124100`. Both native bodies leave the callback return register available. These are exact compiler recoveries, not independently established class or method names.

Floating-point forwarding also needs the complete integer argument set. The matching `002cba50` proposal carries its two float operands separately from four word-register operands. Treating its first two values as integer payloads would omit the native floating loads.

## Preserve the right value across a call

`0017c8f0` and `001b6f48` each load two float constants, invoke `0017c870`, and return the original output pointer. Their helper also receives the two incoming payload registers omitted by the export.

Binding a local pointer directly to s0 introduced another saved register and a larger frame. Changing which pointer was returned did not remove that expansion. A separate preserved return pointer and a mutable callee-argument copy resolved the two-word residual without emitted assembly operations. The empty register dependency forces the original pointer to be preserved before the first float load. The selected `v4_callee_copy_and_preserved_return` proposals reproduce all 64 bytes.

## Independent store groups can determine the generated schedule

The original `00132270` initializer contains six independent zero stores. The first ordinary proposal moved its last zero store to the first available slot. Rotating the corresponding source-store order produced the complete original 60-byte schedule. No emitted assembly was required. The packed 108-byte constructors and earlier 68-byte initializer also benefited from source-store ordering, but other recorded constructors did not. Do not assume one permutation applies to every function.

For `002d96d8` and `002d9730`, source-store ordering reduced the residual to an adjacent word/byte-store swap. A single constrained word-store primitive resolved it. Replacing that primitive with a C++ store and an empty dependency left four differing words. These accepted C++ translation units contain one emitted assembly instruction each; they are not wholly plain C++ recoveries.

## An isolated address proof does not guarantee full-link relocation

The first full build of `queueepsilonprime` differed from the target by three bytes, all in the call at `001394e4`. The original call targets `00139768`; the full link instead resolved `func_00139768` to temporary linked text at `00426764`.

The legacy `obj2d_isExist.s` defines that C symbol. A linker `PROVIDE` alias does not override an existing definition. Isolated probes had assigned the address directly and therefore did not reproduce this collision.

A distinct typed helper declaration using the absolute-address symbol `D_00139768` preserves the original call and avoids the collision. Its new proposal and separately curated source both matched independently. The rejected registered source, prior batch receipts, failed full ELF, and a hash-bound repair receipt remain preserved. The subsequent full executable and all 121 cumulative recovery bundles passed before publication.

The original failed ELF SHA-256 is `b9dadc349c39b6244860308b372f399a6cdba559133dc4c496569d1c1716e054`. See `queueepsilonprime-link-failure.json` and `queueepsilonprime-link-repair.json` for the exact comparison and repair closure. No broad linker-policy change was made.

## Remaining failures are specific hypotheses

The reports saved during this run bind failed sources to their complete original-range comparisons. They identify the closest residual and the next hypothesis. A two-word mismatch is still a failed range. Narrower argument types, broad barriers, or hard register bindings are not general remedies. Do not register a close proposal or claim the compiler cannot reproduce a range merely because the recorded variants failed.

Full executable equality continues to retain original fallback code and data. It is not a source-only rebuild of the whole game, and none of these compiler proofs establishes all overlay, vector-unit, script, or runtime behavior.

## Exact instructions still require exact linked entry addresses

The first `queuekappaprime` full build differed in the previously accepted caller `002b9ab8`: its jump targeted `002b6b88` instead of `002b6b84`. The new callee's 64 instruction bytes were individually exact, but its compiler-generated input section required eight-byte alignment. The legacy linker added four bytes at the original word-aligned entry point. This also shows why reading compiled bytes from the actual symbol does not prove that the symbol resides at the requested native address.

An isolated diagnostic full link changed only the callee section's ELF `sh_addralign` metadata from eight to four. Both its native entry address and the existing caller's complete instructions then matched. The pinned compiler rejects function alignment attributes; the pinned legacy linker rejects the tested `SUBALIGN` forms. Their diagnostics remain preserved.

The build helper now lowers alignment metadata only for the matching executable function section when its original address is congruent to four modulo eight. It validates ELF32 format, section properties, unambiguous selection, and a zero section-relative function offset. Instruction, symbol, and relocation bytes remain intact; compiler flags remain unchanged. The original helper, failed full ELF, object hashes, one-field diagnostic change, and repair receipt remain preserved. Full cumulative acceptance is required before treating this batch as accepted.


The queuekappaprime native alignment repair is now fully accepted, including the 126-bundle cumulative matrix. The scoped C++ linked-address guard is fully accepted through queuelambdaprime (127 bundles) and subsequent checkpoints. Detailed rationale is preserved in sdk-wrapper-rationale.md and medium-vector-and-scalar-rationale.md.
