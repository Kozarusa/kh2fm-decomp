#include "../common/types.h"
extern "C" volatile s32 D_0035e360;
extern "C" volatile s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234400(s32 value,s32 count,s32 flag,s32 index,s32 size,s32 number) {
 s32 result=D_0035e368;
 register volatile s32* cursor asm("$10")=&D_0035e360; // why: original cursor address uses register 10
 asm("" : "+r"(cursor)); // why: preserve original cursor address register
 s32 slot=*cursor;
 volatile s32* pointer=(volatile s32*)(D_01dadc00+slot*32);
 pointer[7]=number;
 *cursor=(slot+1)&63;
 D_0035e368=result+1;
 pointer[0]=10;
 pointer[2]=value;
 pointer[3]=count;
 pointer[4]=flag;
 pointer[5]=index;
 pointer[6]=size;
 pointer[1]=result;
 return result;
}