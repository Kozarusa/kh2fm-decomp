#include "../common/types.h"
struct Vtbl {
    u8 pad[8];
    s32 (*method)(void*);
};
struct Obj {
    Vtbl* vtbl;
};
extern "C" Obj* func_00161548(u8* object);
extern "C" void func_00161770(u8* object, f32 value);
extern "C" void func_001616d8(u8* object);

void func_001615e8(u8* object, f32 scale) {
    Obj* child = func_00161548(object);
    *(Obj**)(object + 0x48) = child;
    if (child != 0) {
        *(f32*)(object + 0x4c) = scale;
        *(f32*)(object + 0x50) = (f32)child->vtbl->method(child);
        func_00161770(object, 0);
        func_001616d8(object);
    }
}