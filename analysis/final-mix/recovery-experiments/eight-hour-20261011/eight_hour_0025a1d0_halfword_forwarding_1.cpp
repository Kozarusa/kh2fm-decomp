#include "../common/types.h"
extern "C" u16 D_00372eea;
extern "C" void func_002b4b00(void);
extern "C" void func_0028f4d8(u32,u16,u32);
extern "C" void func_00240be0(void);
void func_0025a1d0(void)
{
 func_002b4b00();
 register u32 high asm("$15")=0x00370000;
 asm("" : "+r"(high));
 func_0028f4d8(0,*(u16*)(high+0x2eea),0);
 func_00240be0();
}
