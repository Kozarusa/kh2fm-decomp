# 0028a908 blocked
- Range: 0028a908, 120 bytes. Versions tried: 0. Best: not applicable (no source/probe).
- First difference of the best version: not applicable (zero versions).
- Changes tried: not applicable (zero versions).
- Why it stops here: original count<=0 and all-null loop exits preserve unspecified entry v0; call paths propagate callee v0. Literal R4.3 cannot use void or fabricated zero for bypass paths.
- Next hypothesis: ABI review of mixed entry-v0 and outgoing callee-result return contract.
