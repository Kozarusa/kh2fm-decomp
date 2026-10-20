#include "../common/types.h"
extern "C" u32 D_01d48c90;
extern "C" u64 func_001050c8(void);
extern "C" void func_00165898(u64);
void func_001b2f10(void) { u32 one=1;asm("" : "+r"(one));D_01d48c90=one;func_00165898(func_001050c8()); }
