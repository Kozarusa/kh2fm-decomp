# rec63 progress
start 2026-10-13T00:03:20Z
claim 00197318 token 8648aace545c4459879219083dabb4fe attempts 1
v1: 22 words, first diff at 6: C9/C3 -> next: u8 cast on bit test
00197318 v1: 22 words; best v1 22; streak 0
v2: 21 words, first diff 6: C3 done (andi ff fixed) -> next: C9 volatile flags read
00197318 v2: 21 words; best v2 21; streak 0
v3: 21 words, no change from volatile -> next: C7c duplicate call in both arms
00197318 v3: 21 words; best v2 21; streak 1
v4: 22 words, worse -> next: C7a invert condition with mode init
00197318 v4: 22 words; best v2 21; streak 2
00197318 v5: 21 words; best v2 21; streak 3 -> stop
blocked 00197318 -> store-order (claims so far: 1)
claim 00197b98 token f0fc1fac04bc4fbeb957de14b6bd87ad attempts 1 (claim 2)
00197b98 v1: 17 words; best v1 17; streak 0
00197b98 v2: 17 words; best v1 17; streak 1
00197b98 v3: 17 words; best v1 17; streak 2
00197b98 v4: 17 words; best v1 17; streak 3 -> stop
blocked 00197b98 -> address-materialization (claims so far: 2)
claim 00197e08 token 6ead9eb9b8574a69a2dd9f998c8e13e3 attempts 1 (claim 3)
00197e08 v1 exact
submitted 00197e08 v1
claim 00197fe0 token 5fa95f49fa0a4e298ccabf8687a6ec07 attempts 1 (claim 4)
00197fe0 v1 exact
submitted 00197fe0 v1
claim 00198690 token 5b6fea2bdcfc429ca1eb18a2430b497a attempts 1 (claim 5)
00198690 v1: 30 words; best v1 30; streak 0 (Quad local: extra s3 for &value)
00198690 v2: 30 words; best v1 30; streak 1
00198690 v3: 31 words; best v1 30; streak 2 (barriers worse)
00198690 v4: 30 words; best v1 30; streak 3 -> stop
blocked 00198690 -> prologue-epilogue (claims so far: 5)
claim 00198970 token a49d143a08a643b085a2c5efd7b1e87f attempts 1 (claim 6, last)
00198970 v1 exact
submitted 00198970 v1
