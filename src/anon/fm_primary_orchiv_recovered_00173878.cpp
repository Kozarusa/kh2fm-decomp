#include "../common/types.h"
struct Inner {
    u8 pad0[8];
    u32 flags;
};
struct Object {
    u8 pad0[0xc];
    Inner* inner;
    u8 pad1[0x150];
    u32 state;
};
struct Wrapper {
    u8 pad0[4];
    Object* object;
};
extern "C" bool func_0019ba60(...);
extern "C" u32 func_0019c090(...);

u32 func_00173878(s32* slot) {
    if (*slot != 0) {
        func_0019ba60(((Wrapper*)*slot)->object);
    }
    Object* object = ((Wrapper*)*slot)->object;
    s32 value = 0;
    u32 result = func_0019c090(object);
    if (result == 0) {
        s32 flag = 0;
        if ((object->inner->flags & 2) != 0 || (object->state & 0x40) != 0) {
            flag = 1;
        }
        if ((u8)flag == 0) {
            goto store;
        }
    }
    value = 1;
store:
    *slot = value;
    return result;
}
