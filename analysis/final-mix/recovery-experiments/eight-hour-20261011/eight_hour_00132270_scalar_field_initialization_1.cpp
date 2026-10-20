#include "../common/types.h"
extern "C" u8 D_00347c00;
extern "C" f32 D_0036ac28;
void func_00132270(u32* object,u32 payload)
{
 object[1]=payload;
 object[2]=0;
 object[3]=0;
 register f32* scale asm("$15")=&D_0036ac28;
 asm("" : "+r"(scale));
 *(f32*)(object+6)=*scale;
 object[4]=0;
 *object=(u32)&D_00347c00;
 object[5]=0;
 object[7]=0;
 object[8]=0;
}
