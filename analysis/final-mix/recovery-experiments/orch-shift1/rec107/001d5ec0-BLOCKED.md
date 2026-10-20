# 001d5ec0 blocked
- Range: 001d5ec0, 108 bytes. Versions tried: 5. Best: v2 with 11 differing words (108/108 bytes).
- First difference of the best version: !! 001d5ec0: 240f000a  li	t7,10  (compiled: sll t6,a2,0x2). Original forms row*10 with a real 3-operand mult (li 10; mult a2,a2,t7) after sll a3,a3,1; compiler strength-reduces to shift/add. Loop and tail (from 001d5eec on, v0 return of entry value) already match.
- Changes tried: v1 void return (12 words); v2 return u16 entry value (11, best); v3 constant-folded 0x36e596 address (23); v4 u32 row (11); v5 2D array u16 D[][5] index [row-1][column] (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force a real multiply, e.g. hold the stride 10 in a volatile or asm-"+r" register variable (C11d empty asm on a stride variable), and compute column*2 before the multiply.
