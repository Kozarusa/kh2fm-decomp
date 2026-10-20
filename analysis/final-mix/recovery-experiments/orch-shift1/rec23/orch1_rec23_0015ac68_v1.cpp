#include "../common/types.h"
struct Object;
struct VTable {
    u8 pad[20];
    void (*method)(Object*);
};
struct Object {
    VTable* vtable;
};
extern "C" bool func_00197920(...);
extern "C" bool func_001ad938(...);
extern "C" void func_00138840(void*);
extern "C" s32 D_0034f240;

void func_0015ac68(Object* object) {
    if (func_00197920(object) || func_001ad938() || (D_0034f240 & 1 & 0xff)) {
        object->vtable->method(object);
        return;
    }
    func_00138840(object);
}
