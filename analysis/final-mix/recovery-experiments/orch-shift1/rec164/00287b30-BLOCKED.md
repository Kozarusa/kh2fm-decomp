# 00287b30 blocked
- Range: 00287b30, 60 bytes. Versions tried: 0. Best: none, not probed.
- First difference of the best version: none.
- Changes tried: literal R4.3 exit audit only.
- Why it stops here: R12 ABI contract. Outgoing tailcall 00287c78 result flows out unchanged, but both packet accepted sources declare it void. R4.5 declaration reuse cannot represent literal R4.3 result without exception.
- Next hypothesis: establish 00287c78 result contract from original callee; accepted void does not waive result preservation.
