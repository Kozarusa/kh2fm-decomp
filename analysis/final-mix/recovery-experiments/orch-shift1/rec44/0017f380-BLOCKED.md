# 0017f380 blocked
- Range: 0017f380, 88 bytes. Versions tried: 6. Best: v3 with 10 differing words (88/88 bytes).
- First difference of the best version: !! 0017f3ac: 14800006  bnez	a0,0x17f3c8 (compiled: beqz a0,17f3c4, with the call block placed inline and the epilogue after).
- Changes tried: v1 extern C self-prototype (no rows extracted); v2 drop prototype, 13 words; v3 separate temp for loaded child (C11), 10 words; v4 break->return (C7c), 10 words; v5 do-while form, 21 words; v6 for(;;) with if(next){call;continue;} return, 10 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7a/b: keep the exit block first and the recursive call out of line (original has epilogue before the jal block); try testing the loaded value via a volatile read (C9) or a goto-based layout.
