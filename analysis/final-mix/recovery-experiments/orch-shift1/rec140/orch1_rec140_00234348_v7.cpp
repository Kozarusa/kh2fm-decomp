#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234348(s32 value,s32 count,s32 flag,s32 index,s32 size,s32 number) {
 register s32 result asm("$11")=D_0035e368; // why: original sequence value uses register 11
 register s32* cursor asm("$10")=&D_0035e360; // why: original cursor address uses register 10
 s32 slot=*cursor;
 s32* pointer=(s32*)(D_01dadc00+slot*32);
 s32 next=result+1;
 pointer[7]=number;
 *cursor=(slot+1)&63;
 D_0035e368=next;
 pointer[0]=8;
 pointer[2]=value;
 pointer[3]=count;
 pointer[4]=flag;
 pointer[5]=index;
 pointer[6]=size;
 pointer[1]=result;
 return result;
}