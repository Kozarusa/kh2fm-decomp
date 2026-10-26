#include "../common/types.h"
struct Owner { u8 pad0[0x24]; u32 argument; u8 pad1[0x34 - 0x28]; u8* nested; };
extern "C" f32 func_00166d38(u8*);
extern "C" f32 func_00166d10(u32,u32);
extern "C" void func_00154cd0(f32,Owner*,u32);

void func_00155658(Owner* object)
{
    f32 first = func_00166d38(object->nested);
    u8* nested = object->nested;
    u32 argument = object->argument;
    u32 second = *(u32*)(nested + 0x48c);
    f32 result = func_00166d10(argument, *(u32*)(second + 4));
    func_00154cd0(result, object, 1);
    func_00154cd0(first, object, 2);
}
