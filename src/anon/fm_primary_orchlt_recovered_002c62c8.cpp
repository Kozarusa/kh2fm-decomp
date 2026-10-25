#include "../common/types.h"
struct Object;
typedef s32 (*ObjectMethod)(Object*);
struct ObjectVtable {
    ObjectMethod first;
    ObjectMethod second;
    ObjectMethod query;
};
struct Object {
    ObjectVtable* vtable;
};
struct Owner {
    u8 pad[0x10];
    Object* slots[3];
    Object* selected;
};
extern "C" void func_002c6280(Owner*, s32);
extern "C" void func_002c65f8(Object*);

s32 func_002c62c8(Owner* owner) {
    owner->selected = 0;
    s32 found = 0;
    for (s32 index = 2; index >= 0; index--) {
        Object* object = owner->slots[index];
        if (object != 0) {
            if (found == 0) {
                if (object->vtable->query(object) != 0) {
                    found = 1;
                    owner->selected = owner->slots[index];
                } else {
                    func_002c6280(owner, index);
                }
            } else {
                func_002c65f8(object);
            }
        }
    }
    return found;
}
