#include "../common/types.h"
extern "C" s32* func_001a6a20(s32, s32);
extern "C" u32 func_00176a90(s32);

s32 func_00179b68(s32 object) {
    s32 result = 0;
    s32* table = func_001a6a20(0x10002, 12);
    if (table[1] != 0 || func_00176a90(object) != 0) {
        result = 1;
    }
    return result;
}
