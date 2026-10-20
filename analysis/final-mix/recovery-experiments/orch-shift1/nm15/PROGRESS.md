# nm15 progress
start 2026-10-13T17:14:54Z
claim 1 of 3: 001e2c00 token 0c08c589e1b7451c8e3f73ce77cfa412 attempts 3
packet read; earlier proof independently recounted: 1 word, trap sole difference; wrote v1 authorized break 0
001e2c00 v1: 3 words; best v1 3 words; streak 0
blocked 001e2c00 -> address-materialization
claim 2 of 3: 002233f0 token 8f085ac9d75645439674297e98b2f1dc attempts 2
packet read; earlier proof independently recounted: 1 word, trap sole difference; wrote v1 authorized break 0
002233f0 v1: 0 words; best v1 0 words; streak 0
source reviewed: one function, own trap why, no bindings or other instruction asm
submitted 002233f0 v1
claim 3 of 3: 00220c88 token f1ecc67ad29f4d078b71e531db5cb2b9 attempts 2 blocker null
packet and rec131 review read; earlier v4 independently recounted exact but unassigned binding rejected; wrote v1 empty output asm defining entry before any read
00220c88 v1: 4 words; best v1 4 words; streak 0
v1: first diff index 4, C9 -> next volatile read prevents load before spill
00220c88 v2: 0 words; best v2 0 words; streak 0
source reviewed: one function, numeric binding and empty output guard each own why; defined before all reads; no instruction asm
submitted 00220c88 v2
K=3 reached; WP report written
end 2026-10-13T17:18:03Z
