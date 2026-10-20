# Complete-range recovery remains unaccepted: 0016ac38

The original range is 72 bytes, SHA-256 `a4f9992b84a613f1de37852ea1e80fed941ce2d9769a91bb99a4c324d87aeb78`. None of the 13 compiled proposals matches its complete instructions. Compiler diagnostics and rejected sources remain preserved.

The closest equal-size proposal is `eight_hour_0016ac38_argument_lifetime_v2_3.cpp` with 4 differing instruction words. Its hash is `1c2c7de5c1a73062ca9a250b291dc545b5acfab379be71d6f9079fa0d202d8df`; the separately saved proof is `eight_hour_0016ac38_argument_lifetime_v2_3.verification.json`, SHA-256 `188dddd1804f297664500defaaef99597e42635be39b0eb695a8dcb889a3e506`. The full attempt list and range hashes are in `0016ac38-fresh68-failed-census.json`.

Next hypothesis: The closest exact-size proposal has two adjacent move-order swaps. Adding explicit argument transports changed prologue and field-load scheduling. Revisit the lifetimes of the fifth incoming argument, saved fourth argument, and first outgoing pointer together; do not bind the whole wrapper blindly.

These failures do not establish compiler impossibility or runtime equivalence. No proposal for this range is registered. Original fallback bytes remain authoritative.
