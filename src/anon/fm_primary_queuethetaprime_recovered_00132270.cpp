#include "../common/types.h"
extern "C" u8 D_00347c00;

void func_00132270(u32* object,u32 payload)
{
 object[1]=payload;
 object[3]=0;
 object[4]=0;

 *(f32*)(object+6)=1.0f;
 object[5]=0;
 *object=(u32)&D_00347c00;
 object[7]=0;
 object[8]=0;
 object[2]=0;
}
