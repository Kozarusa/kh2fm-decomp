#include "../common/types.h"
extern "C" u8 D_004f3700[];
void func_0015cbb8(u8 a,u8 b,u8 c,u8 d)
{
 register u8* cursor asm("$15")=D_004f3700;
 asm("" : "+r"(cursor));
 D_004f3700[0]=a;
 cursor[1]=b;
 cursor[3]=d;
 cursor[2]=c;
}
