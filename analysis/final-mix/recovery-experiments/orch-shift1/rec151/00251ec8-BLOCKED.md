# 00251ec8 blocked
- Range: 00251ec8, 116 bytes. Versions tried: 0. Best: none; differing words and compiled size unavailable (target 116 bytes).
- First difference of the best version: none; no candidate or probe.
- Changes tried: none. Return-path audit before drafting identifies same contract as rec150 REVIEW 0024eff8: null D_0035ee64 returns caller entry v0 untouched; false func_00139d78 returns its v0; success tail returns func_0023f5b8 result.
- Why it stops here: R12 conservative ABI block. Cannot use void or invent null-path zero. A complete source needs defined C11 entry-v0 capture; R4.8 prohibits assembly in fresh v1. No previously probed compliant baseline is supplied. Preserve target for explicit ABI treatment rather than submit a discarded-result source.
- Next hypothesis: authorize initial defined empty-output entry-v0 capture as return-contract primitive, then return predicate or tail result on respective paths.
