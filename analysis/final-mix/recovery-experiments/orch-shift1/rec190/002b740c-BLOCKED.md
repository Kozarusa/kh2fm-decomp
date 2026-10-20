# 002b740c blocked
- Range: 002b740c, 52 bytes. Versions tried: 4. Best: v1 with 13 differing words (32/52 bytes).
- First difference of the best version: `!! 002b740c: 27bdffe0  addiu sp,sp,-32 | 002b740c: 00000000  nop`
- Changes tried: C19 local volatile argument payload, 13 words; C19 frame-address payload, 13 words; C19 accepted explicit frame transport, 13 words; C11 4-byte function alignment, compile error.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: use the accepted SDK wrapper symbol alias to suppress leading alignment padding, then separately constrain t7 materialization after payload[3].
