# Complete-range recovery remains unaccepted: 0014f068

The original range is 68 bytes, SHA-256 `3da291f6c65ae04da00bbf2372bce46e4af9b06afcd87237f456f899f4a270bf`. None of the 17 compiled proposals matches its complete instructions. Compiler diagnostics and rejected sources remain preserved.

The closest equal-size proposal is `eight_hour_0014f068_float_branch_prediction_v5_2.cpp` with 5 differing instruction words. Its hash is `5a2a33dc5db47577d415d93591c3c9f324433775ba69bc49e25f447da07f8141`; the separately saved proof is `eight_hour_0014f068_float_branch_prediction_v5_2.verification.json`, SHA-256 `2cb98dd5aa3f9d60c36448fc4f2ff3fe2c21322930120e413a73ca228245f4df`. The full attempt list and range hashes are in `0014f068-fresh68-failed-census.json`.

Next hypothesis: Retain the original fall-through store and shared failure return without materializing the floating predicate. The closest exact-size variants reverse the final floating branch and swap the success/failure blocks. Do not replace the negation of <= with an ordered > or < comparison.

These failures do not establish compiler impossibility or runtime equivalence. No proposal for this range is registered. Original fallback bytes remain authoritative.
