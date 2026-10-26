#include "../common/types.h"
struct Object { void* vtable; };
extern "C" u64 func_001c23a8(Object*,u32,u32,u32,u32,u32,u32);
extern "C" u8 D_00351d38;

void func_001c6e58(Object* object, u32 second, u32 third, u32 fourth)
{
    func_001c23a8(object, second, 0, 1, 0, fourth, third);
    object->vtable = &D_00351d38;
}
