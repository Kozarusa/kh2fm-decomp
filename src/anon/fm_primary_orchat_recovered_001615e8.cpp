#include "../common/types.h"
struct Vtbl {
    u8 pad[8];
    s32 (*method)(void*);
};
struct Obj {
    // why: volatile keeps the vtable load after the scale store
    Vtbl* volatile vtbl;
};
extern "C" Obj* func_00161548(u8* object);
extern "C" void func_00161770(u8* object);
extern "C" void func_001616d8(u8* object);

void func_001615e8(u8* object, f32 scale) {
    Obj* child = func_00161548(object);
    *(Obj**)(object + 0x48) = child;
    if (child != 0) {
        // why: keeps store order against the vtable load
        *(volatile f32*)(object + 0x4c) = scale;
        *(f32*)(object + 0x50) = (f32)child->vtbl->method(child);
        func_00161770(object);
        func_001616d8(object);
    }
}
