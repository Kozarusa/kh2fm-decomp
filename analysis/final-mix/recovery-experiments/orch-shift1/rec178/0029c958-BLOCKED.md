# 0029c958 blocked
- Range: 0029c958, 124 bytes. Versions tried: 0. Best: none with N/A differing words (N/A/124 bytes).
- First difference of the best version: N/A; no probe.
- Changes tried: none.
- Why it stops here: R12 ABI conflict. Packet-named accepted source declares func_002954e0(void) returning void, while original uses its outgoing v0 as condition and returns the last outgoing callee v0. R4.5 exact declaration and R4.3 result preservation cannot both be represented.
- Next hypothesis: resolve accepted callee declaration and outgoing result contract.
