#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_001668f8(u32 object) { func_001666a0(); *(volatile u16*)(object+10)=0; *(volatile u8*)(object+14)=1; *(volatile u16*)(object+12)=0; asm volatile("" ::: "memory"); }
