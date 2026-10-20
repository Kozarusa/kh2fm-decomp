# 00265740 / 00265c10: predicate prologue save order

Both original live ranges are 60 bytes. Their best archived proofs match all instructions except prologue stores at offsets 0x4 and 0x8, where register31 must be saved before register16. Existing prior experiments include canonical typed helpers, incoming memory barriers, and explicit register16/register31 clobbers.

Fresh tests use pointer and signed return declarations, typed 32/64-bit output operands for register31, and signed/pointer declarations with post-call memory barriers and optional volatile final load. Eleven complete proofs remain nonmatching. Pointer/signed variants without barriers shrink to 56 bytes; typed volatile register31 output operands preserve 60 bytes but still have the two-word save-order residual. All six barrier-preserving pointer/signed controls retain 60 bytes and the save-order residual. Saved evidence binds complete source/proof files and original range hashes.

Next hypothesis: investigate accepted 60-byte predicate analogues whose first no-argument helper produces a saved pointer. Identify a distinct instruction-neutral register16 save-lifetime dependency rather than another broad memory or link-register marker. The tested typed register31 operand does not solve save scheduling; avoid repeating it. No compiler impossibility is established.
