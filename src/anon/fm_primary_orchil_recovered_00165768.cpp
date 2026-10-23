#include "../common/types.h"
struct Node {
    s32 value;
    u32* data;
    s32 unused;
    Node* next;
};
struct NodeList {
    Node* head;
    Node* tail;
};
struct Pool {
    u8 pad[1024];
    s32 indices[64];
    s32 count;
};
extern "C" NodeList D_004f41c0;
extern "C" Pool* D_0034c7a0;
extern "C" void func_00106420(u32*);

void func_00165768(Node* object) {
    register Node* previous asm("$12"); // why: original keeps the previous node in t4
    register Node* head asm("$15") = D_004f41c0.head; // why: original holds the list head in t7
    if (object == head) {
        D_004f41c0.head = object->next;
        previous = 0;
    } else {
        previous = head;
        register Node* current asm("$13") = head->next; // why: original walks the list in t5
        if (current != object) {
            Node* next;
            do {
                next = current->next;
                previous = current;
                current = next;
            } while (next != object);
        }
        previous->next = object->next;
    }
    if (object == D_004f41c0.tail) {
        D_004f41c0.tail = previous;
    }
    object->next = 0;
    if (object->data != 0) {
        func_00106420(object->data);
    }
    object->data = 0;
    asm volatile("" ::: "memory"); // why: keeps store order
    Pool* pool = D_0034c7a0;
    s32 count = pool->count;
    ((s32*)((u8*)pool + 1024))[count] = ((s32)object - (s32)pool) >> 4;
    pool->count = count + 1;
}
