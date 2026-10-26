#include "../common/types.h"

s32 func_00304d68(double value)
{
    u64 bits = *(u64*)&value;
    u32 high = (u32)(bits >> 32);
    u32 low = (u32)bits;
    high &= 0x7fffffff;
    high |= (low | -low) >> 31;
    high = 0x7ff00000 - high;
    return 1 - (s32)((high | -high) >> 31);
}
