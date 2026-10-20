# 002b84b8 blocked
- Range: 002b84b8, 124 bytes. Versions tried: 5. Best: v2 with 27 differing words (124/124 bytes).
- First difference of the best version: `!! 002b84b8: 27bdffd0  addiu sp,sp,-48 | 002b84b8: 27bdffb0  addiu sp,sp,-80`
- Changes tried: C19 explicit frame transport plus volatile spill, 27 words; C12 removed argument area, 27 words; C11 guarded buffer address, 30 words; C7 explicit loop/break, 27 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: bind both global addresses directly to their outgoing argument registers without preserving either across the retry call.
