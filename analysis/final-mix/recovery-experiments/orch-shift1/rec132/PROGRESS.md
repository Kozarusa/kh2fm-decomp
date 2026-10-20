# rec132 progress
start 2026-10-13T16:56:02Z
claim 1 of 6: 00224cf0 token fcc594075e0244909d257c0f8d32e398 attempts 1 blocker null
00224cf0 v1: 4 words; best v1 4 words; streak 0
v1: 4 words, first diff at 6: C1 -> boundary evidence: required case 3 block lies beyond target
blocked 00224cf0 -> boundary-review
claim 2 of 6: 002252b0 token b68252ea940643cfb4793735bf6201b9 attempts 1 blocker null
002252b0 v1: 0 words; best v1 0 words; streak 0
review v1: one function; clean names; no asm or bindings; globals and arguments confirmed
submitted 002252b0 v1
claim 3 of 6: 00225640 token e1d44c8fc65944d8b7f38e12c66d073b attempts 1 blocker null
00225640 v1: 0 words; best v1 0 words; streak 0
review v1: one function; clean names; no asm or bindings; original first-call arguments a0/a1/a2 forwarded; global confirmed
submitted 00225640 v1
claim 4 of 6: 002256c8 token 96adbe1608a24c15928725e672d6d21a attempts 1 blocker null
002256c8 v1: 0 words; best v1 0 words; streak 0
review v1: one function; clean names; no asm or bindings; first call retains original a0; call arguments and D_0035db18 confirmed
submitted 002256c8 v1
claim 5 of 6: 00226e60 token 6db78a0dbc704f76bb6a31682a01b7f6 attempts 1 blocker null
00226e60 v1: 0 words; best v1 0 words; streak 0
review v1: one function; clean names; no asm or bindings; u8 entry mask and callee-result return confirmed
submitted 00226e60 v1
claim 6 of 6: 00227078 token 74101882b31e4e7a8c821d36566a064a attempts 1 blocker null
00227078 v1: 22 words; best v1 22 words; streak 0
v1: 22 words, first diff at 8: C1 -> all original parameters/globals/callee args confirmed; C7 -> split conjunction into nested tests to preserve missing zero branch
00227078 v2: 7 words; best v2 7 words; streak 0
v2: 7 words, first diff at 10: C11(a) -> compute pointer with offset as left operand to match addu source order
00227078 v3: 3 words; best v3 3 words; streak 0
v3: 3 words, first diff at 10: C11(b) -> introduce state selector temporary before loop counter initialization
00227078 v4: 0 words; best v4 0 words; streak 0
review v4: one function; clean names; no asm or bindings; global pointer reload and original a0 callee argument confirmed
submitted 00227078 v4
claims 6 of 6 resolved; stop claiming
