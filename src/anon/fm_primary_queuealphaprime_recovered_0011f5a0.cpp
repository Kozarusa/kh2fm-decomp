#include "../common/types.h"
extern "C" u8 D_003479a8;
extern "C" void func_0011ee58(u32*);
extern "C" void func_00106420(u32*);

void func_0011f5a0(u32* object)
{
 *(u32*)object=(u32)&D_003479a8;
 func_0011ee58(object);
 func_00106420(object);
}
