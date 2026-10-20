#include "../common/types.h"
struct Node{u32 x[3];Node* next;u32 y[3];u32 state;};
extern "C" Node* D_0038aa40;
Node* func_00102210(void){register Node* previous asm("$14")=0;while(true){register Node* node asm("$2")=previous?previous->next:D_0038aa40;previous=node;if(!node)return 0;if(node->state==1)return node;}}
