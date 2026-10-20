#include "../common/types.h"
extern "C" s8* D_0035ec94;
extern "C" s32 D_0035ec88;
extern "C" s32 D_0035ec90;
extern "C" void func_002346f0(u64,u64,u64,u64,u64);
extern "C" u64 func_002416d8(u64);
void func_00241608(u64 value,u64 first,u64 second) {
 u64 result=func_002416d8(value);
 s8* pointer=D_0035ec94;
 if (!first) first=D_0035ec88;
 if (!second) second=D_0035ec90;
 return func_002346f0(*pointer,first,second,result,0);
}
