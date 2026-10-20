# 0028b160 blocked
- Range: 0028b160, 76 bytes. Versions tried: 7. Best: v4 with 18 differing words (72/76 bytes).
- First difference of the best version: !! 0028b164: 000c6c00 sll t5,t4,0x10 | 0028b164: 0000702d move t6,zero.
- Changes tried: v1 source loop 22 words; C7(b) do-loop with equality break v2 19; C11(c) count bound t4 v3 19; C11(d) initial count guard v4 18; C11(b) signed loop limit temporary v5 18; C11(c) loop limit t5 binding v6 18; C11(d) final count guard v7 19.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(a) move index initialization before guarded raw-count load so delay-slot scheduling can preserve initial sign-extension sequence; test independently from best v4.
