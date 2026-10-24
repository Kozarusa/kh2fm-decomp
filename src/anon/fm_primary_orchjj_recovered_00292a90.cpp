#include "../common/types.h"
struct Entry {
    s32 id;
    u32 enabled : 1;
    u32 flags : 31;
    s32 unknown8;
    s32 unknownC;
};
extern "C" s32 D_0035f4d0;
extern "C" Entry* D_0035f4d4;

s32 func_00292a90(s32 id) {
    s32 result = 0;
    s32 index;
    for (index = 0; index < D_0035f4d0; index++) {
        if ((u8)D_0035f4d4[index].enabled && D_0035f4d4[index].id == id) {
            result = 1;
            break;
        }
    }
    return result;
}
