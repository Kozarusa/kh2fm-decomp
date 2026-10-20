#include "../common/types.h"
extern "C" u8 D_00352a38[];

struct Inner {
    s32* vtable;
};
struct Object {
    u8* vtable;
    Inner* inner;
    s32 pad;
    s32 value;
};

s32 func_001db7d0(Object* object) {
    object->vtable = D_00352a38;
    Inner* inner = object->inner;
    s32 value = object->value;
    return ((s32 (*)(Inner*, s32))inner->vtable[1])(inner, value);
}
