#include "../common/types.h"
extern "C" f32 D_004f3580,D_004f3584,D_0036b200,D_0036b204;
void func_0014ec40(s32 mode,s64 phase) {
 if(phase!=0xffff) return;
 if(mode==1) {register f32 *source asm("$15")=&D_0036b200; asm("" : "+r"(source)); D_004f3580=*source;}
 asm volatile("" : "+r"(mode), "+r"(phase) : : "$15");
 if(phase==0xffff && mode==1) {register f32 *source asm("$15")=&D_0036b204; asm("" : "+r"(source)); D_004f3584=*source;}
}
