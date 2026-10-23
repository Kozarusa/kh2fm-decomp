#include "../common/types.h"
extern "C" u8 D_00350a70;
extern "C" u8 D_00350a56;
extern "C" void func_001ad280(u32*,u64);
extern "C" void func_001c1130(s32);
extern "C" void func_0014c9d8(s32);

void func_001ad5a8(u32* object,u64 payload)
{
 func_001ad280(object,payload);
 *(u32*)object=(u32)&D_00350a70;
 D_00350a56=1;
 func_001c1130(12);
 func_0014c9d8(8);
}
