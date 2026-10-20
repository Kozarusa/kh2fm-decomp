#include "../common/types.h"
extern "C" f32 D_004f3580,D_004f3584,D_0036b200,D_0036b204;

void func_0014ec40(s32 mode,s64 phase) {
 register s64 guard asm("$15")=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 register s32 one asm("$15")=1; asm("" : "+r"(one));
 if(mode==one) {register f32 *source asm("$15")=&D_0036b200; asm("" : "+r"(source)); D_004f3580=*source;}
 guard=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 one=1; asm("" : "+r"(one));
 if(mode==one) {register f32 *source asm("$15")=&D_0036b204; asm("" : "+r"(source)); D_004f3584=*source;}
}
