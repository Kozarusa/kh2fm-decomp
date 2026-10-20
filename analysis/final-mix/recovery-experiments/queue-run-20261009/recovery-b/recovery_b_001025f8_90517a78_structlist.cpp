#include "../common/types.h"
struct Node { u8 pad[56]; Node* next; Node* prev; }; struct Owner { u8 pad0[8]; Node* first; Node* last; u8 pad1[0x110-16]; Node* current; };
extern "C" void func_001022e8(Node*);
void func_001025f8(Owner* owner,Node* node) { if(owner->current==node) owner->current=node?node->next:owner->first; Node** list=&owner->first; Node* previous=node->prev; if(previous) previous->next=node->next; else *list=node->next; Node* next=node->next; if(next) next->prev=node->prev; else list[1]=node->prev; node->prev=0; node->next=0; func_001022e8(node); }
