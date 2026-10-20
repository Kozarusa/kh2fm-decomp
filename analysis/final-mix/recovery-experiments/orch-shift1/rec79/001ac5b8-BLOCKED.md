# 001ac5b8 blocked
- Range: 001ac5b8, 116 bytes. Versions tried: 7. Best: v4 with 15 differing words (128/116 bytes).
- First difference of the best version: !! 001ac5cc: 548f000b  bnel	a0,t7,0x1ac5fc  | 001ac5cc: 148f000b  bne	a0,t7,1ac5fc
- Changes tried: v1 separate head/tail globals, while loop (25 words, 120 bytes); v2 List struct {head,tail} with tail via List* pointer, makes the tail check match the original beql (25); v3 explicit next temp in loop (25); v4 guard if(current!=node) + do-while loop (15, vtable store position now matches); v5 next temp in do-while (15, identical output); v6 vtable as u8* (15, identical); v7 current loaded before previous (15, identical).
- Why it stops here: no improvement for 3 versions (v5, v6, v7).
- Next hypothesis: the original else branch loads head->next into a separate register while previous=head is a copy (t5=t7) and the loop keeps cur in t6; try keeping head in a local Node* head variable plus binding current to $14 (C11c) or reading head->next via a volatile read (C9) so the load sits in the bnel delay slot.
