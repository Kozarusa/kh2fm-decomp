# 00262f58 blocked
- Range: 00262f58, 68 bytes. Versions tried: 0. Best: none in this WP; earlier attempt 6 words (68/68).
- First difference of the best version: not applicable; no probe.
- Changes tried: none.
- Why it stops here: R12 manual conflict. Literal R4.3 requires forwarding sole tail 0028da70 return; accepted declaration is u32 func_0028da70(u64,s32). Mandatory <=6-word copy baseline is void and discards outgoing result. R4 restricted first-copy edits do not include signature/body return-contract repair, and fresh drafting cannot discard outgoing result.
- Next hypothesis: authorize first-copy return-contract correction, then copy earlier proposal with u32 signature and return final callee call, probe and address original 6-word allocation difference.
