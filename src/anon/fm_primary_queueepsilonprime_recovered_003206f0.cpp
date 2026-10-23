#include "../common/types.h"
extern "C" u8 D_00351228;
extern "C" void func_001d48b0(u32*);
extern "C" void func_00106420(u32*);

void func_003206f0(u32* object)
{
 *(u32*)object=(u32)&D_00351228;
 func_001d48b0(object+0x270);
 func_00106420(object);
}
