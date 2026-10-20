# Next investigations for unaccepted medium ranges

These notes interpret preserved evidence and suggest focused controls. They do not change the eight hash-bound blocker reports, queue state, source registries, or acceptance counts. New probing requires a fresh lease from the `medium-register-and-branch` queue and the usual independent acceptance process.

## 0010cce0: Traversal return and loop layout

The saved equal-size-preferred candidate compiled to 76 bytes against 80 native bytes, with 13 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The native null path moves the saved current-node register into the return register even though the preceding helper already returned through that register. The return predicate and loop back edge also occupy specific blocks. Pointer, unsigned 64-bit, and signed 64-bit variants remain shorter or arrange those blocks differently.

Next control: Keep the helper-result null test separate from the preserved current-node return value. Compare the final null and predicate cleanup paths before introducing another register constraint. Preserve the original early termination and back-edge semantics.

Evidence: `0010cce0-fresh76-84-original.txt`, `0010cce0-medium-failed-census.json`, `0010cce0-medium-blocker.md`, and the candidate proof files named in that census.

## 00160488: Three-channel multiplication and frame scheduling

The saved equal-size-preferred candidate compiled to 72 bytes against 76 native bytes, with 17 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The original masks incoming channel arguments to eight bits, uses both multiply banks, and allocates a 16-byte frame partway through the calculation even though there is no obvious ordinary stack payload. Byte-typed parameters remove native masks and the frame; a forced local frame does not restore the multiply scheduling.

Next control: First establish the incoming Word-width model from the three ANDI instructions. Then investigate the three product lifetimes and multiply-bank allocation. Do not count a frame-only byte match as recovery of the complete routine.

Evidence: `00160488-fresh76-84-original.txt`, `00160488-medium-failed-census.json`, `00160488-medium-blocker.md`, and the candidate proof files named in that census.

## 00161548: Nullable indexed lookup cleanup

The saved equal-size-preferred candidate compiled to 68 bytes against 76 native bytes, with 14 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The native code independently handles a negative index, a null object field, and a null helper result. It materializes zero on several paths and loads the result field in a delay slot. Straight nested C++ produces fewer instructions and different cleanup blocks.

Next control: Model the three tests and their result lifetimes independently. Check signed index transport and the helper-result pointer width before changing branch order. Retain a null-safe load of the result field.

Evidence: `00161548-fresh76-84-original.txt`, `00161548-medium-failed-census.json`, `00161548-medium-blocker.md`, and the candidate proof files named in that census.

## 0016ffc8: Fallback value with three bounded ranges

The saved equal-size-preferred candidate compiled to 84 bytes against 80 native bytes, with 13 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The original preserves its first result on the early branch and conditionally selects an alternative value from three unsigned bounded ranges. Positive versus negated source conditions choose different return blocks and speculative delay-slot assignments.

Next control: Keep unsigned range comparisons explicit and distinguish the preserved original result from the candidate. Inspect the final branch-likely result restoration and common return block; do not simplify the conditions into a form with different wraparound behavior.

Evidence: `0016ffc8-fresh76-84-original.txt`, `0016ffc8-medium-failed-census.json`, `0016ffc8-medium-blocker.md`, and the candidate proof files named in that census.

## 00170ee8: Repeated static initializer guards

The saved equal-size-preferred candidate compiled to 68 bytes against 76 native bytes, with 19 differing instruction words. The census was captured before final analysis and is preserved unchanged.

Two Word pairs are initialized under mode and priority guards. The original retains a repeated priority test and specific address materialization and store order. Straight source optimization collapses guards; argument opacity preserves more checks but still changes layout.

Next control: Investigate the data dependencies that keep the second guard alive. Compare address materialization separately from branch layout and zero-store order. Avoid assigning a class constructor identity without independent evidence.

Evidence: `00170ee8-fresh76-84-original.txt`, `00170ee8-medium-failed-census.json`, `00170ee8-medium-blocker.md`, and the candidate proof files named in that census.

## 0018dbd8: Byte boolean materialization and shared return

The saved equal-size-preferred candidate compiled to 80 bytes against 80 native bytes, with 11 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The native code materializes a byte-sized temporary, masks it into a separate register, and uses a branch-likely return assignment. The best later 80-byte candidate still substitutes conditional moves and merges the shared return logic. An equal length does not imply equal instructions.

Next control: Preserve the temporary and result as separate lifetimes. Examine why the pinned compiler selects conditional moves instead of the native branch-likely path. The failed Word comparisons identify the exact point where the layouts diverge.

Evidence: `0018dbd8-fresh76-84-original.txt`, `0018dbd8-medium-failed-census.json`, `0018dbd8-medium-blocker.md`, and the candidate proof files named in that census.

## 0018f0b0: Float and Word initializer with repeated guards

The saved equal-size-preferred candidate compiled to 72 bytes against 80 native bytes, with 20 differing instruction words. The census was captured before final analysis and is preserved unchanged.

This initializer has related mode and priority guards, but also loads a floating global and writes a float field before zeroing a Word pair. The existing global-pointer constraint preserves address materialization, yet repeated guards and stores remain different.

Next control: Treat the float load, Word zero stores, and repeated guard as separate scheduling constraints. Inspect the retained native float register and guard block order. Do not merge this routine with the Word-only initializer merely because their prefixes look similar.

Evidence: `0018f0b0-fresh76-84-original.txt`, `0018f0b0-medium-failed-census.json`, `0018f0b0-medium-blocker.md`, and the candidate proof files named in that census.

## 00192818: Six-Word snapshot and outgoing pointer transport

The saved equal-size-preferred candidate compiled to 80 bytes against 80 native bytes, with 8 differing instruction words. The census was captured before final analysis and is preserved unchanged.

The original loads six fields in a specific order, preserves the source in one register while reusing the incoming source argument register for the outgoing stack pointer, and stores the last field in the helper call delay slot. Ordinary arrays compile to the right size with different field order and register lifetimes.

Next control: Track the original source pointer and outgoing snapshot pointer as distinct values. Vary source loads and snapshot stores independently, retaining their alias relationship. The first two arguments and all six Word values must reach the helper unchanged.

Evidence: `00192818-fresh76-84-original.txt`, `00192818-medium-failed-census.json`, `00192818-medium-blocker.md`, and the candidate proof files named in that census.

All saved successful medium probes were subsequently audited in `medium-probe-preservation-audit.json`. Two malformed experimental declaration families produced compiler errors; corrected variants were probed under new filenames, and the original diagnostics remain preserved. Those generation errors are not treated as evidence against the compiler or recovery feasibility.
