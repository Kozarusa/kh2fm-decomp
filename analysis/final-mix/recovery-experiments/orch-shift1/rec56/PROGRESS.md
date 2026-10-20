# rec56 progress
start 2026-10-12T23:37:11Z
claim 001904a8 token ac36e386f4dd4280b7b37995cae4763e attempts 1
v1 written
v1: 16 words, first diff 0: C12 -> next: separate pointer to quad local (v2)
v2: 16 words: uninit quad folded away -> next: struct return (v3)
v3: 18 words, quad returned in v0 -> next: aligned 4-word struct return (v4)
v4: 16 words same as v1 -> next: pointer kept live via asm (v5)
v5: 6 words, first diff 10: C10/C11 -> next: explicit result pointer copy (v6)
v6: 6 words same -> next: Quad typed copy (v7)
v7: 6 words same -> next: bind temp to t0 (v8)
v8: 5 words, first diff 11: budget reached
blocked 001904a8 -> store-order
claim 001906f0 token c1e159685c8e43c090ec5cf15a46d6a5 attempts 1
v1: 9 words, first diff 7: C11/C10 -> next: dest pointer asm + t0 bind
v2: 2 words, first diff 7: C10 -> next: asm volatile dest
v3: 2 words, first diff 9: C10d -> next: memory barrier after store
v4: EXACT 0 words; v5 = v4 with why comments
submitted 001906f0 v5
claim 00191758 token 754de1d1ad4c4210a026bab13b43fab3 attempts 1
v1: 13 words, first diff 8: C5-like address materialization -> next: array decl for loaded floats
v2: 13 words no change -> next: C9 volatile reads
v3: 13 words no change -> next: u8 array decl + f32 cast
v4: 13 words: no improvement for 3 versions
blocked 00191758 -> address-materialization
claim 00191a50 token 0ad63dc821fa45c9916db5e5621bee2b attempts 1
v1: 24 words first diff 2: C21/C12 -> next: result var in s0 via || chain
v2: 23 words first diff 3: andi merged -> next: C7 nested ifs with result var
submitted 00191a50 v3
claim 001922c8 token 57de333326b644fcb2f9520950889377 attempts 1 (5th claim)
submitted 001922c8 v1
claim 00192320 token d7cc4605f32d4a75bd33a868603bc483 attempts 1 (6th claim, last)
submitted 00192320 v1; K reached, writing WP report
