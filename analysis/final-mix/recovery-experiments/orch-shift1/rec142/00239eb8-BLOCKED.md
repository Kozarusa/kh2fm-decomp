# 00239eb8 blocked
- Range: 00239eb8, 92 bytes. Versions tried: 5. Best: v2 with 21 differing words (96/92 bytes).
- First difference of the best version: !! 00239ec4: c5e10000 lwc1 f1,0(t7) | 00239ec4: 0000682d move t5,zero.
- Changes tried: v1 scalar source 23 words; v2 C11 pointer temporary and empty guard 21 words; v3 C11(a) flag initialization reordered 21 words; v4 C7(b) split first comparison 21 words; v5 C11(b) boolean flag 21 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) initialized numeric binding for the flag, followed by a separately commented guard.
- Verbatim first difference: !! 00239ec4: c5e10000  lwc1	$f1,0(t7)                                   | 00239ec4: 0000682d  move	t5,zero
