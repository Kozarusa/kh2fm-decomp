# Complete-range recovery remains unaccepted: 001a8450

The original range is 68 bytes, SHA-256 `11693e0325b3c564d7a601df56ef1b456a474080951f5df074f4d773afe96ff2`. None of the 18 compiled proposals matches its complete instructions. Compiler diagnostics and rejected sources remain preserved.

The closest equal-size proposal is `eight_hour_001a8450_flag_table_alias_v2_1.cpp` with 2 differing instruction words. Its hash is `f748292d45ac6656abee81270fe26ffe55b1a950ae465aa807d9f06c1713d8ad`; the separately saved proof is `eight_hour_001a8450_flag_table_alias_v2_1.verification.json`, SHA-256 `7da7c09a7ad1b234cc8765f6c835108f8ac101dd24db213ff4fab221043e73fd`. The full attempt list and range hashes are in `001a8450-fresh68-failed-census.json`.

Next hypothesis: The closest exact-size proposal differs only in the bit-index temporary register (11 versus 13). Fixing that register also changes the scaled table-offset register and load schedule. Inspect overlapping lifetimes around the low-five-bit count and scaled quotient before adding further bindings.

These failures do not establish compiler impossibility or runtime equivalence. No proposal for this range is registered. Original fallback bytes remain authoritative.
