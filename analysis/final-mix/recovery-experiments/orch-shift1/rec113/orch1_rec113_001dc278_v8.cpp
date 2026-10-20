#include "../common/types.h"
struct Node {
    void* vtable;
    s32 a4;
    s32 a8;
    s32 pad0;
    s32 pad1;
    s32 pad2;
    s32 pad3;
    s32 pad4;
    f32 value;
    s32 pad5;
    Node* next;
};
extern "C" Node* D_00352ae0;
extern "C" s32 D_00352ae8;
extern "C" u8 D_00352b48[];
extern "C" f32 D_0036e7e4[];

void func_001dc278(Node* node, s32 first, s32 second) {
    Node** list = &D_00352ae0;
    node->pad0 = 0;
    node->pad1 = 0;
    node->vtable = D_00352b48;
    node->pad2 = 0;
    node->pad3 = 0;
    node->pad4 = 0;
    node->pad5 = 0;
    // why: keeps store order
    asm volatile("" ::: "memory");
    f32 volatile* source = D_0036e7e4;
    node->value = *source;
    // why: keeps store order
    asm volatile("" ::: "memory");
    if (list[1] == 0) {
        D_00352ae0 = node;
        list[1] = node;
        node->next = 0;
    } else {
        list[1]->next = node;
        node->next = 0;
        list[1] = node;
    }
    node->a4 = second;
    node->a8 = first;
    D_00352ae8 = D_00352ae8 + 1;
}





