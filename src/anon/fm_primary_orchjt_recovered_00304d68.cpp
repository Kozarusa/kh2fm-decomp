#include "../common/types.h"

s32 func_00304d68(double value)
{
 union Raw { double value; u64 bits; };
 Raw raw;
 raw.value=value;
 u64 bits=raw.bits;
 u32 high=(u32)(bits>>32);
 u32 low=(u32)bits;
 high&=0x7fffffff;
 high|=(u32)(low|(-low))>>31;
 high=0x7ff00000-high;
 return 1-(s32)((u32)(high|(-high))>>31);
}
