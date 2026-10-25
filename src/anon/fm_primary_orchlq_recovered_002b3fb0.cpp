#include "../common/types.h"

struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* table;
};

struct Element {
    Method* table;
    u8 body[72];
};

typedef void (*FreeMethod)(Object*, void*);
struct Allocator {
    FreeMethod* table;
};

struct System {
    u8 pad[20];
    Allocator* allocator;
};

struct Owner {
    Object* first;
    Element* elements;
    Object* last;
};

extern "C" System* D_00347f80;

void func_002b3fb0(Owner* owner) {
    if (owner->first != 0) {
        owner->first->table[4](owner->first);
        owner->first = 0;
    }
    Element* array = owner->elements;
    if (array != 0) {
        Element* end = array + ((s32*)array)[-1];
    next: // why: original keeps the exit test at the loop head (no rotation), a goto loop is not rotated
        if (array != end) {
            end--;
            end->table[3]((Object*)end);
            array = owner->elements;
            goto next;
        }
        Allocator* allocator = D_00347f80->allocator;
        allocator->table[1]((Object*)allocator, (s32*)array - 1);
        owner->elements = 0;
    }
    if (owner->last != 0) {
        owner->last->table[4](owner->last);
        owner->last = 0;
    }
}
