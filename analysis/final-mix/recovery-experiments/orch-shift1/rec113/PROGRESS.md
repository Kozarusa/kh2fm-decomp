# rec113 progress
start 2026-10-13T06:06:18Z
claim 1 of 6: 001db8b8 token 05b31445f9374499b1165d2e91fa2829 attempts 1
v1: 13 words, first diff at 0: C9 -> next: compute quotient first, then load data
001db8b8 v1: 13 words; best v1 13 words; streak 0
v2: 0 words exact
submitted 001db8b8 v2
claim 2 of 6: 001dba18 token e0bf69f059034f40a747d3f05cb46e72 attempts 1
v1: 18 words, first diff at 9: C7 -> next: do-while with separate result var
001dba18 v1: 18 words; best v1 18; streak 0
v2: 23 words, first diff at 1: C7 -> next: Ghidra do-while with early return 0
001dba18 v2: 23 words; best v1 18; streak 1
v3: 18 words, first diff at 9: C7 -> next: while(1) with result var and breaks
001dba18 v3: 18 words; best v1 18; streak 2
v4: 23 words; 001dba18 v4: 23 words; best v1 18; streak 3
blocked 001dba18 -> branch-layout
claim 3 of 6: 001dbb38 token 8270d382c83c4d36aaaa6f869b1d5fb1 attempts 1
v1: 15 words, first diff at 7: C7 -> next: while(1) with returns inside
001dbb38 v1: 15 words; best v1 15; streak 0
v2: 15 words same: C7 -> next: while((object=f(object))!=0) form
001dbb38 v2: 15 words; best v1 15; streak 1
v3: 0 words exact (while((object=f(object))!=0) form; same form may fix blocked 001dba18)
submitted 001dbb38 v3
claim 4 of 6: 001dbc58 token 59be1045e9054080a5568ea56eb90424 attempts 1
v1: 19 words, first diff at 3: C14/C10 -> next: dest pointer variable for quad copy
001dbc58 v1: 19 words; best v1 19; streak 0
v2: 19 words identical: C14 -> next: aligned struct copy
001dbc58 v2: 19 words; best v1 19; streak 1
v3: 19 words identical -> next: C10c volatile quad dest
001dbc58 v3: 19 words; best v1 19; streak 2
v4: 19 words; 001dbc58 v4: 19 words; best v1 19; streak 3
blocked 001dbc58 -> store-order
claim 5 of 6: 001dc278 token 836cdc0b17134422b9629cfd1b0f99ee attempts 1
v1: 29 words, first diff at 0: C21/C5 -> next: pointer to D_00352ae0 for tail access
001dc278 v1: 29 words; best v1 29; streak 0
v2: 28 words, first diff at 0: C10a -> next: store order 36 before 32, a2 store before a1
001dc278 v2: 28 words; best v2 28; streak 0
v3: 28 words identical -> next: C9 volatile float read
001dc278 v3: 28 words; best v2 28; streak 1
v4: 28 words identical -> next: C10d memory barriers around value store
001dc278 v4: 28 words; best v2 28; streak 2
v5: 26 words, first diff at 2: C10d -> next: load float into temp, store pad5 then value
001dc278 v5: 26 words; best v5 26; streak 0
v6: 26 words same -> next: float global as array pointer
001dc278 v6: 26 words; best v5 26; streak 1
v7: 26 words same -> next: volatile pointer read of float
001dc278 v7: 26 words; best v5 26; streak 2
v8: 26 words; 001dc278 v8: 26 words; best v5 26; streak 3
blocked 001dc278 -> store-order
claim 6 of 6: 001dc4e8 token 855547bc07e047b5bb9953de97270a68 attempts 1
v1: 9 words, first diff at 12: C8 -> next: explicit result=0/1 branches
001dc4e8 v1: 9 words; best v1 9; streak 0
v2: 0 words exact
submitted 001dc4e8 v2
