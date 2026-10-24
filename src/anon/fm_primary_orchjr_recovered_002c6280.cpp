#include "../common/types.h"
struct Object;
typedef void (*ObjectMethod)(Object*);
struct ObjectVtable {
    ObjectMethod first;
    ObjectMethod release;
};
struct Object {
    ObjectVtable* vtable;
};

void func_002c6280(u32 owner, s32 index) {
    Object** slot = (Object**)(index * 4 + owner + 0x10);
    Object* object = *slot;
    if (object != 0) {
        object->vtable->release(object);
        *slot = 0;
    }
}
