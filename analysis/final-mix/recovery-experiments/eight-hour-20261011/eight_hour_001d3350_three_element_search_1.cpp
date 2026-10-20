#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value)
{
 register s32 count asm("$14")=0;
 asm("" : "+r"(count));
 s32 current=*cursor;
 while(true){
 if(current==value)return cursor;
 ++count;
 if(count>2)break;
 current=cursor[1];
 ++cursor;
 }
 return 0;
}
