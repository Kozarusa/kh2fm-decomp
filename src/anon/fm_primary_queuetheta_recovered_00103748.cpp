#include "../common/types.h"
extern "C" s32 D_0032ba24,D_0032ba14,D_0032ba18;
extern "C" u8 D_0032ba30;
extern "C" void func_00170c00(s64);

// Preserve original registry aliases.
void func_00103748(void) asm("_ZN4MENU16DestoryAllocatorEv");

void func_00103748(void){if(!D_0032ba30&&D_0032ba24!=1&&D_0032ba24!=2&&D_0032ba24!=6)func_00170c00(D_0032ba14);D_0032ba14=0;D_0032ba18=0;D_0032ba30=0;}
