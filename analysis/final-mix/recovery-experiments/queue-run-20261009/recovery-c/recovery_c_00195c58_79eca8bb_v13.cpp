#include "../common/types.h"
extern "C" void func_00158f90(void);
void func_00195c58(u64 x,s32 p) {
u32 a=*(u32*)(p+0x588);asm volatile("" : "+r"(a) : : "$31");if(a&0x80)func_00158f90();
}