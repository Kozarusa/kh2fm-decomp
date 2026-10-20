#include "../common/types.h"
extern "C" u8 D_00352a38[];

struct Inner {
    virtual void slot0(s32);
    virtual s32 slot1(s32);
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
    return inner->slot1(object->value);
}
