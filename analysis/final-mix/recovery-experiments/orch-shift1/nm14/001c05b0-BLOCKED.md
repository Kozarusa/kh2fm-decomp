# 001c05b0 blocked
- Range: 001c05b0, 100 bytes. Versions tried: 4. Best: v1 with 2 differing words (100/100 bytes).
- First difference of the best version: !! 001c0600: 25ee9350  addiu	t6,t7,-27824   ; = D_01d49350              | 001c0600: ade09350  sw	zero,-27824(t7)   ; = D_01d49350
- Changes tried: v1 C11 two-word array and pair pointer 2 words; v2 input-only pair guard 9 words; v3 volatile input pair guard with memory clobber 4 words (correct instruction order, only t6/t7 exchanged); v4 pair binding to t6 from best v1 3 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: take v3 and bind pair to $14 with its existing input guard and memory clobber. This combines correct order with original registers. Two WPs have blocked; next attempt belongs to opus WP per brief rule 2.
