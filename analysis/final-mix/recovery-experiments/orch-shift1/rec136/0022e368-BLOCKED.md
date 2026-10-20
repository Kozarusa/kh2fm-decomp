# 0022e368 blocked
- Range: 0022e368, 128 bytes. Versions tried: 6. Best: v3 with 28 differing words (128/128 bytes).
- First difference of the best version: !! 0022e36c: 3c0a0036 lui t2,0x36 | 0022e36c: 0000602d move t4,zero.
- Changes tried: C11 count binding, v2 29 words; C11 offset binding, v3 28 words; C10 volatile accesses, v4 32 words; C10 empty memory guards, v5 28 words; C11 counter increment order, v6 28 words. Baseline v1 30 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 introduce a separate global-address temporary to control address materialization order and register allocation.