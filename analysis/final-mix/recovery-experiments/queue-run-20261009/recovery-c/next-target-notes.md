# Read-only backlog analysis while integration drains

No target ownership is claimed by this document. The central queue determines later ownership.

0016a158: The best full 96-byte proposal differs in three register-argument setup words preceding the second call. The target initializes $4 from the returned value before $6 from the stack pointer and $8 from zero. Empty read/write constraints around explicit argument locals may preserve this initialization order.

00172928: The full 92-byte proposal differs only in placement of the two float loads: target f13 is loaded before the call and f12 in its delay slot; proposal has the reverse. Force second-argument floating input before constructing the call while leaving first-argument load schedulable.

00195c58: The full 40-byte proposal saves RA before the initial object flag load; the target loads the flag first. Test preloading the flag followed by an empty dependency barrier, then evaluate the original conditional call.

0019da20: The full 72-byte proposal swaps the zero stores at offsets 0x50 and 0x3c. Canonical stores with empty compiler barriers at each store should preserve the original order; this method independently recovered both 0014dc08 and 0014dc48.

001abf00: The full 52-byte proposal swaps loading constant 1 into $15 and zeroing the $2 result register. Test initializing the fixed constant first, constraining it with an empty input/output barrier, then assigning result zero.
