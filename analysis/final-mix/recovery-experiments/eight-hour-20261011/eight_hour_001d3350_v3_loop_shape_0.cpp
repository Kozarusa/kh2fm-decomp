#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value){
s32 count=0;for(;count<3;++count){s32* result=cursor++;if(*result==value)return result;}return 0;
}
