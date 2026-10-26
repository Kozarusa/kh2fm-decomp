#include "../common/types.h"
struct Object { u8 pad[408]; u32 value; };
extern "C" void func_001386e0(Object*, u32, u32, u32, u32, u32);

void func_00158050(Object* object, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
    func_001386e0(object, p2, p3, p4, p5, p7);
    object->value = p6;
}
