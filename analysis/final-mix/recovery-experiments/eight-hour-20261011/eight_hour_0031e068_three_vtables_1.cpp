#include "../common/types.h"
extern "C" u8 D_00348d58;
extern "C" u8 D_00348698;
extern "C" void func_00106420(u32*);
void func_0031e068(u32* object)
{
 register u32 second asm("$13")=(u32)&D_00348698;
 register u32 first asm("$15")=(u32)&D_00348d58;
 asm("" : "+r"(second),"+r"(first));
 object[0]=first;
 object[36]=second;
 object[104]=second;
 func_00106420(object);
}
