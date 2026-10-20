#include "../common/types.h"
u32 func_00304db0(u64 bits)
{
 register u32 high asm("$2")=(u32)(bits>>32);
 asm("" : "+r"(high));
 u32 low=(u32)bits;
 u32 payload=(high&0x7fffffff)|((low|(0U-low))>>31);
 register u32 exponent asm("$14")=0x7ff00000U;
 asm("" : "+r"(exponent));
 return (exponent-payload)>>31;
}
