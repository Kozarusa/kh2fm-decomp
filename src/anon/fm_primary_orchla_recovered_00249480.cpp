#include "../common/types.h"
extern "C" s8 D_00371d90[];
extern "C" bool func_001a6d08(u32);

s32 func_00249480(s32 index) {
    // why: each D_00371d90 row is 36 bytes; the four signed entries start at offset 32
    s8* entry = D_00371d90 + index * 36;
    s32 result = 1;
    s32 count = 0;
    do {
        if (entry[count + 32] < 0) {
            break;
        }
        if (func_001a6d08(entry[count + 32])) {
            result = 0;
            break;
        }
        count += 1;
    } while (count < 4);
    return result;
}
