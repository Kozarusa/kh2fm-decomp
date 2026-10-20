#include "../common/types.h"
extern "C" f32 D_003713b0;
extern "C" u64 func_00313bc0(f32);

u64 func_00233ac0(u32 value) {
    f32 converted = (f32)value;
    f32* pointer = &D_003713b0;
    asm("" : "+r"(pointer)); // why: original materializes the full global address before loading.
    u64 result = func_00313bc0(converted / *pointer);
    asm("" : "+r"(result)); // why: preserves the original non-tail call and its result.
    return result;
}
