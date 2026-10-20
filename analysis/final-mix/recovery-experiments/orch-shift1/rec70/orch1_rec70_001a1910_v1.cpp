#include "../common/types.h"

void func_001a1910(s32* base, s32 delta, s32 index) {
    s32* entry = (s32*)((u8*)base + index * 12);
    s32 sum = entry[0] + delta;
    s32 result = entry[2];
    if (!(sum < entry[2])) {
        result = sum;
        if (entry[1] < sum) {
            result = entry[1];
        }
    }
    entry[0] = result;
}
