#include "../common/types.h"
extern "C" s32 func_00311450(s32);
s32 func_00311460(s32 value)
{
 if((u32)(value-13)<35)return func_00311450(value);
 return -1;
}
