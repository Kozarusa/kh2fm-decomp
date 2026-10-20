# 0028c0a0 blocked
- Range: 0028c0a0, 124 bytes. Versions tried: 5. Best: v2 with 4 differing words (124/124 bytes).
- First difference of the best version: !! 0028c0fc: 240f0001 li t7,1 | 0028c0fc: 35cee5e5 ori t6,t6,0xe5e5
- Changes tried: initial 5 words; C10 reverse final stores v2 4 words; C10 volatile final stores v3 4 words; C10 memory barrier v4 7 words; C11 color $14 binding v5 4 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 empty +r guard after color materialization using volatile-store baseline v5, one site only.
