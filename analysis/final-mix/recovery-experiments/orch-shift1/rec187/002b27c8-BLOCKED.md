# 002b27c8 blocked
Range: 002b27c8, 120 bytes. Versions tried: 2. Best: v2 with 9 differing words (124/120 bytes).
First difference of the best version: !! 002b27e8: 14400011 bnez v0,0x2b2830 | 002b27e8: 14400012 bnez v0,2b2834.
Changes tried: C1 audited both returns and all arguments. C11b removed the separate loaded temporary, improving 25 words to 9.
Why it stops here: Conservative R12 ABI block. The early exit transports the full s64 flushing result; the late exit transports the untouched u32 text callee result. The s64 source requires an extra move v0,v0 after the latter call. Truncating the early result or discarding either result would violate literal R4.3.
Next hypothesis: Determine a permitted source contract that preserves both outgoing callee result transports without normalization.
