# 001dca70 blocked
- Range: 001dca70, 112 bytes. Versions tried: 6. Best: v3 with 15 differing words (108/112 bytes).
- First difference of the best version: !! 001dca8c: 11e00012  beqz	t7,0x1dcad8   | 001dca8c: 11e00011  beqz	t7,1dcad4
- Changes tried: C7 if/else with early-initialised args (v1 26, v2 26 words); C7 condition written as plain if(x&M) then-first with else assigning second=0 (v3 15, first half now matches); fresh variables for second half (v4 15); cached flags local (v5 15); u32 return with return func_001e7088 (v6 15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: second half needs flags load before lui, a1=0 else outlined with b to the epilogue-join (original joins before the ld s0 epilogue); try volatile read of object[2] in the second condition (C9) or a goto-based layout as in 001dc738.
