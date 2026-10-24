#include "../common/types.h"
extern "C" s32 D_0035037c;
extern "C" s32 func_001024a8(u32);
extern "C" s32 func_001d3148(s32);

s32 func_00197ac0(u32 value) {
    s32 pointer = D_0035037c;
    if (pointer != 0) {
        return func_001d3148(pointer + 0x40);
    }
    return func_001024a8(value);
}
