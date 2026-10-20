#include "../common/types.h"
extern "C" f32 D_004f35a4,D_004f35a8,D_0036b31c,D_0036b320;
void func_00158fd8(s32 mode,s64 phase) {
 if(phase!=0xffff) return;
 if(mode==1) {register f32 *source asm("$15")=&D_0036b31c; asm("" : "+r"(source)); D_004f35a4=*source;}
 asm volatile("" : "+r"(mode), "+r"(phase));
 if(phase==0xffff && mode==1) {register f32 *source asm("$15")=&D_0036b320; asm("" : "+r"(source)); D_004f35a8=*source;}
}
