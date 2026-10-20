#include "../common/types.h"
extern "C" u8 D_00373a98[],D_00373aa0[];
void func_002713a0(s32 a,u8**b,u32*c)
{
 u8* p;
 if(a!=0)goto second;
 p=D_00373a98;goto publish;
 second:p=D_00373aa0;
 publish:
 *b=p;register u32 count asm("$14")=3;asm volatile("" : "+r"(count) : "r"(p) : "memory");*c=count;
}
