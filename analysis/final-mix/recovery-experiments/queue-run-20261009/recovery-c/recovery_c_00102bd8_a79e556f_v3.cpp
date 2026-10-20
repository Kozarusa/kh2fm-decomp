#include "../common/types.h"
extern "C" char D_0032b968;
extern "C" u32 D_0032b994;
extern "C" void func_00102a70(void),func_00102b90(void),func_00102b58(void);
void func_00102bd8(void){register u32*base asm("$13")=(u32*)&D_0032b968;asm("" : "+r"(base));base[9]=(u32)&func_00102b90;asm("" ::: "memory");base[8]=(u32)&func_00102a70;asm("" ::: "memory");D_0032b994=0;func_00102b58();}
