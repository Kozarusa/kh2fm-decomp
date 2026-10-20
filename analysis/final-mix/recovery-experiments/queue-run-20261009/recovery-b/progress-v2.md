# Recovery B progress, second checkpoint window

The primary reports cumulative acceptance of the first two recovery-b submissions, 0014db78 (80 bytes) and 0014dbc8 (60 bytes), in queuealpha. Their integration contributes 140 instruction bytes; queuealpha as a whole accepts six ranges and 412 bytes.

Four additional recovery-b proposals were independently curated, re-probed and submitted: 001668f8 (52 bytes), 00166930 (52 bytes), 0016a158 (96 bytes), and 00172928 (92 bytes). These are review candidates pending cumulative primary acceptance. Total worker exact submitted instruction coverage is six ranges and 432 bytes, of which two ranges and 140 bytes are currently known integrated.

The two short constructors reproduce their stores with typed volatile C++ assignments, an early constrained constant, and a barrier before the final halfword store. The 0016a158 helper obtains exact argument setup solely from explicit 32-bit parameter declarations, replacing variadic guesses. The 00172928 packet helper uses constrained floating-point transport and a symbolic packet-pointer move with memory dependencies; the complete compiler-generated prologue and epilogue remain intact. Failed intermediate proofs remain preserved.

Claims are drained and compiler idle for the primary's second cumulative acceptance window. Eight source variants are prepared for the next two targets, 001abf00 and 001c2c98. They have not been probed. The previous leases were released and the next worker must claim atomically and rename variants to its fresh lease token before any probe.
