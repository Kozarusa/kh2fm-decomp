#include "../common/types.h"
struct Node {
    Node* next;
    s32 second;
    s32 third;
    s32 first;
    f32 value;
    Node* link;
};
struct Pool {
    Node nodes[4];
    s32 freeList[4];
    s32 freeCount;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" Pool D_01c620c8;
extern "C" List D_01c62140;

void func_00199468(s32 first, s32 second, s32 third, f32 value) {
    D_01c620c8.freeCount--;
    Node* node = &D_01c620c8.nodes[D_01c620c8.freeList[D_01c620c8.freeCount]];
    Node* head = D_01c62140.head;
    node->second = second;
    node->third = third;
    node->first = first;
    node->value = value;
    node->next = 0;
    if (head == 0) {
        D_01c62140.tail = node;
        D_01c62140.head = node;
        node->link = 0;
        return;
    }
    D_01c62140.head = node;
    node->link = head;
}
