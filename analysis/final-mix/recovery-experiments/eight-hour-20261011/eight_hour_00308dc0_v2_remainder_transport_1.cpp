#include "../common/types.h"
s32 func_00308dc0(s32* object)
{
 register s32 numerator asm("$5")=object[9];
 register s32 denominator asm("$3")=object[6];
 asm("" : "+r"(numerator),"+r"(denominator));
 register s32 index asm("$2")=numerator%denominator;
 register s32 first asm("$5")=object[5];
 asm("" : "+r"(first),"+r"(index));
 object[9]=index+1;
 return first+index*64;
}
