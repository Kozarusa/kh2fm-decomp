#include "../common/types.h"
struct Object;
struct Slot;
struct Handler {
    u8 pad[0x24];
    void (*callback)(Object*, Slot*);
};
struct Slot {
    Handler* handler;
    u8 pad[12];
};
struct Table {
    u8 pad[0x26];
    u16 count;
    Slot slots[1];
};
struct Group {
    Table* table;
    Object* current;
    u8 pad[4];
    u16 refs;
};
struct Object {
    Object* next;
    u8 pad[4];
    Group* group;
};

extern "C" u32 D_01d9e6e4;
extern "C" void func_001e7798(u32, u32);

// why: void per ruling #36: the single exit tail-calls func_001e7798 (accepted void, store-only),
// so v0/$f0 is either the untouched entry value or a stale slot-callback result (stale-a/stale-b).

void func_001e7be0(Object* object) {
    Group* group = object->group;
    Table* table = group->table;
    s32 index;
    for (index = 0; index < (s16)table->count; index++) {
        Slot* slot = &table->slots[index];
        Handler* handler = slot->handler;
        if (handler != 0 && handler->callback != 0) {
            handler->callback(object, slot);
        }
    }
    group->refs--;
    if (group->refs == 0) {
        group->current = 0;
    } else if (group->current == object) {
        group->current = object->next;
    }
    func_001e7798(D_01d9e6e4, (u32)object);
}
