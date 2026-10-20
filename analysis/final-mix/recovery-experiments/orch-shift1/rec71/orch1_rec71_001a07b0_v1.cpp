#include "../common/types.h"
struct VTable {
    u8 pad[28];
    void (*fn)(void*, void*, void*);
};
struct Obj {
    VTable* vtable;
};
extern "C" Obj* func_0017aab8(s32);

void* func_001a07b0(void* self, void* unused, void* arg) {
    Obj* obj = func_0017aab8(5);
    obj->vtable->fn(self, obj, arg);
    return self;
}
