# 001399c0 blocked
- Range: 001399c0, 116 bytes. Versions tried: 3. Best: v1 with 2 differing words (116/116 bytes).
- First difference of the best version: !! 001399e4: 8e447f80  lw a0,32640(s2) | 001399e4: 8e4f7f80  lw t7,32640(s2); then 001399e8 lw a0,4(a0) vs lw a0,4(t7). Only the temporary register for the list head differs.
- Changes tried: v1 `cur == 0 ? D->next : *(Node* volatile*)&cur->next` in comma-while 2 words; v2 volatile D global 12 (nop in delay slot, still t7); v3 while(1) with node reused as head (a0 chain right but delay slot left as nop, branch layout different) 21.
- Why it stops here: results equal the sibling 00139948 analysis; no improvement over v1 in v2 and v3 and the remaining ideas are the same as the sibling's blocked ones (budget reached for this approach family: 12 attempts across siblings).
- Next hypothesis: C11: get the head load into a0 while keeping the bnez delay slot filled (a shared head/node variable that does not defeat the delay-slot fill).
