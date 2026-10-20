# 00256a58 blocked
- Range: 00256a58, 68 bytes. Versions tried: 0. Best: none, no probe.
- First difference of the best version: not applicable.
- Changes tried: none.
- Why it stops here: R12 unresolved ABI. The sole exit is tail j 00263a58; outgoing callee v0/f0 must flow out. Accepted declaration is void func_00263a58(s64,u8), and its accepted body ends in another callee call. Earlier void signature is not an R4.3 exception. Packet does not resolve actual outgoing return contract.
- Next hypothesis: audit 00263a58 and its outgoing callee return before choosing target signature.
