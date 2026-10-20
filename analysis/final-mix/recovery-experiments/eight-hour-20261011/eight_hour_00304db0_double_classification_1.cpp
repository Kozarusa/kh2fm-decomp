#include "../common/types.h"
u32 func_00304db0(u64 bits)
{
 u32 high=(u32)(bits>>32);
 u32 low=(u32)bits;
 u32 payload=(high&0x7fffffff)|((low|(0U-low))>>31);
 return (0x7ff00000U-payload)>>31;
}
