#include "../common/types.h"

struct Owner {
    u8 pad[0xbd4];
    s32 handle[2];
};

// why: neither callee has an accepted definition or a used result; each writes v0 only on one path, so void
extern "C" void func_002f1900(s32*, s32, Owner*);
extern "C" void func_002f19c8(s32*);

void func_002c6050(Owner* owner, s32 mode) {
    switch (mode) {
    case 1:
        func_002f1900(&owner->handle[0], 5, owner);
        func_002f19c8(&owner->handle[1]);
        break;
    case 2:
        func_002f19c8(&owner->handle[0]);
        func_002f1900(&owner->handle[1], 6, owner);
        break;
    default:
        for (s32 i = 0; i < 2; i++) {
            func_002f19c8(&owner->handle[i]);
        }
        break;
    }
}
