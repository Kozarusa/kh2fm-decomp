#include "../common/types.h"
struct VObj;
struct VTable {
    void (*first)(VObj*);
};
struct VObj {
    VTable* vtable;
};
extern "C" u32** D_0034b278;
extern "C" VObj* D_0034b240;
extern "C" void func_0031dd50(u32);

void func_0015de98() {
    u32** heap = D_0034b278;
    VObj* object = ((VObj* (*)(u32**, s32, u32))(**(u32**)heap))(heap, 4928, (u32)__builtin_return_address(0));
    func_0031dd50((u32)object);
    D_0034b240 = object;
    object->vtable->first(object);
}
