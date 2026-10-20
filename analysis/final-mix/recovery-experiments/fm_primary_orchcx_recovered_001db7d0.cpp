#include "../common/types.h"
extern "C" u8 D_00352a38[];

struct Inner {
    u8* vtable;
};
struct Object {
    u8* vtable;
    Inner* inner;
    s32 pad;
    s32 value;
};

void func_001db7d0(Object* object) {
    object->vtable = D_00352a38;
    register Inner* inner asm("$13") = object->inner; // why: original keeps the inner pointer in t5
    register u8* table asm("$15") = inner->vtable; // why: original loads the vtable into t7
    register s32 (*slot)(Inner*, s32) asm("$14") = *(s32 (**)(Inner*, s32))(table + 4); // why: original loads the slot into t6
    slot(inner, object->value);
}
