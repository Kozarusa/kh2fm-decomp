#include "../common/types.h"
extern "C" s32 func_00311450(s32);
s32 func_00311460(s32 value)
{
 register u32 offset asm("$2")=value-13;
 asm("" : "+r"(offset));
 s32 result;
 if(offset<35){
 result=func_00311450(value);
 asm volatile("");
 }else{
 result=-1;
 }
 return result;
}
