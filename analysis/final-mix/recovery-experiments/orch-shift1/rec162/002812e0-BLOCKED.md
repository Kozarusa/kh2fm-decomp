# 002812e0 blocked
- Range: 002812e0, 92 bytes. Versions tried: 5. Best: v2 with 22 differing words (112/92 bytes).
- First difference of the best version: !! 002812f8: 81cf4188 lb t7,16776(t6) | 002812f8: 91cf4188 lbu t7,16776(t6).
- Changes tried: v1 direct scan23; C9 volatile table v2 22; widened selector v3 23; widened entry v4 24; split postincrement v5 22.
- Why it stops here: no improvement for 3 versions, strict R7 ties count.
- Next hypothesis: C2 explicit signed-byte load transport control at a single site, then separate result t4 binding if needed.
