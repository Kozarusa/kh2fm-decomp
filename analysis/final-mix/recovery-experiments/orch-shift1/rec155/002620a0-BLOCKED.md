# 002620a0 blocked
- Range: 002620a0, 120 bytes. Versions tried: 0. Best: none; no probe.
- First difference of the best version: not applicable.
- Changes tried: none.
- Why it stops here: R12 unresolved ABI. Ordinary jr paths preserve mode/isCreated/isFadeOut callee v0; tail j0028aa40 forwards its unknown return. Packet provides no accepted declaration or body for 0028aa40 to establish common outgoing contract. Void would discard outgoing results.
- Next hypothesis: establish 0028aa40 actual v0/f0 return contract, then preserve all ordinary and tail exits in a compatible nonvoid signature.
