#include "../common/types.h"
struct Object { void* vtable; };
extern "C" void func_0023c098(void*);
extern "C" void func_002369f0(void*);
extern "C" s32 func_00106420(Object*);
extern "C" u8 D_00363880;
extern "C" u8 D_003637e0;

s32 func_00325ae8(Object* object)
{
    object->vtable = &D_00363880;
    func_0023c098((u8*)object + 64);
    func_002369f0((u8*)object + 40);
    object->vtable = &D_003637e0;
    return func_00106420(object);
}
