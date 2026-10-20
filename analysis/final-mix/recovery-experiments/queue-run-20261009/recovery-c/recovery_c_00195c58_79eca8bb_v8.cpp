#include "../common/types.h"
extern "C" u32 func_00158f90(void);
void func_00195c58(u64 x,s32 p) {
u32 a;asm volatile("lw %0,0x588(%1)" : "=r"(a) : "r"(p) : "memory"); if(a&0x80)func_00158f90();
}