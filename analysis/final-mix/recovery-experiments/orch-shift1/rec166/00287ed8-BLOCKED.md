# 00287ed8 blocked
- Range: 00287ed8, 84 bytes. Versions tried: 0. Best: none.
- Original exit audit: the only exit is a tail jump to 00288018. Its packet-listed accepted source declares void and only stores zeros. The allocation path leaves 00167658 result in v0; the existing-global path leaves entry v0 unspecified. Literal R4.3 forbids discarding outgoing callee results or inventing zero on the untouched path. No supported complete signature represents both paths without an exception.
- Why it stops here: R12 conservative ABI block before drafting.
- Next hypothesis: ABI review of tail-callee return transport and untouched entry-v0 path.
- First difference of best version: not applicable; no draft due ABI conflict.
- Changes tried: none; pre-draft exit audit only.
