# rec02 progress
start 2026-10-12T16:39:16Z
claim 00105f00 token 1acf7b3e094d47b5b19f06f6cb63a29e attempts 1
wrote v1
v1: 35 words, first diff at 0: C1/C21 -> next: for-loop rewrite
v2: 0 words exact
submitted 00105f00 v2
claim 00106048 token 5178caf51c3542a29a28a9ec5b35bc99 attempts 1
v1: 25 words, first diff at 1: C10/C11 -> next: u16 fill var, store order f,a,b,c,d,e
v2: 2 words, first diff at 2: C10 -> next: order a,b,c,d,e,f
v3: 7 words, worse -> next: volatile struct local
v4: 2 words (struct), same diff -> next: f = 0xffff literal
v5: 27 words worse; 3 versions no improvement -> block
blocked 00106048 -> store-order
claim 00108930 token a01a47ff6e7d4b3f9149d70bb4cfbbe7 attempts 1
v1: 19 words, first diff at 0: C21/C11 -> next: do-while with result var
v2: 23 words (worse) -> next: do-while, no result var
v3: 17 words, first diff at 1: C7/C11 -> next: result at loop top, next temp
v4: compile error (scope), counts as version
v5: 18 words, result temp differs -> next: result as outer variable
v6: 18 words; 3 versions without beating 17 -> block
blocked 00108930 -> register-allocation
blocked 00108930 -> register-allocation (confirmed)
claim 00109690 token d9f3cab301194c188aca5e49028c55a2 attempts 1
v1: 20 words, first diff at 5: C10/C14 -> next: volatile Quad store
v2: 20 words no change -> next: four u32 zero stores per Ghidra
v3: 24 words worse -> next: volatile u64 pointer + Quad
v4: 22 words -> next: union Quad/u64 (C18)
v5: 3 words, first diff at 24: C10 -> next: asm memory barrier before dword[3] store
v6: 16 words worse (barrier)-> next: volatile store of dword[0]
v7: 3 words, same -> next (last): volatile store of dword[3]
v8: 3 words; budget -> blocked 00109690 -> store-order
claim 00109788 token 66da1defbcf64b459819bc7a11f4ab37 attempts 1
v1: 6 words, first diff at 1: C11 -> next: temporaries
v2: 6 words same -> next: asm register binding
v3: 6 words same (binding ignored) -> next: temp order swapped
v4: 6 words same; no improvement for 3 versions -> block
blocked 00109788 -> register-allocation
claim 0010a828 token 7fb1dfd639f54efabf6b954e25cbffaf attempts 1
v1: 18 words, first diff at 1: C11/C4 -> next: modify far in place (far -= near)
v2: 17 words -> next: volatile constant globals
v3: 17 words same -> next: constants read through local volatile pointers
v4: 17 words same -> next: array declarations for the constants
v5: 17 words; 3 versions no improvement -> block
blocked 0010a828 -> float-transport
WP report written
