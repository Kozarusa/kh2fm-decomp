#include "../common/types.h"
struct Link {
    s32 key;
    s32 pad;
    Link* prev;
    Link* next;
};
struct Handler {
    void** vtable;
};
struct Owner {
    u8 pad0[0x10];
    Handler* handler;
    u8 pad1[0x110];
    Link* head;
};

void func_0011ecc8(Owner* owner, s32 key) {
    Link* node = owner->head;
    if (node != 0) {
        s32 current = node->key;
        while (current != key) {
            node = node->next;
            if (node == 0) {
                return;
            }
            current = node->key;
        }
        if (node->prev == 0) {
            owner->head = node->next;
        } else {
            node->prev->next = node->next;
        }
        if (node->next != 0) {
            node->next->prev = node->prev;
        }
        Handler* handler = owner->handler;
        ((void (*)(Handler*))handler->vtable[1])(handler);
    }
}
