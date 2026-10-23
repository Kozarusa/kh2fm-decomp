#include "../common/types.h"

// Preserve original registry aliases.
void func_00159c58(s32 mode,s64 phase) asm("_Z13func_00159c58ii");
extern "C" f32 D_004f3600,D_0036b374;
extern "C" char D_0034aa18;
extern "C" void func_00190128(void*);

void func_00159c58(s32 mode,s64 phase) {
 register s64 guard asm("$15")=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 register s32 one asm("$15")=1; asm("" : "+r"(one));
 if(mode==one) {register f32 *source asm("$15")=&D_0036b374; asm("" : "+r"(source)); D_004f3600=*source;}
 guard=0xffff; asm("" : "+r"(guard));
 if(phase!=guard) return;
 one=1; asm("" : "+r"(one));
 if(mode==one) func_00190128(&D_0034aa18);
}
