#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Node {
    f32 key;
    kn::FVector* vector;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" f32 D_0036dd5c;

void func_001c1938(kn::FVector* vector, List* list, Node* node, u8* matrix) {
    const f32* one = &D_0036dd5c;
    asm("" : "+r"(one)); // why: original forms the full address (lui+addiu) before the lwc1
    ((f32*)vector)[3] = *one;
    kn::FVector result;
    kn::FVector temp;
    // why: VU0 macro vector times matrix, same sequence and registers as accepted 00140500/001589d0
    asm volatile("lqc2 $vf5,0(%1); lqc2 $vf1,0(%2); lqc2 $vf2,16(%2); lqc2 $vf3,32(%2); lqc2 $vf4,48(%2); vmulax.xyzw ACC,$vf1,$vf5x; vmadday.xyzw ACC,$vf2,$vf5y; vmaddaz.xyzw ACC,$vf3,$vf5z; vmaddw.xyzw $vf5,$vf4,$vf5w; sqc2 $vf5,0(%0)"
                 : : "r"(&temp), "r"(vector), "r"(matrix) : "memory");
    result = temp;
    f32* lanes = (f32*)&result;
    node->vector = vector;
    node->key = lanes[2] / lanes[3];
    Node* cursor = 0;
    Node* previous = 0;
    while ((cursor = cursor == 0 ? list->head : cursor->next) != 0) {
        if (cursor->key >= node->key) {
            break;
        }
        previous = cursor;
    }
    if (previous == 0) {
        if (list->head == 0) {
            list->tail = node;
            list->head = node;
            node->next = 0;
        } else {
            node->next = list->head;
            list->head = node;
        }
    } else if (previous == list->tail) {
        previous->next = node;
        node->next = 0;
        list->tail = node;
    } else {
        node->next = previous->next;
        previous->next = node;
    }
}
