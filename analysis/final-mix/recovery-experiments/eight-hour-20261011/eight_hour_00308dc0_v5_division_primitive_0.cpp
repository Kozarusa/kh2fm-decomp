#include "../common/types.h"
s32 func_00308dc0(s32* object)
{
 register s32 numerator asm("$5")=object[9];
 register s32 denominator asm("$3")=object[6];
 asm("" : "+r"(numerator),"+r"(denominator));
 asm volatile(".set noreorder\n div $0,%0,%1\n beqzl %1,1f\n break 7\n1:\n .set reorder" : : "r"(numerator),"r"(denominator) : "hi","lo","memory");
 register s32 first asm("$5")=object[5];
 register s32 index asm("$2");
 asm volatile("mfhi %0" : "=r"(index) : "r"(first));
 register s32 next asm("$3")=index+1;
 object[9]=next;
 return first+index*64;
}
