#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value){
s32 count=0;s32* result;do{result=cursor++;if(*result==value)break;}while(++count<3);if(count==3)return 0;return result;
}
