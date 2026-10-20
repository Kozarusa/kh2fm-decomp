# 001d9630 evidence correction

The four scoped-counter variants correct the original entry scheduling issue. Their complete 88-byte bodies now match the original from offset 0x0c onward. Only the two saved-register prologue stores at offsets 0x04 and 0x08 differ. This is new narrowing evidence: explicit early return and post-condition counter scope solve the original three-word entry mismatch, leaving a prologue save-order issue. The earlier blocked report describes the archived issue but its next hypothesis should be superseded by this addendum.

Next hypothesis: preserve the successful scoped-counter body and alter only compiler-generated saved-register store order. Use the prologue-save-order specialist controls and accepted analogues. The complete proofs and bound evidence remain unchanged.
