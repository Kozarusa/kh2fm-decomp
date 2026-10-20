# 002a1c68 blocked
- Range: 002a1c68, 108 bytes. Versions tried: 2. Best: v2 with 8 differing words (112/108 bytes).
- First difference of the best version: !! 002a1c7c: 14400012 bnez v0,0x2a1cc8 | 002a1c7c: 14400013 bnez v0,2a1ccc.
- Changes tried: v1 literal R4.3 return transport, 9 words; v2 C1/C20 signed word conversion, 8 words.
- Why it stops here: R12 unresolved ABI widths. Early exit preserves accepted s64 func_00292630 result; normal exit preserves accepted u32 func_00293d80 result without conversion. s64 return inserts dsll32/dsrl32; signed cast inserts move v0,v0. Discarding early upper bits or altering accepted declarations violates rules.
- Next hypothesis: ABI review must preserve both outgoing result widths without conversion or declaration exceptions.
