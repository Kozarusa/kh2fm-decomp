# cdx1-rec12 progress
start 2026-10-13T02:51:36Z
Launch start was a placeholder; recorded actual setup UTC.
self-test: expected refusal, verification.json already exists
claim 1 of 6: 001ad4a8 token f02770f046d144b99c36fac1b1046067 attempts 1 blocker null
packet 001ad4a8 read completely; v1 mirrors instructions and accepted sibling declarations
001ad4a8 v1: 0 words; best v1 0 words; streak 0
submitted 001ad4a8 v1; source review passed
claim 2 of 6: 001ad9c8 token f1f34cd1ede1442fac8f9410fc3c54dc attempts 1 blocker null
packet 001ad9c8 read completely; v1 mirrors float comparisons, stores and return paths
001ad9c8 v1: 10 words; best v1 10 words; streak 0
v1: 10 words, first diff at 13: C1 parameters and paths verified; C10 rotate independent zero stores
001ad9c8 v2: 8 words; best v2 8 words; streak 0
v2: 8 words, first diff at 19: C5 address verified; C11 pointer binding and address transport
001ad9c8 v3: 9 words; best v2 8 words; streak 1
v3: 9 words, first diff at 19: C7 replace early return with conditional body
001ad9c8 v4: 2 words; best v4 2 words; streak 0
v4: 2 words, first diff at 24: C10 reorder upper clamp stores
001ad9c8 v5: 0 words; best v5 0 words; streak 0
submitted 001ad9c8 v5; source review passed
claim 3 of 6: 001adbc0 token 9457b037f2424aa1975ae4b12179d76a attempts 1 blocker null
packet 001adbc0 read; v1 uses accepted declarations and instruction-based tail return
001adbc0 v1: 2 words; best v1 2 words; streak 0
v1: first diff at 6: C10 rotate independent zero stores
001adbc0 v2: 0 words; best v2 0 words; streak 0
submitted 001adbc0 v2; source review passed
claim 4 of 6: 001ae210 token e90208eb38684c47bd6df1a2c76d432b attempts 1 blocker null
packet 001ae210 read; v1 mirrors signed byte reads, eight bit iterations and complement return
001ae210 v1: 0 words; best v1 0 words; streak 0
submitted 001ae210 v1; source review passed
claim 5 of 6: 001aeb80 token b78d0fb0217547739f80ee2661101e23 attempts 1 blocker null
packet 001aeb80 read; v1 mirrors loop, accepted declarations, preserved final callee return
001aeb80 v1: 4 words; best v1 4 words; streak 0
v1: first diff at 17: C11 introduce loaded-value temporary
001aeb80 v2: 4 words; best v1 4 words; streak 1
v2: first diff at 17: C11 bind loaded value to numeric register 15
001aeb80 v3: 2 words; best v3 2 words; streak 0
v3: first diff at 18: C11 bind loop comparison to numeric register 14
001aeb80 v4: 0 words; best v4 0 words; streak 0
submitted 001aeb80 v4; source review passed
claim 6 of 6: 001aebf0 token a1058d04d5fa4098950ff5f7d5a9f857 attempts 1 blocker null
packet 001aebf0 read; v1 mirrors unsigned byte indices, signed bound and selected pointer
001aebf0 v1: 0 words; best v1 0 words; streak 0
submitted 001aebf0 v1; source review passed; 6/6 claims resolved; no further claims
done 2026-10-13T03:02:23Z; WP-REPORT.md written
