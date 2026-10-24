#include "../common/types.h"
struct Entry {
    s32 key;
    s32 object;
};
extern "C" Entry D_01c61970[];
extern "C" s32 D_01c6197c;
extern "C" s32 func_00191f20(s32, u64);
extern "C" s32 func_001920f0(s32);

// Preserve original registry aliases.
s32 func_00192048(s32 value) asm("_Z16u_tail4_00192048jjjj");

s32 func_00192048(s32 value) {
    s32 result = 0;
    s32 index = 0;
    do {
        s32 object = D_01c61970[index].object;
        if (object != 0) {
            result = func_00191f20(object, value);
            if (result != 0) {
                goto found;
            }
        }
        index++;
    } while (index < 3);
    if (result == 0) {
        result = func_00191f20(D_01c6197c, 0x8adc);
    }
found:
    if ((u32)(value - 0x4ac0) < 3) {
        result = func_001920f0(result);
    }
    return result;
}
