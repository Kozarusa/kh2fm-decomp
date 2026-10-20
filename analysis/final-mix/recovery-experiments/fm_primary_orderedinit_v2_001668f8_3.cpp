#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_001668f8(u32 object) { func_001666a0(); register u32 enabled asm("$15")=1; asm("" : "+r"(enabled)); *(u16*)(object+10)=0; *(u8*)(object+14)=enabled; *(u16*)(object+12)=0; asm volatile("" ::: "memory"); }
