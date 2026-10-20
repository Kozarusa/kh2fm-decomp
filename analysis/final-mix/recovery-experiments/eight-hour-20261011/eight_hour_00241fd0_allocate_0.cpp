#include "../common/types.h"
extern "C" u32 func_001063f0(s32);
extern "C" void func_00242088(u32*);
void func_00241fd0(u32* object,u32 value)
{
 u32* saved=object;
 saved[0]=value;
 saved[1]=func_001063f0(1024);
 func_00242088(saved);
}
