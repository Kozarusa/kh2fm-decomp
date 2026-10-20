#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value)
{
 s32 count=0;
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
