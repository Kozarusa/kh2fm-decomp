#include "../common/types.h"
struct Object { void* vtable; };
extern "C" void func_0028b8a0(Object*);
extern "C" void func_0023f820(Object*);
extern "C" u32 func_00106420(Object*);
extern "C" u8 D_0035f3a0;

u32 func_0028b830(Object* object)
{
    object->vtable = &D_0035f3a0;
    func_0028b8a0(object);
    func_0023f820(object);
    return func_00106420(object);
}
