#include "../common/types.h"
extern "C" s32 D_0035f620;
extern "C" u32 D_0035f62c;
extern "C" u32 D_0035f628;
extern "C" f32 D_00374c40;
// why: no argument registers are set before these calls and their results are unused
extern "C" void func_002acda8();
extern "C" void func_002acf48();
extern "C" void func_002aceb0();
// why: a0 and a1 carry two stack word addresses filled by the callee
extern "C" void func_002ae280(u32*, u32*);

// Preserve original registry aliases.
s32 func_002ad018() asm("_Z16wtarget_002ad018jjjj");

s32 func_002ad018() {
    u32 first;
    u32 second;
    f32 ratio;
    f32* scale;
    if (D_0035f620 == 0) {
        func_002acda8();
    }
    func_002acf48();
    second = 0;
    first = 0;
    func_002ae280(&first, &second);
    D_0035f62c = D_0035f62c + first;
    D_0035f628 = D_0035f628 + second;
    func_002aceb0();
    ratio = (f32)D_0035f62c / (f32)D_0035f628;
    scale = &D_00374c40;
    asm("" : "+r"(scale), "+f"(ratio)); // why: original forms the full address with lui+addiu after the divide and loads at offset 0
    return (s32)(ratio * *scale);
}
