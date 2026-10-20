#include "../common/types.h"
extern "C" f32 D_004f3600,D_0036b374;
extern "C" char D_0034aa18;
extern "C" void func_00190128(void*);
void func_00159c58(s32 mode,s64 phase) {
 if(phase!=0xffff) return;
 if(mode==1) {register f32 *source asm("$15")=&D_0036b374; asm("" : "+r"(source)); D_004f3600=*source;}
 asm volatile("" : "+r"(mode), "+r"(phase));
 if(phase==0xffff && mode==1) func_00190128(&D_0034aa18);
}
