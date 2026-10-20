#include "../common/types.h"
struct Node {
    Node* next;
    Node* prev;
    s32 flag;
    s32 pad;
};
struct Header {
    Node* node;
    s32 a;
    s32 b;
    s32 size;
};

void func_001e7798(Header* header, Node* body) {
    Node* node = body - 1;
    node->flag = 0;
    asm volatile("" ::: "memory"); // why: keeps store order
    header->node = node;
    header->size = header->size - ((s32)body[-1].next - (s32)node);
    asm volatile("" ::: "memory"); // why: keeps store order
    Node* prev = node->prev;
    if (prev != 0 && prev->flag == 0) {
        prev->next = body[-1].next;
        body[-1].next->prev = prev;
        node = prev;
    }
    Node* next = node->next;
    if (next->flag == 0) {
        node->next = next->next;
        next->next->prev = node;
    }
}