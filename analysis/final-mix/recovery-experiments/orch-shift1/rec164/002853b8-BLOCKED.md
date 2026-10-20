# 002853b8 blocked
- Range: 002853b8, 92 bytes. Versions tried: 0. Best: none, not probed.
- First difference of the best version: none.
- Changes tried: literal R4.3 audit before drafting.
- Why it stops here: R12 ABI contract. Final 0023fa90 result flows unchanged through jr ra, while sole packet accepted source declares/defines it void. Cannot copy declaration per R4.5 and preserve outgoing result per literal R4.3 without an exception.
- Next hypothesis: establish non-void callee result contract from original 0023fa90 before retry; accepted void declaration grants no exemption.
