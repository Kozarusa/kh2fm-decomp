# Complete-range recovery remains unaccepted: 001a6600

The original range is 68 bytes, SHA-256 `a18f4cd97c4877cb1cf2b1a015a4d1ddfdf996d3c74662121d031618baa84dc7`. None of the 14 compiled proposals matches its complete instructions. Compiler diagnostics and rejected sources remain preserved.

The closest equal-size proposal is `eight_hour_001a6600_float_control_shape_v3_0.cpp` with 6 differing instruction words. Its hash is `dc130d304ceb1896c86401dedf587e87ed5d9acf5e54b6232345666556738ffe`; the separately saved proof is `eight_hour_001a6600_float_control_shape_v3_0.verification.json`, SHA-256 `33935425d97b0d3abc3caeac8930f2bff7eb3e87b0398a39d93976c0686bab04`. The full attempt list and range hashes are in `001a6600-fresh68-failed-census.json`.

Next hypothesis: Preserve the native condition-code predicate and one shared epilogue. Return-type and branch-hint changes did not place the constant-one assignment in the original floating branch delay slot; volatile path markers introduced extra epilogue loads.

These failures do not establish compiler impossibility or runtime equivalence. No proposal for this range is registered. Original fallback bytes remain authoritative.
