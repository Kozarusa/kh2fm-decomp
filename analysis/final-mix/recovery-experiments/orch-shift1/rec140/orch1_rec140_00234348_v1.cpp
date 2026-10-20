#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234348(s32 value,s32 count,s32 flag,s32 index,s32 size,s32 number) {
 s32 slot=D_0035e360;
 s32 result=D_0035e368;
 s32* pointer=(s32*)(D_01dadc00+slot*32);
 pointer[7]=number;
 D_0035e360=(slot+1)&63;
 D_0035e368=result+1;
 pointer[0]=8;
 pointer[2]=value;
 pointer[3]=count;
 pointer[4]=flag;
 pointer[5]=index;
 pointer[6]=size;
 pointer[1]=result;
 return result;
}