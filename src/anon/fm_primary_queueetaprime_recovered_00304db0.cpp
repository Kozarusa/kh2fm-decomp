#include "../common/types.h"

u32 func_00304db0(double value)
{
    u64 bits = *(u64*)&value;
    u32 high = (u32)(bits >> 32);
    u32 low = (u32)bits;
    high &= 0x7fffffff;
    high |= (low | -low) >> 31;
    high = 0x7ff00000 - high;
    return high >> 31;
}
