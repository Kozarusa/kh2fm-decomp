#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_002342f0(s32 value, s32 count, s32 flag, s32 index) {
 s32* sequence=&D_0035e368;
 s32* cursor=&D_0035e360;
 s32 result=*sequence;
 s32 slot=*cursor;
 s32* pointer=(s32*)(D_01dadc00+slot*32);
 pointer[5]=index;
 *cursor=(slot+1)&63;
 *sequence=result+1;
 pointer[0]=7;
 pointer[2]=value;
 pointer[3]=count;
 pointer[4]=flag;
 pointer[1]=result;
 return result;
}