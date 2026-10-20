#include "../common/types.h"
extern "C" s32 func_00311450(s32);
s32 func_00311460(s32 value)
{
 register u32 offset asm("$2")=value-13;
 register s32 result asm("$2");
 if(offset>=35){
 result=-1;
asm volatile("" : : "r"(result));
 }else{
 result=func_00311450(value);
 asm volatile("");
 }
 return result;
}
