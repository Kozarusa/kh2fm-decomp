#include "../common/types.h"
extern "C" u32 func_00144d90(void*, void*);

s32 func_00147050(u8* object, s32 index, u8* context, s32 depth, s32* best) {
    s16* pointer = (s16*)(*(u8**)(object + 4) + index * 48);
    s32 result = 0;
    s32 count;
    if (func_00144d90(pointer + 8, context + 208) == 0) {
        return 0;
    }
    if (*best <= depth) {
        *best = depth;
        result = index;
    }
    for (count = 0; count < 8; count++) {
        s16 child = *pointer++;
        if (child == -1) {
            break;
        }
        s32 found = func_00147050(object, child, context, depth + 1, best);
        if (found != 0) {
            result = found;
        }
    }
    return result;
}
