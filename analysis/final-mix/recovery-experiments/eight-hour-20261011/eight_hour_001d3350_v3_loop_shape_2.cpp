#include "../common/types.h"
s32* func_001d3350(s32* cursor,s32 value){
s32 count=0;do{s32* result=cursor++;if(*result==value)return result;}while(++count<3);return 0;
}
