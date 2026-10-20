#include "../common/types.h"
u32 func_00304db0(double value)
{
 union Raw { double value; u64 bits; };
 Raw raw;
 raw.value=value;
 u64 bits=raw.bits;
 s32 high=(s32)(bits>>32);
 s32 low=(s32)bits;
 high&=0x7fffffff;
 high|=(u32)(low|(-low))>>31;
 high=0x7ff00000-high;
 return (u32)high>>31;
}
