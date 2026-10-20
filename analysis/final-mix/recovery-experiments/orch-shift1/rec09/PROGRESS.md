# rec09 progress
start 2026-10-12T18:55:39Z
claim 00139b28 token 781d042247d9405ab0e2cbae2381958d attempts 1 (claims: 1/6)
v1: 20 words, first diff 8: C7/C11 -> next: separate node var from carried s0
v2: 19 words, first diff 8: C7 -> next: negate first condition
v3: 21 words, first diff 8: C7 -> next: loop with if(node) body else return
v4: 19 words, same as v2 -> next: inline next() helper with ternary, while((n=next(n)))
v5: 14 words -> next: swap helper branch order
v6: 4 words -> next: ternary in helper
v7: 4 words (ternary same as v6) -> next: head local read before branch, == 0 first
submitted 00139b28 v8
claim 00139ba0 token 3d0e9630b7b64bab82d4823670c9e85b attempts 1 (claims: 2/6)
submitted 00139ba0 v1
claim 00139c18 token 9ce29087600b45708552674b925fc5f3 attempts 1 (claims: 3/6)
v1: 21 words, first diff 1: C11 s0/s1 swapped -> next: no temp for sub
v2: 21 words same -> next: if/else form with sub local inside else
v3: 21 words same -> next: second vtable read via object->field24, pass &field
v4: 21 words same -> next: asm opaque on object before computing sub (C11d)
submitted 00139c18 v5
claim 00139d78 token d8f806bcd182427c9a78384e885db266 attempts 1 (claims: 4/6)
v1: 16 words, first diff 0 (56/72 bytes): C1/C11 -> next: inline helper like 00139b28
v2: 17 words -> next: &D->next list pointer after store + u8 result var
v3: 17 words (60/72) -> next: volatile reload of D for list pointer (C9)
v4: 8 words, first diff 9: C7 -> next: if(node!=0){if match..} else 0 form
v5: 9 words (worse) -> next: result initialised 0 before loop, only set 1 in loop (from v4)
v6: worse -> next: v4 with u32 result & 0xff
v7: andi appears; remaining branch layout (~6 words) -> next: v7 with != 0 / else form
v8: 9 words. budget reached (8 versions)
blocked 00139d78 -> branch-layout
claim 0013a820 token fa30673013ee43269e75415f9556666f attempts 1 (claims: 5/6)
v1: 24 words (108/116), first diff 1: C1/C7 -> next: two separate top-level ifs with re-test of code
v2: 13 words (116/116), first diff 3 -> next: cursor[1] store via cursor, D[0] direct (C11b)
v3: 13 words same -> next: scalar globals + separate pointer (C18-like)
v4: 13 words same (optimizer normalizes) -> next: C10b rotate second block store source order to 3,2,1
v5: 13 words same. no improvement for 3 versions
blocked 0013a820 -> branch-layout
claim 0013a958 token 7a51ae1f6a3e4c0b978422edf0000eae attempts 1 (claims: 6/6)
v1: 25 words, first diff 1: C11/C8 -> next: bool found var (sltu) before D check
v2: 27 words worse (dsll32 normalisation) -> next: s64 found
v3: 26 words, logic matches, ordering/scheduling differs -> next: inline normalise helper called in the argument list
submitted 0013a958 v4
