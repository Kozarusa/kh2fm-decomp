# 00139a38 blocked
- Range: 00139a38, 116 bytes. Versions tried: 4. Best: v1 with 2 differing words (116/116 bytes).
- First difference of the best version: !! 00139a5c: 8e447f80  lw a0,32640(s2) | 00139a5c: 8e4f7f80  lw t7,32640(s2); 00139a60 lw a0,4(a0) vs lw a0,4(t7). Only the temporary register of the list head differs.
- Changes tried: v1 `cur == 0 ? (head = D, head->next) : *(Node* volatile*)&cur->next` in comma-while 2 words; v2 asm in comma expression: compile error (parse error before asm); v3 statement expression with empty asm "+r" on head 2 words; v4 head bound to register $4 12 words (nop in bnez delay slot, bad jump target).
- Why it stops here: no improvement for 3 versions (v2,v3,v4).
- Next hypothesis: C11: make the list-head temporary share the allocation preference of the loop variable without defeating delay-slot filling; not found with register binding or empty asm.
