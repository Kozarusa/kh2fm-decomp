#include "../common/types.h"
extern "C" u8 D_00348d58;
extern "C" u8 D_00348698;
extern "C" void func_00106420(u32*);
void func_0031e0b8(u32* object)
{
 register u32 first asm("$14")=(u32)&D_00348d58;
 register u32 second asm("$13")=(u32)&D_00348698;
 asm("" : "+r"(first),"+r"(second));
 object[0]=first;
 asm("" : : : "memory");
 object[20]=second;
 func_00106420(object);
}
