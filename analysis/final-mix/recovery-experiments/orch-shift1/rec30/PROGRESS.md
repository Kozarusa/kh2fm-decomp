# rec30 progress
start 2026-10-12T21:31:42Z
claim 00168aa0 token 96ccf53046074869b0f00ed1a4d13c19 attempts 1
v1: 12 words, first diff at 0: C11 -> next: separate loop counter copy
v2: 2 words, first diff at 3: C11 -> next: swap init order of entry/remaining
v3: exact
submitted 00168aa0 v3
claim 00168b38 token b5b27737d7cd4689a84d0c501b23bf45 attempts 1
v1: exact
submitted 00168b38 v1
claim 0016ace0 token 99735452ec1149a9ac91822eab401883 attempts 1
v1: 17 words, first diff at 4: C11 -> next: pointer variable for dest
v2: 17 words identical: C11 -> next: callee decl without args / u64 object
v3: 17 words same: -> next: object as u32 (C11)
v4: 17 words same: no improvement 3 versions -> block
blocked 0016ace0 -> register-allocation
claim 0016b070 token c78e664c3c4349e7ae122a4fc023a561 attempts 1
v1: 4 words, first diff at 3: C14/C10 -> next: u32 flag store as separate read-modify then f32 read first
v2: 4 words same: -> next: asm lq/sq copy as in 001608c0
v3: 2 words, first diff at 8: C10 -> next: swap source order of the last two stores
v4: exact
submitted 0016b070 v4
claim 0016b7a0 token 61a7de31291346bdad2594595cd87a7e attempts 1
v1: 14 words, first diff at 9: C7 -> next: invert nesting
v2: 13 words, first diff at 9: C7 -> next: do-while with break
v3: 13 words same as v2: C7 -> next: while-top form with early return inside
v4: exact
submitted 0016b7a0 v4
claim 0016b800 token a268d3b03aed45e9800106e5e8d32b77 attempts 1
v1: exact
submitted 0016b800 v1
