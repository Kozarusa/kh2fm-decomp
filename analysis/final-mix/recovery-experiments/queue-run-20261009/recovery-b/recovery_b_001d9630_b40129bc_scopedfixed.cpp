#include "../common/types.h"
extern "C" void func_001a3188(u16,s32,s32);
void func_001d9630(u16* p,s32 n) { if(n<=0) return; register s32 count asm("$16")=n; asm("" : "+r"(count)); do { if(*p) { func_001a3188(*p,100,0); *p=0; } --count; ++p; } while(count); }
