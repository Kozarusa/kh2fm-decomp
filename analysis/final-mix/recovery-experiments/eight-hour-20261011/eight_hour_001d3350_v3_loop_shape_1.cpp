#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value){
s32 count=0;s32 current=*cursor;do{s32* result=cursor++;if(current==value)return result;}while(++count<3 && (current=*cursor,1));return 0;
}
