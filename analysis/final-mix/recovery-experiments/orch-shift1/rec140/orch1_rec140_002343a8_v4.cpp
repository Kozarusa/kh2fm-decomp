#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_002343a8(s32 value, s32 count, s32 flag, s32 index) {
 s32 result=D_0035e368;
 register s32* cursor asm("$10")=&D_0035e360; // why: original cursor address uses register 10
 s32 slot=*cursor;
 s32* pointer=(s32*)(D_01dadc00+slot*32);
 pointer[5]=index;
 *cursor=(slot+1)&63;
 D_0035e368=result+1;
 pointer[0]=9;
 pointer[2]=value;
 pointer[3]=count;
 pointer[4]=flag;
 pointer[1]=result;
 return result;
}