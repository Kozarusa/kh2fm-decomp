#include "../common/types.h"
struct Object;
struct VTable {
    void* slots[8];
    s32 (*slot8)(Object*);
};
struct Object {
    VTable* vtable;
};
extern "C" void func_001acd78(Object*);

s32 func_0031fd78(Object* object) {
    func_001acd78(object);
    // why: original calls through t7 ($15), compiler picks v0 for the return-valued pointer
    register s32 (*slot)(Object*) asm("$15") = object->vtable->slot8;
    return slot(object);
}
