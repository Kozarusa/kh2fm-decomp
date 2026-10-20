# 002b9bd0 blocked
- Range: 002b9bd0, 96 bytes. Versions tried: 6. Best: v3 with 4 differing words (96/96 bytes).
- First difference of the best version: `!! 002b9c14: 3c060007  lui a2,0x7 | 002b9c14: 3c07002c  lui a3,0x2c`
- Changes tried: target symbol alias caused a probe-definition failure; C20 signed pointer transport, 4 words; C11 source-ordered temporaries, 4 words; C11 outgoing-register bindings, 5 words; C11 volatile a2 guard, 7 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: split a2 and a3 constant formation into separate high/low C expressions while preserving the accepted u64 callee declaration.
