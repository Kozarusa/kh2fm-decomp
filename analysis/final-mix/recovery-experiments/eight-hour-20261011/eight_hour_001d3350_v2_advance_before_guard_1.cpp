#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value)
{
 register s32 count asm("$14")=0;
 asm("" : "+r"(count));
 s32 current=*cursor;
 do{
 s32* result=cursor++;
 if(current==value)return result;
 ++count;
 if(count<3)current=*cursor;
 }while(count<3);
 return 0;
}
