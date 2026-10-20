# 001bba30 blocked
- Range: 001bba30, 88 bytes. Versions tried: 5. Best: v2 with 13 differing words (80/88 bytes).
- First difference of the best version: !! 001bba44: 10a00006  beqz	a1,0x1bba60 (compiled beqz a1,1bba74: original keeps a mid-function shared epilogue at 1bba60 with the call block placed after it ending in b back + li v0,1 in its delay slot)
- Changes tried: v1 locals as two u32 + u64 callee param (19, stack1 const-folded); v2 u32 buffer[2], s32 callee param (13); v3 negated inner condition swapped bodies (13); v4 early returns (16); v5 volatile count read (16).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7 - get the call block placed after the epilogue (e.g. ternary result = count ? (calls,1) : 0, or switch/goto-based layout); original returns v0=0 explicitly on count==0 path, then jumps back from the call block.
