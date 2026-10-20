#include "../common/types.h"
extern "C" u8 D_00347c00;
extern "C" f32 D_0036ac28;
void func_00132270(u32* object,u32 payload)
{
 object[1]=payload;
 object[2]=0;
 object[3]=0;
 *(f32*)(object+6)=D_0036ac28;
 object[4]=0;
 *object=(u32)&D_00347c00;
 object[5]=0;
 object[7]=0;
 object[8]=0;
}
