#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value)
{
 register s32 count asm("$14")=0;
 for(;count<3;++count){
 s32* result=cursor;
 register s32 current asm("$15")=*result;
 asm("" : "+r"(count),"+r"(current));
 ++cursor;
 if(current==value)return result;
 }
 return 0;
}
