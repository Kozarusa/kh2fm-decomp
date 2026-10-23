#include "../common/types.h"

// Preserve original registry aliases.
void func_00158fd8(s32 mode,s64 phase) asm("_Z16wtarget_00158fd8jjjj");
extern "C" f32 D_004f35a4,D_004f35a8,D_0036b31c,D_0036b320;

void func_00158fd8(s32 mode,s64 phase) {
 register s64 guard asm("$15")=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 register s32 one asm("$15")=1; asm("" : "+r"(one));
 if(mode==one) {register f32 *source asm("$15")=&D_0036b31c; asm("" : "+r"(source)); D_004f35a4=*source;}
 guard=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 one=1; asm("" : "+r"(one));
 if(mode==one) {register f32 *source asm("$15")=&D_0036b320; asm("" : "+r"(source)); D_004f35a8=*source;}
}
