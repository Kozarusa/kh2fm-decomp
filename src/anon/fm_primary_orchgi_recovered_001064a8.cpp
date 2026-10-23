#include "../common/types.h"
extern "C" f32 D_0036a098;
extern "C" s32 func_002fea18();
extern "C" u64 func_00313bc0(f32);

// Preserve original registry aliases.
u64 func_001064a8(u32 value) asm("_Z13func_001064a8Pv");

u64 func_001064a8(u32 value) {
    f32 scale = (f32)value;
    f32 random = (f32)func_002fea18();
    f32* divisor = &D_0036a098;
    asm("" : "+r"(divisor)); // why: original forms the divisor address before lwc1 0(reg)
    u64 result = func_00313bc0((scale * random) / *divisor);
    asm("" : "+r"(result)); // why: preserves the original non-tail call and its result
    return result;
}
