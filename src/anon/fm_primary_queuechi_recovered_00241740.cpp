#include "../common/types.h"
extern "C" s8* D_0035ec94;
extern "C" void func_00240c08(s32,u32,s32);

void func_00241740(s32 value)
{
 if(value<0)value=D_0035ec94[1];
 func_00240c08(value,0,19);
}
