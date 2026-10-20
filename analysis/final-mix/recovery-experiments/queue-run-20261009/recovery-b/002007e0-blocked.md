# 002007e0: nested-load and prologue scheduling blocker

Original live range is 76 bytes. Archived worker v02 incorrectly treats the second load offset as +1 byte rather than the original +4; it also uses saved register16 for the nested pointer loads. Four new complete probes corrected +4 and varied explicit signed/unsigned input types plus fixed register15 pointer and register14 offset markers. None match. Sources/proofs and original-byte hashes are bound in 002007e0-blocked-evidence.json.

Next hypothesis: combine the original void two-integer helper call declaration and end-only volatile empty marker with a nested-pointer expression whose temporary loads remain in registers15/14. Inspect prologue and load-chain differences separately. Do not reuse the erroneous +1-byte load. The corrected expression is related to 002006b0's isolated save-order residual; that specialist's ABI/load controls are available under the same recovery-b directory.
