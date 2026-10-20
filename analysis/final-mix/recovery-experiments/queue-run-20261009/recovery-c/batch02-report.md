# Recovery C batch 2

Three complete functions are submitted; primary independently owns integration and acceptance.

0014dca8 (96 bytes) was stolen from framed-epilogues using new evidence from the accepted identical sibling 0014dc48. Canonical typed stores and empty memory barriers reproduce the original stores and saved-register epilogue without the 128-bit ABI saves induced by explicit saved-register clobbers. Its prior failure report was inspected before the single successful new probe.

00143348 (76 bytes) was stolen from framed-epilogues after inspecting all six prior failure sources/proofs. New experiments varied volatile stores, stack-result constraints, explicit halfword reads and fixed registers. Variant 13 reads the low stack halfword explicitly through u16*, then writes the two object halfwords with volatile typed stores. This places the original lhu and return-address restore before both stores exactly. Other nineteen controls remain saved; no proof is manufactured by editing bytes.

0019da20 (72 bytes) retains the original initializer and helper calls. Capturing the -1 constant in a normal local with an empty read/write constraint before the first trailing store, then separating stores by empty memory barriers, reproduces the original constant-load and store ordering. Three earlier controls remain preserved.

Live layout and complete original-byte proofs were inspected for all three. batch02-evidence.json binds each source and proof. No shared source, registry, layout, stage or checkpoint was changed by this worker. Types remain provisional; explicit halfword stack access corresponds to the little-endian original instruction.
