#include "../common/types.h"
extern "C" char D_0032b968;
extern "C" u32 D_0032b994;
extern "C" void func_00102a70(void),func_00102b90(void),func_00102b58(void);
void func_00102bd8(void){volatile u32*base=(volatile u32*)&D_0032b968;register u32 callback_high asm("$14")=0x100000;asm("" : "+r"(callback_high));base[9]=(u32)&func_00102b90;base[8]=callback_high+0x2a70;D_0032b994=0;func_00102b58();}
