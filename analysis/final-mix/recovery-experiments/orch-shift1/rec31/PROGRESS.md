# rec31 progress
start 2026-10-12T21:31:42Z
claim 00168958 token b92e7438aae14f22bceced44f29230bf attempts 1
v1: 12 words, first diff at 3: C10/C11 -> next: arg u32 and s32 globals
v2: 4 words, first diff at 3: scheduling C10/C11 -> next: struct type
v3: exact
submitted 00168958 v3
claim 0016ac80 token 4f3112a1a49b4f12a13cdf325ce42376 attempts 1
v1: 16 words, first diff at 8: C20 -> next: callee arg u64
v2: 2 words, first diff at 15: C11 -> next: register bind t0
v2: 2 words; v3 malformed; v4 exact
submitted 0016ac80 v4
claim 0016ae18 token 31efafd97db4459abfd89f23613095f6 attempts 1
v1: 15 words, first diff at 1: C9 -> next: volatile quad read
v2 malformed, v3: 15 words (volatile no change) -> next: struct member copy
v4: 15 words (struct Quad member no change) -> next: float4 struct copy
blocked 0016ae18 -> store-order
claim 0016b740 token 85e6eaf3f6464a0d8f07af1e311bdad6 attempts 1
v1: 23 words, first diff at 4: C20/C4 -> next: callee u64 arg, s32 return
v2: 19 words, first diff at 4: C7 -> next: Ghidra structure result=D; if(id!=0x236){loop}
v3: 22 words (worse) -> next: v2 with for(;;) break loop returning node
v4: 4 words, first diff at 20: C7 -> next: do-while with break
v5: 4 words same -> next: while(node=f(node)) with return node inside, return 0
v6: 9 words worse -> next: for(;;) with returns inside
v7: 19 words worse -> next: v4 with continue form
v8: 4 words; blocked 0016b740 -> branch-layout
claim 0016bb38 token 647d26a1b86e455e9e82854ea7befa04 attempts 1 (claim #5)
submitted 0016bb38 v1
claim 0016c508 token 4ce34b9b724749cdb9ff356ca30bed02 attempts 1 (claim #6, last)
v1: 13 words, first diff at 1: C9 -> next: volatile read of source+8
v2: 13 words same -> next: volatile quad store
v3: 13 words same -> next: asm memory barrier after quad store
v4: 2 words, first diff at 8: C11 -> next: bind quad temp to t0
submitted 0016c508 v5
