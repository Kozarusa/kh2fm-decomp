# rec90 progress
start 2026-10-13T03:50:21Z
claim 1 of 6: 001b9d40 token b56a67e612484015b1f51555be4fbf9d attempts 1
v1: 24 words, first diff at 1: C21/merged masks -> next: separate flag var with if/else-if chain
v2: 14 words, first diff at 9: C7 -> next: flag var with || chain and result=flag
v3: 24 words: merged again. best v2 14; streak 1 -> next: if/else-if chain assigning result directly
v4: 18 words. best v2 14; streak 2 -> next: ternary chain C7
v5: 16 words. best v2 14; streak 3 -> block
blocked 001b9d40 -> branch-layout
claim 2 of 6: 001bb4b0 token 39e10be848fb43ff8899d3c351d840d0 attempts 1
v1: 8 words, first diff at 4: bool result gave sra/xori/andi -> next: u32 result type
v2: 8 words, same. best v1 8; streak 1 -> next: split statements flags&=4 then ==0
v3: 0 words exact
submitted 001bb4b0 v3
claim 3 of 6: 001bb890 token 68fb3a383276440fab1a0dd048bd67ea attempts 1
v1: 23 words, first diff at 1: ors merged (C10c) -> next: volatile u32 access
v2: 22 words (92 bytes), first diff at 1: global not reloaded. best v2 22; streak 0 -> next: pointer global volatile, plain u32 access
v3: 25 words. best v2 22; streak 1 -> next: D as u32 so u32 store aliases the global
v4: 0 words exact
submitted 001bb890 v4
claim 3b->claim 4 of 6: 001bb9b0 token b7041396d4694a75ac7252ef4fa9936a attempts 1
v1: 0 words exact
submitted 001bb9b0 v1
claim 5 of 6: 001bb9f0 token 17ae9ad6661444d193e76ca430e4a042 attempts 1
v1: 0 words exact
submitted 001bb9f0 v1
claim 6 of 6: 001bba30 token 14ffe48a00dc4b83a58612500cbd5cf2 attempts 1
v1: 19 words, first diff at 3: stack1 const-folded, dsll32 from u64 param -> next: array buffer, s32 second param
v2: 13 words, first diff at 5: C7 -> next: negate inner condition, swap bodies
v3: 13 words same. best v2 13; streak 1 -> next: early returns
v4: 16 words. best v2 13; streak 2 -> next: result var set to 1 after calls with count read via volatile? use C9 volatile count read
v5: 16 words. best v2 13; streak 3 -> block
blocked 001bba30 -> branch-layout
