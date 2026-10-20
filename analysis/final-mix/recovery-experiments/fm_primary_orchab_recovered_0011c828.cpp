#include "../common/types.h"
extern "C" s64 func_0011f078(void*, u32);

struct Owner {
    u32 vtable_unused;
    u8 pad0[0x8];
    u32 flags;
    u32 pad1;
    void** target;
    u8 pad2[0xec];
    u32 slot;
};

void func_0011c828(Owner* object, u32 value) {
    void** target = object->target;
    ((void (*)(void*, u32, u32))((void**)*target)[0x44 / 4])(target, object->slot, value);
    if (func_0011f078(object->target, object->slot) != 0) {
        object->flags = object->flags | 2;
    } else {
        object->flags = object->flags & ~2;
    }
}
