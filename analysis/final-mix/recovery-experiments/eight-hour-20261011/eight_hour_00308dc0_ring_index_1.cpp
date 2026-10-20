#include "../common/types.h"
s32 func_00308dc0(s32* object)
{
 register s32 numerator asm("$5")=object[9];
 register s32 denominator asm("$3")=object[6];
 asm("" : "+r"(numerator),"+r"(denominator));
 s32 index=numerator%denominator;
 object[9]=index+1;
 return object[5]+index*64;
}
