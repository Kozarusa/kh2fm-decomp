#include "../common/types.h"
struct Object;
struct VTable {
    void* slot0;
    void (*slot1)(Object*);
};
struct Object {
    VTable* vtable;
    u8 data[32];
};
extern "C" s32 func_002ee6d8(void*);
extern "C" void func_002edfd8(Object*, void*);

s32 func_0031e520(Object* object) {
    void* member = (u8*)object + 36;
    if (func_002ee6d8(member) != 0) {
        func_002edfd8(object, member);
        if (object != 0) {
            object->vtable->slot1(object);
            return 0;
        }
        return 0;
    }
    return 1;
}
