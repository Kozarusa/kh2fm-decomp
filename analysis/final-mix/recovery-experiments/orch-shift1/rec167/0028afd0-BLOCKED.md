# 0028afd0 blocked
- Range: 0028afd0, 104 bytes. Versions tried: 0. Best: not applicable, zero-version ABI blocker; differing words and compiled bytes not applicable (target 104 bytes).
- First difference of the best version: not applicable, no version drafted or probed.
- Changes tried: none; audited original return paths under R4.3.
- Why it stops here: R12 conservative ABI block. The 37(a0) nonzero path reaches 0028b030 with untouched entry v0; the zero path returns func_0028b1c0 result on zero, or tail-calls func_00289b30 on nonzero. Mixed entry-v0/callee-result exits cannot be represented without an unsupported contract exception.
- Next hypothesis: ABI review of mixed untouched entry-v0 and outgoing callee-result exits before recovery; no invented zero and no accepted-void exception.
