#include "../common/types.h"
extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 original) { register u32 object asm("$14")=original; asm("" : "+r"(object)); *(u32*)(original+0x70)=4; register u32 value asm("$5")=*(u32*)(object+0x80); asm volatile("" : "+r"(value)); func_001991a8(0x22,value); }
