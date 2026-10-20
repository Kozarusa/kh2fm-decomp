#include "../common/types.h"
u32 func_003160e0(s32* first,s32* second,u32 payload,u32* output)
{
 if(first[1]==second[1]){
 output[0]=payload;
 output[1]=6;
 output[3]=8;
 return 1;
 }
 return 0;
}
