# rec42 progress
start 2026-10-12T22:32:46Z
claim 00179b68 token 5f08decbd3bc41b8b9fef45ebb042255 attempts 1
v1: 21 words, first diff 0: C12 -> v2 result init before call/ || form
submitted 00179b68 v2
claim 00179f80 token 303e6309f942415e9e3e1712bc2de909 attempts 1
v1: 2 words, diff 12: C11 -> v2 return callee s32
submitted 00179f80 v2
claim 0017a538 token 9345434a5397423d8558a1170d39ee81 attempts 1
v1: 14 words C8 -> v2 separate flag temp
submitted 0017a538 v2
claim 0017a600 token 1aaf442fd9784c23997e7038ddb1b474 attempts 1
submitted 0017a600 v1
claim 0017a968 token c30bca6f5127454f9dc74a62be195760 attempts 1
v1: 23 words, operator= self-check + sw zero: C14 -> v2 Quad
v2: 14 words (Quad,f32 stores ok; store order, lq addressing): -> v3 FVector by value
v3: 15 words: -> v4 asm lq/sq copy, natural store order
v4: 2 words (store order C10) -> v5 order 3,0,1,2
v5: 4 words worse -> v6 barrier after [3]
v6: 7 words worse -> v7 order 1,2,3,0
v7: 2 words same -> v8 order 3,2,1,0
blocked 0017a968 -> store-order
claim 0017cb78 token 0ed3b7bd8620430c9d990e9848be8bc8 attempts 1 (6th/K)
v1: 20 words, lwc1 offset folded vs 0(t7): C9 -> v2 volatile global
v2: 20 words same -> v3 u8 array global read via cast
v3: 20 words same -> v4 volatile pointer var
blocked 0017cb78 -> address-materialization
