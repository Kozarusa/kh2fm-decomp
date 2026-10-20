#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_0017fe10(void*, u8*);
extern "C" f32 func_0017ce10(f32);

void func_0017fef0(u8* object) {
    Quad buffer;
    Quad temporary;
    func_0017fe10(&buffer, object);
    Quad* target = (Quad*)(object + 0xa0);
    // why: original holds the scratch address in t7 ($15)
    register Quad* scratch asm("$15") = &temporary;
    // why: original holds the accumulator address in t6 ($14)
    register Quad* accumulator asm("$14") = (Quad*)(object + 0xb0);
    // why: VU macro vector difference and accumulate; the compiler cannot emit lqc2/vsub/sqc2
    asm volatile(
        "lqc2 $vf1,0(%3); lqc2 $vf2,0(%0); vsub.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%2); "
        "lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vadd.wxyz $vf1,$vf1,$vf2; sqc2 $vf1,0(%1)"
        : "+r"(target), "+r"(accumulator), "+r"(scratch) : "r"(&buffer) : "memory");
    *(f32*)(object + 0xbc) = func_0017ce10(*(f32*)(object + 0xbc));
    if (target != &buffer) {
        // why: binds the quad temporary to t0 as in the original
        register Quad copy asm("$8") = buffer;
        *target = copy;
    }
}
