#include "../common/types.h"
extern "C" s8* D_0035ec94;
extern "C" void func_00240c08(s32,u32,s32);
void func_00241740(s32 value)
{
 if(value<0){register s8* object asm("$14")=D_0035ec94;asm("" : "+r"(object));value=object[1];}
 func_00240c08(value,0,19);
}
