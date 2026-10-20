#include "../common/types.h"
extern "C" u8 D_00347bb0;
extern "C" u8 D_003a99f0[];
extern "C" void func_00124bb8(u32*,u32);
extern "C" void func_0011ed90(u32);
void func_00127f40(u32* object,u32 resource)
{
 func_00124bb8(object,resource);
 u32 header=object[1];
 *object=(u32)&D_00347bb0;
 register u32 origin asm("$13")=(u32)D_003a99f0;
 u32 first=*(u16*)(header+16);
 u32 end=*(u16*)(header+18);
 object[2]=origin;
 u32 count=end-first;
 u32 endAgain=*(volatile u16*)(header+18);
 register u32 stride asm("$14")=count*64;
 asm("" : "+r"(stride));
 register u32 buffer asm("$15")=origin+endAgain*64;
 asm("" : "+r"(buffer));
 object[3]=buffer;
 register u32 next asm("$12")=buffer+stride;
 asm("" : "+r"(next));
 object[4]=next;
 object[5]=next+stride;
 func_0011ed90(header+*(u32*)(header+24));
}
