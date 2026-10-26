#include "../common/types.h"
struct Object { void* vtable; u8 pad[256]; void* inner; };
extern "C" void func_00239870(void*);
extern "C" u8 D_00348590;
extern "C" u8 D_00347e60;
extern "C" u8 D_00347f98;

void func_0031b070(Object* object)
{
    object->vtable = &D_00348590;
    object->inner = &D_00347e60;
    func_00239870((u8*)object + 284);
    object->inner = &D_00347f98;
    object->vtable = &D_00347f98;
}
