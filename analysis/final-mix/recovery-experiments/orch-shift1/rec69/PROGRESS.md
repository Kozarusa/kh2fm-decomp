# rec69 progress
start 2026-10-13T00:35:46Z
claim 0019c8d0 token 0bccc90ce6db4ad69493fcff988ab4b8 attempts 1
submitted 0019c8d0 v1
claim 0019ca28 token 1686f62608764aa099acbebdff7ce1c6 attempts 1
v1: 11 words, first diff at 0: C12 frame size -> next: larger out struct (32 bytes)
v2: 5 words, first diff at 5: C10 -> next: move out.pointer=0 after first copy
0019ca28 v3: 5 words; best v2 5 words; streak 1 (same output)
0019ca28 v4: 5 words; best v2 5; streak 2
0019ca28 v5: 5 words; best v2 5; streak 3 -> stop
blocked 0019ca28 -> store-order
claim 0019d4f8 token 10fe54d0286c4f92bb929bb383a84a29 attempts 1
blocked 0019d4f8 -> boundary-review
claim 0019eb60 token 8decb2f5dde54417bc530c0174a6d908 attempts 1
submitted 0019eb60 v1
claim 0019ebc0 token 82c57097234d4ae1b433d02ae9e2676e attempts 1
submitted 0019ebc0 v1
claim 0019ee28 token f613032b5995458ea6911f6546564839 attempts 1
0019ee28 v1: 10 words, first diff at 1: C4 float zero via mtc1 + struct base -> next: struct global with f32 fields
0019ee28 v2: 11 words; best v1 10; streak 1
0019ee28 v3: 7 words; best v3 7; streak 0 (local f32 zero)
0019ee28 v4: 7 words; best v3 7; streak 1 (array cast, same output)
0019ee28 v5: 7 words; best v3 7; streak 2
0019ee28 v6: 7 words; best v3 7; streak 3 -> stop
blocked 0019ee28 -> store-order
