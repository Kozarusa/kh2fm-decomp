# rec58 progress
start 2026-10-12T23:45:22Z
claim 00192388 token 789f4c4be453482695b76a72c6e782be attempts 1 (claims: 1/6)
v1: 14 words, first diff at 2: C7 -> next: single-exit with advanced pointer
v2: 14 words, same: C7b -> next: separate returns advancing text first
v3: 14 words same -> next: offset form
v4: 14 words, no improvement x3
blocked 00192388 -> branch-layout
claim 00192940 token 3aa4ce702862447ea3c4c4efb6eb3786 attempts 1 (claims: 2/6)
v1: 8 words, first diff at 4: C10 -> next: statement order 5,1,2,3,4,0
v2: 10 words worse -> next: struct assignment
v3: 8 words same as v1 -> next: source order 2,0,1,3,4,5
v4: 8 words -> next: explicit temporaries in target load/store order
v5: 11 words, no improvement
blocked 00192940 -> store-order
claim 001942b8 token 4878a2ed3c2b472990a5b8af267b47af attempts 1 (claims: 3/6)
submitted 001942b8 v1
claim 001945a0 token 67bbb888eb0749e2912b2461a6433ad8 attempts 1 (claims: 4/6)
v1: 13 words, first diff at 8: u64 return gives dsll32 -> next: pointer return, cursor=record+4 stores 0,3,1,2
v2: 19 words, float load must precede stores -> next: f32 local loaded before stores
v3: 17 words -> next: D as array (lui/addiu/lwc1 0), record[4] direct then p=record+4 p[3],p[1],p[2]
v4: 19 words -> next: u8 array D with f32 pointer deref loaded first
v5: 17 words, no improvement x4
blocked 001945a0 -> address-materialization
claim 00194930 token f425ad6c69aa438a8d69b51bcc2ded3c attempts 1 (claims: 5/6)
submitted 00194930 v1
claim 00195468 token 1451eb79dda24b17a52ab370adc1f55a attempts 1 (claims: 6/6)
v1: 11 words, mthi/mfhi odd, 56 bytes -> next: Ghidra-form loop with s16 key param
v2: 11 words, first diff 1 -> next: single result var, idx incremented, one return
v3: 9 words, 52 bytes, regs only -> next: C11c bind index to \, entry to \
v4: 8 words, 56 bytes mthi back -> next: also bind result to \
v5: 2 words -> next: C10a reorder cursor++ before result=index
v6: 2 words same -> next: entry = *cursor++ ; result=index++ 
v7: 8 words worse -> next: explicit continue flag after cursor++
v8: 2 words, budget reached
blocked 00195468 -> branch-layout
