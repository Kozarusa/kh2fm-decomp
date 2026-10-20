#include "../common/types.h"
struct Node {u32 unused0[3];Node* next;u32 unused1[3];u32 state;};
extern "C" Node* D_0038aa40;
u32 func_00102180(Node** output){
Node* previous=0;u32 count=0;Node* node;
again:
if(previous)node=previous->next;else node=D_0038aa40;
previous=node;
if(__builtin_expect(node!=0,0))goto have_node;
return count;
have_node:
if(node->state!=1)goto again;
*output++=node;++count;goto again;
}
