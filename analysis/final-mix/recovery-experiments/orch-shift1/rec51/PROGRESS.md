# rec51 progress
start 2026-10-12T23:07:55Z
claim 00186d18 token fb657cdba7764b27b583b860e8ab8f57 attempts 1
v1: 10 words, first diff at 1: C1/C21 (pointer advanced a0+=320 in orig) -> next: use sub-pointer struct
v2: 8 words, first diff at 2: C11/C7 -> next: expression form result = value>=140 && value<151
v3: 8 words, worse form (sltiu range): C8 -> next: separate temporaries below/under in v2 form
v4: 8 words, movn: C8 -> next: v2 form with 140 test as ((value<140)^0)==0 via u8 bool
v5: 8 words same as v2 -> next: if/else in flag block
v6: 8 words, no improvement x3 (v2..v6 all 8)
blocked 00186d18 -> register-allocation (claims so far: 1)
claim 001874a0 token 6df4ed6b728a4e268104929a5f6f04e2 attempts 1 (claim 2)
v1: 31 words 136/124, result in saved reg: C12 -> next: assign result after the call
submitted 001874a0 v2
claim 001877a0 token 02f3ecbd44a642b1a02ea2c31d9c71f6 attempts 1 (claim 3)
v1: 18 words, 112/116, address materialized separately: C5-like -> next: declare as array and index [0]
v2: 18 words same -> next: pointer local with asm barrier inside if
submitted 001877a0 v3
claim 00187b90 token 0a6b8d818908488a9156fe00cc978cbc attempts 1 (claim 4)
v1: 6 words, first diff at 6: C10 -> next: swap final two zero stores
v2: 4 words, first diff at 6: C11/C10 -> next: load 144 into a local first
v3: 4 words no change -> next: data[0] before entry local
v4: 4 words no change -> next: C11b temp for 136 value declared after entry
v5: 4 words, no improvement x3
blocked 00187b90 -> register-allocation (claims so far: 4)
claim 00188430 token 8818f790f1e941ffb7dbf0c7449aa345 attempts 1 (claim 5)
v1: 2 words, stores 4/8 swapped: C10 -> next: swap source order
v2: 9 words worse -> next: v1 + asm memory barrier between stores 1 and 2
v3: 11 words worse -> next: v1 with volatile pointer stores
v4: 9 words, no improvement x3
blocked 00188430 -> store-order (claims so far: 5)
claim 001884d0 token d9ff9eaf43bd4a1a9e839867fccbbdc0 attempts 1 (claim 6, final)
v1: 4 words, first diff at 18 (lhu position): C9 -> next: volatile u16 read
v2: 15 words worse -> next: u16 id local declared after the stores
v3: 4 words no change -> next: struct global + struct entry
v4: 4 words, no improvement x3
blocked 001884d0 -> store-order (claims so far: 6)
WP report written
