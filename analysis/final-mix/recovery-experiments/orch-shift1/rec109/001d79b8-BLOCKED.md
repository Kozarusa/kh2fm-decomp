# 001d79b8 blocked
- Range: 001d79b8, 80 bytes. Versions tried: 7. Best: v4 with 14 differing words (80/80 bytes).
- First difference of the best version: !! 001d79bc: 0000502d  move	t2,zero | 001d79bc: 0000602d  move	t4,zero
- Changes tried: v1 pointer walk s32* (18); v2 separate temp for loaded value (18); v3 ternary slot select (18); v4 struct Entry array indexed by index (14, size matches but compiler hoists lw and uses bnezl with reload, sw before swc1); v5 struct pointer walk (18, a0 is incremented in place instead of keeping a0 and using a separate t5); v6 compile error; v7 empty asm on cursor (18).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps a0 live and uses a separate cursor (t5=a0+4, +8 in the bnez delay slot) with slot/index in t2/t3; find a form that stops a0 being reused as cursor (e.g. make table used after the loop, or volatile read of entry key) while keeping the pointer walk and swc1-before-sw order.
