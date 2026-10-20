# 00261ce8 blocked
- Range: 00261ce8, 92 bytes. Versions tried: 0. Best: none; no probe.
- First difference of the best version: not applicable.
- Changes tried: none.
- Why it stops here: R12 unresolved ABI. Sole exit is tail j 002827f0, which passes through outgoing callee return. Packet accepted source defines void func_002827f0(u8*,u64,u64), which does not resolve literal R4.3 outgoing return contract. Prior accepted void is no exception.
- Next hypothesis: audit 002827f0 every exit and actual outgoing v0/f0 contract before drafting.
