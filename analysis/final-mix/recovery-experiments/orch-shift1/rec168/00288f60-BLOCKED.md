# 00288f60 blocked
- Range: 00288f60, 120 bytes. Versions tried: 0. Best: not applicable (no source/probe).
- First difference of the best version: not applicable (zero versions).
- Changes tried: not applicable (zero versions).
- Why it stops here: literal R4.3 forbids void because v0 is untouched on the sole jr ra exit; returning entry v0 needs an unspecified-entry-v0 exception.
- Next hypothesis: ABI review of untouched entry-v0 contract; do not fabricate zero.
