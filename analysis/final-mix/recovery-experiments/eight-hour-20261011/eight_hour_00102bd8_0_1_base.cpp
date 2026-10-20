#include "../common/types.h"
extern "C" char D_0032b968;
extern "C" u32 D_0032b994;
extern "C" void func_00102b90(void),func_00102b58(void);
// Original callback 00102a70 has high word 00100000 and positive low offset 2a70.
void func_00102bd8(void)
{
 volatile u32* table=(volatile u32*)&D_0032b968;
 register u32 first asm("$15")=(u32)&func_00102b90;
 register u32 high asm("$14")=0x00100000;
 asm("" : "+r"(table) : "r"(high));
 table[9]=first;
 table[8]=high+0x2a70;
 D_0032b994=0;
 func_00102b58();
}
