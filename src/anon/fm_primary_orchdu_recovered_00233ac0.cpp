#include "../common/types.h"
extern "C" u64 func_00313bc0(f32);

u64 func_00233ac0(u32 value) {
    f32 converted = (f32)value;

         u64 result = func_00313bc0(converted / 216000.0f);
    asm("" : "+r"(result));     return result;
}
