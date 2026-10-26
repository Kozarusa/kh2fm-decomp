#include "../common/types.h"
struct Object { void* vtable; };
extern "C" void func_001c23a8(Object*,u32,u32,u32,u32,u32,u32);
extern "C" void* D_00363748;
extern "C" u8 D_00363758;

void func_002ed2b0(Object* object, u32 second, u32 third)
{
    func_001c23a8(object, second, 0, 1, 0, 128, third);
    object->vtable = &D_00363758;
    D_00363748 = object;
}
