# 0029ec40 blocked
- Range: 0029ec40, 88 bytes. Versions tried: 8. Best: v7 with 2 differing words (88/88 bytes), earliest tie; v7 is ineligible because two guards were accidentally added. Valid v8 also has 2 words.
- First difference of the best version: !! 0029ec6c: 03e00008 jr ra | 0029ec6c: 24020001 li v0,1
- Changes tried: v1 direct translation 20; v2 default result temporary 20; v3 C11 initialized result binding 16; v4 initialization guard 19; v5 match return through result 16; v6 match result guard 3; v7 accidentally two guards 2; v8 default-only guard from v6 2.
- Why it stops here: budget reached.
- Next hypothesis: remove match-result guard from valid v8 while retaining default-only guard, allowing li v0,1 in return delay slot.
