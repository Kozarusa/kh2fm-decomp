#include "../common/types.h"
extern "C" f32 D_0036c258;
extern "C" u64 func_0014aba8();
extern "C" void func_0014aa58(u64,s32,s32);
void func_0016e000(f32*object){register f32*scale asm("$15")=&D_0036c258;asm("":"+r"(scale));f32 coefficient=scale[0];asm("":"+r"(object):"f"(coefficient):"$f0");f32 scaled=object[0]*coefficient;register f32 rounded asm("$f1");asm("cvt.w.s %0,%1":"=f"(rounded):"f"(scaled));union {f32 value;s32 word;} converted;converted.value=rounded;s32 amount=converted.word;u64 receiver=func_0014aba8();func_0014aa58(receiver,amount,0);}

