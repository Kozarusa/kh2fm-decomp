# 00287f30 blocked
- Range: 00287f30, 92 bytes. Versions tried: 0. Best: none.
- Original exit audit: jr ra at 00287f84 receives untouched entry-v0 when global is zero and outgoing 00106420 callee result otherwise. No instruction defines a common return value. Literal R4.3 disallows a void exception and invented zero.
- Why it stops here: R12 conservative ABI block before drafting.
- Next hypothesis: ABI review of conditional callee-result and untouched entry-v0 transport.
- First difference of best version: not applicable; no draft due ABI conflict.
- Changes tried: none; pre-draft exit audit only.
