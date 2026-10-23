#include "../common/types.h"
struct Inner {
    u8 pad[0x588];
    u32 flags;
};
struct Object {
    s32 first;
    Inner* inner;
};
extern "C" u32 func_0016cbc8(u64, u64, u64, u64);
extern "C" u32 func_00177998(Inner*);

u32 func_001a6440(Object* object) {
    Inner* inner = object->inner;
    if (inner->flags & 4) {
        func_00177998(inner);
    }
    return func_0016cbc8(object->first, 21, 0, 0);
}
