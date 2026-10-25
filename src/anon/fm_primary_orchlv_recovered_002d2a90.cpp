#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Object;
typedef void (*ObjectMethod)(Object*, s32, s32, Object*, s32);
struct ObjectVtable {
    u8 pad[0x50];
    ObjectMethod notify;
};
struct Object {
    ObjectVtable* vtable;
    u8 pad0[0xb3c - 4];
    s32 pending;
    u8 pad1[0xb6c - 0xb40];
    s32 state;
};

extern "C" u64 func_0016abf8(Object*, s32, s32, s32);
extern "C" kn::FVector* func_001dc5f8(u64);
extern "C" void func_0016bda8(kn::FVector*, Object*);

void func_002d2a90(Object* object) {
    if (object->state >= 0) {
        if (object->state == 0) {
            object->vtable->notify(object, 0x60c, 0, object, 0);
        } else {
            object->vtable->notify(object, 0x60d, 0, object, 0);
            u64 effect = func_0016abf8(object, 1, 1, 0);
            if (effect != 0) {
                kn::FVector* position = func_001dc5f8(effect);
                kn::FVector current;
                func_0016bda8(&current, object);
                *position = current;
            }
        }
        object->pending = 0;
    }
}
