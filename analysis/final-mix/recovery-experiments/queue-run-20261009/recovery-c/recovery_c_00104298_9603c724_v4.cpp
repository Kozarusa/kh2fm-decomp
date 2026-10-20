#include "../common/types.h"
extern "C" char D_0032ba48,D_0032b930;
void func_00104298(s32 type,s32 id){if(id==0xffff&&type==1){register s32 kept asm("$4")=type;asm("" : "+r"(kept));u32*o=(u32*)&D_0032ba48;*(u32*)&D_0032ba48=(u32)&D_0032b930;o[5]=kept;o[6]=170000;o[10]=0x4000;*(u8*)((char*)o+8)=0x47;o[1]=0;o[7]=0;o[8]=0;o[9]=0;}}
