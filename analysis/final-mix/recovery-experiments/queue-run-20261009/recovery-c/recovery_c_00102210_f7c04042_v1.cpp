#include "../common/types.h"
struct Node{u32 x[3];Node* next;u32 y[3];u32 state;};
extern "C" Node* D_0038aa40;
Node* func_00102210(void){Node* previous=0;Node* node;again:if(previous)node=previous->next;else node=D_0038aa40;previous=node;if(node)goto present;return 0;present:if(node->state==1)return node;goto again;}
