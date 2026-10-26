#include "../common/types.h"
struct Object { void* vtable; };
extern "C" void func_0023c098(void*);
extern "C" void func_002369f0(void*);
extern "C" u8 D_0035eb98;
extern "C" u8 D_00347f98;

void func_0031cd90(Object* object)
{
    object->vtable = &D_0035eb98;
    func_0023c098((u8*)object + 48);
    func_002369f0((u8*)object + 24);
    object->vtable = &D_00347f98;
}
