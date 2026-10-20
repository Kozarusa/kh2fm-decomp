# 00284e40 blocked
- Range: 00284e40, 100 bytes. Versions tried: 0. Best: none, no probe (n/a/100 bytes).
- First difference of the best version: n/a, no eligible draft.
- Changes tried: none; literal exit audit before drafting.
- Why it stops here: R12 ABI contract conflict. Terminal tail j 002bd730 forwards its result, while packet accepted source provides void func_002bd730(u32,u64,u64,u64) and a void gateway declaration. R4.5 requires copying declaration; R4.3 and brief forbid accepted void exemption or outgoing result discard. No evidence resolves actual result type.
- Next hypothesis: independently audit 002bd730/gateway return contract and provide approved compatible declaration.
