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
    // why: original keeps the cursor in a1 and the key copied to t6
    register Link* node asm("$5");
    for (node = owner->head; node != 0; node = node->next) {
        if (node->key == key) {
            if (node->prev != 0) {
                node->prev->next = node->next;
            } else {
                owner->head = node->next;
            }
            if (node->next != 0) {
                node->next->prev = node->prev;
            }
            Handler* handler = owner->handler;
            ((void (*)(Handler*))handler->vtable[1])(handler);
            return;
        }
    }
}
